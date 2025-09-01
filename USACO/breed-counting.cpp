#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MOD 1000000007
#define INF 1000000009

int main() 
{
    freopen("bcount.in", "r", stdin);
    freopen("bcount.out", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, q; cin >> n >> q;
    vector<int> c1(n + 1), c2(n + 1), c3(n + 1);
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        c1[i + 1] = c1[i] + (x == 1);
        c2[i + 1] = c2[i] + (x == 2);
        c3[i + 1] = c3[i] + (x == 3);
    }
    for (int i = 0; i < q; i++) {
        int l, r; cin >> l >> r;
        cout << c1[r] - c1[l-1] << ' ' << c2[r] - c2[l-1] << ' ' << c3[r] - c3[l-1] << '\n';
    }
}