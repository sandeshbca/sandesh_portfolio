#include<iostream>
using namespace std;
class myClass {
    public :
    void method();
};
void myClass :: method(){
        cout << "sandesh";
}
int main(){
    myClass myObj;
    myObj.method();
    return 0;
}