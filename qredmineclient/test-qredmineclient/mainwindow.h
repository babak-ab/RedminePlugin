#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "issuerequest.h"
#include <QMainWindow>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {
  Q_OBJECT

public:
  explicit MainWindow(QWidget *parent = 0);
  ~MainWindow();

private slots:
  void slt();

private:
  Ui::MainWindow *ui;
  IssueRequest *rest;
};

#endif // MAINWINDOW_H
