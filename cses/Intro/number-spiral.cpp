#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pii pair<int, int>
#define pll pair<long long, long long>
#define vi vector<int>
#define vb vector<bool>
#define vs vector<string>
#define vll vector<long long>
#define mii map<int, int>
#define si set<int>
#define sc set<char>
#define f first
#define s second
#define sp << " " <<
#define spe << " "

int main() {
  // cases
  // even row even column
  // even row odd column
  // odd row even column
  // odd row odd column
  // figure out a function f(x,y) of row y column x
  ll t, row, col;
  cin >> t;
  while (t--) {
    cin >> row >> col;
    ll mx = max(row, col);
    if (row < col) {
      if (mx % 2 == 0) {
        cout << (mx - 1) * (mx - 1) + row << '\n';
      } else {
        cout << mx * mx - row + 1 << '\n';
      }
    } else {
      if (mx % 2 == 0) {
        cout << mx * mx - col + 1 << '\n';
      } else {
        cout << (mx - 1) * (mx - 1) + col << '\n';
      }
    }
  }
}