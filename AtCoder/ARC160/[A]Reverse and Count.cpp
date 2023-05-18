#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;


// ###### Naive ######
int n, m;
vector<int> q;
vector<vector<int> > seqs;
int compare(vector<int> seq1, vector<int> seq2){
    if(seq1.size() != seq2.size()) return seq1 < seq2;
    for(int i = 0; i < seq1.size(); ++ i){
        if(seq1[i] != seq2[i]) return seq1[i] < seq2[i];
    }
    return 0;
}
void reverse(vector<int> &seq, vector<int> &q, int l, int r){
    for(int i = 0; i < n; ++ i){
        seq.push_back(q[i]);
    }
    for(int i = l, j = r; i < j; ++ i, -- j){
        swap(seq[i], seq[j]);
    }
}
int main(){
    cin >> n >> m;
    for(int i = 0; i < n; ++ i){
        int x;
        cin >> x;
        q.push_back(x);
    }
    for(int i = 0; i < n; ++ i){
        for(int j = i; j < n; ++ j){
            vector<int> seq;
            reverse(seq, q, i, j);
            seqs.push_back(seq);
        }
    }
    sort(seqs.begin(), seqs.end(), compare);
    for(int i = 0; i < seqs[m - 1].size(); ++ i){
        if(i) cout << " ";
        cout << seqs[m - 1][i];
    }
    return 0;
}