#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "coreplugin/icore.h"

#include <QMessageBox>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    issue = new IssueRequest(this);
    connect(issue, &IssueRequest::sigReplyOk,
            this, &MainWindow::sltIssueReplyOk);

    project = new ProjectRequest(this);
    connect(project, &ProjectRequest::sigReplyOk, this,
            &MainWindow::sltProjectReplyOk);

    connect(issue, &IssueRequest::sigReplyError,
            this, &MainWindow::sltReplayError);
    connect(project, &ProjectRequest::sigReplyError, this,
            &MainWindow::sltReplayError);


    ui->tableView->setLayoutDirection(Qt::RightToLeft);
    ui->tableView->horizontalHeader()->setSectionResizeMode(
                QHeaderView::Interactive);
    ui->tableView->horizontalHeader()->setCascadingSectionResizes(false);
    ui->tableView->resizeColumnsToContents();

    ui->tableView->horizontalHeader()->setStretchLastSection(true);
    ui->tableView->setVerticalScrollMode(QTableView::ScrollPerPixel);
    ui->tableView->setHorizontalScrollMode(QTableView::ScrollPerPixel);
    ui->tableView->setEditTriggers(QTableView::NoEditTriggers);
    ui->tableView->setSelectionMode(QTableView::SingleSelection);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    connect(Settings::instance(),&Settings::sigSettingChanged,this,
            &MainWindow::sltSettingChanged);

    ui->tableView->horizontalHeader()->setSectionsMovable(true);

    sltSettingChanged();
}
void MainWindow::sltReplayError(QString err) {

    QMessageBox::critical(this,"Connection Failed",
                          err + "\nCheck Redmine setting in options");

}


void MainWindow::sltSettingChanged()
{
    issueStatus =  Settings::instance()->issueColumnStatus();

}

MainWindow::~MainWindow() { delete ui; }
void MainWindow::sltProjectReplyOk() {
    ui->comboBox_project->setModel(project->getModel());
    ui->comboBox_project->setModelColumn(1);
}

void MainWindow::sltIssueReplyOk() {
    ui->tableView->setModel(issue->getModel());
    ui->tableView->setWordWrap(true);
    ui->tableView->setTextElideMode(Qt::ElideMiddle);

    ui->tableView->resizeColumnsToContents();
    ui->tableView->setColumnWidth(IssueModel::ColumnName_Subject, ui->tableView->width() / 4);
    ui->tableView->resizeRowsToContents();
    ui->tableView->setColumnHidden(IssueModel::ColumnName_Author,!issueStatus.author);
    ui->tableView->setColumnHidden(IssueModel::ColumnName_Category,!issueStatus.category);
    ui->tableView->setColumnHidden(IssueModel::ColumnName_CreateOn,!issueStatus.created_on);
    ui->tableView->setColumnHidden(IssueModel::ColumnName_Description,!issueStatus.description);
    ui->tableView->setColumnHidden(IssueModel::ColumnName_DoneRatio,!issueStatus.done_ratio);
    ui->tableView->setColumnHidden(IssueModel::ColumnName_DueDate,!issueStatus.due_date);
    ui->tableView->setColumnHidden(IssueModel::ColumnName_Priority,!issueStatus.priority);
    ui->tableView->setColumnHidden(IssueModel::ColumnName_Project,!issueStatus.project);
    ui->tableView->setColumnHidden(IssueModel::ColumnName_StartDate,!issueStatus.start_date);
    ui->tableView->setColumnHidden(IssueModel::ColumnName_Subject,!issueStatus.subject);
    ui->tableView->setColumnHidden(IssueModel::ColumnName_Tracker,!issueStatus.tracker);
    ui->tableView->setColumnHidden(IssueModel::ColumnName_UpdateOn,!issueStatus.updated_on);
    ui->tableView->setColumnHidden(IssueModel::ColumnName_Status,!issueStatus.status);


}

void MainWindow::on_pushButton_issue_clicked() {
    ui->tableView->setModel(Q_NULLPTR);
    SettingConnection setting = Settings::instance()->settingConnection();
    int row = ui->comboBox_project->currentIndex();
    QModelIndex idx = ui->comboBox_project->model()->index(row, 0);
    QVariant data = ui->comboBox_project->model()->data(idx);
    int type_id = data.toInt();
    issue->getIssue(setting.server, setting.user, setting.password, type_id);
}

void MainWindow::on_pushButton_loadAllIssue_clicked() {
    ui->tableView->setModel(Q_NULLPTR);
    SettingConnection setting = Settings::instance()->settingConnection();
    issue->getIssue(setting.server, setting.user, setting.password);
}

void MainWindow::on_pushButton_project_clicked() {
    ui->tableView->setModel(Q_NULLPTR);
    ui->comboBox_project->setModel(Q_NULLPTR);
    ui->comboBox_project->clear();
    SettingConnection setting = Settings::instance()->settingConnection();
    project->getProject(setting.server, setting.user, setting.password);
}
