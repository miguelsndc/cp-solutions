#include <bits/stdc++.h>

using namespace std;

#define ll long long int
#define ld long double
#define MOD 1000000007
#define ii pair<int, int>

void solve() {
    int q; cin >> q;
    set<int> numbers;
    map<int, int> count;
    for (int i = 0; i < q; i++) {
        int type, x; cin >> type;
        if (type == 1) {
            cin >> x;
            count[x]++;
            numbers.insert(x);
        }
        else if (type == 2) {
            cin >> x;
            if ((--count[x]) == 0) {
                numbers.erase(x);
            }
        }
        else if (type == 3) {
            cout << numbers.size() << '\n';
        }
    }
}

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1; // cin >> tt;
    while(tt--) {
         solve();
    }
}