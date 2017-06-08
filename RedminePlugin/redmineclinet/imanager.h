#ifndef IBASE_H
#define IBASE_H

#include <QAuthenticator>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QObject>
#include <QXmlStreamWriter>
class IManager : public QObject {
  Q_OBJECT
public:
  IManager(QObject *parent = 0);
  void request(QUrl url, QString username, QString password);

protected:
  QNetworkAccessManager *manager;
  //  QString mUsername;
  //  QString mPassword;
  //  QUrl mUrl;

protected:
  virtual void parse(QNetworkReply *reply) = 0;
private slots:
  void sltReplyFinished(QNetworkReply *reply);
signals:
  virtual void sigReplyError(QString err) = 0;
  virtual void sigReplyOk() = 0;
};

#endif // IBASE_H
