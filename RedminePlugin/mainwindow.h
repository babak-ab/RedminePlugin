#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "Settings.h"
#include "issuemodel.h"
#include "issuerequest.h"
#include "projectmodel.h"
#include "projectrequest.h"
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

  void sltIssueReplyOk();

  void on_pushButton_loadAllIssue_clicked();

  void on_pushButton_project_clicked();

  void sltProjectReplyOk();

private:
  Ui::MainWindow *ui;
  IssueRequest *issue;
  ProjectRequest *project;
};

#endif // MAINWINDOW_H
