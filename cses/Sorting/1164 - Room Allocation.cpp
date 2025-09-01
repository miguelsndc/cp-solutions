#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pi;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<pair<pair<int, int>, int> > v(n);
    int ans[n];
    for (int i = 0; i < n; i++) {
        cin >> v[i].first.first >> v[i].first.second;
        v[i].second = i;
    }
    sort(v.begin(), v.end());

    int rooms = 0, last_room = 0;
    priority_queue<pi> pq;
    for (int i = 0; i < n; i++) {
        if (pq.empty()) {
            last_room++;
            pq.push(make_pair(-v[i].first.second, last_room));
            ans[v[i].second] = last_room;
        } else {
            pi minn = pq.top();
            if (-minn.first < v[i].first.first) {
                pq.pop();
                pq.push(make_pair(-v[i].first.second, minn.second));
                ans[v[i].second] = minn.second;
            } else {
                last_room++;
                pq.push(make_pair(-v[i].first.second, last_room));
                ans[v[i].second] = last_room;
            }
        }
        rooms = max(rooms, (int)pq.size());
    }

    cout << rooms << '\n';
    for (int i = 0; i < n; i++) {
        cout << ans[i] << ' ';
    }
}
