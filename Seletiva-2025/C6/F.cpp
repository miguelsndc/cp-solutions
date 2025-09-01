#include <bits/stdc++.h>

using namespace std;

#define ll long long int
#define ld long double
#define MOD 1000000007
#define ii pair<int, int>
#define vi vector<int>
#define vii vector<ii>

void solve() {
    int n, m; cin >> n >> m;
    vi v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    struct s {
        int v, time, pos;
        s() {}
        s(int a, int b, int c): v(a), time(b), pos(c) {}
    };

    vector<s> vs(n);
    for (int i = 0; i < n; i++) {
        int time = int((v[i] / m)) + 1 - (v[i] % m == 0);
        vs[i] = {v[i], time, i};
    }
    stable_sort(begin(vs), end(vs), [] (auto a, auto b) { return a.time < b.time;});
    for (int i = 0; i < n; i++) {
        cout << vs[i].pos + 1 << ' ';
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