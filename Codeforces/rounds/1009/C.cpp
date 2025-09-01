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

const int maxn = 2e5 + 5;

bool valid(int x, int y) {
    int z = x ^y;
    return ((x+y)>z) && ((x+z)>y) && ((y+z)>x);
}

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tc; cin >> tc;
    while(tc--) {
        int x; cin >> x;
        int l = 0, r = x - 1;
        bool found = false;
        while(l <= r) {
            int m = l + (r - l) / 2;
            if (valid(x, m)) {
                writeln(m);
                found = true;
                break;
            }
            l = m + 1;
        }
        if (!found) {
            writeln(-1);
        }
    }
}