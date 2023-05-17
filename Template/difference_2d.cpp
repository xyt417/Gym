// difference_2d [798]
#include <bits/stdc++.h>
using namespace std;
int M[1010][1010];
int D[1010][1010];
int main(){
    int n, m, q;
    for(int i = 1; i <= n; ++ i){
        for(int j = 1; j <= m; ++ j){
            cin >> M[i][j];
        }
    }
    for(int i = 1; i <= n; ++ i){
        for(int j = 1; j <= m; ++ j){
            D[i][j] = M[i][j] - M[i - 1][j] - M[i][j - 1] + M[i - 1][j - 1];
        }   
    }
    while(q --){
        int x1, x2, y1, y2, c;
        cin >> x1 >> y1 >> x2 >> y2 >> c;
        D[x1][y1] += c;
        D[x2 + 1][y1] -= c;
        D[x1][y2 + 1] -= c;
        D[x2 + 1][y2 + 1] += c;
    }
    for(int i = 1; i <= n; ++ i){
        for(int j = 1; j <= m; ++ j){
            M[i][j] = M[i - 1][j] + M[i][j - 1] - M[i - 1][j - 1] + D[i][j];
        }
    }
    for(int i = 1; i <= n; ++ i){
        for(int j = 1; j <= m; ++ j){
            cout << M[i][j] << " ";
        }
    }
    return 0;
}