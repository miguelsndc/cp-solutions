#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MOD 1000000007
#define INF 1000000009

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, q; cin >> n >> q;
    vector<ll> numbers(n);
    for (int i = 0; i < n; i++) cin >> numbers[i];
    vector<ll> ps(n + 1);
    for(int i = 0; i < n; i++) {
        ps[i + 1] = ps[i] + numbers[i];
    }
    for (int i = 0; i < q; i++) {
        ll l, r; cin >> l >> r;
        cout << ps[r] - ps[l] << '\n';
    }
}