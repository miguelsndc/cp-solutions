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
 
const int MAXN = 1e6 + 10;
 
int bit[MAXN];
void add(int x, int val) {
    for (int i = x + 1; i < MAXN; i += i & (-i)) bit[i] += val;
}
int get(int x) {
    int ans = 0;
    for (int i = x; i > 0; i -= i & (-i)) ans += bit[i];
    return ans;
}
int sum(int x, int y) {
    return get(y) - get(x);
}
 
int rem[MAXN], cnt[MAXN], a[MAXN], total[MAXN], sz;
 
int main()
{
    ios::sync_with_stdio(false);
 
    int n; cin >> n;
    fori(n) cin >> a[i], total[sz++] = a[i];
 
    sort(total, total + sz);
    sz = unique(total, total + sz) - total;
 
    fori(n) a[i] = lower_bound(total, total + sz, a[i]) - total;
 
    for (int i = n - 1; i >= 0; i --)
    {
        cnt[a[i]] ++;
        add(cnt[a[i]], 1);
        rem[i] = cnt[a[i]];
    }
 
    memset(cnt, 0, sizeof cnt);
    ll ans = 0;
    fori(n)
    {
        add(rem[i], -1);
        cnt[a[i]] ++;
        ans += sum(1, cnt[a[i]]);
    }
 
    writeln(ans);
    return 0;
}