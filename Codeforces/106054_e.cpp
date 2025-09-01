#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll M = 0;
int min_turns = INT_MAX;

struct Info {
    ll max_val = 0;
    int min_t = -1;
};

vector<vector<int>> adj;
vector<ll> T;
vector<int> parent_, depth_, height_, sub_size;

void dfs1(int v, int p, int d) {
    parent_[v] = p;
    depth_[v] = d;
    sub_size[v] = 1;
    height_[v] = 0;
    for (int c : adj[v]) if (c != p) {
        dfs1(c, v, d + 1);
        sub_size[v] += sub_size[c];
        height_[v] = max(height_[v], height_[c] + 1);
    }
}

pair<Info, deque<ll>> dfs(int v, int p, bool need_vector) {
    Info info;
    deque<ll> profile_deque;
    vector<pair<int, int>> children;
    for (int c : adj[v]) if (c != p) {
        children.emplace_back(c, sub_size[c]);
    }
    size_t num_children = children.size();
    bool multi = num_children > 1;
    bool child_flag = multi || need_vector;
    ll summed_max = 0;
    int summed_min_d = -1;
    deque<ll> summed_deque;
    if (num_children == 0) {
        // leaf
    } else if (num_children == 1) {
        auto [child_info, child_deque] = dfs(children[0].first, v, child_flag);
        summed_max = child_info.max_val;
        summed_min_d = child_info.min_t;
        if (child_flag) summed_deque = move(child_deque);
    } else {
        // multi
        sort(children.begin(), children.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            return a.second > b.second;
        });
        auto [heavy_info, heavy_deque] = dfs(children[0].first, v, true);
        summed_deque = move(heavy_deque);
        for (size_t i = 1; i < num_children; ++i) {
            auto [light_info, light_deque] = dfs(children[i].first, v, true);
            deque<ll>& light_d = light_deque;
            if (light_d.size() > summed_deque.size()) {
                swap(summed_deque, light_d);
            }
            while (summed_deque.size() < light_d.size()) {
                summed_deque.push_back(0);
            }
            for (size_t d = 0; d < light_d.size(); ++d) {
                summed_deque[d] += light_d[d];
            }
        }
        ll mx = 0;
        int mn_d = -1;
        for (size_t d = 0; d < summed_deque.size(); ++d) {
            if (summed_deque[d] > mx) {
                mx = summed_deque[d];
                mn_d = (int)d;
            }
        }
        summed_max = mx;
        summed_min_d = mn_d;
    }
    info.max_val = max(T[v], summed_max);
    if (T[v] > summed_max) {
        info.min_t = 0;
    } else if (T[v] < summed_max) {
        info.min_t = 1 + summed_min_d;
    } else {
        info.min_t = 0;
        if (summed_min_d >= 0) info.min_t = min(info.min_t, 1 + summed_min_d);
    }
    if (need_vector) {
        if (num_children == 0) {
            profile_deque.push_front(T[v]);
        } else {
            summed_deque.push_front(T[v]);
            profile_deque = move(summed_deque);
        }
    }
    if (v != 1) {
        if (info.max_val > M) {
            M = info.max_val;
            min_turns = info.min_t + 1;
        } else if (info.max_val == M) {
            min_turns = min(min_turns, info.min_t + 1);
        }
    }
    return {info, move(profile_deque)};
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    adj.resize(N + 1);
    T.resize(N + 1, 0);
    for (int i = 2; i <= N; ++i) cin >> T[i];
    for (int i = 0; i < N - 1; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    parent_.resize(N + 1, -1);
    depth_.resize(N + 1, 0);
    height_.resize(N + 1, 0);
    sub_size.resize(N + 1, 1);
    dfs1(1, -1, 0);
    dfs(1, -1, false);
    cout << M << " " << min_turns << "\n";
    return 0;
}