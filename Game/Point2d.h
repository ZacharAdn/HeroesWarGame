//
// Created by zahar on 06/12/16.
//

#ifndef CPPEX1_POINT2D_H
#define CPPEX1_POINT2D_H

#include <string>

using namespace std;


class Point2d {
private:
    int x,y;

public:

    Point2d();

    Point2d(int x, int y);

    virtual ~Point2d();

    int getX() const;

    void setX(int x);

    int getY() const;

    void setY(int y);

//    Point2d & operator=(const Point2d *point);

    string toString();
};


#endif //CPPEX1_POINT2D_H
