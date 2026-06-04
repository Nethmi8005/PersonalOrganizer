#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "signup.h"
#include "menu.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)  {

    ui->setupUi(this);
    this->showMaximized();
    db.openDatabase();
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_pushButton_clicked() {
    QString Username = ui->lineEdit->text();
    QString password = ui->lineEdit_2->text();

    if (db.validateLogin(Username , password)) {
        QMessageBox::information(this, "Login", "Login successful!");
        menu *menuWindow = new menu();
        this->hide();
        menuWindow->show();


        connect(menuWindow, &menu::destroyed, this, &MainWindow::deleteLater);
    } else {
        QMessageBox::warning(this, "Login Failed", "Invalid username or password.");
    }
}


void MainWindow::on_pushButton_2_clicked() {
    signup *signupForm = new signup(this);

    this->hide();

    signupForm->show();


    connect(signupForm, &signup::destroyed, this, &MainWindow::showNewMainWindow);

}

void MainWindow::showNewMainWindow() {

        MainWindow *newMainWindow = new MainWindow();


        newMainWindow->show();

}
