#ifndef CONNECTIONCHECK_H
#define CONNECTIONCHECK_H

#include "imanager.h"
class Check : public IManager {
  Q_OBJECT
public:
  Check(QObject *parent = 0);

  // IBase interface
  void checkConnection(QUrl url, QString username, QString password);

protected:
  void parse(QNetworkReply *reply);

signals:
  void sigReplyError(QString err);
  void sigReplyOk();
};

#endif // CONNECTIONCHECK_H
