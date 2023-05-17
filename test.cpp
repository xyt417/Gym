#include <bits/stdc++.h>
using namespace std;
#define FOR(a, x, y) for(int a = x; a < y; ++ a)
int A[100010], B[100010];
int main(){
    int n, m, x;
    cin >> n >> m >> x;
    FOR(i, 0, n){
        cin >> A[i];
    }
    FOR(j, 0, m){
        cin >> B[j];
    }
    int i = 0, j = m - 1;
    while(i < n && j >= 0){
        int sum = A[i] + B[j];
        if(sum == x) cout << i ++ << " " << j --;
        else if(sum > x) j --;
        else i ++;
    }
    return 0;
}