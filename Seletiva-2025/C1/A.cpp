#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define vi vector<int>

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cout.precision(10); cout.setf(ios::fixed);

  ll tc, n, d, h;
  cin >> tc;
  while(tc--) {
    cin >> n >> d >> h;
    vi y(n);
    // diff
    for (int i = 0; i < n; i++) cin >> y[i];
    long double ans = (long double) (d * h) * 0.5;
    for (int i = 0; i < n - 1; i++) {
      if (y[i + 1] - y[i] >= h) {
        ans += d * h * 0.5;
      } else {
        long double sb = (long double) d * (y[i] + h - y[i + 1]) / h;
        long double dh = y[i + 1] - y[i];
        ans += (long double) (d + sb) * 0.5 * dh;
      }
    }
    cout << ans << '\n';
  }
}