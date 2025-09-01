#include <bits/stdc++.h>

using namespace std;

#define vi vector<int>
#define ll long long
#define pii pair<int,int>
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m, k;
  cin >> n >> m;
  auto comp = [](pii& a, pii&b) {
    if (a.second == b.second) {
      return a.first > b.first;
    } 
    return a.second < b.second;
  };
  priority_queue<pii, vector<pii>, decltype(comp)> pq(comp);
  unordered_map<int, int> mp;
  for (int i = 0; i < m; i++) {
    cin >> k;
    mp[k]++; 
    pq.push({k, mp[k]});
    cout << pq.top().first << '\n';
  }
}
