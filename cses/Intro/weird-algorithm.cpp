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
  long long n;
  cin >> n;
  cout << n spe;
  while (n != 1) {
    if (n % 2 == 0) {
      n /= 2;
    } else {
      n = n * 3 + 1;
    }
    cout << n spe;
  }
}