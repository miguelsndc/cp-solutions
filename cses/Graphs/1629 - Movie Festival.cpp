#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    pair<int, int> movies[n];

    for (int i = 0; i < n; i++) {
        cin >> movies[i].second >> movies[i].first;
    }

    sort(movies, movies + n);
    int curr_event_end = -1;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (movies[i].second >= curr_event_end) {
            curr_event_end = movies[i].first;
            ans++;
        }
    }

    cout << ans;

    return 0;
}