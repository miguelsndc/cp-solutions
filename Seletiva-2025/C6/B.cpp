#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define MOD 1000000007
#define ii pair<int, int>
#define fi first
#define se second

void solve() {
    int n; cin >> n;
    vector<int> v(n);
    for (int &x:v)cin>>x;
    vector<int> a = v;
    sort(begin(a), end(a));
    int l = 0, r = n - 1;
    int ans = -1;
    // menor cara que consegue comer todo mundo
    // quando achar se o ai >= menor, da
    while(l <= r) {
        int m = l + (r - l) / 2;
        bool can = true;
        ll t = a[m];
        for (int i = 0; i < n && can; i++) {
            if (i != m) {
                if (t <= a[i]) can = false;
                else t += a[i];
            }
        }
        if (can) {
            ans = m;
            r = m - 1;
        } else {
            l = m + 1;
        }
    }
    for (int i = 0; i < n; i++) {
        if (ans != -1 && v[i] >= a[ans]) {
            cout << "T";
        } else {
            cout << "N";
        }
    }
}

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1; // cin >> tt;
    for (int t = 1; t <= tt; t++) {
        solve();
    }
}