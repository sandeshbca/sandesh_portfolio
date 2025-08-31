#include<iostream>
using namespace std;
class account{
    private:
    double balance;
    string password;


    public:
    string accountId;
    string username;

    void setData(double b, string p){
        balance = b;
        password = p;
    }
    void displayData(){
        cout << "accountId : " << accountId << endl;
        cout << "username : " << username << endl;
        cout << "balance : " << balance << endl;
        cout << "password : " << password << endl;
    }
};

int main(){
    account a1;
    a1.accountId = "abc";
    a1.username = "abc123";
    a1.setData(20000,"abc@123");
    a1.displayData();

    return 0;
}
