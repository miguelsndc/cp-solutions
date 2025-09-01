#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MOD 1000000007
#define INF 1000000009

void solve() {
    int n; cin >> n;
    vector<pair<int, int>> times;
    for (int i = 0; i < n; i++) {
        int a, b; cin >> a >> b;
        times.push_back({a, 1});
        times.push_back({b, -1});
    }
    sort(begin(times), end(times));
    ll maxs = 0, sum = 0;
    for (const auto &[k, v]: times) {
        sum += v;
        maxs = max(maxs, sum);
    }
    cout << maxs;
}

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1; 
    while(tt--) {
         solve();
    }
}