#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {

  ui->setupUi(this);
  //  check = new Check(this);
  //  check->checkConnection(QUrl("http://iransamin.ir/issues.xml"),
  //                         "babak.a2bolghasemi", "babak8403363*-");

  //  connect(check, &Check::sigReplyError, this, &MainWindow::sltError);
  //  connect(check, &Check::sigReplyOk, this, &MainWindow::sltOk);
  rest = new IssueRequest(this);
  rest->getIssue(QUrl("http://iransamin.ir"), "babak.abolghasemi",
                 "babak8403363*-");
  connect(rest, &IssueRequest::sigReplyOk, this, &MainWindow::slt);

  project = new ProjectRequest(this);
  project->getProject(QUrl("http://iransamin.ir"), "babak.abolghasemi",
                      "babak8403363*-");
  connect(project, &ProjectRequest::sigReplyOk, this, &MainWindow::slt1);

  ui->tableView->setLayoutDirection(Qt::RightToLeft);
  ui->tableView->horizontalHeader()->setSectionResizeMode(
      QHeaderView::Interactive);
  ui->tableView->horizontalHeader()->setCascadingSectionResizes(false);
  ui->tableView->resizeColumnsToContents();
  ui->tableView->horizontalHeader()->setStretchLastSection(true);
  ui->tableView->setVerticalScrollMode(QTableView::ScrollPerPixel);
  // ui->tableView->setHorizontalScrollBar(QTableView::ScrollPerPixel);
}
void MainWindow::sltError(IManager::ReplayError error) { qDebug() << "AUth"; }
void MainWindow::sltOk() { qDebug() << "Ok"; }
void MainWindow::slt1() {
  ui->comboBox->setModel(project->getModel());
  ui->comboBox->setModelColumn(1);
}
void MainWindow::slt() {
  qDebug() << "slt";
  ui->tableView->setModel(Q_NULLPTR);
  ui->tableView->setModel(rest->getModel());
  ui->tableView->setWordWrap(true);
  ui->tableView->setTextElideMode(Qt::ElideMiddle);
  ui->tableView->resizeColumnsToContents();
  ui->tableView->setColumnWidth(1, ui->tableView->width() / 2);
  ui->tableView->resizeRowsToContents();
  ui->tableView->setAlternatingRowColors(true);
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::on_pushButton_clicked() {
  //  ui->tableView->setModel(Q_NULLPTR);
  // rest->getIssue(QUrl("http://iransamin.ir"), "babak.abolghasemi",
  //               "babak8403363*-");

  int row = ui->comboBox->currentIndex();
  qDebug() << "Row" << row;
  QModelIndex idx = ui->comboBox->model()->index(row, 0);
  QVariant data = ui->comboBox->model()->data(idx);
  int type_id = data.toInt();
  qDebug() << type_id;
  rest->getIssue(QUrl("http://iransamin.ir"), "babak.abolghasemi",
                 "babak8403363*-", type_id);
}
