#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (int& x : a) cin >> x;
    int i = 0, j = 0, cur = a[0], cnt = 0;
    while (j < n) {
        if (cur == x) {
            cnt++;
            cur += a[++j];
        } else if (cur > x)
            cur -= a[i++];
        else
            cur += a[++j];
    }
    cout << cnt << '\n';
}