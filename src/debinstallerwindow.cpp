/*
 Copyright (C) 2018 by SR_team <sr-tream@yandex.ru>

 This program is free software; you can redistribute it and/or
 modify it under the terms of the GNU General Public License as
 published by the Free Software Foundation; either version 2 of
 the License or (at your option) version 3 or any later version
 accepted by the membership of KDE e.V. (or its successor approved
 by the membership of KDE e.V.), which shall act as a proxy 
 defined in Section 14 of version 3 of the license.

 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "debinstallerwindow.h"
#include <iostream>

DebInstallerWindow::DebInstallerWindow( QString pkg )
    : QMainWindow()
{
    m_pkg = QFileInfo(pkg);
    setWindowTitle(m_pkg.fileName());
    
    QWidget *widget = new QWidget(this);
    setCentralWidget(widget);
    m_ui.setupUi(widget);
    
    QObject::connect(m_ui.install, SIGNAL(clicked()), this, SLOT(onInstallClicked()));
    QObject::connect(m_ui.remove, SIGNAL(clicked()), this, SLOT(onRemoveClicked()));
    
    m_set = new QSettings("Prime-Hack", "DebInstaller", this);
    m_ui.sudo->setText(m_set->value("sudo", "kdesudo").toString());
    m_ui.apt->setText(m_set->value("apt", "apt-get").toString());
    m_ui.installArgs->setText(m_set->value("installArgs", "install --force-yes").toString());
    m_ui.removeArgs->setText(m_set->value("removeArgs", "remove --force-yes").toString());
    m_ui.checkInstall->setText(m_set->value("checkInstall", "list --installed").toString());
    m_ui.getInfo->setText(m_set->value("getInfo", "dpkg -I").toString());
    
    loadPkgInfo();
    
    if (checkPkgInstalled())
        m_ui.remove->setEnabled(true);
    else m_ui.install->setEnabled(true);
    
    m_processPkg = new QProcess(this);
    QObject::connect(m_processPkg, &QProcess::readyReadStandardOutput, this, &DebInstallerWindow::onAddLogData);
    QObject::connect(m_processPkg, SIGNAL(finished(int, QProcess::ExitStatus)), this, SLOT(onProcessFinished(int, QProcess::ExitStatus)));
}

void DebInstallerWindow::closeEvent(QCloseEvent* event)
{
    if (m_processPkg->processId()){
        QMessageBox msg;
        msg.setWindowTitle("Close program");
        msg.setText("Process of package is not finished.\nDo you want close program?");
        msg.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
        if (msg.exec() == QMessageBox::No){
            event->ignore();
            return;
        }
        else m_processPkg->kill();
    }
    m_set->setValue("sudo", m_ui.sudo->text());
    m_set->setValue("apt", m_ui.apt->text());
    m_set->setValue("installArgs", m_ui.installArgs->text());
    m_set->setValue("removeArgs", m_ui.removeArgs->text());
    m_set->setValue("checkInstall", m_ui.checkInstall->text());
    m_set->setValue("getInfo", m_ui.getInfo->text());
    
    return QMainWindow::closeEvent(event);
}

void DebInstallerWindow::loadPkgInfo()
{
    QProcess loadPkgInfo;
    loadPkgInfo.setEnvironment(QProcess::systemEnvironment());
    QStringList getInfo = m_ui.getInfo->text().split(' ');
    loadPkgInfo.setProgram(getInfo.first());
    QStringList args;
    for (int i = 1; i < getInfo.count(); ++i){
        if (getInfo.at(i).isEmpty())
            continue;
        args << getInfo.at(i);
    }
    args << m_pkg.filePath();
    loadPkgInfo.setArguments(args);
    loadPkgInfo.start();
    loadPkgInfo.waitForFinished(3000);
    parsePkgInfo(QString(loadPkgInfo.readAllStandardOutput().toStdString().c_str()).split('\n'));
}

void DebInstallerWindow::parsePkgInfo(const QStringList &pkgInfo)
{
    QRegExp re(R"( ([\w-]+):\s+(.+))");
    QString section, data;
    
    for (auto &str : pkgInfo){
        if (str.isEmpty())
            continue;
        
        if (re.indexIn(str) == 0){
            if (!section.isEmpty()){
                setPkgInfo(section, data);
                section.clear();
                data.clear();
            }
            section = re.cap(1);
            data = re.cap(2);
        } else if (!section.isEmpty())
            data += "\n" + str;
    }
    
    if (!section.isEmpty())
        setPkgInfo(section, data);
}

void DebInstallerWindow::setPkgInfo(const QString& section, const QString& data)
{
    if (section.toLower() == "package"){
        m_ui.pkgName->setText(data);
    }
    else if (section.toLower() == "installed-size"){
        double size = data.toDouble();
        if (size < 1024)
            m_ui.size->setText(data + " KiB");
        else {
            size /= 1024;
            if (size < 1024)
                m_ui.size->setText(QString::number(size, 'f', 2) + " MiB");
            else {
                size /= 1024;
                m_ui.size->setText(QString::number(size) + " GiB");
            }
        }
    }
    else if (section.toLower() == "description"){
        m_ui.description->setText(data);
    }
    else if (section.toLower() == "version"){
        m_ui.version->setVisible(true);
        m_ui.label_version->setVisible(true);
        m_ui.version->setText(data);
    }
    else if (section.toLower() == "architecture"){
        m_ui.architecture->setVisible(true);
        m_ui.label_architecture->setVisible(true);
        m_ui.architecture->setText(data);
    }
    else if (section.toLower() == "maintainer"){
        m_ui.maintainer->setVisible(true);
        m_ui.label_maintainer->setVisible(true);
        m_ui.maintainer->setText(data);
    }
    else if (section.toLower() == "section"){
        m_ui.section->setVisible(true);
        m_ui.label_section->setVisible(true);
        m_ui.section->setText(data);
    }
    else if (section.toLower() == "priority"){
        m_ui.priority->setVisible(true);
        m_ui.label_priority->setVisible(true);
        m_ui.priority->setText(data);
    }
    else if (section.toLower() == "homepage"){
        m_ui.homepage->setVisible(true);
        m_ui.label_homepage->setVisible(true);
        m_ui.homepage->setText("<a href=\"" + data + "\">" + data + "</a>");
    }
    else if (section.toLower() == "provides"){
        m_ui.provides->setVisible(true);
        m_ui.label_provides->setVisible(true);
        m_ui.provides->setText(data);
    }
    else if (section.toLower() == "suggests"){
        m_ui.suggests->setVisible(true);
        m_ui.label_suggests->setVisible(true);
        m_ui.suggests->setText(data);
    }
    else if (section.toLower() == "depends"){
        m_ui.depends->setVisible(true);
        m_ui.label_depends->setVisible(true);
        m_ui.depends->setText(data);
    }
    else if (section.toLower() == "recommends"){
        m_ui.recommends->setVisible(true);
        m_ui.label_recommends->setVisible(true);
        m_ui.recommends->setText(data);
    }
}

bool DebInstallerWindow::checkPkgInstalled()
{
    QProcess checkPkgInstalled;
    checkPkgInstalled.setEnvironment(QProcess::systemEnvironment());
    QStringList apt = m_ui.apt->text().split(' ');
    checkPkgInstalled.setProgram(apt.first());
    QStringList args;
    for (int i = 1; i < apt.count(); ++i){
        if (apt.at(i).isEmpty())
            continue;
        args << apt.at(i);
    }
    for (auto &str : m_ui.checkInstall->text().split(' ')){
        if (str.isEmpty())
            continue;
        args << str;
    }
    args << m_ui.pkgName->text();
    checkPkgInstalled.setArguments(args);
    checkPkgInstalled.start();
    checkPkgInstalled.waitForFinished(5000);
    
    return QString(checkPkgInstalled.readAllStandardOutput().toStdString().c_str()).indexOf(m_ui.pkgName->text()) >= 0;
}

void DebInstallerWindow::onInstallClicked()
{
    m_ui.install->setEnabled(false);
    m_ui.tabWidget->setCurrentWidget(m_ui.log);
    
    m_processPkg->setEnvironment(QProcess::systemEnvironment());
    QStringList sudo = m_ui.sudo->text().split(' ');
    m_processPkg->setProgram(sudo.first());
    QStringList args;
    for (int i = 1; i < sudo.count(); ++i){
        if (sudo.at(i).isEmpty())
            continue;
        args << sudo.at(i);
    }
    QString command;
    for (auto &str : m_ui.apt->text().split(' ')){
        if (str.isEmpty())
            continue;
        if (!command.isEmpty())
            command += " ";
        command += str;
    }
    for (auto &str : m_ui.installArgs->text().split(' ')){
        if (str.isEmpty())
            continue;
        if (!command.isEmpty())
            command += " ";
        command += str;
    }
    if (!command.isEmpty())
        command += " ";
    command += m_pkg.filePath();
    args << command;
    m_processPkg->setArguments(args);
    m_processPkg->start();
    
    std::cout << sudo.first().toStdString() << std::endl;
    for (auto &str : args)
        std::cout << str.toStdString() << std::endl;
}

void DebInstallerWindow::onRemoveClicked()
{
    m_ui.remove->setEnabled(false);
    m_ui.tabWidget->setCurrentWidget(m_ui.log);
    
    m_processPkg->setEnvironment(QProcess::systemEnvironment());
    QStringList sudo = m_ui.sudo->text().split(' ');
    m_processPkg->setProgram(sudo.first());
    QStringList args;
    for (int i = 1; i < sudo.count(); ++i){
        if (sudo.at(i).isEmpty())
            continue;
        args << sudo.at(i);
    }
    QString command;
    for (auto &str : m_ui.apt->text().split(' ')){
        if (str.isEmpty())
            continue;
        if (!command.isEmpty())
            command += " ";
        command += str;
    }
    for (auto &str : m_ui.removeArgs->text().split(' ')){
        if (str.isEmpty())
            continue;
        if (!command.isEmpty())
            command += " ";
        command += str;
    }
    if (!command.isEmpty())
        command += " ";
    command += m_ui.pkgName->text();
    args << command;
    m_processPkg->setArguments(args);
    m_processPkg->start();
}

void DebInstallerWindow::onAddLogData()
{
    QTextCodec* defaultTextCodec = QTextCodec::codecForName("ISO-8859-1");
    auto text = defaultTextCodec->fromUnicode(m_processPkg->readAll());
    m_ui.aptLog->setPlainText(m_ui.aptLog->toPlainText() + "\n" + text);
    auto sb = m_ui.aptLog->verticalScrollBar();
    sb->setValue( sb->maximum() );
}

void DebInstallerWindow::onProcessFinished(int exitCode, QProcess::ExitStatus exitStatus)
{
    if (checkPkgInstalled())
        m_ui.remove->setEnabled(true);
    else m_ui.install->setEnabled(true);
}
