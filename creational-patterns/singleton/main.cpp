#include <bits/stdc++.h>

using namespace std;

class Singleton {
    private:
        string name, loves;
        static Singleton *instancePtr;
        Singleton() {}

    public:
        Singleton(const Singleton &obj) = delete;
        static Singleton *getInstance() {
            return instancePtr;
        }
        void setValues(string name, string loves) {
            this->name = name;
            this->loves = loves;
        }
        void print() {
            cout<< name << " Loves "<< loves<<"."<<endl;
        }
};

Singleton *Singleton ::instancePtr = new Singleton();

int main() {
    Singleton *obj = Singleton::getInstance();
    obj->setValues("Learner", "Geeksforgeeks");
    obj->print();

    cout<< "Address of obj: "<< obj<<endl;

    Singleton *obj1 =Singleton::getInstance();
    obj1->setValues("Everyone", "Geeksforgeeks");
    obj1->print();

    cout<<"Address of obj1: "<<obj1;

    return 0;
}