#ifndef DAEMON_H
#define DAEMON_H

#include <QObject>
#include <QCoreApplication>
#include <QString>

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

  private:
    enum State
    {
      RUNNING,
      SUSPENDED
    };

    State mState;
};

#endif // DAEMON_H
