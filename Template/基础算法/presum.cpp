#include<bits/stdc++.h>
using namespace std;
#define SIZE 100010

int presum[SIZE];
int main(){
    int n, m, k;
    cin >> n >> m;
    for(int i = 1; i <= n; ++ i){
        cin >> k;
        presum[i] = presum[i - 1] + k;
    }
    while(m --){
        int l, r;
        cin >> l >> r;
        cout << presum[r] - presum[l - 1] << '\n';
    }
    return 0;
}