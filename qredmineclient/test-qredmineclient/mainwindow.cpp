#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {

  ui->setupUi(this);
  rest = new IssueRequest(this);
  rest->getIssue(QUrl("http://iransamin.ir/issues.xml"), "babak.abolghasemi",
                 "babak8403363*-");
  connect(rest, &IssueRequest::sigRecvResponse, this, &MainWindow::slt);
  ui->tableView->setLayoutDirection(Qt::RightToLeft);
  ui->tableView->horizontalHeader()->setSectionResizeMode(
      QHeaderView::Interactive);
  ui->tableView->horizontalHeader()->setCascadingSectionResizes(false);
  ui->tableView->resizeColumnsToContents();
}
void MainWindow::slt() {
  ui->tableView->setModel(rest->getModel());
  ui->tableView->resizeColumnsToContents();
}

MainWindow::~MainWindow() { delete ui; }
