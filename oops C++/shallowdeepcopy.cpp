#include<iostream>
using namespace std;
class student{
  public:
  string name;
  double* cgpaptr;
  
  student(string name, double cgpa){
    this->name=name;
    cgpaptr=new double;
    *cgpaptr=cgpa;

  }
  student( student &obj){
    this->name=obj.name;
    cgpaptr=new double;
    this->cgpaptr=obj.cgpaptr;
  }
   void getinfo(){
    cout << "name : " << name << endl;
    cout << "cgpa : " << *cgpaptr << endl;

   }
};
int main(){
    student s1("sandesh",8.9);
    student s2(s1);
    s1.getinfo();
    *(s2.cgpaptr)=9.2;
    s2.name="rahul";
    s2.getinfo();

    return 0;
}