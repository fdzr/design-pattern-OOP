#include <bits/stdc++.h>

using namespace std;

class Pizza {
    public:
        virtual int getPrice() const = 0;
        virtual ~Pizza() {}
};

class HamAndMushroomPizza: public Pizza {
    public:
        virtual int getPrice() const { return 850; }
        virtual ~HamAndMushroomPizza() {}
};

class DeluxePizza: public Pizza {
    public:
        virtual int getPrice() const { return 1050; }
        virtual ~DeluxePizza() {}
};

class HawaiianPizza: public Pizza {
    public:
        virtual int getPrice() const { return 1150; }
        virtual ~HawaiianPizza() {}
};

class PizzaFactory {
    public:
        enum PizzaType {
            HamMushroom,
            Deluxe,
            Hawaiian
        };

        static unique_ptr<Pizza> createPizza(PizzaType pizzaType) {
            switch (pizzaType)
            {
            case HamMushroom:
                return make_unique<HamAndMushroomPizza>();
                break;
            case Deluxe:
                return make_unique<DeluxePizza>();
                break;
            case Hawaiian:
                return make_unique<DeluxePizza>();
                break;
            default:
                throw "invalid pizza type";
                break;
            }
        }
};

void pizzaInformation(PizzaFactory::PizzaType pizzaType) {
    unique_ptr<Pizza> pizza = PizzaFactory::createPizza(pizzaType);
    cout<< "Price of "<<pizzaType<< " is "<<pizza->getPrice()<<endl;
}


int main () {
    pizzaInformation(PizzaFactory::HamMushroom);
    pizzaInformation(PizzaFactory::Deluxe);
    pizzaInformation(PizzaFactory::Hawaiian);

    return 0;
}