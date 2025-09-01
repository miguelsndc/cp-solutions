#include <bits/stdc++.h>

using namespace std;

#define vi vector<int>
#define ll long long

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t, n;
  cin >> t;
  while(t--) {
    cin >> n;
    string s;
    cin >> s;
    int c = 0;
    s.push_back('*');
    for (int i = 0; i < n; i++) {
      if (s[i] == '*' && s[i + 1] == '*') break;
      c += (s[i] == '@');
    }
    cout << c << '\n';
  }
}