#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
  issue = new IssueRequest(this);
  connect(issue, &IssueRequest::sigReplyOk, this, &MainWindow::sltReplyOk);
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

void MainWindow::sltReplyOk() {
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
  issue->getIssue(setting.server, setting.user, setting.password);
}
