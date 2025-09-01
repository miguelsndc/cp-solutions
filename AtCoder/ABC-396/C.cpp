#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

constexpr i64 inf = 1E18;

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<int> b(n), w(m);

    for (int i = 0; i < n; i++) cin >> b[i];
    for (int i = 0; i < m; i++) cin >> w[i];

    sort(b.rbegin(), b.rend());
    sort(w.rbegin(), w.rend());
    
    vector<i64> psb(n + 1), psw(m + 1), maxx(m + 1);
    for(int i = 0; i < n; i++) psb[i + 1] = psb[i] + b[i];
    for(int i = 0; i < m; i++) { 
        psw[i + 1] = psw[i] + w[i];
        maxx[i + 1] = max(maxx[i], psw[i + 1]);
    }

    i64 ans = 0;
    for (int i = 0; i <= n; i++) {
        ans = max(ans, psb[i] + maxx[min(i, m)]);
    }
    cout << ans;
}