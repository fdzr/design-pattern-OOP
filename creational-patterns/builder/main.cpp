#include <bits/stdc++.h>

using namespace std;

class Pizza {
    public:
        void setDough(const string& dough) {
            m_dough = dough;
        }
        void setSauce(const string& sauce) {
            m_sauce = sauce;
        }
        void setTopping(const string& topping) {
            m_topping = topping;
        }
        void open() {
            cout<< "Pizza with "<<m_dough<< " dough, "
                <<m_sauce<< "sauce and "<<m_topping
                <<" topping. Mmm."<<endl;
        }

    private:
        string m_dough;
        string m_sauce;
        string m_topping;
};

class PizzaBuilder {
    public:
        virtual ~PizzaBuilder() {
            cout<<"Destructor of class [PizzaBuilder]"<<endl;
        }
        Pizza* getPizza() {
            return m_pizza.get();
        }
        void createNewPizzaProduct() {
            m_pizza = make_unique<Pizza>();
        }
        virtual void buildDough() = 0;
        virtual void buildSauce() = 0;
        virtual void buildTopping() = 0;
    protected:
        unique_ptr<Pizza> m_pizza;
};

class HawaiianPizzaBuilder: public PizzaBuilder {
    public:
        virtual ~HawaiianPizzaBuilder() override {
            cout<<"Destructor of class [HawaiianPizzaBuilder]"<<endl;
        };
        virtual void buildDough() override {
            m_pizza->setDough("cross");
        }
        virtual void buildSauce() override {
            m_pizza->setSauce("mild");
        }
        virtual void buildTopping() override {
            m_pizza->setTopping("ham+pinneapple");
        }
};

class SpicyPizzaBuilder: public PizzaBuilder {
    public:
        virtual ~SpicyPizzaBuilder () override {
            cout<<"Destructor of class [SpicyPizzaBuilder]"<<endl;
        }
        virtual void buildDough() override {
            m_pizza->setDough("pan baked");
        }
        virtual void buildSauce() override {
            m_pizza->setSauce("hot");
        }
        virtual void buildTopping() override {
            m_pizza->setTopping("pepperoni+salami");
        }
};

class Cook {
    public:
        ~ Cook() {
            cout<<"Destructor of class [Cook]"<<endl;
        }
        void openPizza() const {
            m_pizzaBuilder->getPizza()->open();
        }
        void makePizza(PizzaBuilder* pb) {
            m_pizzaBuilder = pb;
            m_pizzaBuilder->createNewPizzaProduct();
            m_pizzaBuilder->buildDough();
            m_pizzaBuilder->buildSauce();
            m_pizzaBuilder->buildTopping();
        }
    private:
        PizzaBuilder *m_pizzaBuilder;
};

int main () {
    Cook cook{};
    HawaiianPizzaBuilder hawaiianPizzaBuilder;
    cook.makePizza(&hawaiianPizzaBuilder);
    cook.openPizza();

    SpicyPizzaBuilder spicyPizzaBuilder;
    cook.makePizza(&spicyPizzaBuilder);
    cook.openPizza();

    return 0;
}