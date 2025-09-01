#include <bits/stdc++.h>
using namespace std;
#define ll long long int
bool matches(char c, char sk) {
    if (sk == '1' && (c == 'i' || c == 'j')) return true;
    if (sk == '2' && (c == 'a' || c == 'b' || c == 'c')) return true;
    if (sk == '3' && (c == 'd' || c == 'e' || c == 'f')) return true;
    if (sk == '4' && (c == 'g' || c == 'h')) return true;
    if (sk == '5' && (c == 'k' || c == 'l')) return true;
    if (sk == '6' && (c == 'm' || c == 'n')) return true;
    if (sk == '7' && (c == 'p' || c == 'r' || c == 's')) return true;
    if (sk == '8' && (c == 't' || c == 'u' || c == 'v')) return true;
    if (sk == '9' && (c == 'w' || c == 'x' || c == 'y')) return true;
    if (sk == '0' && (c == 'o' || c == 'q' || c == 'z')) return true;
    return false;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s;
    while((cin >> s) && s != "-1") {
        int n; cin >> n;
        vector<string> w(n);
        for(int i=0;i<n;i++) {
            cin >> w[i];
        }
        vector<array<int, 3>> v;
        for (int i = 0; i < n; i++) {
            int l = -1, r = -1, t = -1, matched = false;
            for (int j = 0; j < w[i].size(); j++) {
                for (int k = 0; k < s.size(); k++) {
                    if (matches(w[i][j], s[k])) {
                        matched = true;
                        l = r = k; t = j;
                        break;
                    }
                }
                if (matched) break;
            }
            if (matched) {
                while(matches(w[i][t], s[r])) {
                    t++, r++;
                }
                v.push_back({l, r-1, i});
            }
        }
        if (v.empty()) {
            cout << "No solution.\n";
            continue;
        }
        vector<vector<int>> ww;
        
    }
}