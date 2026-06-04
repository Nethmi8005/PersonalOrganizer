#include "signup.h"
#include "ui_signup.h"
#include "mainwindow.h"
#include <QMessageBox>
#include <QDebug>

signup::signup(QWidget *parent) :
    QDialog(parent), ui(new Ui::signup) {
    ui->setupUi(this);


    if (db.openDatabase()) {
        qDebug() << "Database connected successfully.";
    } else {
        qDebug() << "Failed to connect to the database.";
    }
}

signup::~signup() {
    delete ui;
}


void signup::on_pushButton_clicked() {
    QString username = ui->lineEdit->text();
    QString email = ui->lineEdit_2->text();
    QString password = ui->lineEdit_3->text();
    QString confirmPassword = ui->lineEdit_4->text();

    if (username.isEmpty() || email.isEmpty() || password.isEmpty() || confirmPassword.isEmpty()) {
        QMessageBox::warning(this, "Input Error", "All fields are required.");
        return;
    }

    if (password != confirmPassword) {
        QMessageBox::warning(this, "Password Mismatch", "Passwords do not match.");
        return;
    }


    if (db.createUser(username, email, password)) {
        QMessageBox::information(this, "Signup", "Account created successfully!");
        this->close();
        MainWindow *mainWindow = new MainWindow();
        mainWindow->show();
    } else {
        QMessageBox::warning(this, "Signup Failed", "Could not create account. Email might already be in use.");
        qDebug() << "Failed to create user in the database.";
    }
}


void signup::on_pushButton_2_clicked() {
    this->close();
    MainWindow *mainWindow = new MainWindow(this);
    mainWindow->show();
    qDebug() << "Main window displayed, signup dialog hidden.";
}
