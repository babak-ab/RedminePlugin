/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QPushButton *pushButton_issue;
    QComboBox *comboBox_project;
    QTableView *tableView;
    QPushButton *pushButton_project;
    QPushButton *pushButton_loadAllIssue;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        pushButton_issue = new QPushButton(centralwidget);
        pushButton_issue->setObjectName(QStringLiteral("pushButton_issue"));

        gridLayout->addWidget(pushButton_issue, 2, 0, 1, 1);

        comboBox_project = new QComboBox(centralwidget);
        comboBox_project->setObjectName(QStringLiteral("comboBox_project"));

        gridLayout->addWidget(comboBox_project, 0, 0, 1, 1);

        tableView = new QTableView(centralwidget);
        tableView->setObjectName(QStringLiteral("tableView"));

        gridLayout->addWidget(tableView, 4, 0, 1, 2);

        pushButton_project = new QPushButton(centralwidget);
        pushButton_project->setObjectName(QStringLiteral("pushButton_project"));

        gridLayout->addWidget(pushButton_project, 0, 1, 1, 1);

        pushButton_loadAllIssue = new QPushButton(centralwidget);
        pushButton_loadAllIssue->setObjectName(QStringLiteral("pushButton_loadAllIssue"));

        gridLayout->addWidget(pushButton_loadAllIssue, 2, 1, 1, 1);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        pushButton_issue->setText(QApplication::translate("MainWindow", "Load Issue", Q_NULLPTR));
        pushButton_project->setText(QApplication::translate("MainWindow", "Load Project", Q_NULLPTR));
        pushButton_loadAllIssue->setText(QApplication::translate("MainWindow", "Load All Issue", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
