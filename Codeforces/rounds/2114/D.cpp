#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define vi vector<int>
#define pii pair<int, int>
#define fast ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define fi first
#define se second

#ifdef CARNEDESOOOL
#define debug(...) dbg(#__VA_ARGS__, __VA_ARGS__)
template<typename... T>
void dbg(const char* names, T... args) {
    const char* p = names;
    ((cout << string(p, strchr(p, ',') ? strchr(p, ',') : p+strlen(p)) << " = " << args << '\n',
      p = strchr(p, ',') ? strchr(p, ',')+1 : p+strlen(p)), ...);
}
#else
#define debug(...)
#endif

using ll = long long;

constexpr ll inf = 1E18;
constexpr int mod = 1e9 + 7, maxn = 2e5 + 5;

void solve() {
   int n;
    cin >> n;
    vector<ll> x(n), y(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }

    if (n == 1) {
        cout << 1 << '\n';
        return;
    }

    vector<ll> pre_min_x(n + 1, inf), suf_min_x(n + 1, inf),pre_max_x(n + 1, -inf), 
    suf_max_x(n + 1, -inf),pre_min_y(n + 1, inf), suf_min_y(n + 1, inf), pre_max_y(n + 1, -inf), suf_max_y(n + 1, -inf);

    for (int i = 0; i < n; i++) {
        pre_min_x[i + 1] = min(pre_min_x[i], x[i]);
        pre_max_x[i + 1] = max(pre_max_x[i], x[i]);
        pre_min_y[i + 1] = min(pre_min_y[i], y[i]);
        pre_max_y[i + 1] = max(pre_max_y[i], y[i]);
    }
    for (int i = n - 1; i >= 0; i--) {
        suf_min_x[i] = min(suf_min_x[i + 1], x[i]);
        suf_max_x[i] = max(suf_max_x[i + 1], x[i]);
        suf_min_y[i] = min(suf_min_y[i + 1], y[i]);
        suf_max_y[i] = max(suf_max_y[i + 1], y[i]);
    }

    ll paradoarea = (pre_max_x[n] - pre_min_x[n] + 1) * (pre_max_y[n] - pre_min_y[n] + 1), min_area = paradoarea;

    for (int i = 0; i < n; i++) {
        ll new_min_x = (i == 0 ? suf_min_x[1] : min(pre_min_x[i], suf_min_x[i + 1]));
        ll new_max_x = (i == 0 ? suf_max_x[1] : max(pre_max_x[i], suf_max_x[i + 1]));
        ll new_min_y = (i == 0 ? suf_min_y[1] : min(pre_min_y[i], suf_min_y[i + 1]));
        ll new_max_y = (i == 0 ? suf_max_y[1] : max(pre_max_y[i], suf_max_y[i + 1]));
        ll w = new_max_x - new_min_x + 1;
        ll h = new_max_y - new_min_y + 1;
        ll area = w * h;
        ll area_i;
        if (area > n - 1) {
            area_i = area;
        } else {
            area_i = min((w + 1) * h, w * (h + 1));
        }
        min_area = min(min_area, area_i);
    }
    cout << min_area << '\n';
}

int main()  {
    fast;
    int tt = 1;  cin >> tt;
    while(tt--) solve();
}