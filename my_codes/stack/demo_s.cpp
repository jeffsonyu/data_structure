#include "stack.hh"
#include <iostream>

using namespace std;

int main(){
    
    stack<int> S(50);
    S.append(1);
    S.append(2);
    S.append(3);
    S.append(4);
    S.append(5);

    S.print();
    S.append(100);
    S.print();

    S.pop();
    S.print();
    
    return 0;
}