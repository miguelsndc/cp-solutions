#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define F first
#define S second

const int mxn = 55, inf = 1e9;
void solve() {
    vector<set<int>> edges(mxn);

    auto f = [&](int x, int y) {
        edges[x].insert(y);
        edges[y].insert(x);
    };

    f(1,6);
    f(2,6);
    f(3,6);
    f(3,4);
    f(3,5);
    f(3,15);
    f(4,3);
    f(4,6);
    f(4,5);
    f(5,6);
    f(5,4);
    f(5,3);
    f(6,1);
    f(6,2);
    f(6,3);
    f(6,4);
    f(6,5);
    f(6,7);
    f(7,8);
    f(7,6);
    f(8,9);
    f(8,7);
    f(9,8);
    f(9,10);
    f(9,12);
    f(10, 9);
    f(10,11);
    f(11, 10);
    f(11, 12);
    f(12,13);
    f(12,9);
    f(12, 11);
    f(13,12);
    f(13,15);
    f(14,13);
    f(15,3);
    f(15,13);
    f(16, 17);
    f(16,18);
    f(17, 18);
    f(16, 17);
    f(16,18);
    f(17,18);


    char inst; int x, y;
    while((cin >> inst)) {
        if(inst == 'q') return;

        if (inst == 'i') {
            cin >> x >> y;
            edges[x].insert(y);
            edges[y].insert(x);
        }
        if (inst == 'd') {
            cin >> x >> y;
            edges[x].erase(y);
            edges[y].erase(x);
        }
        if (inst == 'n') {
            cin >> x;
            cout << edges[x].size() << '\n';
        }
        if (inst == 'f') {
            cin >> x;
            int cnt = 0;
            set<int> ans;
            for (int u: edges[x]) {
                for (int v: edges[u]) {
                    ans.insert(v);
                }
            }
            for (int u: edges[x]) ans.erase(u);
            ans.erase(x);
            cout << ans.size() << '\n';
        }
        if (inst == 's') {
            cin >> x >> y;
            vector<int> dist(mxn, inf);
            dist[x] = 0;
            queue<int> q;
            q.push(x);
            while(!q.empty()) {
                int u = q.front(); q.pop();
                for (int v: edges[u]) {
                    if (dist[v] > (dist[u] + 1)) {
                        dist[v] = dist[u] + 1;
                        q.push(v);
                    }
                }
            }
            if (dist[y] == inf) {
                cout << "Not connected" << '\n';
            } else {
                cout << dist[y] << '\n';
            }
        }
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1; // cin >> T;
    while(T--) solve();
}