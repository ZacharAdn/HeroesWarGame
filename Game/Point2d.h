//
// Created by zahar on 06/12/16.
//

#ifndef CPPEX1_POINT2D_H
#define CPPEX1_POINT2D_H

using namespace std;

#include <string>


class Point2d {
public:

    Point2d();

    Point2d(int x, int y);

    virtual ~Point2d();

    int getX() const;

    void setX(int x);

    int getY() const;

    void setY(int y);

    string toString();

private:
    int x,y;
};


#endif //CPPEX1_POINT2D_H
