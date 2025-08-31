#include<iostream>
using namespace std;
class person{
    public:
    string name;
    long long contact;

  /*  person(string name, long long contact){
        this->name=name;
        this->contact=contact;
    }*/

    
    void display(){
        cout << "name : " << name << endl;
        cout << "contact : " << contact << endl;
    }
};
class personn : public person{
    public:
      int age;
      /*personn(string name, long long contact, int age) :  person(name, contact){
        this->age=age;

      }*/

      
      
      void displayy(){
        display();
         cout << "age : " << age << endl;
      }
};
int main(){
    personn p1 ;
    p1.name="sandesh";
    p1.contact=8953305102;
    p1.age=20;

    p1.displayy();


    return 0;



    
}