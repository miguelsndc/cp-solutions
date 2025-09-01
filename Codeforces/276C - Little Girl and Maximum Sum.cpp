#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

#define ll long long int
#define MOD 1000000007
#define ii pair<ll, ll>
#define vi vector<ll>
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

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    /*
    biggest elements should appear in most frequent positions
    for each l and r calculate a sweep line algorithm
    ps it up to find most frequent positions
    then put largest elements on most frequent positions
    */
    int n, q; cin >> n >> q;
    vi a(n); fori(n) cin >> a[i];
    vi v(n + 1);
    vector<ii> queries(q);
    fori(q) {
        int l, r; cin >> l >> r;
        queries[i] = {l, r};
        l--,r--;
        v[l]++, v[r + 1]--;
    }
    vi freq(n + 1);
    vi arr(n + 1);
    fori(n) {
        freq[i + 1] = freq[i] + v[i];
    }
    vector<ii> pos(n);
    fori(n) {
        pos[i] = {freq[i + 1], i}; 
    }
    sort(rbegin(pos), rend(pos));
    priority_queue<int> pq{a.begin(), a.end()};
    fori(n) {
        auto [f, j] = pos[i];
        arr[j] = pq.top();
        pq.pop();
    }
    ll sum = 0;
    vi ps(n + 1);
    fori(n) {
        ps[i + 1] = ps[i] + arr[i];
    }
    for(const auto [l, r]: queries) {
        sum += ps[r] - ps[l - 1];
    }
    writeln(sum);
}