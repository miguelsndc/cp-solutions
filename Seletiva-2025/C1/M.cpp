#include <bits/stdc++.h>

using namespace std;

#define vi vector<int>
#define ll long long

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vi segs(n);
  bool ok = false;
  for (int i = 0; i < n; i++) cin >> segs[i];
  sort(segs.begin(), segs.end());
  for (int i = 2; i < n; i++) {
    int a = segs[i], b = segs[i - 1], c = segs[i - 2];
    if (a < b + c) {
      cout << "YES";
      return 0;
    }
  }

  cout << "NO";
}