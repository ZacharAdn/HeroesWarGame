//
// Created by zahar on 07/12/16.
//

#ifndef CPPEX1_POTION_H
#define CPPEX1_POTION_H

using namespace std;
#include "../Item.h"
class Hero;

class Potion : public  Item{
public:

    Potion();

    /**
     *
     * @param location
     * @param amount
     */
    Potion(Point2d &location, double amount);

    ~Potion();

    virtual double getAmount() const;

    virtual void setAmount(double amount);

    char getcharToPrint() override ;

    void acceptToUse(Hero *hero) override ;

    virtual const string &getName() const = 0;

    virtual string toString();

private:
    char charToPrint;
    double amount;
    string name;

};


#endif //CPPEX1_POTION_H
