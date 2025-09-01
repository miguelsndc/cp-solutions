#include <bits/stdc++.h>

using namespace std;

#define vi vector<int>
#define ll long long

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  vector<ll> s(n);
  for (int i = 0; i < n; i++) cin >> s[i];
  ll max_k = s[0];
  ll moves = 0;
  for (int i = 0; i < n; i++) {
    max_k = max(max_k, s[i]);
    moves += max(0LL, max_k - s[i]);
  }
  cout << moves;
}