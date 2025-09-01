#include <bits/stdc++.h>

using namespace std;

#define vi vector<int>

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  string s;
  cin >> s;
  vi sequence;
  int c = 0;
  for (int i = 1; i < s.size(); i++) {
    if (s[i] == '-') c++;
    else {
      sequence.push_back(c);
      c = 0;
    }
  }
  for (int i = 0; i < sequence.size(); i++) {
    cout << sequence[i] << ((i != sequence.size() - 1) ? " ": "");
  }
}