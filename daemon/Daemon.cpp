#include "Daemon.hpp"
#include <QDebug>

Daemon::Daemon()
  : mState(State::RUNNING)
{

}

int Daemon::Run()
{
  //Set the state to running
  mState = State::RUNNING;
  char * string = "running\n";
  QString running = "running";
  qDebug() << "Hello I am in adaptor";
  return 1;
}

QString Daemon::Suspend()
{
  //Set the state to suspended
  mState = State::SUSPENDED;
  return QString("Suspended");
}

QString Daemon::DataTransmit(const QString & arg)
{
  //Read some data that was transmitted
  return arg;
}

QString Daemon::Quit()
{
  //Quit the application
  QMetaObject::invokeMethod(QCoreApplication::instance(), "quit");
  char * quit = "Quit\n";
  return quit;
}
