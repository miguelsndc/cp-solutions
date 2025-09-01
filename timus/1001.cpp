#include <bits/stdc++.h>
using namespace std;
void solve() {
    long long a;
    vector<double> sq;
    while((cin >> a)) {
        sq.push_back(sqrt(a));
    }
    reverse(begin(sq), end(sq));
    for (double c: sq) {
        cout << setprecision(4) << fixed << c << '\n';
    }
}
int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1; // cin >> tt;
    for (int t = 1; t <= tt; t++) {
         solve();
    }
}