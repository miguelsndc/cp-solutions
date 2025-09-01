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
  int n;
  cin >> n;
  vll arr(n);
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  ll mx = 0, sum = 0;
  for (auto k : arr) {
    mx = max(mx, k);
    sum += (mx - k);
  }
  cout << sum;
}
