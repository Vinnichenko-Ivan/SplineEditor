#ifndef SPLINESETTING_H
#define SPLINESETTING_H

#include <QWidget>
#include <QGridLayout>
#include <QPushButton>
#include <QComboBox>
#include <QCheckBox>
#include <QLabel>
#include <QDebug>
#include <QRectF>
#include <GUI/knotsetting.h>
#include <Spline/splinehandler.h>

class SplineSetting : public QWidget
{
    Q_OBJECT
private:
    QGridLayout *layout;
    QComboBox *splineEdit;
    SplineHandler *handler;
    QCheckBox *checkTestLine;
    QPushButton *deleteSpline;
    KnotSetting *knotSetting;
    int editSpline;
public:
    explicit SplineSetting(SplineHandler* handlerIn, QWidget *parent = nullptr);

public slots:
    void updateEditSplines();
    void updateSplineSetting();

signals:

};

#endif // SPLINESETTING_H
