#include<iostream>
using namespace std;
class student{   //base class
    public:
    string name;
    int age;

    void inputdetails(string n, int a){
        name = n;
        age = a;

    }
    void displays(){
        cout << "name : " << name << endl;
        cout << "age : " << age << endl;
    }
};
class studentt : public student{  //derieved class
   public:
   int rollno;

   void getdetails(int r){
    rollno = r;
   }
   void displayy(){
     displays(); //calling base class function 
     cout << "rollno : " << rollno << endl;
   }
};
int main(){
    studentt s1;
    s1.inputdetails("sandesh",20);
    s1.getdetails(1234);
    s1.displayy();
    return 0;
}