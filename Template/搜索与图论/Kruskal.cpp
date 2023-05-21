#include<bits/stdc++.h>
using namespace std;
const int N = 10010;

int p[N];
int n, m;

struct Edge{
    int a, b, w;
    bool operator<(Edge &W){
        return w < W.w;
    }
}edges[N];

int find(int x){
    if(x != p[x]) return find(p[x]);
    return x;
}

int kruskal(){
    
}