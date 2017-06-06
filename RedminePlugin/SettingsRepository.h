#ifndef SETTINGSREPOSITORY_H
#define SETTINGSREPOSITORY_H

#include <QString>
#include <QUrl>

namespace Redmine {

struct SettingConnection {
  SettingConnection() {
    name = "";
    server = "";
    password = "";
    user = "";
    savePassword = false;
  }

  QString name;
  QUrl server;
  QString user;
  QString password;
  int savePassword;
};
}

#endif // SETTINGSREPOSITORY_H
