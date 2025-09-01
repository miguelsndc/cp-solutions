#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define MOD 1000000007
#define ii pair<int, int>
#define v vector
#define fi first
#define se second

void solve() {
    int n, m; cin >> n >> m; // n * m <= 2000
    v<v<int>> cows(n, v<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> cows[i][j];
        }
    }
    // pra cada carta, qual vaca ta com essa carta ? 
    v<int> order;
    for (int k = 0; k < n * m; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (cows[i][j] == k) {
                    order.push_back(i);
                }
            }
        }
    }
    bool impossible = false;
    for (int i = 0; i < n * m - n; i++) {
        set<int> seen;
        for (int j = i; j < i + n; j++) {
            seen.insert(order[j]);
        }
        if (seen.size() != n) {
            impossible = true;
        }
    }
    if (impossible) {
        cout << -1;
    } else {
        for (int i = 0; i < n; i++) {
            cout << order[i] + 1 << ' ';
        }
    }
    cout << '\n';
}

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1; cin >> tt;
    for (int t = 1; t <= tt; t++) {
         solve();
    }
}