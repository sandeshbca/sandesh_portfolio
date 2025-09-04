#include<iostream>
using  namespace std;
class student {
    private :
    int rollno;
    string name, subject[5];
    int marks[5],total;
    double percentage;

    public:
    void inputdata(){
        cout << "\nEnter the rollno : ";
        cin >>rollno;
        cout << "\nEnter the name : ";
        cin >>name;
        cout << "\nEnter the 5 subject : ";
        for(int i=0; i<5; i++){
            cout << "\nsubject " << i+1 << ": ";
           cin >>subject[i];
        }
        cout << "\nEnter the marks for subject : ";
        total = 0;
        for(int i=0; i<5; i++){
            cout << "\nmarks In " << subject[i] << " : ";
          cin >>marks[i];
          total +=marks[i];
        }
        percentage = total*100/500;
         
        
    }

    void displaydata(){
         cout  << "\n=========Student Details==========\n";
         cout << "\nRollno : " << rollno;
         cout << "\nName : " << name;
         cout << "\nStudent marks :\n ";
         for(int i=0; i<5; i++){
            cout << subject[i] << " : " << marks[i] << endl;
         }
         cout << "\nTotal marks : " << total;
         cout << "\nPercentage : " << percentage << " % " << endl;
    }

};

 int main(){
    student s1;
    s1.inputdata();
    s1.displaydata();

    return 0;
 }
