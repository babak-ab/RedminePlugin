#ifndef PROJECTMODEL_H
#define PROJECTMODEL_H
#include <QObject>
class ProjectModel {
public:
  struct Project {
    int id;
    QString name;
    QString identifier;
    QString description;
    quint64 created_on;
    quint64 updated_on;
    bool is_public;
  };

  ProjectModel();
};

#endif // PROJECTMODEL_H
