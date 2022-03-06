#include<iostream>
#include<queue>

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

    queue<int> Q;
    int x0 = 1;
    Q.push(x0);
    int visited[N+1] = {0, };

    visited[x0] = 1;

    while (!Q.empty()){
        int s = Q.front();
        cout << s << " ";
        Q.pop();
        for (int i = 1; i <= N; i++){
            if (!visited[i] && M[s-1][i-1]){
                visited[i] = 1;
                Q.push(i);
            }
        }
    }

    cout << endl;
    return 0;
}
