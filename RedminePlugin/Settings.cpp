#include <QSettings>
#include <coreplugin/icore.h>

#include "Settings.h"
#include "redmineconstants.h"
#include "redmineplugin.h"

namespace Redmine {

Settings *Settings::_instance = 0;

Settings::Settings(QObject *parent) : IOptionsPage(parent) {
  setDisplayCategory(tr("Redmine"));
  setCategoryIcon(categoryIcon());
  setCategory(category());
  setDisplayName(tr("General"));
  _instance = this;
  if (QSettings *settings = Core::ICore::instance()->settings()) {
    settings->beginGroup(QString::fromLatin1(Constants::SETTINGS_CATEGORY));
    int size = settings->beginReadArray(QLatin1String("Repositories"));
    for (int i = 0; i < size; i++) {
      SettingConnection r;
      settings->setArrayIndex(i);
      r.name = settings->value(QLatin1String("Name")).toString();
      r.server = settings->value(QLatin1String("Server")).toString();
      r.user = settings->value(QLatin1String("User")).toString();
      r.savePassword = settings->value(QLatin1String("SavePassword")).toInt();
      r.password = settings->value(QLatin1String("Password")).toString();
      // this->_repositories.append(r);
    }
    settings->endArray();
    settings->endGroup();
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
  return Core::Id(Constants::SETTINGS_CATEGORY);
}

QString Settings::displayCategory() const { return tr("Redmine"); }

QString Settings::categoryIcon() const {
  return QLatin1String(":/images/remone_red.png");
}

QWidget *Settings::createPage(QWidget *parent) {
  this->settingsWidget = new SettingsWidget(parent);
  return this->settingsWidget;
}

void Settings::apply() {

  this->_settingConnection = this->settingsWidget->settingConnection();
  //  if (QSettings *settings = Core::ICore::instance()->settings()) {
  //    settings->beginGroup(QLatin1String(Constants::SETTINGS_CATEGORY));
  //    settings->beginWriteArray(QLatin1String("Repositories"));
  //    for (int i = 0; i < this->_repositories.size(); i++) {
  //      settings->setArrayIndex(i);
  //      settings->setValue(QLatin1String("Name"),
  //      this->_repositories.at(i).name);
  //      settings->setValue(QLatin1String("Server"),
  //                         this->_repositories.at(i).server);
  //      settings->setValue(QLatin1String("User"),
  //      this->_repositories.at(i).user);
  //      settings->setValue(QLatin1String("SavePassword"),
  //                         this->_repositories.at(i).savePassword);
  //      settings->setValue(QLatin1String("Password"),
  //                         this->_repositories.at(i).password);
  //    }
  //    settings->endArray();
  //    settings->endGroup();
  //  }
}

void Settings::finish() { delete settingsWidget; }

void Settings::setMainWindowSplitterSizes(QByteArray sizes) {
  if (QSettings *settings = Core::ICore::instance()->settings()) {
    settings->beginGroup(QLatin1String(Constants::SETTINGS_CATEGORY));
    settings->setValue(QLatin1String("MainWindowSplitterSizes"), sizes);
    settings->endGroup();
  }
}

QByteArray Settings::mainWindowSplitterSizes() {
  QByteArray sizes;
  if (QSettings *settings = Core::ICore::instance()->settings()) {
    settings->beginGroup(QLatin1String(Constants::SETTINGS_CATEGORY));
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
}
