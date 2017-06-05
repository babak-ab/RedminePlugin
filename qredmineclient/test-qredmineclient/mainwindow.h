#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "check.h"
#include "issue/issuerequest.h"
#include <QMainWindow>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {
  Q_OBJECT

public:
  explicit MainWindow(QWidget *parent = 0);
  ~MainWindow();

  void sltError(IManager::ReplayError error);
  void sltOk();
private slots:
  void slt();

  void on_pushButton_clicked();

private:
  Ui::MainWindow *ui;
  IssueRequest *rest;
  Check *check;
};

#endif // MAINWINDOW_H
