#ifndef DAEMON_H
#define DAEMON_H

#include <QObject>
#include <QCoreApplication>
#include <QString>
#include <QDBusVariant> 

class Daemon : public QObject
{
  Q_OBJECT

  public:
    Daemon();

  public slots:
    int Run();
    QString Suspend();
    QString DataTransmit(const QString &);

    QString Quit();

    QDBusVariant VariantTest();

  private:
    enum State
    {
      RUNNING,
      SUSPENDED
    };

    State mState;
};

#endif // DAEMON_H
