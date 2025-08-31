#include<iostream>
using namespace std;
class student{
     private:
     string name;
     int age;

     public:
     void setData(string n, int a){
        name = n;
        age = a;
     }
     void displayData(){
        cout << "name : " << name << endl;
        cout << "age : " << age << endl;
     }

};

int main(){
    student s1;
    s1.setData("sandesh",20);
    s1.displayData();

    return 0;

}