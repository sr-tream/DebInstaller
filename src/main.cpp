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

// application header
#include "debinstallerwindow.h"

// KF headers
#include <KAboutData>
#include <KLocalizedString>

// Qt headers
#include <QApplication>
#include <QCommandLineParser>
#include <QFileDialog>

int main(int argc, char **argv)
{
    QApplication application(argc, argv);

    KLocalizedString::setApplicationDomain("debinstaller");

    KAboutData aboutData( QStringLiteral("debinstaller"),
                          i18n("DebInstaller"),
                          QStringLiteral("%{VERSION}"),
                          i18n("A installer of debian packages"),
                          KAboutLicense::GPL,
                          i18n("Copyright 2018, SR_team <sr-tream@yandex.ru>"));

    aboutData.addAuthor(i18n("SR_team"),i18n("Author"), QStringLiteral("sr-tream@yandex.ru"));
    aboutData.setOrganizationDomain("prime-hack.net");
    aboutData.setDesktopFileName(QStringLiteral("net.prime-hack.debinstaller"));

    KAboutData::setApplicationData(aboutData);
    application.setWindowIcon(QIcon::fromTheme(QStringLiteral("debinstaller")));

    QCommandLineParser parser;
    parser.addPositionalArgument("deb", QCoreApplication::translate("main", "Path to debian package"));
    
    parser.addHelpOption();
    parser.addVersionOption();
    aboutData.setupCommandLine(&parser);

    parser.process(application);
    aboutData.processCommandLine(&parser);
    
    if (!parser.positionalArguments().isEmpty()){
        for(auto &pkg : parser.positionalArguments()){
            if (QFileInfo(pkg).suffix().toLower() == "deb"){
                DebInstallerWindow *mainWindow = new DebInstallerWindow(pkg);
                mainWindow->show();
            }
        }
    } else {
        // TODO: выкидывать диалог выбора файла, и таки выкинуть reurn из этого условия.
        QStringList packages = QFileDialog::getOpenFileNames(nullptr, "Select debian packages", QDir::homePath(), "*.deb");
        for(auto &pkg : packages){
            if (QFileInfo(pkg).suffix().toLower() == "deb"){
                DebInstallerWindow *mainWindow = new DebInstallerWindow(pkg);
                mainWindow->show();
            }
        }
    }
    return application.exec();
}
