//
// Created by strau on 12/3/2023.
//

// You may need to build the project (run Qt uic code generator) to get "ui_home.h" resolved

#include "home.h"
#include "ui_home.h"


home::home(QWidget *parent) :
        QWidget(parent), ui(new Ui::home)
{
    ui->setupUi(this);
}

home::~home()
{
    delete ui;
}
