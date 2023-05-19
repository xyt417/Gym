#include<bits/stdc++.h>
using namespace std;
const int N = 100010;
int e[N], ne[N], h[N], idx;
int st[N];
void add(int a, int b){
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++;
}
// 深度优先遍历
int DFS(int u){
    st[u] = true; // 标记u已经被遍历过
    for(int i = h[u]; i != -1; i = ne[i]){
        int j = e[i];
        if(!st[j]) DFS(j);
    }
}
// 广度优先遍历
int BFS(int u){
    queue<int> q;
    st[u] = true; // 标记u已经被遍历过
    q.push(u);
    while(q.size()){
        u = q.front();
        q.pop();
        for(int i = h[u]; i != -1; i = ne[i]){
            int j = e[i];
            if(!st[j]){
                st[j] = true; // 标记j已经被遍历过
                q.push(j);
            }
        }
    }
}
// [846.树的重心]
int weight = 2e9;
//重心
int n;
int center;
int dfs(int u){
    st[u] = true;
    int childnodes;
    int nnodes = 1;
    int maxn = 0;
    for(int i = h[u]; i != -1; i = ne[i]){
        int j = e[i];
        if(st[j] != true){
            st[j] = true;
            childnodes = dfs(j);
            maxn = max(maxn, childnodes);
            nnodes += childnodes;
        }
    }
    maxn = max(n - nnodes, maxn);
    if(maxn < weight){
        weight = maxn;
        center = u;
    }
    return nnodes;
}
int main(){
    memset(h, -1, sizeof(h)); //init
    cin >> n;
    int root;
    for(int i = 0; i < n - 1; ++ i){
        int a, b;
        cin >> a >> b;
        add(a, b), add(b, a);
        root = a;
    }
    dfs(root);
    cout << weight << endl;
    return 0;
}