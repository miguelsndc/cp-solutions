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
  string a;
  cin >> a;
  int longest = 1, keeping = 1;
  char prev;
  for (int i = 0; i < a.size(); i++) {
    if (a[i] == prev && i != 0) {
      keeping += 1;
      longest = max(longest, keeping);
    } else {
      keeping = 1;
    }
    prev = a[i];
  }
  cout << longest;
}