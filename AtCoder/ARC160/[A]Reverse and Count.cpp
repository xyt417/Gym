#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

// [complexity:O(n^2)]
int main(){
    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    for(auto &x : A) cin >> x;

    int a = 1, b = N * (N + 1) / 2;
    for(int i = 0; i < N; ++ i){
        vector<int> small, large;
        for(int j = i + 1; j < N; ++ j){
            if(A[j] > A[i]) large.push_back(A[j]);
            else small.push_back(A[j]);
        }
        int x = -1;
        if(K - a < small.size()){
            sort(begin(small), end(small));
            x = small[K - a];
        }
        if(b - K < large.size()){
            sort(begin(large), end(large));
            reverse(begin(large), end(large));
            x = large[b - K];
        }
        if(x != -1){
            int j = i;
            while(A[j] != x) ++ j;
            reverse(begin(A) + i, begin(A) + j + 1);
        }
        a += small.size();
        b -= large.size();
    }
    for(int i = 0; i < N; ++ i) cout << A[i] << " \n"[i + 1 == N];
    return 0;
}


// ###### Naive[complexity:O(n^3logn)] ######
// int n, m;
// vector<int> q;
// vector<vector<int> > seqs;
// int compare(vector<int> seq1, vector<int> seq2){
//     if(seq1.size() != seq2.size()) return seq1 < seq2;
//     for(int i = 0; i < seq1.size(); ++ i){
//         if(seq1[i] != seq2[i]) return seq1[i] < seq2[i];
//     }
//     return 0;
// }
// void reverse(vector<int> &seq, vector<int> &q, int l, int r){
//     for(int i = 0; i < n; ++ i){
//         seq.push_back(q[i]);
//     }
//     for(int i = l, j = r; i < j; ++ i, -- j){
//         swap(seq[i], seq[j]);
//     }
// }
// int main(){
//     cin >> n >> m;
//     for(int i = 0; i < n; ++ i){
//         int x;
//         cin >> x;
//         q.push_back(x);
//     }
//     for(int i = 0; i < n; ++ i){
//         for(int j = i; j < n; ++ j){
//             vector<int> seq;
//             reverse(seq, q, i, j);
//             seqs.push_back(seq);
//         }
//     }
//     sort(seqs.begin(), seqs.end(), compare);
//     for(int i = 0; i < seqs[m - 1].size(); ++ i){
//         if(i) cout << " ";
//         cout << seqs[m - 1][i];
//     }
//     return 0;
// }