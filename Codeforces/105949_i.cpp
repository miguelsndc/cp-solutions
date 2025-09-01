#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int ALPHA = 26;
const int maxn = 3e5 + 10;
int trie[maxn][ALPHA], word_end[maxn], z = 1;
void add(string &s) {
    int cur = 0;
    for(int i = 0; i < s.size(); i++) {
        if (trie[cur][s[i] - 'a'] == -1) {
            memset(trie[z], -1, sizeof trie[z]);
            trie[cur][s[i] - 'a'] = z++;
        }
        cur = trie[cur][s[i] - 'a'];
    }
    word_end[cur]++;
}
void init(){
	memset(trie[0], -1, sizeof trie[0]);
    memset(word_end, 0, sizeof word_end);
	z = 1;
}
int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    init();
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        reverse(s.begin(), s.end());
        add(s);
    }

    cout << z - 1 << '\n';
}
