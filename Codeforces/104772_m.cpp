#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(), (x).end()
bool equal(char c, char d) {
    return (tolower(c) == tolower(d));
}
bool vowel(char c) {
    c = tolower(c);
    return (c == 'a') or (c == 'e') or (c == 'i') or (c == 'o') or (c == 'u') or (c == 'y');
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    string s, f;
    cin >> s >> f;
    int i = 0, j = 0;


    bool ok = true;
    while (i < s.size() and j < f.size() and ok) {
        if (equal(s[i], f[j])) {
            i++, j++;
        } else {
            while (!equal(s[i], f[j])) {
                if (vowel(f[j])) {
                    j++;
                } else {
                    ok = false;
                    break;
                }
            }
        }
    }
    while(j < f.size()) ok &= vowel(f[j++]);
    if (i == s.size() and ok) {
        cout << "Same";
    } else {
        cout << "Different";
    }
}