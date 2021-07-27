#ifndef SPLINEDISPLAY_H
#define SPLINEDISPLAY_H

#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGridLayout>
#include <QTimer>
#include <QRectF>
#include <QLineF>
#include <algorithm>
#include <Spline/splinehandler.h>


class SplineDisplay : public QWidget
{
    Q_OBJECT
private:
    SplineHandler* handler;
public:
    explicit SplineDisplay(SplineHandler* handlerIn, QWidget *parent = nullptr);
    QGraphicsScene *scene;
    QGridLayout *layout;
    QGraphicsView *view;
    QTimer *updater;
signals:

private slots:
    void repaint();

public slots:
    void scale();
};

#endif // SPLINEDISPLAY_H
