#include <bits/stdc++.h>

using namespace std;

#define vi vector<int>
#define ll long long

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  string s;
  cin >> s;
  // number of wows is the sum of the number of vv's before and after each o
  // calculate the number of pairs 

  ll pairs_seen = 0;
  vector<ll> pairs_before_j;
  for (ll i = 0; i < s.size() -1; i++) {
    if (s[i] == 'v' && s[i + 1] == 'v') {
      pairs_seen++;
    }
    if (s[i] == 'o') {
      pairs_before_j.push_back(pairs_seen);
    }
  }
  ll count = 0;
  for (auto c: pairs_before_j) {
    count += c * (pairs_seen - c); // before * after;
  }
  cout << count;
}