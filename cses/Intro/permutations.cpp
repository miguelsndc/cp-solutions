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
  if (n > 1 && n < 4) {
    cout << "NO SOLUTION";
    return 0;
  } else if (n == 1) {
    cout << 1;
    return 0;
  }

  int c = 2;
  for (int i = 0; i < n; i++) {
    cout << c spe;
    c += 2;
    if (c > n) {
      c = 1;
    }
  }
}