#include<iostream>
using namespace std;
class student{
    string name;
    int roll;
  
    public:
    student(){   //default constructor
        name = "sandesh";
        roll = 1234;
    }
    student(string n, int r){   //parameterized constructor
       this-> name = name;
        this-> roll = roll;

    }
    student(const student &s){    // copy constructor
        name = s.name;
        name = s.roll;

    }
    void display(){
        cout << "name : " << name << endl << "roll : " << roll << endl;
    }
};int main(){
   // student s1;
    student s2("sandeshh",1212);
   // student s3(s1);
   // s1.display();
    s2.display();
   // s3.display();

    return 0;
}