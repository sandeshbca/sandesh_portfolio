#include<iostream>
#include<iomanip>
#include<fstream>
using namespace std;

class BankAccount{
    private:
    int accNo;
    string name;
    double balance;

    public:
  // create new account
    void createAccount(){
        cout << "\nEnter account number : ";
        cin >> accNo;
        cout << "\nEnter the name : ";
        cin >> name;
        cout << "\nEnter Initial Balance : ";
        cin >> balance;
        cout << "\nAccount Created successfully!\n";

    }

    //show account details
    void showAccount(){
        cout << "\nAccount number : " << accNo;
        cout << "\nAccount Holder Name : " << name;
        cout <<  "\n Balance :  " << balance << endl;

    }
    //Modify account details
    void modifyAccount(){
        cout << "\nAccount Number : " << accNo; 
        cout << "\nModify account Holder Name : ";
        cin >> name; 
        cout << "\nModify Balance : ";
        cin >> balance; 
    }
    //Deposit money
    void deposit(double amt){
        balance += amt;
    }

    //withdraw money
    void withdraw(double amt){
        if(balance>=amt)
        balance -= amt;
        else
        cout << "Insufficient Balance!\n";
    }
    //REport for table view
    void report() const{
        cout << accNo << setw(20) << name << setw(15) << balance << endl;
    }

    //getter
    int getAccNo() const {
        return accNo;
    }
    double getBalance() const {
        return balance;
    }
};

// file handling function
void writeAccount(){
    BankAccount ac;
    ofstream outfile("bank.dat", ios::binary | ios::app);
    ac.createAccount();
    outfile.write(reinterpret_cast<char *>(&ac), sizeof(BankAccount));
    outfile.close();
}

void displayAccount(int n){
    BankAccount ac;
    ifstream infile("bank.dat", ios::binary);
    bool found = false;

    while(infile.read(reinterpret_cast<char *>(&ac), sizeof(BankAccount)));
    {
        if(ac.getAccNo()==n){
              ac.showAccount();
              found = true;
        } 
    }
    infile.close();
    if(!found){
        cout << "\nAccount not found!\n";
    }
    
}

void depositWithdraw(int n, int option){
    BankAccount ac;
    fstream file("bank.dat", ios::binary | ios::in | ios::out);
    bool found = false;

    while (!file.eof() && !found){
       int pos = file.tellg();
       file.read(reinterpret_cast<char *>(&ac), sizeof(BankAccount));
       if(ac.getAccNo() == n){
         ac.showAccount();
         double amt;
         if(option == 1){ //deposit
            cout << "\nEnter deposit ammount : ";
            cin >> amt;
            ac.deposit(amt);
         }else if(option == 2){   //withdraw
            cout << "\nEnter withdraw amount : ";
            cin >> amt;
            ac.withdraw(amt);
         }
         file.seekg(pos);
         file.write(reinterpret_cast<char *>(&ac), sizeof(BankAccount));
         cout << "\nTransaction completed.\n";
         found = true;
        }
   }
   file.close();
   if(!found)
   cout << "\nAccount not found!\n";
     
}
void displayAll() {
    BankAccount ac;
    ifstream inFile("bank.dat", ios::binary);
    cout << "\n\n\t\tACCOUNT HOLDER LIST\n\n";
    cout << "=====================================================\n";
    cout << "A/c no." << setw(20) << "NAME" << setw(15) << "BALANCE\n";
    cout << "=====================================================\n";
    while (inFile.read(reinterpret_cast<char *>(&ac), sizeof(BankAccount))) {
        ac.report();
    }
    inFile.close();
}

void deleteAccount(int n) {
    BankAccount ac;
    ifstream inFile("bank.dat", ios::binary);
    ofstream outFile("temp.dat", ios::binary);

    while (inFile.read(reinterpret_cast<char *>(&ac), sizeof(BankAccount))) {
        if (ac.getAccNo() != n) {
            outFile.write(reinterpret_cast<char *>(&ac), sizeof(BankAccount));
        }
    }
    inFile.close();
    outFile.close();
    remove("bank.dat");
    rename("temp.dat", "bank.dat");
    cout << "\nAccount Deleted Successfully.\n";
}

// ===== Main Menu =====
int main() {
    int choice, num;
    do {
        cout << "\n\n===== BANK MANAGEMENT SYSTEM =====\n";
        cout << "1. Create Account\n";
        cout << "2. Deposit Amount\n";
        cout << "3. Withdraw Amount\n";
        cout << "4. Balance Enquiry\n";
        cout << "5. All Account Holder List\n";
        cout << "6. Delete Account\n";
        cout << "7. Exit\n";
        cout << "Select Your Option (1-7): ";
        cin >> choice;

        switch (choice) {
        case 1:
            writeAccount();
            break;
        case 2:
            cout << "\nEnter Account Number: ";
            cin >> num;
            depositWithdraw(num, 1);
            break;
        case 3:
            cout << "\nEnter Account Number: ";
            cin >> num;
            depositWithdraw(num, 2);
            break;
        case 4:
            cout << "\nEnter Account Number: ";
            cin >> num;
            displayAccount(num);
            break;
        case 5:
            displayAll();
            break;
        case 6:
            cout << "\nEnter Account Number: ";
            cin >> num;
            deleteAccount(num);
            break;
        case 7:
            cout << "\nThanks for using Bank Management System!\n";
            break;
        default:
            cout << "\nInvalid choice! Try again.\n";
        }
    } while (choice != 7);

   return 0;
}
