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
struct IssueColumnStatus{
    IssueColumnStatus()
    {
        project = false;
        tracker = false;
        status = false;
        priority = false;
        author = false;
        category = false;
        subject = false;
        description = false;
        start_date = false;
        due_date = false;
        created_on = false;
        updated_on = false;
        done_ratio = false;
    }

    bool project;
    bool tracker;
    bool status;
    bool priority;
    bool author;
    bool category;
    bool subject;
    bool description;
    bool start_date;
    bool due_date;
    bool created_on;
    bool updated_on;
    bool done_ratio;
};
}

#endif // SETTINGSREPOSITORY_H
