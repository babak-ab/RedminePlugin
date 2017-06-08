#ifndef PROJECTREQUEST_H
#define PROJECTREQUEST_H

#include "imanager.h"
#include "projectmodel.h"
class ProjectRequest : public IManager {
  Q_OBJECT
public:
  ProjectRequest(QObject *parent);

  // IManager interface
  ProjectModel *getModel() const;

  void getProject(QUrl url, QString usename, QString password);

protected:
  void parse(QNetworkReply *reply);

private:
  ProjectModel *model;
signals:
  void sigReplyError(QString err);
  void sigReplyOk();
};

#endif // PROJECTREQUEST_H
