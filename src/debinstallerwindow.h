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

#ifndef DEBINSTALLERWINDOW_H
#define DEBINSTALLERWINDOW_H


#include "ui_debinstaller.h"

#include <QMainWindow>
#include <QSettings>
#include <QFileInfo>
#include <QProcess>
#include <QRegExp>
#include <QMessageBox>
#include <QScrollBar>
#include <QTextCodec>
#include <QTextDecoder>

class DebInstallerWindow : public QMainWindow
{
    Q_OBJECT
public:
    DebInstallerWindow( QString pkg );
    
protected:
    void closeEvent(QCloseEvent * event) override;
    
    virtual void loadPkgInfo();
    virtual void parsePkgInfo(const QStringList &pkgInfo);
    virtual void setPkgInfo(const QString &section, const QString &data);
    
    virtual bool checkPkgInstalled();
    
private slots:
    void onInstallClicked();
    void onRemoveClicked();
    void onAddLogData();
    void onProcessFinished(int exitCode, QProcess::ExitStatus exitStatus);

private:
    Ui::mainWidget m_ui;
    QSettings     *m_set;
    QFileInfo      m_pkg;
    QProcess      *m_processPkg;
};

#endif // DEBINSTALLERWINDOW_H
