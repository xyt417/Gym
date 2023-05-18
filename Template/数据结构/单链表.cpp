const int N = 100010;

// ############# 单链表 ###############
int head, e[N], ne[N], idx;
// 初始化
void init(){
    head = -1;
    idx = 0;
}
// 头插
void insert(int a){
    e[idx] = a, ne[idx] = head, head = idx ++;
}
// 头删
void remove(){
    head = ne[head];
}
