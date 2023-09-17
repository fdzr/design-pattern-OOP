#include <bits/stdc++.h>

using namespace std;

class Dog {
public:
    virtual ~Dog() = default;
    virtual void performsConversion() const = 0;
};

class DogFemale: public Dog {
public:
    virtual void performsConversion() const override {
        cout<<"Dog female performs conversion"<<endl;
    }
};

class Cat {
public:
    virtual ~Cat() = default;
    virtual void performsConversion() const = 0;
};

class CatFemale: public Cat {
public:
    virtual void performsConversion() const override {
        cout<<"Cat female performs conversion"<<endl;
    }
};

class DogNature {
public:
    void carryOutNature(Dog *dog) {
        cout<<"On with the Dog nature!!";
        dog->performsConversion();
    }
};

class ConversionAdapter: public Dog {
private:
    Cat *cat;
public:
    ConversionAdapter(Cat *c): cat{c} {}
    virtual void performsConversion() const override {
        cat->performsConversion();
    }
};

int main() {
    DogFemale *dogFemale = new DogFemale();
    CatFemale *catFemale = new CatFemale();
    DogNature dogNature;
    ConversionAdapter *adaptedCat = new ConversionAdapter(catFemale);
    dogNature.carryOutNature(dogFemale);
    dogNature.carryOutNature(adaptedCat);

    delete adaptedCat;
    delete catFemale;
    delete dogFemale;

    return 0;
}