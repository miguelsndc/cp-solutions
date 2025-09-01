#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, x;
    cin >> n >> x;
    pair<int, int> values[n];
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        values[i] = make_pair(t, i + 1);
    }
    sort(values, values + n);
    int i = 0;
    int j = n - 1;
    while (i < j) {
        ll sum = values[i].first + values[j].first;
        if (sum == x) {
            cout << values[i].second << ' ' << values[j].second;
            return 0;
        } else if (sum < x) {
            i++;
        } else {
            j--;
        }
    }

    cout << "IMPOSSIBLE";
    return 0;
}