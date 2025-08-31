#include<iostream>
using namespace std;
class myClass{
    public: 
    int num;
    string name;
    
};
int main(){
    myClass myObj;
    myObj.num = 20;
    myObj.name =  "sandesh";

    cout << myObj.num << "\n" <<  myObj.name;
    

  return 0;
}