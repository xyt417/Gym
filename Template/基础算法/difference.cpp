// differnece [797]
#include<bits/stdc++.h>
using namespace std;
int q[100010];
int d[100010];
int main(){
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; ++ i){
        cin >> q[i];
    }
    for(int i = 1; i <= n; ++ i){
        d[i] = q[i] - q[i - 1];
    }
    while(m --){
        int l, r, c;
        cin >> l >> r >> c;
        d[l] += c; 
        d[r + 1] -= c;
    }   
    for(int i = 1; i <= n; ++i){
        q[i] = q[i - 1] + d[i];
    }
    for(int i = 1; i <= n; ++ i){
        cout << q[i] << " ";
    }
    return 0;
}