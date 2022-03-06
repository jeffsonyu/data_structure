#include "queue.hh"
#include <iostream>

using namespace std;

int main(){
    
    queue<int> Q(50);
    Q.appendleft(1);
    Q.appendleft(2);
    Q.appendleft(3);
    Q.appendleft(4);
    Q.appendleft(5);

    Q.print();
    Q.appendleft(100);
    Q.print();

    Q.pop();
    Q.print();
    
    return 0;
}