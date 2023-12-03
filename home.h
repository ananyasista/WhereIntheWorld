//
// Created by strau on 12/3/2023.
//

#ifndef P3_HOME_H
#define P3_HOME_H

#include <QWidget>


QT_BEGIN_NAMESPACE
namespace Ui { class home; }
QT_END_NAMESPACE

class home : public QWidget
{
    Q_OBJECT

public:
    explicit home(QWidget *parent = nullptr);

    ~home() override;

private:
    Ui::home *ui;
};


#endif //P3_HOME_H
