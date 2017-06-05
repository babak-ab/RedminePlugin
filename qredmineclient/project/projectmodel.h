#ifndef PROJECTMODEL_H
#define PROJECTMODEL_H
#include <QAbstractTableModel>
#include <QList>
#include <QObject>
#include <QPair>
class ProjectModel : public QAbstractTableModel {
  Q_OBJECT
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
  enum { ID = 0, SUBJECT, DESCRIPTION };
  ProjectModel(QObject *parent = 0);
  int rowCount(const QModelIndex &parent) const;
  int columnCount(const QModelIndex &parent) const;
  QVariant data(const QModelIndex &index, int role) const;
  QVariant headerData(int section, Qt::Orientation orientation, int role) const;
  Qt::ItemFlags flags(const QModelIndex &index) const;
  bool setData(const QModelIndex &index, const QVariant &value,
               int role = Qt::EditRole);
  bool insertRows(int position, int rows,
                  const QModelIndex &index = QModelIndex());
  bool removeRows(int position, int rows,
                  const QModelIndex &index = QModelIndex());
  QList<Project> getList();
  void addProject(Project issue);

  void removeProject(int row);

  void clear();

private:
  QList<Project> listProject;
};

#endif // PROJECTMODEL_H
