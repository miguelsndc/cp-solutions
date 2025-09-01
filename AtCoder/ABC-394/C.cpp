#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()

#ifdef CARNEDESOOOL
#define debug(...) dbg(#__VA_ARGS__, __VA_ARGS__)
template <typename... T>
void dbg(const char* names, T... args) {
    const char* p = names;
    ((cout << string(p, strchr(p, ',') ? strchr(p, ',') : p + strlen(p)) << " = " << args << '\n',
      p = strchr(p, ',') ? strchr(p, ',') + 1 : p + strlen(p)),
     ...);
}
#else
#define debug(...)
#endif

using ll = long long;

constexpr ll inf = 1E18;
constexpr int mod = 1e9 + 7, maxn = 2e5 + 5;

void solve() {
    string s;
    cin >> s;
    vector<char> st, aux;

    for (char c : s) {
        st.push_back(c);
        while (st.size() > 1 and st[st.size() - 1] == 'A' and st[st.size() - 2] == 'W') {
            st.pop_back();
            st.pop_back();
            aux.push_back('C');
            aux.push_back('A');
        }
        while (aux.size()) {
            while (st.size() > 1 and st[st.size() - 1] == 'A' and st[st.size() - 2] == 'W') {
                st.pop_back();
                st.pop_back();
                aux.push_back('C');
                aux.push_back('A');
            }
            st.push_back(aux.back());
            aux.pop_back();
        }
    }
    for (char c : st) {
        cout << c;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1;  // cin >> tt;
    while (tt--) {
        solve();
    }
}