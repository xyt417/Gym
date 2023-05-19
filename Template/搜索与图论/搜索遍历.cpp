#include<bits/stdc++.h>
using namespace std;
const int N = 100010;
const int M = 100010;
int e[2 * M], ne[2 * M], h[N], idx; // 注: 无向图的边数是有向图的两倍，M条无向边邻接表得开 2M
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
int weight = 2e9; // 重心分割最大连通块节点数
int n; // 节点数
int center; // 重心
int dfs(int u){
    st[u] = true;
    int childnodes; // 子树节点数
    int nnodes = 1; // 当前节点为根的树的节点数
    int maxn = 0; // 以当前节点为分割点的最大连通块节点数
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