#include<bits/stdc++.h>
using namespace std;
const int N = 510;
const int M = 100010;

int n1, n2, m;
bool st[N];
int match[N];
int h[N], e[M], ne[M], idx;
void add(int a, int b){
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++;
}
bool find(int x){
    for(int i = h[x]; i != -1; i = ne[i]){
        int j = e[i];
        if(!st[j]){ //
            st[j] = true;
            if(!match[j] || find(match[j])){
                match[j] = x;
                return true;
            }
        }
    }
    return false;
}
// [二分图的最大匹配]
int main(){
    memset(h, -1, sizeof(h));
    cin >> n1 >> n2 >> m;
    while(m --){
        int x, y;
        cin >> x >> y;
        add(x, y);
    }
    int res = 0;
    for(int i = 1; i <= n1; ++ i){
        memset(st, false, sizeof(st));
        if(find(i)) res ++;
    }
    cout << res;
    return 0;
}