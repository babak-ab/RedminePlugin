#ifndef QREDMINECLIENT_H
#define QREDMINECLIENT_H

#include "qredmineclient_global.h"
#include <QAuthenticator>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QObject>
class QREDMINECLIENTSHARED_EXPORT QRedmineClient : public QObject {
  Q_OBJECT
public:
  QRedmineClient(QObject *parent = 0);
};

#endif // QREDMINECLIENT_H
