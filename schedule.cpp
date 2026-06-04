#include "schedule.h"
#include "ui_schedule.h"
#include "menu.h"
#include <QMessageBox>

Schedule::Schedule(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Schedule)
{
    ui->setupUi(this);
    db.openDatabase();
}

Schedule::~Schedule()
{
    delete ui;
    db.closeDatabase();
}

void Schedule::on_pushButton_clicked()
{
    menu *cos=new menu();
    this->hide();
    cos->show();

    connect(cos,&menu::destroyed,this,&Schedule::deleteLater);

}

void Schedule::on_pushButton_2_clicked()
{
    QString courseName = ui->courseNameLineEdit->text();
    QString time = ui->timeTimeEdit->text();
    QString deadline = ui->deadlineDateEdit->text();
    QString title = ui->titleComboBox->currentText();

    if (courseName.isEmpty() || time.isEmpty() || deadline.isEmpty() || title.isEmpty()) {
        QMessageBox::warning(this, "Input Error", "Please fill in all fields before saving.");
        return;
    }
    bool success = db.addEvent(courseName, time, deadline, title);

    if (success) {
        QMessageBox::information(this, "Success", "Schedule event added successfully!");
    } else {
        QMessageBox::critical(this, "Error", "Failed to add schedule event.");
    }
}
