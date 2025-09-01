#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define MOD 1000000007
#define ii pair<int, int>
#define fi first
#define se second

void solve() {
    int n, k; cin >> n >> k;
    set<int> ms;
    vector<int> freq(n + 1);
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        ms.insert(x);
        freq[x]++;
    }
    int cnt = 0;
    while(!ms.empty()) {
        auto q = ms.begin();
        auto it = ms.lower_bound(k - *q);
        if (it != end(ms) && (*it + *q) == k && (it != q || (it == q && freq[*q] >= 2))) {
            cnt++;
            freq[*it]--;
            if (freq[*it] == 0) {
                ms.erase(it);
            }
        } 
        freq[*ms.begin()]--;
        if (freq[*ms.begin()] == 0) {
            ms.erase(ms.begin());
        }
    }
    cout << cnt << '\n';
}

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1; cin >> tt;
    for (int t = 1; t <= tt; t++) {
         solve();
    }
}