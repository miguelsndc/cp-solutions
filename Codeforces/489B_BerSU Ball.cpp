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
    int n;cin>>n;
    vi b(n);rep(i,0,n)cin>>b[i];
    int m;cin>>m;
    vi g(m);rep(i,0,m)cin>>g[i];
    // boys <= 100 girls <= 100 upper bound of pairs is min(|boys|,|girls|)
    // n² keep a record of the pairs for each boy
    vector<ii>m1;
    sort(begin(b),end(b));
    sort(begin(g),end(g));
    map<int,int> m2, m3;
    rep(i,0,n){
        rep(j,0,m){
            if (abs(b[i] - g[j]) <= 1) {
                m1.push_back({i,j});
                m3[i]=true;
                m2[j]=true;
            }
        }
    }
    int matches = 0;
    sort(begin(m1), end(m1));
    for (const auto&[boy, girl]: m1) {
        if (m2[girl] && m3[boy]) {
            matches++;
            m2[girl] = false;
            m3[boy] = false;
        }
    }
    cout << matches << '\n';
}