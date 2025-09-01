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
    int q; cin >> q;
    bool is_rev = false;
    deque<int> dq;
    loop(i, 0, q) {
        string s; cin >> s; int x;
        if (s == "toFront") {
            cin >> x;
            is_rev ? dq.push_back(x) : dq.push_front(x);
        }
        else if (s == "push_back") {
            cin >> x;
            is_rev ? dq.push_front(x) : dq.push_back(x);
        }
        else if (s == "front" ) {
            if(dq.empty()) {
                cout << "No job for Ada?\n";   
            } else {
                if (is_rev) {
                    cout << dq.back() << '\n';
                    dq.pop_back();
                } else {
                    cout << dq.front() << '\n';
                    dq.pop_front();
                }
            }
        }
        else if (s == "back" ) {
            if(dq.empty()) {
                cout << "No job for Ada?\n";   
            } else {
                if (is_rev) {
                    cout << dq.front() << '\n';
                    dq.pop_front();
                } else {
                    cout << dq.back() << '\n';
                    dq.pop_back();
                }
            }
        }
        else if (s == "reverse" ) {
            is_rev = !is_rev;
        }
    }
}