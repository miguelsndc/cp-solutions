#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
// -----------
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string text = "#";
    int i = 1;
    while (cin >> text && text != "#") {
        string ans;
        if (text == "HELLO") {
            ans = "ENGLISH";
        } else if (text == "HOLA") {
            ans = "SPANISH";
        } else if (text == "HALLO") {
            ans = "GERMAN";
        } else if (text == "BONJOUR") {
            ans = "FRENCH";
        } else if (text == "CIAO") {
            ans = "ITALIAN";
        } else if (text == "ZDRAVSTVUJTE") {
            ans = "RUSSIAN";
        } else {
            ans = "UNKNOWN";
        }
        cout << "Case " << i << ": " << ans << "\n";
        i++;
    }

    return 0;
}