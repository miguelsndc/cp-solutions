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

char open(char c) {
    if (c == ']') return '[';
    if (c == ')') return '(';
    if (c == '>') return '<';
}

char is_open(char c) {
    return (c == '[' or c == '(' or c == '<');
}

void solve() {
    string s;
    cin >> s;
    stack<char> st;
    for (char c : s) {
        if (st.size() and is_open(st.top()) and !is_open(c) and open(c) == st.top()) {
            st.pop();
        } else {
            st.push(c);
        }
    }
    if (st.empty()) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
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