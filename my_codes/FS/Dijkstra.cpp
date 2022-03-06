#include <iostream>

using namespace std;

#define N 7

int M[N][N] = {{0, 3, 5, 0, 4, 0, 0},
               {3, 0, 0, 2, 0, 1, 0},
               {5, 0, 0, 0, 0, 0, 9},
               {0, 2, 0, 0, 0, 0, 0},
               {4, 0, 0, 0, 0, 1, 0},
               {0, 1, 0, 0, 1, 0, 0},
               {0, 0, 9, 0, 0, 0, 0}};

int main(){
    int P[N+1] = {100000, 10000, 10000, 10000, 10000, 10000, 10000, 10000};
    int visit[N+1] = {0, 1, 1, 1, 1, 1, 1, 1};
    int chemin[N+1] = {0, };

    int x0 = 1;
    P[x0] = 0;

    for (int i = 1; i <= N; i++){
        int s = 0;
        for (int j = 1; j <= N; j++){
            if (P[s] >= P[j] && visit[j]) s = j;
        }
        visit[s] = 0;
        for (int k = 1; k <= N; k++){
            if (M[s-1][k-1] && visit[k]){
                if (P[k] > P[s] + M[s-1][k-1]){
                    P[k] = P[s] + M[s-1][k-1];
                    chemin[k] = s;
                }
            }
        }
    }


    for (int i = 1; i <= N; i++){
        cout << P[i] << " " << chemin[i] << endl;
    }

    return 0;
}