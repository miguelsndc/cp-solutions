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
#define MOD 1000000007

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);  // see Fast Input & Output

  vi v(7);
  for (int i = 0; i < 7; i++) cin >> v[i];
  sort(v.rbegin(), v.rend());

  int a = 1e9 + 1, b = 1e9 + 1, c = 1e9 + 1;
  while (v.size() > 0) {
    int smallest = v.back();
    v.pop_back();

    if (smallest < a) {
      a = smallest;
      continue;
    } else if (smallest < b) {
      b = smallest;
      continue;
    }

    if (smallest != a + b) {
      c = min(c, smallest);
    }
  }

  cout << a << " " << b << " " << c;
}
