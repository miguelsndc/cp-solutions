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
  // modular exponentiation of 2^n
  int n;
  cin >> n;
  ll x = 1;
  ll power = 2 % MOD;
  int k = log2(n);
  for (int i = 0; i <= k; i++) {
    int a = (n >> i) & 1;
    if (a == 1) x = (x % MOD * power % MOD) % MOD;
    power = (power % MOD * power % MOD) % MOD;
  }
  cout << x;
}