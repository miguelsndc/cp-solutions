#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
void solve() {
    int N; cin >> N;
    string S; cin >> S;
    vector<int> v;
    for (int i = 0; i < N; i++) {
        int val = (S[i] == '1');
        if (v.empty()) {
            v.push_back(val);
            continue;
        }
        if (val != v.back()) {
            v.push_back(val);
        }
    }
    int cnt1 = count(v.begin(), v.end(), 1);
    int cnt0 = v.size() - cnt1;
    cout << min(cnt1, cnt0) << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1; // cin >> T;
    while(T--) solve();
}