// 离散化 [802.区间和]
#include <bits/stdc++.h>
using namespace std;
const int N = 300010;
typedef pair<int, int> PII;
int n, m;
int a[N], s[N];
vector<int> alls;
vector<PII> add, query;
int find(int x){
    int l = 0, r = alls.size();
    while(l < r){
        int mid = l + r >> 1;
        if(alls[mid] >= x) r = mid;
        else l = mid + 1;
    }
    return l;
}
int main(){
    cin >> n >> m;
    for(int i = 0; i < n; ++ i){
        int x, c;
        cin >> x >> c;
        add.push_back({x, c});
        alls.push_back(x);
    }
    for(int i = 0; i < m; ++ i){
        int l, r;
        cin >> l >> r;
        query.push_back({l, r});
        alls.push_back(l);
        alls.push_back(r);
    }
    // 去重
    sort(alls.begin(), alls.end());
    alls.erase(unique(alls.begin(), alls.end()), alls.end());
    for(PII ADD : add){
        a[find(ADD.first) + 1] += ADD.second;
    }
    for(int i = 1; i <= alls.size(); ++ i){
        s[i] = s[i - 1] + a[i];
    }
    for(PII Q : query){
        cout << s[find(Q.second) + 1] - s[find(Q.first)] << '\n';
    }
    return 0;
}