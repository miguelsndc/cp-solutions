#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int freq[26];
    memset(freq, 0, sizeof freq);
    for (int i = 0; i < n; i++) {
        freq[(int)(s[i] - 'a')]++;
    }

    int prev = -1;
    string res;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 26; j++) {
            if (freq[j] > 0 and j != prev) {
                res.push_back((char)(j + 'a'));
                freq[j]--, prev = j;
                break;
            }
        }
    }

    for (int i = 0; i < 26; i++) {
        while (freq[i] > 0) {
            res.push_back((char)(i + 'a'));
            freq[i]--;
        }
    }

    cout << res << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--) solve();
}