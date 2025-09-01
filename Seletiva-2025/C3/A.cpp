#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define all(a) a.begin(), a.end()
#define pll pair<ll, ll>
#define pii pair<int, int>
#define vi vector<ll>
#define MOD 1000000007
#define loop(x, s, n) for(int x = s; x < n; x++)

ll n,x,d, c=0;

void subsets(ll i, vi& v, vi &s) {
    if (i == n) {
        if(v.size() > 0) {
            ll sum = 0, mins = 1e9 + 1, maxs = -1;
            loop(i, 0, v.size()) {
                sum += v[i];
                mins = min(mins, v[i]);
                maxs = max(maxs, v[i]);
            }

            if (sum >= x && (maxs - mins) <= d) c++;
        }
        return;
    }
    subsets(i + 1, v, s);
    v.push_back(s[i]);
    subsets(i + 1, v, s);
    v.pop_back();
}

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >>n>>x>>d;
    vi s(n);loop(i,0,n)cin>>s[i];
    vi v;
    subsets(0, v, s);
    cout << c;
}