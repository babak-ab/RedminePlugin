#ifndef SETTINGSWIDGET_H
#define SETTINGSWIDGET_H

#include "SettingsRepository.h"
#include "check.h"
#include <QList>
#include <QWidget>
using namespace Redmine;
namespace Ui {
class SettingsWidget;
}

class SettingsWidget : public QWidget {
  Q_OBJECT

public:
  explicit SettingsWidget(QWidget *parent = 0);
  ~SettingsWidget();

  Redmine::SettingConnection settingConnection() const;

private slots:
  void checkConnection();

  void on_pushButton_checkConnection_clicked();

  void sltReplyError(IManager::ReplayError err);

  void sltReplyOk();

private:
  Ui::SettingsWidget *ui;
  Check *check;
  Redmine::SettingConnection mSettingConnection;
};

#endif // SETTINGSWIDGET_H
