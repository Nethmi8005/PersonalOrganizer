#ifndef DATABASE_H
#define DATABASE_H

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QString>
#include <QCryptographicHash>


class Database {
public:
    Database();
    ~Database();

    bool openDatabase();
    void closeDatabase();


    bool createUser(const QString &username, const QString &email, const QString &password);
    bool validateLogin(const QString &username, const QString &password);


    bool changeUsername(const QString &email, const QString &newUsername);
    bool changePassword(const QString &email, const QString &newPassword);

    bool addIncome(const QString &description, double amount, const QString &date);

    bool addBudget(const QString &category, double monthlylimit, const QString &budget);

    bool addReport(const QString &totalIncome, const QString &totalExpenses, const QString &savings);

    bool addEvent(const QString &courseName, const QString &time, const QString &deadline, const QString &title);


private:
    QSqlDatabase db;

};

#endif // DATABASE_H
