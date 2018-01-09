#include <klocalizedstring.h>

/********************************************************************************
** Form generated from reading UI file 'debinstaller.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DEBINSTALLER_H
#define UI_DEBINSTALLER_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_mainWidget
{
public:
    QGridLayout *gridLayout;
    QTabWidget *tabWidget;
    QWidget *info;
    QGridLayout *gridLayout_5;
    QFormLayout *formLayout_2;
    QLabel *label_pkgName;
    QLabel *pkgName;
    QLabel *label_size;
    QLabel *size;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_4;
    QTextBrowser *description;
    QWidget *detail;
    QFormLayout *formLayout;
    QLabel *label_version;
    QLabel *version;
    QLabel *label_architecture;
    QLabel *architecture;
    QLabel *label_maintainer;
    QLabel *maintainer;
    QLabel *label_section;
    QLabel *section;
    QLabel *priority;
    QLabel *label_priority;
    QLabel *label_homepage;
    QLabel *homepage;
    QLabel *label_provides;
    QLineEdit *provides;
    QLabel *label_depends;
    QTextBrowser *depends;
    QLabel *label_recommends;
    QLabel *label_suggests;
    QTextBrowser *suggests;
    QTextBrowser *recommends;
    QSpacerItem *verticalSpacer;
    QWidget *log;
    QGridLayout *gridLayout_2;
    QPlainTextEdit *aptLog;
    QWidget *settings;
    QGridLayout *gridLayout_3;
    QLineEdit *installArgs;
    QLabel *label_sudo;
    QLineEdit *sudo;
    QLabel *label_apt;
    QLineEdit *apt;
    QLabel *label_checkInstall;
    QLineEdit *checkInstall;
    QLabel *label_getInfo;
    QLabel *label_installArgs;
    QLineEdit *getInfo;
    QLabel *label_removeArgs;
    QLineEdit *removeArgs;
    QHBoxLayout *horizontalLayout;
    QPushButton *install;
    QPushButton *remove;

    void setupUi(QWidget *mainWidget)
    {
        if (mainWidget->objectName().isEmpty())
            mainWidget->setObjectName(QStringLiteral("mainWidget"));
        mainWidget->resize(335, 310);
        mainWidget->setMinimumSize(QSize(335, 0));
        QIcon icon(QIcon::fromTheme(QStringLiteral("debinstaller")));
        mainWidget->setWindowIcon(icon);
        mainWidget->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        gridLayout = new QGridLayout(mainWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        tabWidget = new QTabWidget(mainWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        info = new QWidget();
        info->setObjectName(QStringLiteral("info"));
        info->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        gridLayout_5 = new QGridLayout(info);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        formLayout_2 = new QFormLayout();
        formLayout_2->setObjectName(QStringLiteral("formLayout_2"));
        label_pkgName = new QLabel(info);
        label_pkgName->setObjectName(QStringLiteral("label_pkgName"));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        label_pkgName->setFont(font);

        formLayout_2->setWidget(0, QFormLayout::LabelRole, label_pkgName);

        pkgName = new QLabel(info);
        pkgName->setObjectName(QStringLiteral("pkgName"));

        formLayout_2->setWidget(0, QFormLayout::FieldRole, pkgName);

        label_size = new QLabel(info);
        label_size->setObjectName(QStringLiteral("label_size"));
        label_size->setFont(font);

        formLayout_2->setWidget(1, QFormLayout::LabelRole, label_size);

        size = new QLabel(info);
        size->setObjectName(QStringLiteral("size"));

        formLayout_2->setWidget(1, QFormLayout::FieldRole, size);


        gridLayout_5->addLayout(formLayout_2, 0, 0, 1, 1);

        groupBox = new QGroupBox(info);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setFont(font);
        gridLayout_4 = new QGridLayout(groupBox);
        gridLayout_4->setSpacing(0);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        gridLayout_4->setContentsMargins(0, 0, 0, 0);
        description = new QTextBrowser(groupBox);
        description->setObjectName(QStringLiteral("description"));
        QFont font1;
        font1.setBold(false);
        font1.setWeight(50);
        description->setFont(font1);

        gridLayout_4->addWidget(description, 0, 0, 1, 1);


        gridLayout_5->addWidget(groupBox, 1, 0, 1, 1);

        tabWidget->addTab(info, QString());
        detail = new QWidget();
        detail->setObjectName(QStringLiteral("detail"));
        detail->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        formLayout = new QFormLayout(detail);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        label_version = new QLabel(detail);
        label_version->setObjectName(QStringLiteral("label_version"));
        label_version->setFont(font);
        label_version->setVisible(false);

        formLayout->setWidget(1, QFormLayout::LabelRole, label_version);

        version = new QLabel(detail);
        version->setObjectName(QStringLiteral("version"));
        version->setVisible(false);
        version->setWordWrap(false);
        version->setOpenExternalLinks(false);
        version->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByMouse);

        formLayout->setWidget(1, QFormLayout::FieldRole, version);

        label_architecture = new QLabel(detail);
        label_architecture->setObjectName(QStringLiteral("label_architecture"));
        label_architecture->setFont(font);
        label_architecture->setVisible(false);

        formLayout->setWidget(2, QFormLayout::LabelRole, label_architecture);

        architecture = new QLabel(detail);
        architecture->setObjectName(QStringLiteral("architecture"));
        architecture->setVisible(false);
        architecture->setOpenExternalLinks(false);
        architecture->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByMouse);

        formLayout->setWidget(2, QFormLayout::FieldRole, architecture);

        label_maintainer = new QLabel(detail);
        label_maintainer->setObjectName(QStringLiteral("label_maintainer"));
        label_maintainer->setFont(font);
        label_maintainer->setVisible(false);

        formLayout->setWidget(3, QFormLayout::LabelRole, label_maintainer);

        maintainer = new QLabel(detail);
        maintainer->setObjectName(QStringLiteral("maintainer"));
        maintainer->setVisible(false);
        maintainer->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByMouse);

        formLayout->setWidget(3, QFormLayout::FieldRole, maintainer);

        label_section = new QLabel(detail);
        label_section->setObjectName(QStringLiteral("label_section"));
        label_section->setFont(font);
        label_section->setVisible(false);

        formLayout->setWidget(4, QFormLayout::LabelRole, label_section);

        section = new QLabel(detail);
        section->setObjectName(QStringLiteral("section"));
        section->setVisible(false);
        section->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByMouse);

        formLayout->setWidget(4, QFormLayout::FieldRole, section);

        priority = new QLabel(detail);
        priority->setObjectName(QStringLiteral("priority"));
        priority->setVisible(false);
        priority->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByMouse);

        formLayout->setWidget(5, QFormLayout::FieldRole, priority);

        label_priority = new QLabel(detail);
        label_priority->setObjectName(QStringLiteral("label_priority"));
        label_priority->setFont(font);
        label_priority->setVisible(false);

        formLayout->setWidget(5, QFormLayout::LabelRole, label_priority);

        label_homepage = new QLabel(detail);
        label_homepage->setObjectName(QStringLiteral("label_homepage"));
        label_homepage->setFont(font);
        label_homepage->setVisible(false);

        formLayout->setWidget(6, QFormLayout::LabelRole, label_homepage);

        homepage = new QLabel(detail);
        homepage->setObjectName(QStringLiteral("homepage"));
        homepage->setVisible(false);
        homepage->setOpenExternalLinks(true);
        homepage->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByMouse);

        formLayout->setWidget(6, QFormLayout::FieldRole, homepage);

        label_provides = new QLabel(detail);
        label_provides->setObjectName(QStringLiteral("label_provides"));
        label_provides->setFont(font);
        label_provides->setVisible(false);

        formLayout->setWidget(7, QFormLayout::LabelRole, label_provides);

        provides = new QLineEdit(detail);
        provides->setObjectName(QStringLiteral("provides"));
        provides->setVisible(false);
        provides->setReadOnly(true);

        formLayout->setWidget(7, QFormLayout::FieldRole, provides);

        label_depends = new QLabel(detail);
        label_depends->setObjectName(QStringLiteral("label_depends"));
        label_depends->setFont(font);
        label_depends->setVisible(false);

        formLayout->setWidget(8, QFormLayout::LabelRole, label_depends);

        depends = new QTextBrowser(detail);
        depends->setObjectName(QStringLiteral("depends"));
        depends->setMaximumSize(QSize(16777215, 60));
        depends->setVisible(false);

        formLayout->setWidget(8, QFormLayout::FieldRole, depends);

        label_recommends = new QLabel(detail);
        label_recommends->setObjectName(QStringLiteral("label_recommends"));
        label_recommends->setFont(font);
        label_recommends->setVisible(false);

        formLayout->setWidget(9, QFormLayout::LabelRole, label_recommends);

        label_suggests = new QLabel(detail);
        label_suggests->setObjectName(QStringLiteral("label_suggests"));
        label_suggests->setFont(font);
        label_suggests->setVisible(false);

        formLayout->setWidget(10, QFormLayout::LabelRole, label_suggests);

        suggests = new QTextBrowser(detail);
        suggests->setObjectName(QStringLiteral("suggests"));
        suggests->setMaximumSize(QSize(16777215, 60));
        suggests->setVisible(false);

        formLayout->setWidget(10, QFormLayout::FieldRole, suggests);

        recommends = new QTextBrowser(detail);
        recommends->setObjectName(QStringLiteral("recommends"));
        recommends->setMaximumSize(QSize(16777215, 60));
        recommends->setVisible(false);

        formLayout->setWidget(9, QFormLayout::FieldRole, recommends);

        verticalSpacer = new QSpacerItem(0, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);

        formLayout->setItem(11, QFormLayout::FieldRole, verticalSpacer);

        tabWidget->addTab(detail, QString());
        log = new QWidget();
        log->setObjectName(QStringLiteral("log"));
        log->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        gridLayout_2 = new QGridLayout(log);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        aptLog = new QPlainTextEdit(log);
        aptLog->setObjectName(QStringLiteral("aptLog"));
        aptLog->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        aptLog->setReadOnly(true);
        aptLog->setTabStopWidth(35);

        gridLayout_2->addWidget(aptLog, 0, 0, 1, 1);

        tabWidget->addTab(log, QString());
        settings = new QWidget();
        settings->setObjectName(QStringLiteral("settings"));
        gridLayout_3 = new QGridLayout(settings);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        installArgs = new QLineEdit(settings);
        installArgs->setObjectName(QStringLiteral("installArgs"));

        gridLayout_3->addWidget(installArgs, 2, 1, 1, 1);

        label_sudo = new QLabel(settings);
        label_sudo->setObjectName(QStringLiteral("label_sudo"));

        gridLayout_3->addWidget(label_sudo, 0, 0, 1, 1);

        sudo = new QLineEdit(settings);
        sudo->setObjectName(QStringLiteral("sudo"));

        gridLayout_3->addWidget(sudo, 0, 1, 1, 1);

        label_apt = new QLabel(settings);
        label_apt->setObjectName(QStringLiteral("label_apt"));

        gridLayout_3->addWidget(label_apt, 1, 0, 1, 1);

        apt = new QLineEdit(settings);
        apt->setObjectName(QStringLiteral("apt"));

        gridLayout_3->addWidget(apt, 1, 1, 1, 1);

        label_checkInstall = new QLabel(settings);
        label_checkInstall->setObjectName(QStringLiteral("label_checkInstall"));

        gridLayout_3->addWidget(label_checkInstall, 4, 0, 1, 1);

        checkInstall = new QLineEdit(settings);
        checkInstall->setObjectName(QStringLiteral("checkInstall"));

        gridLayout_3->addWidget(checkInstall, 4, 1, 1, 1);

        label_getInfo = new QLabel(settings);
        label_getInfo->setObjectName(QStringLiteral("label_getInfo"));

        gridLayout_3->addWidget(label_getInfo, 5, 0, 1, 1);

        label_installArgs = new QLabel(settings);
        label_installArgs->setObjectName(QStringLiteral("label_installArgs"));

        gridLayout_3->addWidget(label_installArgs, 2, 0, 1, 1);

        getInfo = new QLineEdit(settings);
        getInfo->setObjectName(QStringLiteral("getInfo"));

        gridLayout_3->addWidget(getInfo, 5, 1, 1, 1);

        label_removeArgs = new QLabel(settings);
        label_removeArgs->setObjectName(QStringLiteral("label_removeArgs"));

        gridLayout_3->addWidget(label_removeArgs, 3, 0, 1, 1);

        removeArgs = new QLineEdit(settings);
        removeArgs->setObjectName(QStringLiteral("removeArgs"));

        gridLayout_3->addWidget(removeArgs, 3, 1, 1, 1);

        tabWidget->addTab(settings, QString());

        gridLayout->addWidget(tabWidget, 0, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        install = new QPushButton(mainWidget);
        install->setObjectName(QStringLiteral("install"));
        install->setEnabled(false);

        horizontalLayout->addWidget(install);

        remove = new QPushButton(mainWidget);
        remove->setObjectName(QStringLiteral("remove"));
        remove->setEnabled(false);

        horizontalLayout->addWidget(remove);


        gridLayout->addLayout(horizontalLayout, 1, 0, 1, 1);


        retranslateUi(mainWidget);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(mainWidget);
    } // setupUi

    void retranslateUi(QWidget *mainWidget)
    {
        label_pkgName->setText(tr2i18n("Package name:", Q_NULLPTR));
        pkgName->setText(QString());
        label_size->setText(tr2i18n("Size:", Q_NULLPTR));
        size->setText(QString());
        groupBox->setTitle(tr2i18n("Description", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(info), tr2i18n("Information", Q_NULLPTR));
        label_version->setText(tr2i18n("Version:", Q_NULLPTR));
        version->setText(QString());
        label_architecture->setText(tr2i18n("Architecture:", Q_NULLPTR));
        label_maintainer->setText(tr2i18n("Maintainer:", Q_NULLPTR));
        label_section->setText(tr2i18n("Section:", Q_NULLPTR));
        label_priority->setText(tr2i18n("Priority:", Q_NULLPTR));
        label_homepage->setText(tr2i18n("Homepage:", Q_NULLPTR));
        label_provides->setText(tr2i18n("Provides:", Q_NULLPTR));
        label_depends->setText(tr2i18n("Depends:", Q_NULLPTR));
        depends->setHtml(tr2i18n("<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Noto Sans'; font-size:10pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", Q_NULLPTR));
        label_recommends->setText(tr2i18n("Recommends:", Q_NULLPTR));
        label_suggests->setText(tr2i18n("Suggests:", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(detail), tr2i18n("Detail", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(log), tr2i18n("Log", Q_NULLPTR));
        installArgs->setText(tr2i18n("install -y", Q_NULLPTR));
        label_sudo->setText(tr2i18n("Sudo command", Q_NULLPTR));
        sudo->setText(tr2i18n("kdesudo -c", Q_NULLPTR));
        label_apt->setText(tr2i18n("Apt command", Q_NULLPTR));
        apt->setText(tr2i18n("apt", Q_NULLPTR));
        label_checkInstall->setText(tr2i18n("Check install args", Q_NULLPTR));
        checkInstall->setText(tr2i18n("list --installed", Q_NULLPTR));
        label_getInfo->setText(tr2i18n("Get info command", Q_NULLPTR));
        label_installArgs->setText(tr2i18n("Install args", Q_NULLPTR));
        getInfo->setText(tr2i18n("dpkg -I", Q_NULLPTR));
        label_removeArgs->setText(tr2i18n("Remove args", Q_NULLPTR));
        removeArgs->setText(tr2i18n("remove -y", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(settings), tr2i18n("Settings", Q_NULLPTR));
        install->setText(tr2i18n("Install", Q_NULLPTR));
        remove->setText(tr2i18n("Remove", Q_NULLPTR));
        Q_UNUSED(mainWidget);
    } // retranslateUi

};

namespace Ui {
    class mainWidget: public Ui_mainWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // DEBINSTALLER_H

