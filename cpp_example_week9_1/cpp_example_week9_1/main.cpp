#include <iostream>

using namespace std;

class Person{
private:
    int id;
    double weight;
    string name;
public:
    void show(){
        cout<<id<<" "<<weight<<" "<<name<<endl;
    }
    Person();
    Person(int id, string name);
    Person(int id, string name, double weight);
};

Person::Person(){
    this->id = 1;
    this->weight = 10.1;
    this->name = "chanzzz";
}

Person::Person(int id, string name){
    this->id = id;
    this->weight = 20.5;
    this->name = name;
}

Person::Person(int id, string name, double weight){
    this->id = id;
    this->weight = weight;
    this->name = name;
}

int main(void){
    Person seo,chan(2,"chan"),seochan(3,"seochan",60.4);
    seo.show();
    chan.show();
    seochan.show();
    return 0;
}
