#include <bits/stdc++.h>

using namespace std;

#define ll long long int
#define ld long double
#define MOD 1000000007
#define ii pair<int, int>
#define vi vector<int>
#define vii vector<ii>

void setIO(string s) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

void solve() {
    int n; cin >> n;
    vii v(n / 2);
    for (int i = 0; i < n / 2; i++) {
        int a, b; cin >> a >> b;
        if (a > b) swap(a, b);
        v[i] = {a, b};
    }
    sort(begin(v), end(v));
    vi seen(n / 2), aux;
    int mx = -1;
    for (int i = 0 ; i < n / 2; i++) {
        if (v[i].first >= mx) {
            mx = v[i].first;
            aux.push_back(v[i].first);
            aux.push_back(v[i].second);
            mx = v[i].second;
            seen[i] = true;
        }
    }
    int mn = 1e9 + 1;
    for (int i = n/2 - 1 ; i >= 0; i--) {
        if (!seen[i] && v[i].second <= mn) {
            mn = v[i].first;
            aux.push_back(v[i].second);
            aux.push_back(v[i].first);
            mn = v[i].first;
            seen[i] = true;
        }
    }

    if (find(begin(seen), end(seen), false) != end(seen)) {
        cout << -1;
    } else {
        for (int c: aux) {
            cout << c << ' ';
        }
    }
}

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1; // cin >> tt;
    while(tt--) {
         solve();
    }
}