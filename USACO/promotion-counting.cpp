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
#define pb push_back
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
using pi = pair<int, int>;
#define f first
#define s second
#define mp make_pair

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);  // see Fast Input & Output
  freopen("promote.in", "r", stdin);
  freopen("promote.out", "w", stdout);

  int bronze_before, bronze_after;
  int silver_before, silver_after;
  int gold_before, gold_after;
  int plat_before, plat_after;

  int bronze_to_silver, silver_to_gold, gold_to_plat;

  cin >> bronze_before >> bronze_after;
  cin >> silver_before >> silver_after;
  cin >> gold_before >> gold_after;
  cin >> plat_before >> plat_after;

  gold_to_plat = plat_after - plat_before;
  gold_before -= gold_to_plat;
  silver_to_gold = gold_after - gold_before;
  silver_before -= silver_to_gold;
  bronze_to_silver = silver_after - silver_before;

  cout << bronze_to_silver << '\n';
  cout << silver_to_gold << '\n';
  cout << gold_to_plat;
}