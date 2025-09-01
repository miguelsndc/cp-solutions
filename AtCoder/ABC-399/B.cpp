#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u32 = unsigned;
using u64 = unsigned long long;
constexpr i64 inf = 1E18;
constexpr int mod = 1e9 + 7, maxn = 1e5 + 5;

void solve() {
    int n; cin >> n;
    vector<int> p(n); vector<int> ranks(n), det(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }
    priority_queue<int> pq {p.begin(), p.end()};
    /*
        pega o maximo, pra cada pessoa com o maximo no vetor determina o rank dela pra ser r
        dps aumenta r pela qntd de pessoas com score maximo
    */
    int r = 1, k = 0;
    while(!pq.empty()) {
        int mx = pq.top(); pq.pop();
        for (int i = 0; i < n; i++) {
            if (p[i] == mx) {
                k++;
                ranks[i] = r;
                p[i] = -1;
            }
        }
        r += k;
        k = 0;
    }

    for (int i = 0; i < n; i++) {
        cout << ranks[i] << '\n';
    }
}

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1; // cin >> tt;
    while(tt--) {
        solve();
    }
}