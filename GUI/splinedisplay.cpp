#include "splinedisplay.h"

SplineDisplay::SplineDisplay(QWidget *parent) : QWidget(parent)
{
    QPalette p(palette());
    p.setColor(QPalette::Background, Qt::black);
    setAutoFillBackground(true);
    setPalette(p);
}
