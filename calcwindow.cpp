#include "calcwindow.h"
#include "ui_calcwindow.h"
#include "cmath"

double numForCalcuate;

CalcWindow::CalcWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CalcWindow)
{
    ui->setupUi(this);

    connect(ui->zero, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->one, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->two, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->three, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->four, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->five, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->six, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->seven, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->eight, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->nine, SIGNAL(clicked()), this, SLOT(digits_numbers()));

    connect(ui->plusMinus, SIGNAL(clicked()), this, SLOT(operations()));
    connect(ui->percent, SIGNAL(clicked()), this, SLOT(operations()));
    connect(ui->sin, SIGNAL(clicked()), this, SLOT(operations()));
    connect(ui->cos, SIGNAL(clicked()), this, SLOT(operations()));
    connect(ui->backspace, SIGNAL(released()), this, SLOT(operations()));

    connect(ui->subtract, SIGNAL(clicked()), this, SLOT(math()));
    connect(ui->additional, SIGNAL(clicked()), this, SLOT(math()));
    connect(ui->devide, SIGNAL(clicked()), this, SLOT(math()));
    connect(ui->exp, SIGNAL(clicked()), this, SLOT(math()));
    connect(ui->multiply, SIGNAL(clicked()), this, SLOT(math()));

    connect(ui->dot, SIGNAL(clicked()), this, SLOT(dot_push()));

    ui->devide->setCheckable(true);
    ui->multiply->setCheckable(true);
    ui->additional->setCheckable(true);
    ui->subtract->setCheckable(true);
    ui->exp->setCheckable(true);
}

CalcWindow::~CalcWindow()
{
    delete ui;
}

void CalcWindow::digits_numbers(){
    QPushButton *button = (QPushButton *) sender();
    ui->result->setText(QString::number((ui->result->text() + button->text()).toDouble(), 'g', 15));
}

void CalcWindow::dot_push()
{
    if(!(ui->result->text().contains('.')))
        ui->result->setText(ui->result->text() + ".");
}

void CalcWindow::operations(){
    QPushButton *button = (QPushButton *) sender();

    if(button->text() == "+/-"){
        ui->result->setText(QString::number((ui->result->text()).toDouble() * -1, 'g', 15));

    }else if(button->text() == "%"){
        ui->result->setText(QString::number((ui->result->text()).toDouble() * 0.01, 'g', 15));

    }else if(button->text() == "sin"){
        ui->result->setText(QString::number(sin((ui->result->text()).toDouble()), 'g', 15));
    }

    else if(button->text() == "cos"){
        ui->result->setText(QString::number(cos((ui->result->text()).toDouble()), 'g', 15));
    }else if(button->text() == "<-"){
        ui->result->setText(QString::number(ui->result->text()
                                            .remove(ui->result->text().length() - 1,
                                                    ui->result->text().length()).toDouble()
                                            ,'g',15));
    }

}

void CalcWindow::on_equal_clicked()
{
    double numSecond = ui->result->text().toDouble();

    if(ui->additional->isChecked()){
        ui->result->setText(QString::number(numForCalcuate + numSecond, 'g', 15));
        ui->additional->setChecked(false);

    }else if(ui->subtract->isChecked()){
        ui->result->setText(QString::number(numForCalcuate - numSecond, 'g', 15));
        ui->subtract->setChecked(false);

    }else if(ui->multiply->isChecked()){
        ui->result->setText(QString::number(numForCalcuate * numSecond, 'g', 15));
        ui->multiply->setChecked(false);

    }else if(ui->devide->isChecked()){
        if (numSecond == 0) {
            ui->result->setText(0);
        }else{
            ui->result->setText(QString::number(numForCalcuate / numSecond, 'g', 15));
        }
         ui->devide->setChecked(false);

    }else if(ui->exp->isChecked()){
        ui->result->setText(QString::number(pow(numForCalcuate, numSecond), 'g', 15));
        ui->multiply->setChecked(false);
    }

}

void CalcWindow::math()
{
    QPushButton *button = (QPushButton *)sender();

    numForCalcuate = ui->result->text().toDouble();
    ui->result->setText("");
    button->setChecked(true);
}
