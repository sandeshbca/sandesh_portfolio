#include<iostream>
#include<fstream>
#include<string>
using namespace std;
/*int main(){
    ofstream out;
    out.open("file.txt");
    out<<"this is me\n";
    out<<"this is me\n";
    out<<"this is me\n";
    out<<"this is me\n";
    out.close();

    ifstream in;
    in.open("file.txt");
    string st;
    //in>>st;
    //cout<<st;
    while(in.eof()==0){
        getline(in, st);
        cout<<st<<endl;
    }
    in.close();

    return 0;

}*/

int main(){
    char ch;
    fstream file;
    file.open("file.txt", ios::in);
  while(file.get(ch)){
        
        cout<<ch;
    }
    cout<<endl;
    return 0;
}