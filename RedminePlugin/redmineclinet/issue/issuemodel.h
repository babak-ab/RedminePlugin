#ifndef ISSUEMODEL_H
#define ISSUEMODEL_H

#include <QAbstractTableModel>
#include <QList>
#include <QPair>
class IssueModel : public QAbstractTableModel {
  Q_OBJECT

public:
    enum ColumnName{
        ColumnName_ID = 0,
        ColumnName_Subject,
        ColumnName_Tracker,
        ColumnName_Status,
        ColumnName_DoneRatio,
        ColumnName_Priority,
        ColumnName_Author,
        ColumnName_StartDate,
        ColumnName_DueDate,
        ColumnName_Category,
        ColumnName_Project,
        ColumnName_Description,
        ColumnName_CreateOn,
        ColumnName_UpdateOn
    };

  struct Issue {
    Issue() {
      id = 0;
      project_name = "";
      tracker_name = "";
      status_name = "";
      priority_name = "";
      author_name = "";
      category_name = "";
      subject = "";
      description = "";
      start_date = "";
      due_date = "";
      created_on = "";
      updated_on = "";
      done_ratio = 0;
    }

    int id;
    QString project_name;
    QString tracker_name;
    QString status_name;
    QString priority_name;
    QString author_name;
    QString category_name;
    QString subject;
    QString description;
    QString start_date;
    QString due_date;
    QString created_on;
    QString updated_on;
    double done_ratio;
  };
  enum { ID = 0, SUBJECT, DESCRIPTION };
  IssueModel(QObject *parent = 0);
  IssueModel(QList<QPair<QString, QString>> listofPairs, QObject *parent = 0);

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

  void clear();

private:
  QList<Issue> listOfIssue;
};

#endif // ISSUEMODEL_H
