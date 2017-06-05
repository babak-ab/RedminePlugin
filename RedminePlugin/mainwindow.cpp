#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
  issue = new IssueRequest(this);
  connect(issue, &IssueRequest::sigReplyOk, this, &MainWindow::sltIssueReplyOk);

  project = new ProjectRequest(this);
  connect(project, &ProjectRequest::sigReplyOk, this,
          &MainWindow::sltProjectReplyOk);

  ui->tableView->setLayoutDirection(Qt::RightToLeft);
  ui->tableView->horizontalHeader()->setSectionResizeMode(
      QHeaderView::Interactive);
  ui->tableView->horizontalHeader()->setCascadingSectionResizes(false);
  ui->tableView->resizeColumnsToContents();

  ui->tableView->horizontalHeader()->setStretchLastSection(true);
  ui->tableView->setVerticalScrollMode(QTableView::ScrollPerPixel);
  ui->tableView->setHorizontalScrollMode(QTableView::ScrollPerPixel);
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
  ui->tableView->setColumnWidth(1, ui->tableView->width() / 2);

  ui->tableView->resizeRowsToContents();
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
  SettingConnection setting = Settings::instance()->settingConnection();
  project->getProject(setting.server, setting.user, setting.password);
}
