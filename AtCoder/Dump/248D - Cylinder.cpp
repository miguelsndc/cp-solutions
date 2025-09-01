#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int q;
    cin >> q;
    queue<ii> qu;
    while (q--) {
        int n, x, c;
        cin >> n;
        if (n == 1) {
            cin >> x >> c;
            qu.push(make_pair(x, c));
        } else {
            cin >> c;
            ll sum = 0;
            while (c > 0) {
                ll amount = min(qu.front().second, c);
                sum += qu.front().first * amount;
                qu.front().second -= amount;
                c -= amount;
                if (qu.front().second <= 0) {
                    qu.pop();
                }
            }
            cout << sum << '\n';
        }
    }

    return 0;
}
