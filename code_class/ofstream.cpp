#include<iostream>
#include<fstream>

using namespace std;

int main(){
    int num;
    ifstream fin;
    ofstream fout;
    fin.open("in.txt");
    fout.open("out.txt");

    while(fin >> num){
        fout << num+1 << endl;
    }

    fin.close();
    fout.close();

    cout << "Finish!" << endl;
    return 0;
}