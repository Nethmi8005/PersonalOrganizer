#include "budget.h"
#include "menu.h"
#include "ui_budget.h"
#include "QMessageBox"


budget::budget(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::budget)
{
    ui->setupUi(this);
    connect(ui->pushButton_2, &QPushButton::clicked, this, &::budget:: on_pushButton_2_clicked);
    db.openDatabase();
}

budget::~budget()
{
    delete ui;
    db.closeDatabase();
}

void budget::on_pushButton_clicked()
{
    menu *com=new menu();
    this->hide();
    com->show();

    connect(com,&menu::destroyed,this,&budget::deleteLater);
}

void budget::on_pushButton_2_clicked()
{
    QString category = ui->categoryComboBox->currentText();  // Retrieve the category
    double monthlylimit = ui->monthlyLimitSpinBox->value();
    QString budget = ui->budgetLineEdit->text();  // Retrieve the date (you can use QDateEdit's text)

    // Validate input data
    if (category.isEmpty() || monthlylimit <= 0 || budget.isEmpty()) {
        QMessageBox::warning(this, "Input Error", "Please fill in all fields correctly.");
        return;
    }

    // Add the budget to the database
    bool success = db.addBudget(category, monthlylimit, budget);

    // Show appropriate message based on success or failure
    if (success) {
        QMessageBox::information(this, "Success", "Budget added successfully!");
    } else {
        QMessageBox::critical(this, "Error", "Failed to add the budget. Please try again." );
    }
}
