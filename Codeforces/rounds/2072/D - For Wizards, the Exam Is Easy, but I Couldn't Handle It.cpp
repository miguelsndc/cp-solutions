#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define MOD 1000000007
#define ii pair<int, int>
#define fi first
#define se second

void solve() {
    int n; cin >> n;
    vector<int> v(n);
    for (int &x: v) cin >> x;
    int best = 0;
    int bestl = 0, bestr = 0;
    for (int i = 0; i < n; i++) {
        int c1 =0, c2 = 0;
        for (int j = i + 1; j < n; j++) {
            c1 += v[j] > v[i]; // inversao q vou ter
            c2 += v[j] < v[i]; // inversao q ja tenho
            // se eu movi eu tiro as inversoes q eu tinha e adiciono as q eu vou ter
            // ent tirando o minimo eu minimizo as inversoes
            if (best > c1 - c2) {
                best = c1 - c2;
                bestl = i; bestr = j;
            }
        }
    }
    cout << bestl + 1 << ' ' << bestr + 1 << '\n';
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