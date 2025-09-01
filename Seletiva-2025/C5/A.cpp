#include <bits/stdc++.h>

using namespace std;

#define ll long long int
#define ld long double
#define MOD 1000000007
#define ii pair<int, int>
#define vi vector<int>
#define vii vector<ii>

int f(int n, vi v, vi &orig, int mod) {
    bool sorted = true;
    int cnt = 0;
    for (int i = 0; i < max(2 * n, 4); i++) {
        if (i % 2 == mod) {
            for (int i = 0; i < 2 * n - 1; i+=2) {
                swap(v[i], v[i + 1]);
            }
        } else {
            for (int i = 0; i < n; i++) {
                swap(v[i], v[i + n]);
            }
        }
        cnt++;

        sorted = true;
        int mx = v[0];
        for (int i = 1; i < 2 * n; i++) {
            if (v[i] > mx) {
                mx = v[i];
            } else {
                sorted = false;
                break;
            }
        }

        if (sorted) break;
    }

    return (sorted ? cnt : -1);
}

void solve() {
    int n; cin >> n;
    vi v(2 * n);
    for (int i = 0; i < 2 * n; i++) {
        cin >> v[i];
    }

    int cnt = 0;
    bool sorted = true;
    int mx = v[0];
    for (int i = 1; i < 2 * n; i++) {
        if (v[i] > mx) mx = v[i];
        else sorted = false;
    }

    if (sorted) {
        cout << 0;
        return;
    }

    int ans = f(n, v, v, 0);
    int ans2 = f(n, v, v, 1);

    if (ans != -1 && ans2 != -1) {
        cout << min(ans, ans2);
    } else {
        cout << max(ans, ans2);
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