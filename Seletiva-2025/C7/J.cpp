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
    int n; cin >> n;
    vector<ll> y(n);
    loop(i, 0, n) cin >> y[i];
    stack<ll> s;
    ll maxa = 1;
    y.push_back(0);
    for (ll i = 0; i < y.size(); ++i) {
        while(s.size() && y[i] < y[s.top()]) {
            ll height = y[s.top()];
            s.pop();
            ll left = s.size() ? s.top() : -1;
            maxa = max(maxa, ((i - left - 1) * height));
        }
        s.push(i);
    }
    cout << maxa;
}