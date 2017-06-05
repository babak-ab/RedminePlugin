#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "Settings.h"
#include "issuemodel.h"
#include "issuerequest.h"
#include <QMainWindow>
using namespace Redmine;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {
  Q_OBJECT

public:
  explicit MainWindow(QWidget *parent = 0);
  ~MainWindow();

private slots:
  void on_pushButton_issue_clicked();

  void sltReplyOk();

private:
  Ui::MainWindow *ui;
  IssueRequest *issue;
};

#endif // MAINWINDOW_H
