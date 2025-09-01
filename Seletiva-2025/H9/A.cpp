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
const int maxn = 1e6 + 5;

int trie[maxn][26], word_end[maxn], cnt[maxn], z = 1;

void add(string &s) {
    int cur = 0;
    fori(s.size()) {
        if (trie[cur][s[i] - 'a'] == -1) {
            memset(trie[z], -1, sizeof trie[z]);
            trie[cur][s[i] - 'a'] = z++;
            cnt[z] = 0;
        }
        cnt[cur]++;
        cur = trie[cur][s[i] - 'a'];
    }
    word_end[cur]++;
}

int query(string &s){
	int cur = 0;
	fori(s.size()){
		if(trie[cur][s[i] - 'a'] == -1) return 0;
		cur = trie[cur][s[i] - 'a'];
	}
	return cnt[cur] + word_end[cur];
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
    int n, q; cin >> n >> q;
    fori(n) {
        string s; cin >> s;
        add(s);
    }
    fori(q) {
        string pref; cin >> pref;
        writeln(query(pref));
    }
}