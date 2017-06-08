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
IssueColumnStatus SettingsWidget::getIssueColumnStatus(){

    IssueColumnStatus issue;
    issue.author = ui->checkBox_author->isChecked();
    issue.category = ui->checkBox_category->isChecked();
    issue.created_on = ui->checkBox_createdOn->isChecked();
    issue.description = ui->checkBox_description->isChecked();
    issue.done_ratio = ui->checkBox_doneRatio->isChecked();
    issue.due_date = ui->checkBox_dueDate->isChecked();
    issue.status = ui->checkBox_status->isChecked();
    issue.priority = ui->checkBox_priority->isChecked();
    issue.project = ui->checkBox_project->isChecked();
    issue.start_date = ui->checkBox_startDate->isChecked();
    issue.subject = ui->checkBox_subject->isChecked();
    issue.tracker= ui->checkBox_tracker->isChecked();
    issue.updated_on= ui->checkBox_updatedOn->isChecked();
    return issue;

}

void SettingsWidget::setIssueColumnStatus(IssueColumnStatus status)
{
    ui->checkBox_author->setChecked(status.author);
    ui->checkBox_category->setChecked(status.category);
    ui->checkBox_createdOn->setChecked(status.created_on);
    ui->checkBox_description->setChecked(status.description);
    ui->checkBox_doneRatio->setChecked(status.done_ratio);
    ui->checkBox_dueDate->setChecked(status.due_date);
    ui->checkBox_status->setChecked(status.priority);
    ui->checkBox_priority->setChecked(status.project);
    ui->checkBox_project->setChecked(status.start_date);
    ui->checkBox_startDate->setChecked(status.status);
    ui->checkBox_subject->setChecked(status.subject);
    ui->checkBox_tracker->setChecked(status.tracker);
    ui->checkBox_updatedOn->setChecked(status.updated_on);
}

void SettingsWidget::on_pushButton_checkConnection_clicked() {

    checkConnection();
}

