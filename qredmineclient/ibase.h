#ifndef IBASE_H
#define IBASE_H

#include <QAuthenticator>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QObject>
#include <QXmlStreamWriter>
class IBase : public QObject {
  Q_OBJECT
public:
  enum ConnectionError { ConnectionError_Authentication };
  IBase(QObject *parent = 0);

protected:
  QNetworkAccessManager *manager;
  QString mUsername;
  QString mPassword;
  QUrl mUrl;

protected:
  virtual void parse(QByteArray xml) = 0;
private slots:
  virtual void sltReplyFinished(QNetworkReply *reply) = 0;
signals:
  virtual void sigReplyError(ConnectionError err) = 0;
  virtual void sigRecvResponse() = 0;
};

#endif // IBASE_H
