#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define all(a) a.begin(), a.end()
#define pll pair<ll, ll>
#define pii pair<int, int>
#define vi vector<int>
#define MOD 1000000007

// nao ta no map eu boto
// se ja tiver no map e ocorrer dps do L
// eu boto o L 1 pra frente da ultima ocorrencia
// de qlqr forma atualiza o map
int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    vector<ll> seq(n);
    for(int i = 0; i < n; i++) cin >> seq[i];
    map<int, int> m;
    int l = 0, maxs = 0;
    for(int r = 0; r < n; r++) {
        if (m.find(seq[r]) == m.end()) {
            m.insert({seq[r], r});
        } else {
            if(m[seq[r]] >= l) l = m[seq[r]] + 1;
            m[seq[r]] = r; 
        }
        maxs = max(maxs, r - l + 1);
    }
    cout << maxs;
}