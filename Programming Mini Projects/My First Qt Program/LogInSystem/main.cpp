#include "login.h"
#include <QApplication>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QWidget>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QWidget w;
    QLabel lblUser("Username: ");
    QLabel lblPass("Password: ");
    QLineEdit blkUser;
    QLineEdit blkPass;
    lblUser.setParent(&w);
    lblPass.setParent(&w);
    blkUser.setParent(&w);
    blkPass.setParent(&w);
    lblUser.move(12,12);
    lblPass.move(12,42);
    blkUser.move(70,10);
    blkPass.move(70,40);
    w.show();
    return a.exec();
}
