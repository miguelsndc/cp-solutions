#include <bits/stdc++.h>

using namespace std;

#define vi vector<int>

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  map<int, int> mp;
  for (int i = 1; i <= 12; i++) {
    string s;
    cin >> s;
    mp[i] = s.size();
  };
  
  int count = 0;  
  for(auto c: mp) {
    if (c.first == c.second) count++;
  }

  cout << count;
}