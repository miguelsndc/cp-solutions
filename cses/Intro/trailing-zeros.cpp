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
  // trailing zeroes in factorial
  // what creates a trailing zero ?
  // 2 * 5, multiple of 10 * anything,
  // 1 * 2* 3* 4* 5* 6* 7* 8* 9* 10
  // 00
  ll n;
  cin >> n;
  ll trailing = 0;
  while (n >= 5) {
    trailing += ceil(n / 5);
    n /= 5;
  }
  cout << trailing;
}