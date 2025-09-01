#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

#define ll long long int
#define MOD 1000000007
#define ii pair<int, int>
#define vi vector<int>
#define fi first
#define se second
#define fori(n) for(int i = 0; i < n; i++)
#define forj(n) for(int j = 0; j < n; j++)
#define fork(n) for(int k = 0; k < n; k++)
#define debug(x) cout << #x << " is: " << x << '\n'
#define write(x) cout << x << ' '; 
#define writeln(x) cout << x << '\n';
#define se second

const int maxn = 305;

int mat[maxn][maxn], suf[maxn];

void solve() {
    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
        suf[i] = 0;
        for (int j = 1; j <= n; j++) {
            cin >> mat[i][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = n; j >= 1; j--) {
            if (mat[i][j] != 1) break;
            suf[i]++;
        }
    }

    multiset<int> ms;
    for (int i = 1; i <= n; i++) {
        ms.insert(suf[i]);
    }
    int ans= 1;
    while(!ms.empty()) {
        int m = *ms.begin();
        if (m >= ans) {
            ans++;
        }
        ms.extract(m);
    }
    writeln(min(ans, n));
}

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    while(t--) {
        solve();
    }
}