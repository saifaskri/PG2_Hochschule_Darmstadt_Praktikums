#ifndef DISHDECORATOR_H
#define DISHDECORATOR_H
#include "dish.h"

class DishDecorator : public Dish
{
protected:
    Dish *dish;

    virtual void printDishDesc() {
        if (dish) dish->printDesc();
    }
    virtual float getComponentPrice() = 0;

public:
    DishDecorator(Dish *d, std::string n) : Dish(n), dish(d) {}
    virtual ~DishDecorator() { delete dish; }

    virtual float getPrice() {
        return (dish ? dish->getPrice() : 0) + getComponentPrice();
    }
    virtual void printDesc() = 0;
};

/*----------------------------------------------------*
 * Von Oberklasse DishDecorator abgeleitete Beilagen  *
 *----------------------------------------------------*/
class Side : public DishDecorator
{
    static std::map<std::string, float> namePriceBag;

protected:
    float getComponentPrice() { return namePriceBag[name]; }

public:
    Side(Dish *d, std::string n) : DishDecorator(d, n) {}

    void printDesc() {
        printDishDesc();
        printf("[Sides]  %20s: %5.2f %c\n",
               getName().c_str(), getComponentPrice(), 128);
    }

    static const std::map<std::string, float>& getNamePriceBag() {
        return namePriceBag;
    }
};

/*----------------------------------------------------*
 * Von Oberklasse DishDecorator abgeleitete Getraenke *
 *----------------------------------------------------*/
class Drink : public DishDecorator
{
    static std::map<std::string, float> namePriceBag;

protected:
    float getComponentPrice() { return namePriceBag[name]; }

public:
    Drink(Dish *d, std::string n) : DishDecorator(d, n) {}

    void printDesc() {
        printDishDesc();
        printf("[Drinks] %20s: %5.2f %c\n",
               getName().c_str(), getComponentPrice(), 128);
    }

    static const std::map<std::string, float>& getNamePriceBag() {
        return namePriceBag;
    }
};

#endif // DISHDECORATOR_H
