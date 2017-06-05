#include "issuemodel.h"

IssueModel::IssueModel(QObject *parent) : QAbstractTableModel(parent) {}

void IssueModel::clear() { listOfIssue.clear(); }

int IssueModel::rowCount(const QModelIndex &parent) const {
  Q_UNUSED(parent);
  return listOfIssue.size();
}

int IssueModel::columnCount(const QModelIndex &parent) const {
  Q_UNUSED(parent);
  return 3;
}

QVariant IssueModel::data(const QModelIndex &index, int role) const {
  if (!index.isValid())
    return QVariant();

  if (index.row() >= listOfIssue.size() || index.row() < 0)
    return QVariant();

  if (role == Qt::DisplayRole) {
    switch (index.column()) {
    case 0:
      return listOfIssue[index.row()].id;
    case 1:
      return listOfIssue[index.row()].subject;
    case 2:
      return listOfIssue[index.row()].description;
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
    case 0:
      return tr("ID");

    case 1:
      return tr("Subject");

    case 2:
      return tr("Description");

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
    case 0:
      listOfIssue[row].id = value.toInt();
      break;
    case 1:
      listOfIssue[row].subject = value.toString();
      break;
    case 2:
      listOfIssue[row].description = value.toString();
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
