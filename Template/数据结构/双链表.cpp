const int N = 100010;

// ############# 双链表 ###############
int e[N], l[N], r[N], idx;
// 初始化
void init(){
    r[0] = 1, l[1] = 0;
    idx = 2;
}
// 在节点a右端插入值
void insert(int a, int x){
    e[idx] = x;
    l[idx] = a, r[idx] = r[a]; 
    l[r[a]] = idx, r[a] = idx ++;
}
// 删除节点a
void remove(int a){
    l[r[a]] = l[a];
    r[l[a]] = r[a];
}