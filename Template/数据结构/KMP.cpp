// [831.KMP字符串]
#include<bits/stdc++.h>
using namespace std;

int ne[100010];
char s[1000010], p[100010];
int main(){
    int n, m;
    cin >> m >> p + 1;
    cin >> n >> s + 1;
    vector<int> ans;
    // ################### KMP #######################
    // 求模式串Next数组
    for(int i = 2, j = 0; i <= m; ++ i){
        while(j && p[i] != p[j + 1]) j = ne[j];
        if(p[i] == p[j + 1]) ++ j;
        ne[i] = j;
    }
    // 匹配
    for(int i = 1, j = 0; i <= n; ++ i){
        while(j && s[i] != p[j + 1]) j = ne[j];
        if(s[i] == p[j + 1]) ++ j;
        if(j == m){
            // 匹配成功后操作
            ans.push_back(i - j);
            j = ne[j];
        }
    }
    for(int pos : ans) cout << pos << " ";
    return 0;
}