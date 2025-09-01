#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
// -----------
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n;
    cin >> n;
    ll ans = 0;
    for (ll a = 1; a * a * a <= n; a++) {
        for (ll b = a; a * b * b <= n; b++) {
            ans += n / a / b - b + 1;
        }
    }

    cout << ans;

    return 0;
}