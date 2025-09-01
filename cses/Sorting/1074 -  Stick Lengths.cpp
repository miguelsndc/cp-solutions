#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    ll sticks[n];
    for (int i = 0; i < n; i++) cin >> sticks[i];

    sort(sticks, sticks + n);

    ll median = sticks[n / 2];
    ll cost = 0;

    for (int i = 0; i < n; i++) {
        cost += abs(sticks[i] - median);
    }

    cout << cost;

    return 0;
}