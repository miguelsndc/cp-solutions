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
    int tc, x;
    cin >> tc;
    ll sum = 0;
    string comm;
    while (tc--) {
        cin >> comm;
        if (comm == "report") {
            cout << sum << "\n";
        } else {
            cin >> x;
            sum += x;
        }
    }
    return 0;
}