#include "projectmodel.h"

ProjectModel::ProjectModel(QObject *parent) : QAbstractTableModel(parent) {}

int ProjectModel::rowCount(const QModelIndex &parent) const {
  Q_UNUSED(parent);
  return listProject.size();
}

int ProjectModel::columnCount(const QModelIndex &parent) const {
  Q_UNUSED(parent);
  return 2;
}

QVariant ProjectModel::data(const QModelIndex &index, int role) const {
  if (!index.isValid())
    return QVariant();

  if (index.row() >= listProject.size() || index.row() < 0)
    return QVariant();

  if (role == Qt::DisplayRole) {
    switch (index.column()) {
    case 0:
      return listProject[index.row()].id;
    case 1:
      return listProject[index.row()].name;
    }
  }
  return QVariant();
}
void ProjectModel::clear() {
  beginResetModel();
  listProject.clear();
  endResetModel();
}

QVariant ProjectModel::headerData(int section, Qt::Orientation orientation,
                                  int role) const {
  if (role != Qt::DisplayRole)
    return QVariant();

  if (orientation == Qt::Horizontal) {
    switch (section) {
    case 0:
      return tr("ID");

    case 1:
      return tr("Name");
    default:
      return QVariant();
    }
  }
  return QVariant();
}

bool ProjectModel::insertRows(int position, int rows,
                              const QModelIndex &index) {
  Q_UNUSED(index);
  beginInsertRows(QModelIndex(), position, position + rows - 1);

  for (int row = 0; row < rows; row++) {
    Project project;
    listProject.insert(position, project);
  }

  endInsertRows();
  return true;
}

bool ProjectModel::removeRows(int position, int rows,
                              const QModelIndex &index) {
  Q_UNUSED(index);
  beginRemoveRows(QModelIndex(), position, position + rows - 1);

  for (int row = 0; row < rows; ++row) {
    listProject.removeAt(position);
  }

  endRemoveRows();
  return true;
}

bool ProjectModel::setData(const QModelIndex &index, const QVariant &value,
                           int role) {
  if (index.isValid() && role == Qt::EditRole) {
    int row = index.row();

    switch (index.column()) {
    case 0:
      listProject[row].id = value.toInt();
      break;
    case 1:
      listProject[row].name = value.toString();
      break;

    default:
      return false;
    }
    emit dataChanged(index, index);
    return true;
  }

  return false;
}

Qt::ItemFlags ProjectModel::flags(const QModelIndex &index) const {
  if (!index.isValid())
    return Qt::ItemIsEnabled;

  return QAbstractTableModel::flags(index) | Qt::ItemIsEditable;
}

QList<ProjectModel::Project> ProjectModel::getList() { return listProject; }

void ProjectModel::addProject(Project issue) {

  beginInsertRows(QModelIndex(), listProject.size(), listProject.size());
  listProject.push_back(std::move(issue));
  endInsertRows();
}
void ProjectModel::removeProject(int row) {
  beginRemoveRows(QModelIndex(), row, row);
  listProject.erase(std::next(listProject.begin(), row));
  endRemoveRows();
}
