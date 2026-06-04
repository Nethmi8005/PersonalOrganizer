#include "database.h"
#include <QCryptographicHash>
#include <QSqlQuery>
#include <QVariant>

Database::Database() {
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("users.db");
}

Database::~Database() {
    closeDatabase();
}

bool Database::openDatabase() {
    if (!db.open()) {
        return false;
    }

    QSqlQuery query;
    query.exec("CREATE TABLE IF NOT EXISTS users (id INTEGER PRIMARY KEY, username TEXT UNIQUE, email TEXT UNIQUE, password TEXT)");
    query.exec("CREATE TABLE IF NOT EXISTS income (id INTEGER PRIMARY KEY, description TEXT, amount REAL, date TEXT)");
    query.exec("CREATE TABLE IF NOT EXISTS reports (id INTEGER PRIMARY KEY, total_income REAL, total_expenses REAL, savings REAL)");
    query.exec("CREATE TABLE IF NOT EXISTS budget (id INTEGER PRIMARY KEY,category TEXT,monthly_limit REAL,budget_amount TEXT)");
    query.exec("CREATE TABLE IF NOT EXISTS schedule (id INTEGER PRIMARY KEY ,course_name TEXT ,time TEXT, deadline TEXT,title TEXT)");

    return true;
}

void Database::closeDatabase() {
    if (db.isOpen()) {
        db.close();
    }
}

bool Database::createUser(const QString &username, const QString &email, const QString &password) {
    if (!db.isOpen()) return false;

    QSqlQuery query;
    query.prepare("INSERT INTO users (username, email, password) VALUES (:username, :email, :password)");
    query.bindValue(":username", username);
    query.bindValue(":email", email);
    query.bindValue(":password", QCryptographicHash::hash(password.toUtf8(), QCryptographicHash::Sha256).toHex());
    return query.exec();
}

bool Database::validateLogin(const QString &username, const QString &password) {
    if (!db.isOpen()) return false;

    QSqlQuery query;
    query.prepare("SELECT password FROM users WHERE username = :username");
    query.bindValue(":username", username);

    if (query.exec() && query.next()) {
        QString storedPassword = query.value(0).toString();
        QString hashedPassword = QCryptographicHash::hash(password.toUtf8(), QCryptographicHash::Sha256).toHex();
        return storedPassword == hashedPassword;
    }
    return false;
}

bool Database::changeUsername(const QString &email, const QString &newUsername) {
    if (!db.isOpen()) return false;

    QSqlQuery query;
    query.prepare("UPDATE users SET username = :newUsername WHERE email = :email");
    query.bindValue(":newUsername", newUsername);
    query.bindValue(":email", email);
    return query.exec();
}

bool Database::changePassword(const QString &email, const QString &newPassword) {
    if (!db.isOpen()) return false;

    QSqlQuery query;
    query.prepare("UPDATE users SET password = :newPassword WHERE email = :email");
    query.bindValue(":newPassword", QCryptographicHash::hash(newPassword.toUtf8(), QCryptographicHash::Sha256).toHex());
    query.bindValue(":email", email);
    return query.exec();
}


bool Database::addIncome(const QString &description, double amount, const QString &date) {
    if (!db.isOpen()) return false;

    QSqlQuery query;
    query.prepare("INSERT INTO income (description, amount, date) VALUES (:description, :amount, :date)");
    query.bindValue(":description", description);
    query.bindValue(":amount", amount);
    query.bindValue(":date", date);

    return query.exec();
}


bool Database::addBudget(const QString &category, double monthlylimit, const QString &budget){
    if (!db.isOpen())
        return false;

    QSqlQuery query;
    query.prepare("INSERT INTO budget (category, monthlylimit, budget_amount) VALUES (:category, :monthlylimit, :budget_amount)");
    query.bindValue(":category", category);
    query.bindValue(":monthlylimit", monthlylimit);
    query.bindValue(":budget_amount", budget);

    return query.exec();
}
bool Database::addReport(const QString &totalIncome, const QString &totalExpenses, const QString &savings) {
    if (!db.isOpen()) return false;

    QSqlQuery query;
    query.prepare("INSERT INTO reports (total_income, total_expenses, savings) VALUES (:totalincome, :totalexpenses, :savings)");
    query.bindValue(":totalIncome", totalIncome.toDouble());
    query.bindValue(":totalExpenses", totalExpenses.toDouble());
    query.bindValue(":savings", savings.toDouble());

    return query.exec();
    }
bool Database::addEvent(const QString &courseName, const QString &time, const QString &deadline, const QString &title) {
    if (!db.isOpen()) return false;

    QSqlQuery query;
    query.prepare("INSERT INTO schedule (course_name, time, deadline, title) VALUES (:courseName, :time, :deadline, :title)");
    query.bindValue(":courseName", courseName);
    query.bindValue(":time", time);
    query.bindValue(":deadline", deadline);
    query.bindValue(":title", title);

    return query.exec();
}
