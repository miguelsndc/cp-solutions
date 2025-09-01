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
  for (ll i = 1; i <= n; i++) {
    cout << (i * i * (i * i - 1) / 2) - (4 * (i - 1) * (i - 2)) << '\n';
  }
}