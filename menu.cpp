#include "menu.h"
#include "ui_menu.h"
#include "income.h"
#include "budget.h"
#include "report.h"
#include "schedule.h"
#include "mainwindow.h"

menu::menu(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::menu)


{
    ui->setupUi(this);
}

menu::~menu()
{
    delete ui;
}

void menu::on_pushButton_clicked()
{
    Income *th=new Income();
    this->hide();
    th->show();

    connect(th,&Income::destroyed,this,&menu::deleteLater);
}


void menu::on_pushButton_3_clicked()
{
    budget *dia=new budget();
    this->hide();
    dia->show();

    connect(dia,&budget::destroyed,this,&menu::deleteLater);
}


void menu::on_pushButton_4_clicked()
{
    report *con=new report();
    this->hide();
    con->show();

    connect(con,&report::destroyed,this,&menu::deleteLater);
}


void menu::on_pushButton_2_clicked()
{
    Schedule *col=new Schedule();
    this->hide();
    col->show();

    connect(col,&Schedule::destroyed,this,&menu::deleteLater);
}


void menu::on_pushButton_5_clicked()
{
    MainWindow *dol=new MainWindow();
    this->hide();
    dol->show();

    connect(dol,&MainWindow::destroyed,this,&menu::deleteLater);
}

