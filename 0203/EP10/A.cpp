#include <bits/stdc++.h>
using namespace std;

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

int trie[maxn][26], word_end[maxn], z = 1; map<string, bool> seen;

void add(string &s) {
    if (seen[s]) {
        return;
    }
    seen[s] = true;
    int cur = 0;
    fori(s.size()) {
        if (trie[cur][s[i] - 'a'] == -1) {
            memset(trie[z], -1, sizeof trie[z]);
            trie[cur][s[i] - 'a'] = z++;
        }
        cur = trie[cur][s[i] - 'a'];
    }
    word_end[cur]++;
}

vector<string> query(string &pref){
	int cur = 0;
    vector<string> result;
	fori(pref.size()){
		if(trie[cur][pref[i] - 'a'] == -1) return result;
		cur = trie[cur][pref[i] - 'a'];
	}

    function<void(int, string)> dfs = [&](int u, string s) {
        if (word_end[u] > 0 and s != pref) {
            result.push_back(s);
        }
        fori(26) {
            if (trie[u][i] != -1) {
                dfs(trie[u][i], s + char('a' + i));
            }
        }
    };
    
    dfs(cur, pref);
	return result;
}

void init(){
	memset(trie[0], -1, sizeof trie[0]);
    memset(word_end, 0, sizeof word_end);
	z = 1;
}

int main() 
{
    init();
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    fori(n) {
        string s;cin>>s;
        add(s);
    }
    int q; cin >> q;
    fori(q) {
        writeln("Case #" << i + 1 << ":");
        string pref; cin >> pref;
        auto matches = query(pref);
        if (matches.empty()) {
            writeln("No match.");
        } else {
            for (string s: matches) {
                writeln(s);
            }
        }
    }
}