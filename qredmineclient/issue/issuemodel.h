#ifndef ISSUEMODEL_H
#define ISSUEMODEL_H

#include <QAbstractTableModel>
#include <QList>
#include <QPair>
class IssueModel : public QAbstractTableModel {
  Q_OBJECT

public:
  struct Issue {
    Issue() {
      id = 0;
      project_id = 0;
      project_name = "";
      tracker_id = 0;
      tracker_name = "";
      issueStatus_id = 0;
      issueStatus_name = "";
      priority_id = 0;
      priority_name = "";
      author_id = 0;
      author_name = "";
      category_id = 0;
      category_name = "";
      subject = "";
      description = "";
      start_date = 0;
      due_date = 0;
      created_on = 0;
      updated_on = 0;
      done_ratio = 0;
    }

    int id;
    int project_id;
    QString project_name;
    int tracker_id;
    QString tracker_name;
    int issueStatus_id;
    QString issueStatus_name;
    int priority_id;
    QString priority_name;
    int author_id;
    QString author_name;
    int category_id;
    QString category_name;
    QString subject;
    QString description;
    quint64 start_date;
    quint64 due_date;
    quint64 created_on;
    quint64 updated_on;
    double done_ratio;
  };
  enum { ID = 0, SUBJECT, DESCRIPTION };
  IssueModel(QObject *parent = 0);
  IssueModel(QList<QPair<QString, QString>> listofPairs, QObject *parent = 0);
    void clear();
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
  QList<Issue> getList();
  void addIssue(Issue issue);

  void removeIssue(int row);

private:
  QList<Issue> listOfIssue;
};

#endif // ISSUEMODEL_H
