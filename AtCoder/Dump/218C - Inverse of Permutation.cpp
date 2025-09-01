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
    int n;
    cin >> n;
    int inv_perm[n];
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        inv_perm[t - 1] = i + 1;
    }

    for (int i = 0; i < n; i++) {
        cout << inv_perm[i] << ' ';
    }
    return 0;
}