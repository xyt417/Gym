#include<bits/stdc++.h>
using namespace std;
#define SIZE 100010

int a[SIZE], s[SIZE]; // hash
int main(){
    int n, ans = 0;
    cin >> n;
    for(int i = 0, j = 0; i < n; ++ i){
        cin >> a[i];
        ++ s[a[i]];
        while(s[a[i]] > 1) -- s[a[j ++]];
        ans = max(ans, i - j + 1);
    }
    cout << ans;
    return 0;
}