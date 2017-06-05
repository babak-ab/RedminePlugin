#ifndef ISSUEREQUEST_H
#define ISSUEREQUEST_H

#include "QDomDocument"
#include "ibase.h"
#include "issuemodel.h"
class IssueRequest : public IBase {
  Q_OBJECT

public:
  IssueRequest(QObject *parent = 0);

  void getIssue(QUrl url, QString usename, QString password);

  IssueModel *getModel() const;

private:
  IssueModel *model;
  // REST interface
private slots:
  void sltReplyFinished(QNetworkReply *reply);

signals:
  void sigReplyError(ConnectionError err);
  void sigRecvResponse();
  // REST interface
protected:
  void parse(QByteArray xml);
};

#endif // ISSUE_H
