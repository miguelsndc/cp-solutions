#include <bits/stdc++.h>
#include <string.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
// -----------
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tc;
    string t;
    cin >> tc;
    while (tc--) {
        cin >> t;
        if (t == "1" || t == "4" || t == "78") {
            cout << '+' << "\n";
        } else if (t.size() > 1 && t[t.size() - 1] == '5' && t[t.size() - 2] == '3') {
            cout << '-' << "\n";
        } else if (
            t.size() > 1 &&
            t[0] == '9' && t[t.size() - 1] == '4') {
            cout << '*' << "\n";
        } else {
            cout << '?' << '\n';
        }
    }
    return 0;
}
