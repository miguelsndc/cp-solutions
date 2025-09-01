#include <bits/stdc++.h>

using namespace std;

#define vi vector<int>
#define ll long long

bool f(string s1, string s2) {
    for (int i = 0; i < s1.size() - 1; i++) {
      if (s1[i] == s1[i + 1]) {
        return false;
      }
    }
    for (int i = 0; i < s2.size() - 1; i++) {
      if (s2[i] == s2[i + 1]) {
        return false;
      }
    }
    return true;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t, n, m;
  string s1, s2;
  cin >> t;
  while(t--) {
    cin >> n >> m;
    cin >> s1 >> s2;

    if (f(s1,s2)) {
      cout << "YES\n";
      continue;
    }

    bool can = 0;
    while (s1.size() > 1) {
      s2.push_back(s1.back());
      s1.pop_back();
      if (f(s1, s2)) {
        can = 1;
        break;
      }
    }

    if (can) {
      cout << "YES\n";
      continue;
    }

    while (s2.size() > 1) {
      s1.push_back(s2.back());
      s2.pop_back();
      if (f(s1, s2)) {
        can = 1;
        break;
      }
    }

    if (can) {
      cout << "YES\n";
      continue;
    } else {
      cout << "NO\n";
    }
  }
}