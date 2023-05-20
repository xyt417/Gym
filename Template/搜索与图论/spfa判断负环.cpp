#include<bits/stdc++.h>
using namespace std;
const int N = 100010;

int h[N], e[N], w[N], ne[N], idx;
int dist[N], cnt[N];
bool st[N];
void add(int a, int b, int c){
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx ++;
}
int n, m;
// 存在负环返回true
bool spfa(){
    // dist初始化为0，不需要初始化为无穷大，这样只有负权边才会更新，负环会一直更新
    // 要判断从任意点出发的负环，且只有从负环上所有点出发才能确保存在距离不会变成正的路线，从而不会被正权边阻塞(dist初始化为0)
    queue<int> q;
    for(int i = 1; i <= n; ++ i){
        q.push(i);
        st[i] = true;
    }

    while(q.size()){
        int t = q.front();
        q.pop();
        st[t] = false;
        for(int i = h[t]; i != -1; i = ne[i]){
            int j = e[i];
            if(dist[j] > dist[t] + w[i]){ // 负权边才更新
                dist[j] = dist[t] + w[i];
                cnt[j] = cnt[t] + 1; // 记录经过的边数
                if(cnt[j] >= n) return true; // 经过n条边，即为第n+1个点，说明有负环
                if(!st[j]){
                    q.push(j);
                    st[j] = true;
                }
            }
        }
    }
    return false; // 不存在负环
}
// [SPFA判断负环]
int main(){
    memset(h, -1, sizeof(h));
    cin >> n >> m;
    while(m --){
        int x, y, z;
        cin >> x >> y >> z;
        add(x, y, z);
    }
    if(spfa()) cout << "Yes";
    else cout << "No";
    return 0;
}