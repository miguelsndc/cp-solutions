#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
// -----------
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tc, l, w, h;
    cin >> tc;
    for (int i = 1; i <= tc; i++) {
        cin >> l >> w >> h;
        if (l <= 20 && w <= 20 && h <= 20) {
            cout << "Case " << i << ": " << "good" << '\n';
        } else {
            cout << "Case " << i << ": " << "bad" << "\n";
        }
    }

    return 0;
}