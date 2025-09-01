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
  if ((n * (n + 1) / 2) % 2 != 0) {
    cout << "NO";
    return 0;
  }
  // 1 2 3 4 5 6 7
  // target = n(n+1)/4
  int target = (n * (n + 1)) / 4;
  vb table(n + 1);
  int i = 1, j = n;
  int sum = 0;
  vi a, b;
  while (i < j) {
    if (sum == target) {
      break;
    }
    sum += j;
    table[j] = true;
    a.emplace_back(j);
    if (sum == target) {
      break;
    }
    sum += i;
    a.emplace_back(i);
    table[i] = true;
    i++;
    j--;
  }

  cout << "YES\n";
  if (a.size() == n) {
    cout << n / 2 << '\n';
    for (int i = 0; i < n / 2; i++) {
      cout << a[i] spe;
    }
    cout << '\n';
    cout << n / 2 << '\n';
    for (int i = n / 2; i < n; i++) {
      cout << a[i] spe;
    }
  } else {
    cout << a.size() << '\n';
    for (int c : a) {
      cout << c spe;
    }
    cout << '\n';
    cout << n - a.size() << '\n';
    for (int i = 1; i <= n; i++) {
      if (!table[i]) cout << i spe;
    }
  }

  return 0;
}