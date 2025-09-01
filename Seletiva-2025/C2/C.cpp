#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define all(a) a.begin(), a.end()
#define pll pair<ll, ll>
#define pii pair<int, int>
#define vi vector<int>
#define MOD 1000000007
#define loop(x, s, n) for(int x = s; x < n; x++)

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tt; cin >> tt;
    stack<string> pile;
    int snowcoatc = 0;
    while(tt--) {
        string inst; cin >> inst;

        if(inst == "put") {
            string s; cin >> s;
            pile.push(s);
        }
        else if(inst == "get") {
            if (pile.empty()) {
                cout << "empty\n";
                continue;
            }

            string s = pile.top();
            cout << s << '\n';
            pile.pop();
        }
        else if(inst == "iditarod") {
            stack<string> r;

            bool found = false;

            while(!pile.empty()) {
                string s = pile.top();
                if (s == "snowcoat") {
                    found = true;
                    pile.pop();
                    break;
                } else {
                    r.push(s);
                    pile.pop();
                }
            }

            while(!r.empty()) {
                pile.push(r.top());
                r.pop();
            }

            cout << (found ? "winner winner chicken dinner :)\n" : "oopsimcold :(\n");
        }
    } 
}