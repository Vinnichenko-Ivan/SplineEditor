#ifndef KNOT_H
#define KNOT_H

#include <map>
#include <QString>

class Knot
{
public:
    Knot();
    double x;
    double y;
    std::map<QString, double> parametrs;
};

#endif // KNOT_H
