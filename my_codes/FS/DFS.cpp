#include<iostream>
#include<stack>

using namespace std;

#define N 7
int M[N][N] = {{0, 1, 1, 0, 1, 0, 0},
               {1, 0, 0, 1, 0, 1, 0},
               {1, 0, 0, 0, 0, 0, 1},
               {0, 1, 0, 0, 0, 0, 0},
               {1, 0, 0, 0, 0, 1, 0},
               {0, 1, 0, 0, 1, 0, 0},
               {0, 0, 1, 0, 0, 0, 0}};

int main(){

    stack<int> S;
    int x0 = 1;
    S.push(x0);
    int visited[N+1] = {0, };

    while (!S.empty()){
        int s = S.top();
        S.pop();
        
        if (!visited[s]){
            cout << s << " ";
            visited[s] = 1;
            for (int i = 1; i <= N; i++){
                if (M[s-1][i-1]){
                    S.push(i);
                }
            }
        }

    }
    cout << endl;

    return 0;
}