#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define pii pair<int, int>
#define pll pair<long long, long long>
#define vi vector<int>
#define vb vector<bool>
#define vs vector<string>
#define vll vector<long long>
#define mii map<int, int>
#define si set<int>
#define sc set<char>
#define f first
#define s second
#define sp << " " <<
#define spe << " "

// i should use the chesse with most deliciouness until it's over
// then i take the next most delicious one and so on and so forth
// until either we run out of cheese or we reach maximum grams
// try sorting + greedy - select the greastest amount from the current best cheese

void solve(ll n, ll w) {
    vector<pll> c(n);
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        c[i] = {a, b};
    }
    sort(c.rbegin(), c.rend());
    ll amount = 0;
    for (auto &[del, am] : c) {
        amount += min(am, w) * del;
        w -= min(am, w);
        if (w == 0) {
            break;
        }
    }
    cout << amount << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n, w;
    cin >> n >> w;
    solve(n, w);
    return 0;
}