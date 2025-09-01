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
  //  4 4
  //  3 2
  //  2 1
  //  0 0
  int t, A, B;
  cin >> t;
  while (t--) {
    cin >> A >> B;

    if ((2 * A - B) % 3 || (2 * A - B) < 0 || (2 * B - A) % 3 ||
        (2 * B - A) < 0) {
      cout << "NO\n";
    } else {
      cout << "YES\n";
    }
  }
}