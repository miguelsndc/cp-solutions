#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()

#ifdef CARNEDESOOOL
#define debug(...) dbg(#__VA_ARGS__, __VA_ARGS__)
template <typename... T>
void dbg(const char* names, T... args) {
    const char* p = names;
    ((cout << string(p, strchr(p, ',') ? strchr(p, ',') : p + strlen(p)) << " = " << args << '\n',
      p = strchr(p, ',') ? strchr(p, ',') + 1 : p + strlen(p)),
     ...);
}
#else
#define debug(...)
#endif

using i64 = long long;

constexpr i64 inf = 1E18;
constexpr int mod = 1e9 + 7, maxn = 2e5 + 5;

void solve() {
    int h, w;
    cin >> h >> w;
    vector<string> g(h);
    for (int i = 0; i < h; i++) {
        cin >> g[i];
    }
    int start_y, start_x, end_y, end_x;
    cin >> start_y >> start_x >> end_y >> end_x;
    --start_y, --start_x, --end_y, --end_x;
    vector<vector<int>> dist(h, vector<int>(w, 1e9));
    dist[start_y][start_x] = 0;
    deque<pair<int, int>> dq;
    dq.push_back({start_y, start_x});

    int dx[] = {0, 0, 1, -1};
    int dy[] = {1, -1, 0, 0};

    while (!dq.empty()) {
        auto [cur_y, cur_x] = dq.front();
        dq.pop_front();
        for (int i = 0; i < 4; i++) {
            int new_y = cur_y + dy[i];
            int new_x = cur_x + dx[i];
            if (new_y >= 0 and new_y < h and new_x >= 0 and new_x < w and g[new_y][new_x] == '.' and dist[cur_y][cur_x] < dist[new_y][new_x]) {
                dist[new_y][new_x] = dist[cur_y][cur_x];
                dq.push_front({new_y, new_x});
            }
        }
        for (int i = 0; i < 4; i++) {
            for (int scale = 1; scale <= 2; scale++) {
                int new_y = cur_y + dy[i] * scale;
                int new_x = cur_x + dx[i] * scale;
                if (new_y >= 0 and new_y < h and new_x >= 0 and new_x < w and dist[cur_y][cur_x] + 1 < dist[new_y][new_x]) {
                    dist[new_y][new_x] = dist[cur_y][cur_x] + 1;
                    dq.push_back({new_y, new_x});
                }
            }
        }
    }
    cout << dist[end_y][end_x] << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1;  // cin >> tt;
    while (tt--) {
        solve();
    }
}