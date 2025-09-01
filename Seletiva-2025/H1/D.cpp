#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define all(a) a.begin(), a.end()
#define pll pair<ll, ll>
#define pii pair<int, int>
#define vi vector<int>
#define MOD 1000000007
#define loop(x, s, n) for(int x = s; x < n; x++)

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, q; cin >> n >> q;
    string s; cin >> s;
    vi ps(n + 1);
    loop(i, 0, n) {
        ps[i + 1] = ps[i] + (s[i] == s[i + 1]);
    }
    loop(i, 0, q) {
        int l, r; cin >> l >> r; l--; r--;
        cout << ps[r] - ps[l] << '\n';
    }
}