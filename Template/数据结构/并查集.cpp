const int N = 100010;
// ############## 朴素并查集 ##############
int p[N]; // 存储每个点的根节点
int init(int n){ // 初始化 编号为: 1 ~ n
    for(int i = 1; i <= n; ++ i) p[i] = i;
}
int find(int x){ // 返回x的根节点
    if(p[x] != x) p[x] = find(p[x]);
    return p[x];
}
void merge(int a, int b){ // 合并a和b所在的两个集合
    p[find(a)] = find(b);
}

// ############## 维护size的并查集 ##############
int p[N], size[N]; // p[]存储每个点的根节点，size[]只有根节点的有意义，表示根节点所在集合中点的数量
int init(int n){ // 初始化 编号为: 1 ~ n
    for(int i = 1; i <= n; ++ i) p[i] = i, size[i] = 1;
}
int find(int x){ // 返回x的根节点
    if(p[x] != x) p[x] = find(p[x]);
    return p[x];
}
void merge(int a, int b){ // 合并a和b所在的两个集合
    p[find(a)] = find(b);
    size[find(b)] += size[find(a)];
}

// ############## 维护到根节点距离的并查集 ##############
int p[N], d[N]; // p[]存储每个点的根节点，d[x]存储x到p[x]的距离
int init(int n){ // 初始化 编号为: 1 ~ n
    for(int i = 1; i <= n; ++ i) p[i] = i, d[i] = 0;
}
int find(int x){ // 返回x的根节点
    if(p[x] != x){
        d[x] += d[p[x]];
        p[x] = find(p[x]);
    }
    return p[x];
}