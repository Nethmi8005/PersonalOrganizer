#include "income.h"
#include "ui_income.h"
#include "menu.h"
#include <QMessageBox>


Income::Income(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Income)
{
    ui->setupUi(this);
    connect(ui->pushButton_2, &QPushButton::clicked, this, &::Income::on_pushButton_2_clicked);
    db.openDatabase();
}

Income::~Income()
{
    delete ui;
    db.closeDatabase();
}

void Income::on_pushButton_clicked()
{
    menu *co=new menu();
    this->hide();
    co->show();

    connect(co,&menu::destroyed,this,&Income::deleteLater);
}

void Income::on_pushButton_2_clicked()
{
    QString description = ui->descriptionComboBox->currentText();  // QLineEdit for description
    double amount = ui->amountDoubleSpinBox->text().toDouble();  // QLineEdit for amount
    QString date = ui->dateDateEdit->text();  // QDateEdit for date

    // Validation: Check if the fields are filled
    if (description.isEmpty() || amount <= 0 || date.isEmpty()) {
        QMessageBox::warning(this, "Input Error", "Please fill all fields with valid data.");
        return;
    }

    // Call the Database function to add the income
    bool success = db.addIncome(description, amount, date);

    if (success) {
        // Show success message
        QMessageBox::information(this, "Success", "Added successfully!");
    } else {
        // Show error message
        QMessageBox::critical(this, "Error", "Failed to add income. Please try again.");
    }
}



