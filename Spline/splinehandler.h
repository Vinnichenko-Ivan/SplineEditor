#ifndef SPLINEHANDLER_H
#define SPLINEHANDLER_H

#include <vector>
#include <map>
#include <QVector>
#include "Spline/spline.h"
#include "Spline/Kochanek–Bartels/splinekonchakbartles.h"

class SplineHandler
{
private:

public:
    std::vector<Spline*> splines;
    SplineHandler();
    QVector<QString> algorithms = {"liner", "Konchak - Bartles"};
    void addSpline(QColor color, QString name, QString algorithm);
    QVector<QString> getNames();
    bool getCheckLineFlag(int index);
    bool updateNames;
    void setTestLine(int index, bool flag);
    void deleteSpline(int index);
};

#endif // SPLINEHANDLER_H
