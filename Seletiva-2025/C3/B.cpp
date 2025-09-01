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
    int n, m; cin >> n >> m;
    vi v(100005);
    loop(i, 0, m) {
        int l, r; cin >> l >> r;
        v[l]++; v[r+1]--;
    } 
    loop(i, 1, n + 1) {
        v[i] += v[i - 1];
    }
    int c = 0;
    loop(i, 0, n + 1) {
        if(v[i] >= m) c++;
    }
    cout << c;
}