#include<bits/stdc++.h>
using namespace std;
#define SIZE 1010

int M[SIZE][SIZE];
int main(){
    int n, m, q, k;
    cin >> n >> m >> q;
    for(int i = 1; i <= n; ++ i)
        for(int j = 1; j <= m; ++ j){
            cin >> k;
            M[i][j] = M[i - 1][j] + M[i][j - 1] - M[i - 1][j - 1] + k;
        }
    while(q --){
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        cout << M[x2][y2] - M[x2][y1 - 1] - M[x1 - 1][y2] + M[x1 - 1][y1 - 1] << '\n';
    }
    return 0;
}