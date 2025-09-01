#include <bits/stdc++.h>
using namespace std;
#define ll long long
int len, N;  
vector<int> ans, A;
struct Query {
    int l, r, val, idx;
    bool operator<(const Query& other) const {
        int block_a = l / len, block_b = other.l / len;
        if (block_a != block_b)
            return block_a < block_b;
        return (block_a & 1) ? (r > other.r) : (r < other.r);
    }
};

vector<int> S;
int get_ans(int val) {
    if (val == -1) return 0;
    return S[val] > 0;
}
void add(int idx) {
    S[A[idx]]++;
}
void remove(int idx) {
    S[A[idx]]--;
}

void mo(vector<Query> queries) {
    sort(queries.begin(), queries.end());
    ans.assign(queries.size(), 0);
    int cur_l = 0, cur_r = -1;
    for (Query q : queries) {
        while (cur_l > q.l) {
            cur_l--;
            add(cur_l);
        }
        while (cur_r < q.r) {
            cur_r++;
            add(cur_r);
        }
        while (cur_l < q.l) {
            remove(cur_l);
            cur_l++;
        }
        while (cur_r > q.r) {
            remove(cur_r);
            cur_r--;
        }
        ans[q.idx] = get_ans(q.val); 
    }
}
void solve() {
    cin >> N;
    A.assign(N, 0);
    S.assign(N, 0);
    len = sqrt(N + 0.);
    map<int, int> mp;
    for (int &i: A) cin >> i;
    vector<int> B = A;
    sort(B.begin(), B.end());
    for (int i = 0; i < N; i++) {
        mp[B[i]] = i;
    }
    for (int i = 0; i < N; i++) {
        A[i] = mp[A[i]];
    }
    int q; cin >> q;
    vector<Query> queries(q);
    for (int i = 0; i < q; i++) {
        int l, r, val; cin >> l >> r >> val; 
        queries[i] = {--l, --r, mp.count(val) ? mp[val]: -1, i};
    }
    mo(queries);
    for (int x: ans) {
        cout << x;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1; // cin >> T;
    while(T--) solve();
}