#include <bits/stdc++.h>
using namespace std;

// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// #define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

#define ll long long int
#define MOD 1000000007
#define ii pair<int, int>
#define vi vector<int>
#define fi first
#define se second
#define fori(n) for(int i = 0; i < n; i++)
#define forj(n) for(int j = 0; j < n; j++)
#define fork(n) for(int k = 0; k < n; k++)
#define debug(x) cout << #x << " is: " << x << '\n'
#define write(x) cout << x << ' '; 
#define writeln(x) cout << x << '\n';
#define se second

const int maxn = 50;

ii trie[maxn][26]; int word_end[maxn], cnt[maxn], z = 1;

void add(string &s) {
    int cur = 0;
    fori(s.size()) {
        if (trie[cur][s[i] - 'a'].fi == -1) {
            memset(trie[z], -1, sizeof trie[z]);
            trie[cur][s[i] - 'a'].fi = z++;
            trie[cur][s[i] - 'a'].se = 0;
        }
        trie[cur][s[i] - 'a'].se++;
        cur = trie[cur][s[i] - 'a'].fi;
    }
    word_end[cur]++;
}

void query(string s){
	int cur = 0;
	fori(s.size()){
		if(trie[cur][s[i] - 'a'].fi == -1) {
            cout << -1 << '\n';
            return;
        }
		cur = trie[cur][s[i] - 'a'].fi;
	}
    // reached end of prefix, iterate to max cnt until reach a word end
    int mxend = 0, found = true;
    while(found) {
        int mx = -1;
        int c = 0;
        found = false;
        for (int i = 0; i < 26; i++) {
            if (trie[cur][i].fi != -1 && trie[cur][i].se > mx) {
                mx = trie[cur][i].se;
                c = i;
                found = true;
            }
        }
        if (found) {
            mxend = max(mxend, word_end[cur]);
            cur = trie[cur][c].fi;
            s += (c + 'a');
        }
    }

    cout << s << ' ' << word_end[cur] << '\n';
}

void init(){
    memset(trie[0], -1, sizeof trie[0]);
    memset(word_end, 0, sizeof word_end);
    memset(cnt, 0, sizeof cnt);
	z = 1;
}

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    init();
    int n; cin >> n;
    fori(n) {
        string s; cin >> s;
        add(s);
    }
    int q; cin >> q;
    fori(q) {
        string pref; cin >> pref;
        query(pref);
    }
}