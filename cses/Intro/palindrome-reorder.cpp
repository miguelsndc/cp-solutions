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
  string s, res;
  cin >> s;
  res.append(s.size(), ' ');
  map<char, int> mp;
  for (auto c : s) {
    mp[c]++;
  }
  int odd = 0, left = 0, right = s.size() - 1;
  for (auto p : mp) {
    char letter = p.first;
    int count = p.second;
    if (count % 2) {
      odd++;
      if (odd > 1) break;
      res[s.size() / 2] = letter;
      count--;
    }
    while (count) {
      res[left++] = letter;
      res[right--] = letter;
      count -= 2;
    }
  }
  if (odd > 1) {
    cout << "NO SOLUTION";
  } else {
    cout << res;
  }
  return 0;
}