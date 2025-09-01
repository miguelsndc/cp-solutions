#include <bits/stdc++.h>

using namespace std;

#define ll long long int
#define ld long double
#define MOD 1000000007
#define ii pair<ll, ll>
#define vi vector<ll>
#define vii vector<ii>

void solve() {
    ll h, n; cin >> h >> n;
    vi a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];

    priority_queue<ii, vector<ii>, greater<ii>> pq;
    for (int i = 0; i < n; i++) {
        pq.push({1, i});
    }
    ll last_turn = 1;
    while(h > 0) {
        auto [turn, i] = pq.top(); pq.pop();
        h -= a[i];
        last_turn = turn;
        if (last_turn < 0) {
            int a =2;
        }
        pq.push({ turn + b[i], i});
    }
    cout << last_turn << '\n';
}

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1; cin >> tt;
    while(tt--) {
         solve();
    }
}