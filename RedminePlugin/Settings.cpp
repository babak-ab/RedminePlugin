#include <QSettings>
#include <coreplugin/icore.h>

#include "Settings.h"
#include "coreplugin/settingsdatabase.h"
#include "redmineconstants.h"
#include "redmineplugin.h"

Settings *Settings::_instance = 0;

Settings::Settings(QObject *parent) : IOptionsPage(parent) {
  setDisplayCategory(tr("Redmine"));
  setCategoryIcon(categoryIcon());
  setCategory(category());
  setDisplayName(tr("General"));
  _instance = this;
  if (QSettings *settings = Core::ICore::instance()->settings()) {
    settings->beginGroup(QString::fromLatin1("Redmine.Settings"));
    SettingConnection r;
    r.name = settings->value(QLatin1String("Name")).toString();
    r.server = settings->value(QLatin1String("Server")).toString();
    r.user = settings->value(QLatin1String("User")).toString();
    r.savePassword = settings->value(QLatin1String("SavePassword")).toInt();
    r.password = settings->value(QLatin1String("Password")).toString();
    settings->endGroup();
    _settingConnection = r;
  }
}

Settings::~Settings() {}

Settings *Settings::instance() {
  if (_instance == 0) {
    _instance = new Settings(0);
  }
  return _instance;
}

QString Settings::id() const { return QLatin1String("Redmine.Settings"); }

QString Settings::displayName() const { return tr("Redmine"); }

Core::Id Settings::category() const {
  return Core::Id(Constants::SETTINGS_CATEGORY_REDMINE);
}

QString Settings::displayCategory() const { return tr("Redmine"); }

QString Settings::categoryIcon() const {
  return QLatin1String(":/images/remone_red.png");
}

QWidget *Settings::createPage(QWidget *parent) {
  this->settingsWidget = new SettingsWidget(parent);
  this->settingsWidget->setSettingConnection(_settingConnection);
  return this->settingsWidget;
}

void Settings::apply() {

  this->_settingConnection = this->settingsWidget->settingConnection();
  if (QSettings *settings = Core::ICore::instance()->settings()) {
    settings->beginGroup(QLatin1String("Redmine.Settings"));
    settings->setValue(QLatin1String("Name"), this->_settingConnection.name);
    settings->setValue(QLatin1String("Server"),
                       this->_settingConnection.server.toString());
    settings->setValue(QLatin1String("User"), this->_settingConnection.user);
    settings->setValue(QLatin1String("SavePassword"),
                       this->_settingConnection.savePassword);
    settings->setValue(QLatin1String("Password"),
                       this->_settingConnection.password);
    settings->endGroup();
  }
}

void Settings::finish() { delete settingsWidget; }

void Settings::setMainWindowSplitterSizes(QByteArray sizes) {
  if (QSettings *settings = Core::ICore::instance()->settings()) {
    settings->beginGroup(QLatin1String(Constants::SETTINGS_CATEGORY_REDMINE));
    settings->setValue(QLatin1String("MainWindowSplitterSizes"), sizes);
    settings->endGroup();
  }
}

QByteArray Settings::mainWindowSplitterSizes() {
  QByteArray sizes;
  if (QSettings *settings = Core::ICore::instance()->settings()) {
    settings->beginGroup(QLatin1String(Constants::SETTINGS_CATEGORY_REDMINE));
    sizes =
        settings->value(QLatin1String("MainWindowSplitterSizes")).toByteArray();
    settings->endGroup();
  }
  return sizes;
}

SettingConnection Settings::settingConnection() const {
  return _settingConnection;
}

void Settings::setSettingConnection(
    const SettingConnection &settingConnection) {
  _settingConnection = settingConnection;
  // this->settingsWidget->setSe
}

QWidget *Settings::widget() { return createPage(0); }
