#include <bits/stdc++.h>

using namespace std;

#define ll long long int
#define ld long double
#define MOD 1000000007
#define ii pair<int, int>

void setIO(string s) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

void solve() {
    int n; cin >> n;
    string r, b; cin >> r >> b;
    vector<int> red, blue;
    for (int i = 0; i < n; i++) {
        red.push_back(r[i] - '0');
        blue.push_back(b[i] - '0');
    }

    ll rc = 0, bc = 0;
    for (int i = 0; i < n; i++) {
        if (red[i] > blue[i]) {
            rc++; 
        } else if (blue[i] > red[i]) {
            bc++;
        }
    }

    if (rc > bc) {
        cout << "RED\n";
    } else if (rc < bc) {
        cout << "BLUE\n";
    } else {
        cout << "EQUAL\n";
    }
}

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1; cin >> tt;
    while(tt--) {
         solve();
    }
}