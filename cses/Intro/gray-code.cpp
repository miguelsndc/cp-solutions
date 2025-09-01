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

void bin(string &a, int n) {
  if (n > 1) bin(a, n / 2);
  a.push_back((char)to_string(n % 2).c_str()[0]);
}

int main() {
  int n;
  cin >> n;
  int i = 0;
  int p = pow(2, n);
  string a, b;
  a.reserve(n);
  b.reserve(n);
  for (int i = 0; i < p; i++) {
    bin(a, i);
    b.append(n - a.size(), '0');
    b += a;
    cout << b << '\n';
    a = "";
    b = "";
  }
}