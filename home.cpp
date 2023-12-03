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

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "backend.h" // Include your backend header

MainWindow::MainWindow(QWidget *parent) :
        QMainWindow(parent),
        ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Instantiate your backend
    Backend backend;

    // Connect a button click to a backend function
    connect(ui->pushButton, &QPushButton::clicked, &backend, &Backend::performAction);
}

MainWindow::~MainWindow()
{
    delete ui;
}
