#include "issuemodel.h"

IssueModel::IssueModel(QObject *parent) : QAbstractTableModel(parent) {}

int IssueModel::rowCount(const QModelIndex &parent) const {
  Q_UNUSED(parent);
  return listOfIssue.size();
}

int IssueModel::columnCount(const QModelIndex &parent) const {
  Q_UNUSED(parent);
  return 14;
}

QVariant IssueModel::data(const QModelIndex &index, int role) const {
  if (!index.isValid())
    return QVariant();

  if (index.row() >= listOfIssue.size() || index.row() < 0)
    return QVariant();

  if (role == Qt::DisplayRole) {
    switch (index.column()) {
    case ColumnName_ID:
      return listOfIssue[index.row()].id;
    case ColumnName_Subject:
      return listOfIssue[index.row()].subject;
    case ColumnName_Description:
      return listOfIssue[index.row()].description;
    case ColumnName_Author:
      return listOfIssue[index.row()].author_name;
    case ColumnName_Category:
      return listOfIssue[index.row()].category_name;
    case ColumnName_CreateOn:
      return listOfIssue[index.row()].created_on;
    case ColumnName_DoneRatio:
      return listOfIssue[index.row()].done_ratio;
    case ColumnName_DueDate:
      return listOfIssue[index.row()].due_date;
    case ColumnName_Status:
      return listOfIssue[index.row()].status_name;
    case ColumnName_Project:
      return listOfIssue[index.row()].project_name;
    case ColumnName_Priority:
      return listOfIssue[index.row()].priority_name;
    case ColumnName_StartDate:
      return listOfIssue[index.row()].start_date;
    case ColumnName_UpdateOn:
      return listOfIssue[index.row()].updated_on;
    case ColumnName_Tracker:
      return listOfIssue[index.row()].tracker_name;
    }
  }
  return QVariant();
}

QVariant IssueModel::headerData(int section, Qt::Orientation orientation,
                                int role) const {
  if (role != Qt::DisplayRole)
    return QVariant();

  if (orientation == Qt::Horizontal) {
    switch (section) {
    case ColumnName_ID:
      return tr("ID");
    case ColumnName_Subject:
      return tr("Subject");
    case ColumnName_Description:
      return tr("Description");
    case ColumnName_Author:
      return tr("Author");
    case ColumnName_Category:
      return tr("Category");
    case ColumnName_CreateOn:
      return tr("Created On");
    case ColumnName_DoneRatio:
      return tr("Done Ratio");
    case ColumnName_DueDate:
      return tr("Due Date");
    case ColumnName_Status:
      return tr("Status");
    case ColumnName_Project:
      return tr("Project");
    case ColumnName_Priority:
      return tr("Priority");
    case ColumnName_StartDate:
      return tr("Start Date");
    case ColumnName_UpdateOn:
      return tr("Updated On");
    case ColumnName_Tracker:
      return tr("Tracker");
    default:
      return QVariant();
    }
  }
  return QVariant();
}

bool IssueModel::insertRows(int position, int rows, const QModelIndex &index) {
  Q_UNUSED(index);
  beginInsertRows(QModelIndex(), position, position + rows - 1);

  for (int row = 0; row < rows; row++) {
    Issue issue;
    listOfIssue.insert(position, issue);
  }

  endInsertRows();
  return true;
}

bool IssueModel::removeRows(int position, int rows, const QModelIndex &index) {
  Q_UNUSED(index);
  beginRemoveRows(QModelIndex(), position, position + rows - 1);

  for (int row = 0; row < rows; ++row) {
    listOfIssue.removeAt(position);
  }

  endRemoveRows();
  return true;
}

bool IssueModel::setData(const QModelIndex &index, const QVariant &value,
                         int role) {
  if (index.isValid() && role == Qt::EditRole) {
    int row = index.row();

    switch (index.column()) {
    case ColumnName_ID:
      listOfIssue[row].id = value.toInt();
      break;
    case ColumnName_Subject:
      listOfIssue[row].subject = value.toString();
      break;
    case ColumnName_Description:
      listOfIssue[row].description = value.toString();
      break;
    case ColumnName_Author:
      listOfIssue[row].author_name = value.toString();
      break;
    case ColumnName_Category:
      listOfIssue[row].category_name = value.toString();
      break;
    case ColumnName_DoneRatio:
      listOfIssue[row].done_ratio = value.toDouble();
      break;
    case ColumnName_DueDate:
      listOfIssue[row].due_date = value.toString();
      break;
    case ColumnName_Status:
      listOfIssue[row].status_name = value.toInt();
      break;
    case ColumnName_Priority:
      listOfIssue[row].priority_name = value.toString();
      break;
    case ColumnName_Project:
      listOfIssue[row].project_name = value.toString();
      break;
    case ColumnName_StartDate:
      listOfIssue[row].start_date = value.toString();
      break;
    case ColumnName_Tracker:
      listOfIssue[row].tracker_name = value.toString();
      break;
    case ColumnName_UpdateOn:
      listOfIssue[row].updated_on = value.toString();
      break;
    case ColumnName_CreateOn:
      listOfIssue[row].created_on = value.toString();
      break;

    default:
      return false;
    }
    emit dataChanged(index, index);
    return true;
  }

  return false;
}

Qt::ItemFlags IssueModel::flags(const QModelIndex &index) const {
  if (!index.isValid())
    return Qt::ItemIsEnabled;

  return QAbstractTableModel::flags(index) | Qt::ItemIsEditable;
}

QList<IssueModel::Issue> IssueModel::getList() { return listOfIssue; }

void IssueModel::clear() {

  beginResetModel();
  listOfIssue.clear();
  endResetModel();
}

void IssueModel::addIssue(IssueModel::Issue issue) {

  beginInsertRows(QModelIndex(), listOfIssue.size(), listOfIssue.size());
  listOfIssue.push_back(std::move(issue));
  endInsertRows();
}
void IssueModel::removeIssue(int row) {
  beginRemoveRows(QModelIndex(), row, row);
  listOfIssue.erase(std::next(listOfIssue.begin(), row));
  endRemoveRows();
}
