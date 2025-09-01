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
    string w;
    while (n--) {
        cin >> w;
        if (w.size() == 5) {
            cout << 3 << '\n';
            continue;
        }

        if (
            w[0] == 't' && w[1] == 'w' || w[1] == 'w' && w[2] == 'o' || w[0] == 't' && w[2] == 'o') {
            cout << 2 << '\n';
        } else {
            cout << 1 << "\n";
        }
    }
    return 0;
}