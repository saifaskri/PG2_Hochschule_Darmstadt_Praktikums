#ifndef DISH_H
#define DISH_H
#include <stdio.h>
#include <string>
#include <map>

class Dish
{
    Dish();
    Dish(const Dish&);
    Dish& operator=(const Dish&);

protected:
    std::string name;

public:
    explicit Dish(std::string n) : name(n) {}
    virtual ~Dish() {}

    std::string getName() { return name; }

    virtual float getPrice() = 0;
    virtual void printDesc() = 0;
};

/*------------------------------------------------*
 * Von Basisklasse Dish abgeleitetes Hauptgericht *
 *------------------------------------------------*/
class Menu : public Dish
{
    static std::map<std::string, float> namePriceBag;

public:
    explicit Menu(std::string n) : Dish(n) {}

    float getPrice() { return namePriceBag[name]; }

    void printDesc() {
        printf("[Main]   %20s: %5.2f %c\n",
               getName().c_str(), getPrice(), 128);
    }

    static const std::map<std::string, float>& getNamePriceBag() {
        return namePriceBag;
    }
};

#endif // DISH_H
