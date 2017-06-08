#ifndef ISSUEREQUEST_H
#define ISSUEREQUEST_H

#include "QDomDocument"
#include "imanager.h"
#include "issuemodel.h"
class IssueRequest : public IManager {
  Q_OBJECT

public:
  IssueRequest(QObject *parent = 0);

  void getIssue(QUrl url, QString usename, QString password);
  void getIssue(QUrl url, QString usename, QString password, int projectId);

  IssueModel *getModel() const;

private:
  IssueModel *model;
  // REST interface

signals:
  void sigReplyError(QString err);
  void sigReplyOk();

  // IManager interface
protected:
  void parse(QNetworkReply *reply);
};

#endif // ISSUE_H
