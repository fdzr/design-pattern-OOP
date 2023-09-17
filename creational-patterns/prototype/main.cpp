#include <bits/stdc++.h>

using namespace std;


enum VehiculePrototypes {
    AircraftPrototype,
    CarPrototype
};

class Vehicule {
    public:
        Vehicule() {    
            parts.push_back("Engine");
            parts.push_back("Fuel Tank");
        }
        virtual ~Vehicule() {
            cout<<"Vehicule class has been destroyed and memory released...!"<<endl;
        }
        virtual Vehicule* clone() const = 0;
        virtual void listAllParts() const = 0;
        virtual void setVehiculeName(const string name) {
            this->name = name;
        };
        virtual void addParts(string part) {
            parts.push_back(part);
        }
        list<string> getParts() const { return parts; }
    
    private:
        string name;
        list<string> parts;

};

class Aircraft: public Vehicule {
    public:
        Aircraft(): Vehicule() {
            addParts("IFE");
            addParts("Passenger seats");
        }
        ~Aircraft() {
            cout<<"Aircraft class has been destroyed and memory released...!"<<endl;
        }
        Vehicule* clone() const override {
            return new Aircraft;
        }
        void listAllParts() const override {
            for(auto part: getParts())
                cout<<part<<endl;
            cout<<"=================================="<<endl;
        }
};

class Car: public Vehicule {
    public:
        Car(): Vehicule() {
            addParts("Mirrors");
            addParts("Shift Gear");
        }
        ~Car() {
            cout<<"Car class has been destroyed and memory released...!"<<endl;
        }
        Vehicule* clone() const override {
            return new Car;
        }
        void listAllParts() const override {
            for(auto part: getParts())
                cout<<part<<endl;
            cout<<"=========================================="<<endl;
        }
};

class PrototypeFactory {
    public:
        ~PrototypeFactory() {
            delete vehicule_prototype[VehiculePrototypes::AircraftPrototype];
            delete vehicule_prototype[VehiculePrototypes::CarPrototype];
            cout<<"Prototype factory has been destroyed and memory released\n";
        }
        Vehicule *preparePrototype(int prototypeIndex) {
            assert(prototypeIndex >=0 && prototypeIndex <=1);
            return vehicule_prototype[prototypeIndex]->clone();
        }

    private:
        Vehicule *vehicule_prototype[2] = {new Aircraft, new Car};
};



int main() {
    Vehicule *vehicule;
    PrototypeFactory *pFactory = new PrototypeFactory();
    vehicule = pFactory->preparePrototype(VehiculePrototypes::AircraftPrototype);
    vehicule->setVehiculeName("Boeing...");
    vehicule->addParts("MCAS");
    vehicule->addParts("EICAS");
    vehicule->listAllParts();

    cout<<"\n\n\n";
    cout<<"======================="<<endl;

    vehicule = pFactory->preparePrototype(VehiculePrototypes::AircraftPrototype);
    (*vehicule).setVehiculeName("Airbus...");
    (*vehicule).addParts("ECAM");
    (*vehicule).listAllParts();

    cout<<"\n\n\n";
    cout<<"======================="<<endl;

    vehicule = pFactory->preparePrototype(VehiculePrototypes::CarPrototype);
    vehicule->setVehiculeName("MURAT124...");
    vehicule->addParts("SALLOW DOG");
    vehicule->addParts("DISCO BALL");
    vehicule->addParts("SUBWOOFERS");
    vehicule->listAllParts();


    delete pFactory;
    delete vehicule;

    return 0;
}