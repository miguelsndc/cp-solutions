#include <bits/stdc++.h>

using namespace std;

#define vi vector<int>
#define ll long long

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  ll t, n, f, a, b;
  cin >> t;
  while(t--) {
    cin >> n >> f>>a>>b;
    bool can = 1;
    vi m(n + 1);
    for (ll i = 1; i <= n; i++) cin >> m[i];
    for (ll i = 1; i <= n; i++) {
      ll dt = m[i] - m[i - 1];
      f -= min(a * dt, b); // minimum between waiting or tuning on/off the phone
      if (f <= 0) {
        can = 0;
        break;
      }
    }
    cout << (can ? "YES\n" : "NO\n");
  }
}