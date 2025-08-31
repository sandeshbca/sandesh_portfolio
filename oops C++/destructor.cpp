#include<iostream>
using namespace std;
class student {
    public:
    string name;
    double* marksptr;

    student(string name, double marks){
      this->name=name;
      marksptr = new double;
      *marksptr = marks;
    }
    student(){
        delete marksptr; //memory leak na ho
    }
     void getinfo(){
        cout << "name : " << name << endl;
        cout << "marks : " << marksptr << endl;
     }

};
int main(){
    student s1("sandesh", 78.9);
    s1.getinfo();
}