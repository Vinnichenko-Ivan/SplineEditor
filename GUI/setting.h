#ifndef SETTING_H
#define SETTING_H

#include <QWidget>
#include <QPalette>
#include <QPushButton>
#include <QScrollBar>
#include <QGridLayout>
#include <QLabel>
#include <GUI/addnewspline.h>
class Setting : public QWidget
{
    Q_OBJECT
public:
    explicit Setting(AddNewSpline* addNewSplineIn, QWidget *parent = nullptr);
    QPushButton *addNewSpline;
    QGridLayout *layout;
    AddNewSpline* addNewSplineDialog;

signals:

};

#endif // SETTING_H
