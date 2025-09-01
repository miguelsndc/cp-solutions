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
  string game;
  cin >> game;
  int a = 0, b = 0, changed = 0;
  for (int i = 0; i < game.size(); i += 2) {
    int score = (game[i + 1] == '2') + 1;
    if (game[i] == 'A') {
      a += score;
    } else {
      b += score;
    }
    if (a == 10 && b == 10) {
      changed = true;
    }
    if ((changed && abs(b - a) >= 2) || (!changed && (a == 11 || b == 11))) {
      break;
    }
  }

  cout << (a > b ? 'A' : 'B');
}