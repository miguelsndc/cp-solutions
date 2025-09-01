#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define all(a) a.begin(), a.end()
#define pll pair<ll, ll>
#define pii pair<int, int>
#define vi vector<int>

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    vi v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    sort(all(v));
    v.resize(unique(all(v)) - v.begin());
    cout << v[v.size() - 2];
}