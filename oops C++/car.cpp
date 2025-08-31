#include<iostream>
using namespace std;
class car{
    private:
     double rate;

    public:
    string brand;
    string model;
    int year;
    string number;

   /* void setRate(double r){
        rate = r;
    }
    double getRate(){
        return rate;
    }*/
    public:
    car() {
        cout << "hi i am constructor";
    }
    car(string brand, string model, int year, string number){
       this-> brand = brand;
       this-> model = model;
       this-> year = year;
    }
}; 



int main(){
    car c1("BMW", "x333", 2323);
  /*  car1.brand = "BMW";
    car1.model = "m5";
    car1.year = 2020;
    car1.number = "UP63M2323";
   // car1.setRate(340000);

    car car2;
    car2.brand = "audi";
    car2.model = "xclass";
    car2.year =  2022;
    car2.number = "UP65H1234";

   //cout << car1.brand << " " << car1.model << " " << car1.year << "\t" << car1.number << "\n";
   // cout << car2.brand << " " << car2.model << " " << car2.year << " " << car2.number << "\n";
//  cout << car1.getRate() << endl;*/

car c2(c1);
c2.getinfo();
    return 0;

}