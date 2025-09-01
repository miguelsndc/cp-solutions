#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MOD 1000000007
#define INF 1000000009

void solve() {
    int n; cin >> n;
    int sqr = sqrt(n * 1.0);
    vector<vector<int>> g(n, vector<int>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> g[i][j];
        }
    }
    
    bool valid = true;

    vector<set<int>> rows(n); 
    vector<set<int>> cols(n); 
    vector<set<int>> subgrids(n); 

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int x = g[i][j];
            if (rows[i].find(x) != rows[i].end()) {
                valid = false;
            }
            rows[i].insert(x);

            if (cols[j].find(x) != cols[j].end()) {
                valid = false;
            }
            cols[j].insert(x);

            int grid_i = (i / sqr) * sqr + j / sqr;

            if (subgrids[grid_i].find(x) != subgrids[grid_i].end()) {
                valid = false;
            }
            subgrids[grid_i].insert(x);
        }
    }

    cout << (valid ? "yes\n" : "no\n");
}

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tt; cin >> tt;
    while(tt--) {
         solve();
    }
}