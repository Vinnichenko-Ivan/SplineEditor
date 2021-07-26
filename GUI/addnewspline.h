#ifndef ADDNEWSPLINE_H
#define ADDNEWSPLINE_H

#include <QWidget>
#include <QLabel>
#include <QDebug>
#include <QLineEdit>
#include <QComboBox>
#include <QGridLayout>
#include <QColorDialog>
#include <QPushButton>
#include <QColor>
#include <QString>
#include <Spline/splinehandler.h>

class AddNewSpline : public QWidget
{
    Q_OBJECT
private:
    SplineHandler* handler;
    QLineEdit* nameIn;
    QComboBox* algorithms;
    QPushButton* colorIn;
    QGridLayout* layout;
    QPushButton* addNew;
    QLabel* colorLable;
    QPalette *palette;
    QColor changedColor = QColor(0,0,255);
    QString changedAlgorithm = "default";


public:
    QColorDialog* getColor;
    explicit AddNewSpline(QColorDialog* getColorIn,SplineHandler* handlerIn, QWidget *parent = nullptr);


signals:
    void updateSplines();
private slots:
    void addSpline();

public slots:
   // void addNewSpline();
};

#endif // ADDNEWSPLINE_H
