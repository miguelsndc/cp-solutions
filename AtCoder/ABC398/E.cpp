#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u32 = unsigned;
using u64 = unsigned long long;
constexpr i64 inf = 1E18;

array<int, 105> color{0};
vector<int> g[105];
void colorize(int u, int p, int c) {
  color[u] = c;
  for (int v : g[u]) {
    if (v != p) colorize(v, u, c ^ 1);
  }
}

void solve() {
  int n;
  cin >> n;
  set<pair<int, int>> edges, pickable;
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    if (u > v) swap(u, v);
    g[u].push_back(v);
    g[v].push_back(u);
    edges.insert({u, v});
  }
  colorize(1, 0, 0);
  set<int> black, white;
  for (int i = 1; i <= n; i++) {
    if (color[i])
      black.insert(i);
    else
      white.insert(i);
  }
  int a = black.size(), b = white.size();
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      if (((black.count(i) and white.count(j)) or (white.count(i) and black.count(j))) and edges.count({i, j}) == 0) {
        if (i > j) swap(i, j);
        pickable.insert({i, j});
      }
    }
  }

  bool turn = 0;
  if ((a * b - (n - 1)) & 1) {
    cout << "First" << endl;
    fflush(stdout);
    turn = 1;
  } else {
    cout << "Second" << endl;
    fflush(stdout);
  }
  int x = 0, y = 0;
  do {
    if (turn) {
      auto e = pickable.begin();
      cout << e->first << ' ' << e->second << endl;
      fflush(stdout);
      pickable.erase(e);
      turn ^= 1;
    } else {
      cin >> x >> y;
      if (x > y) swap(x, y);
      if (pickable.count({x, y})) pickable.erase({x, y});
      turn ^= 1;
    }
  } while (x != -1 and y != -1);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int tt = 1;  // cin >> tt;
  while (tt--) {
    solve();
  }
}