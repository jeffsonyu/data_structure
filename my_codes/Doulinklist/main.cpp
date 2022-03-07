#include <iostream>
#include "DList.h"

int main(){
    DList<int> aL(50);
    aL.append(1);
    aL.append(2);
    aL.append(3);
    aL.append(4);
    aL.append(5);
    aL.print();

    aL.insertPos(100, 0);
    aL.print();
    
    aL.removePos(5);
    int a = aL.getValuePos(2);
    aL.print();
    cout << "The 2th element is: " << a << endl;

    return 0;
}