#include <bits/stdc++.h>
using namespace std;
#define ll long long
void solve() {
    int K;
    cin >> K;
    vector<pair<int,int>> cnt(K);
    for (int i = 0; i < K; i++) {
        cin >> cnt[i].first;
        cnt[i].second = i + 1;
    }
    priority_queue<pair<int,int>> pq;
    for (int i = 0; i < K; i++) pq.push({cnt[i].first, cnt[i].second});
    while(!pq.empty()) {
        auto [freq, idx] = pq.top();
        pq.pop();

        cout << idx << ' ';
        freq--;

        if (pq.size() > 0) {
            auto [freq2, idx2] = pq.top();
            pq.pop();
            cout << idx2 << ' ';
            freq2--;
            if (freq2 > 0) {
                pq.push({freq2, idx2});
            }
        }

        if (freq > 0) {
            pq.push({freq, idx});
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;  // cin >> T;
    while (T--) solve();
}
