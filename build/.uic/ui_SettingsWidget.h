/********************************************************************************
** Form generated from reading UI file 'SettingsWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGSWIDGET_H
#define UI_SETTINGSWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SettingsWidget
{
public:
    QHBoxLayout *horizontalLayout_2;
    QGroupBox *groupSettings;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QLineEdit *lineEdit_server;
    QCheckBox *checkBox_savePassword;
    QLineEdit *lineEdit_username;
    QLineEdit *lineEdit_password;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label;
    QPushButton *pushButton_checkConnection;
    QLabel *label_status;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *SettingsWidget)
    {
        if (SettingsWidget->objectName().isEmpty())
            SettingsWidget->setObjectName(QStringLiteral("SettingsWidget"));
        SettingsWidget->resize(936, 659);
        horizontalLayout_2 = new QHBoxLayout(SettingsWidget);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        groupSettings = new QGroupBox(SettingsWidget);
        groupSettings->setObjectName(QStringLiteral("groupSettings"));
        verticalLayout_3 = new QVBoxLayout(groupSettings);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        lineEdit_server = new QLineEdit(groupSettings);
        lineEdit_server->setObjectName(QStringLiteral("lineEdit_server"));

        gridLayout->addWidget(lineEdit_server, 0, 1, 1, 1);

        checkBox_savePassword = new QCheckBox(groupSettings);
        checkBox_savePassword->setObjectName(QStringLiteral("checkBox_savePassword"));

        gridLayout->addWidget(checkBox_savePassword, 3, 1, 1, 1);

        lineEdit_username = new QLineEdit(groupSettings);
        lineEdit_username->setObjectName(QStringLiteral("lineEdit_username"));

        gridLayout->addWidget(lineEdit_username, 1, 1, 1, 1);

        lineEdit_password = new QLineEdit(groupSettings);
        lineEdit_password->setObjectName(QStringLiteral("lineEdit_password"));
        lineEdit_password->setEchoMode(QLineEdit::Password);

        gridLayout->addWidget(lineEdit_password, 2, 1, 1, 1);

        label_3 = new QLabel(groupSettings);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 0, 0, 1, 1);

        label_4 = new QLabel(groupSettings);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout->addWidget(label_4, 2, 0, 1, 1);

        label = new QLabel(groupSettings);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 1, 0, 1, 1);

        pushButton_checkConnection = new QPushButton(groupSettings);
        pushButton_checkConnection->setObjectName(QStringLiteral("pushButton_checkConnection"));

        gridLayout->addWidget(pushButton_checkConnection, 3, 0, 1, 1);


        verticalLayout->addLayout(gridLayout);

        label_status = new QLabel(groupSettings);
        label_status->setObjectName(QStringLiteral("label_status"));
        label_status->setStyleSheet(QStringLiteral(""));

        verticalLayout->addWidget(label_status);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        verticalLayout_3->addLayout(verticalLayout);


        horizontalLayout_2->addWidget(groupSettings);

        horizontalLayout_2->setStretch(0, 1);
        QWidget::setTabOrder(lineEdit_server, lineEdit_username);
        QWidget::setTabOrder(lineEdit_username, lineEdit_password);
        QWidget::setTabOrder(lineEdit_password, pushButton_checkConnection);
        QWidget::setTabOrder(pushButton_checkConnection, checkBox_savePassword);

        retranslateUi(SettingsWidget);

        QMetaObject::connectSlotsByName(SettingsWidget);
    } // setupUi

    void retranslateUi(QWidget *SettingsWidget)
    {
        SettingsWidget->setWindowTitle(QApplication::translate("SettingsWidget", "Form", Q_NULLPTR));
        groupSettings->setTitle(QApplication::translate("SettingsWidget", "Settings", Q_NULLPTR));
        checkBox_savePassword->setText(QApplication::translate("SettingsWidget", "Save Password", Q_NULLPTR));
        label_3->setText(QApplication::translate("SettingsWidget", "Server URL:", Q_NULLPTR));
        label_4->setText(QApplication::translate("SettingsWidget", "Password:", Q_NULLPTR));
        label->setText(QApplication::translate("SettingsWidget", "Username:", Q_NULLPTR));
        pushButton_checkConnection->setText(QApplication::translate("SettingsWidget", "Check Connection", Q_NULLPTR));
        label_status->setText(QApplication::translate("SettingsWidget", "Status:", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class SettingsWidget: public Ui_SettingsWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGSWIDGET_H
