#include<bits/stdc++.h>
using namespace std;

// ################# 高精度加法 #####################
string Add(string s1, string s2){
    string res;
    int len1 = s1.length(), len2 = s2.length();
    int len = max(len1, len2);
    int c = 0;
    for(int i = 0; i < len; ++ i){
        int a = 0, b = 0;
        if(i < len1) a = s1[len1 - i - 1] - '0';
        if(i < len2) b = s2[len2 - i - 1] - '0';
        c = a + b + c;
        res += c % 10 + '0';
        c /= 10;
    }
    if(c) res += c + '0';
    reverse(res.begin(), res.end());
    return res;
}
// #################################################

// ################# 高精度减法 #####################
// 输入默认无先导0
int Cmp(string s1, string s2){
    if(s1.length() != s2.length()) return s1.length() > s2.length();
    for(int i = 0; i < s1.length(); ++ i)
        if(s1[i] != s2[i])
            return s1[i] > s2[i];
    return 1; // 相等
}
// s1 >= s2
string Sub(string s1, string s2){
    if(!Cmp(s1, s2)) return '-' + Sub(s2, s1);
    int len1 = s1.length(), len2 = s2.length();
    string res;
    int c = 0;
    for(int i = 0; i < len1; ++ i){
        int a = 0, b = 0;
        if(i < len1) a = s1[len1 - i - 1] - '0';
        if(i < len2) b = s2[len2 - i - 1] - '0';
        c = a - b - c;
        res += (c + 10) % 10 + '0';
        c = c < 0 ? 1 : 0; // 是否借1
    }
    while(res.length() > 1 && res.back() == '0') res.pop_back(); // 去除先导0
    reverse(res.begin(), res.end());
    return res;
}
// #################################################

// ############# 高精度乘法(大数 x 小数) ############
string Mul(string s, int n){
    string res;
    int len = s.length();
    int c = 0;
    for(int i = 0; i < len || c; ++ i){
        int a = 0;
        if(i < len) a = s[len - i - 1] - '0';
        c = a * n + c;
        res += c % 10 + '0';
        c /= 10;
    }
    while(res.length() > 1 && res.back() == '0') res.pop_back(); // 去除先导0
    reverse(res.begin(), res.end());
    return res;
}
// #################################################

// ############# 高精度除法(大数 ÷ 小数) ############
string Div(string s, int n, int &r){
    string res;
    int len = s.length();
    r = 0;
    for(int i = 0; i < len; ++ i){
        r = r * 10 + s[i] - '0';
        res += r / n + '0';
        r %= n;
    }
    reverse(res.begin(), res.end());
    while(res.length() > 1 && res.back() == '0') res.pop_back(); // 去除先导0
    reverse(res.begin(), res.end());
    return res;
}
// #################################################

// #################### Test #######################
int main(){
    // ### Add & Sub ###
    // string s1, s2; 
    // cin >> s1 >> s2;
    // cout << Add(s1, s2) << endl;
    // cout << Sub(s1, s2) << endl;

    // ### Mul & Div ###
    string s;
    int n, r;
    cin >> s >> n;
    // cout << Mul("123", n) << endl;
    cout << Div(s, n, r) << '\n'; 
    cout << r << '\n';
    return 0;
}
// #################################################