#include "SettingsWidget.h"
#include "ui_SettingsWidget.h"

SettingsWidget::SettingsWidget(QWidget *parent)
    : QWidget(parent), ui(new Ui::SettingsWidget) {
  ui->setupUi(this);
  check = new Check(this);
  connect(check, &Check::sigReplyError, this, &SettingsWidget::sltReplyError);
  connect(check, &Check::sigReplyOk, this, &SettingsWidget::sltReplyOk);
  ui->lineEdit_server->setText(mSettingConnection.server.toString());
  ui->lineEdit_username->setText(mSettingConnection.user);
  ui->lineEdit_password->setText(mSettingConnection.password);
  ui->checkBox_savePassword->setChecked(mSettingConnection.savePassword);
}

SettingsWidget::~SettingsWidget() { delete ui; }

void SettingsWidget::sltReplyOk() {

  ui->label_status->setStyleSheet("color:green");
  ui->label_status->setText("Status: Connection Ok");
}

void SettingsWidget::setSettingConnection(
    const Redmine::SettingConnection &settingConnection) {
  mSettingConnection = settingConnection;
  ui->lineEdit_server->setText(mSettingConnection.server.toString());
  ui->lineEdit_username->setText(mSettingConnection.user);
  ui->lineEdit_password->setText(mSettingConnection.password);
  ui->checkBox_savePassword->setChecked(mSettingConnection.savePassword);
}

Redmine::SettingConnection SettingsWidget::settingConnection()  {


    mSettingConnection.server = QUrl(ui->lineEdit_server->text());
    mSettingConnection.user = ui->lineEdit_username->text();
    mSettingConnection.password = ui->lineEdit_password->text();
    mSettingConnection.savePassword = ui->checkBox_savePassword->isChecked();
    mSettingConnection.name = ui->lineEdit_username->text();
  return mSettingConnection;
}

void SettingsWidget::sltReplyError(IManager::ReplayError err) {

  ui->label_status->setStyleSheet("color:red");
  switch (err) {
  case IManager::ReplayError_Authentication:
    ui->label_status->setText("Status: Authentication Failed");
    break;
  }
}

void SettingsWidget::checkConnection() {

  mSettingConnection.server = QUrl(ui->lineEdit_server->text());
  mSettingConnection.user = ui->lineEdit_username->text();
  mSettingConnection.password = ui->lineEdit_password->text();
  if (mSettingConnection.server.isValid()) {
    check->checkConnection(mSettingConnection.server, mSettingConnection.user,
                           mSettingConnection.password);
  } else {
    ui->label_status->setText("Status: Server address is invalid");
  }
}

void SettingsWidget::on_pushButton_checkConnection_clicked() {

  checkConnection();
}
