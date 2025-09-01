#include <bits/stdc++.h>

using namespace std;

#define ll long long int
#define ld long double
#define MOD 1000000007
#define ii pair<int, int>
#define vi vector<int>
#define vii vector<ii>

void setIO(string s) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

void solve() {
    int n; cin >> n;
    vi aux, v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    for (int i : v) {
        int pos = lower_bound(aux.begin(), aux.end(), i) - aux.begin();
        if (pos == aux.size()) {
            aux.push_back(i);
        } else {
            aux[pos] = i;
        }
	}
    cout << aux.size();
}

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1; // cin >> tt;
    while(tt--) {
         solve();
    }
}