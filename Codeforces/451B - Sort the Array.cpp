#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define MOD 1000000007
#define ii pair<int, int>
#define vi vector<int>
#define fi first
#define se second
#define rep(var, k, n) for (int var = k; var < n; var++)
#define repi(var, k, n) for (int var = k; var <= n; var++)
#define se second
const int maxn = 2e5 + 5;

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    /*
        is it possible to sort array a by reversing a segment l:r of a ?
        segment is a contiguous subsequence
        all a[i] are distinct
        find longest decreasing subarray reverse it then see if its sorted
        find O(n)
        reverse O(n)
        check O(n),good to go
    */
    int n;cin >> n;
    vi v(n); rep(i,0,n) cin>>v[i];
    bool can = true;
    rep(i,0,n-1) {
        if (v[i] > v[i + 1]) {
            can = false;
            break;
        }
    }
    if (can) {
        cout << "yes\n";
        cout << 1 << ' ' << 1;
        return 0;
    }
    int start = 0, end = 0;
    rep(i,0,n-1) {
        if (v[i] > v[i + 1]) {
            start = i; end = 0;
            while(start + end < n && v[start] >= v[start + end]) {
                end++;
            }
            break;
        }
    }
    reverse(v.begin() + start, v.begin() + start + end);;
    can = true;
    rep(i,0,n-1) {
        if (v[i] > v[i + 1]) {
            can = false;
            break;
        }
    }
    if (can) {
        cout <<"yes\n";
        cout << start + 1 << ' ' << start + end ; 
    } else {
        cout << "no\n";
    }
}
