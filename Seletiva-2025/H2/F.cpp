#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define all(a) a.begin(), a.end()
#define pll pair<ll, ll>
#define pii pair<int, int>
#define vi vector<int>
#define MOD 1000000007
#define loop(x, s, n) for(int x = s; x < n; x++)

// f (k) k tamanho da string
// retorna se existe caracter k dominante
// monotonica pois sempre true a partir de um certo k (k <= tam da string)
// passa em nlogn checagem * binsearch

// abacaba
// 

bool ok(int k, string &s) {

    set<int> st;
    st.insert(begin(s), end(s));

    if (st.size() == s.size()) {
        return (s.size()/ 2 + 1) < k;
    }
    else if (st.size() == 1) {
        return 1 < k;
    }

    map<char, pair<int,int>> mp;
    for (int i = 0; i < s.size(); i++) {
        mp[s[i]] =  {i + 1, max(mp[s[i]].second, i + 1 - mp[s[i]].first)};
    }

    for (auto [key, v]: mp) {
        mp[key].second = max(mp[key].second, abs(mp[key].first - (int)s.size()) + 1);
    }

    for (auto [_, v]: mp) {
        if (v.second < k) {
            return true;
        }
    }
    return false;
}

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s; cin >> s;
    int x = 0;
    for (int b = s.size(); b >= 1; b /= 2) {
        while(!ok(x + b, s)) x += b;
    }
    cout << x;
}