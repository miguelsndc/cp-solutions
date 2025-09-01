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
    int n, i = 1;
    while (cin >> n && n != 0) {
        int sum = 0, q;
        for (int i = 0; i < n; i++) {
            cin >> q;
            q == 0 ? sum-- : sum++;
        }
        cout << "Case " << i << ": " << sum << '\n';
        i++;
    }

    return 0;
}