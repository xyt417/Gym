#include<bits/stdc++.h>
using namespace std;
// ################# 高精度加法 #####################
string Add(string s1, string s2){
    int n=s1.size(), m=s2.size();
    string res;
    int t=0;
    for(int i=n-1, j=m-1; i>=0||j>=0||t; i--, j--){
        if(i>=0) t+=s1[i]-'0';
        if(j>=0) t+=s2[j]-'0';
        res.push_back(t%10+'0');
        t/=10;
    }
    reverse(res.begin(), res.end());
    return res;
}
// ###############################################
// #################### Test #####################
int main(){
    string s1, s2; 
    cin>>s1>>s2;
    cout<<Add(s1, s2);
    return 0;
}
// ###############################################