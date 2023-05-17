// [803.区间合并]
#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> PII;
const int _inf = -2e9;
int n;
vector<PII> merge(vector<PII> &segs){
    vector<PII> res;
    sort(segs.begin(), segs.end());
    int st = _inf, ed = _inf;
    for(PII seg : segs){
        if(ed < seg.first){
            if(st != _inf) res.push_back({st, ed});
            st = seg.first, ed = seg.second;
        }
        else ed = max(ed, seg.second);
    }
    if(st != _inf) res.push_back({st, ed});
    return res;
}
int main(){
    cin >> n;
    vector<PII> segs;
    while(n --){
        PII seg;
        cin >> seg.first >> seg.second;
        segs.push_back(seg);
    }
    // segs = merge(segs);
    // for(PII seg : segs){
    //     cout << "[" << seg.first << ',' << seg.second << "]" << '\n';
    // }
    cout << merge(segs).size();
    return 0;
}