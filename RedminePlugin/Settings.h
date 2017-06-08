#ifndef SETTINGS_H
#define SETTINGS_H

#include <QIcon>
#include <coreplugin/dialogs/ioptionspage.h>

#include "SettingsRepository.h"
#include "SettingsWidget.h"

namespace Redmine {

class Settings : public Core::IOptionsPage {
  Q_OBJECT
public:
  Settings(QObject *parent);
  ~Settings();

  QString id() const;
  QString displayName() const;
  Core::Id category() const;
  QString displayCategory() const;
  QWidget *createPage(QWidget *parent);
  QString categoryIcon() const;
  void apply();
  void finish();
  static Settings *instance();

  void setMainWindowSplitterSizes(QByteArray sizes);
  QByteArray mainWindowSplitterSizes();

private:
  SettingsWidget *settingsWidget;
  SettingConnection _settingConnection;
  static Settings *_instance;

  IssueColumnStatus _issueColumnStatus;

  // IOptionsPage interface
public:
  QWidget *widget();
  void setSettingConnection(const SettingConnection &settingConnection);
  SettingConnection settingConnection() const;
  IssueColumnStatus issueColumnStatus() const;

Q_SIGNALS:
  void sigSettingChanged();
};

} // namespace RedmineConnector

#endif // SETTINGS_H
