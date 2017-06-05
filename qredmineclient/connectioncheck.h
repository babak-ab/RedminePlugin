#ifndef CONNECTIONCHECK_H
#define CONNECTIONCHECK_H

#include "ibase.h"
class ConnectionCheck : public IBase {
  Q_OBJECT
public:
  ConnectionCheck(QObject *parent = 0);

  // IBase interface
  void checkConnection(QUrl url, QString usename, QString password);

protected:
  void parse(QByteArray xml);

private slots:
  void sltReplyFinished(QNetworkReply *reply);

signals:
  void sigReplyError(ReplayError err);
  void sigReplyOk();
};

#endif // CONNECTIONCHECK_H
