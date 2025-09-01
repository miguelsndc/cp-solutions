#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define pii pair<int, int>
#define pll pair<long long, long long>
#define vi vector<int>
#define vb vector<bool>
#define vs vector<string>
#define vll vector<long long>
#define mii map<int, int>
#define si set<int>
#define sc set<char>
#define f first
#define s second
#define sp << " " <<
#define spe << " "

// we need to store distinct tickets and know how many of them we need
// use multiset for tickets because there's no n!= m constraint
// costumer is getting the ticked with the greatest price that's is less or equal their budget
// let's use lower bound and if the value is greater than what we need we backtrack

void solve(int n, int m) {
    int h, t;
    multiset<int> tickets;
    for (int i = 0; i < n; i++) {
        cin >> h;
        tickets.insert(h);
    }
    for (int i = 0; i < m; i++) {
        cin >> t;
        auto lbound_it = tickets.lower_bound(t);
        if (*lbound_it == t) {  // we get a value == t
            cout << t << '\n';
            tickets.erase(tickets.find(*lbound_it));
        } else if (lbound_it == tickets.end() && tickets.size() > 0) {  // all values are smaller than t but we can get the greatest one
            lbound_it--;
            cout << *lbound_it << '\n';
            tickets.erase(tickets.find(*lbound_it));
        } else if (lbound_it != tickets.end() && lbound_it != tickets.begin()) {  // we got a value greater, but we can't affford it, so we backtrack
            lbound_it--;
            cout << *lbound_it << '\n';
            tickets.erase(tickets.find(*lbound_it));
        } else {  // if we can't do any of these things we are done
            cout << -1 << '\n';
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    solve(n, m);

    return 0;
}