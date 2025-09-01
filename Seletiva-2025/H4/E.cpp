#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define MOD 1000000007
#define ii pair<int, int>
#define fi first
#define se second

/*  
    ~ "friends"; * "enemies";
    1. If x ∼ y and y ∼ z then x ∼ z (The friends of my friends are my friends as well.
    2. If x ∼ y then y ∼ x (Friendship is mutual.)
    3. x ∼ x (Everyone is a friend of himself.)
    ∗ is symmetric and irreflexive
    1. If x ∗ y then y ∗ x (Hatred is mutual.)
    2. Not x ∗ x (Nobody is an enemy of himself.)
    Also
    1. If x ∗ y and y ∗ z then x ∼ z (A common enemy makes two people friends.
    2. If x ∼ y and y ∗ z then x ∗ z (An enemy of a friend is an enemy.
    Operations setFriends(x,y) and setEnemies(x,y) must preserve these properties. 

 */

const int MAXN = 2 * (1e4 + 5);
int parents[MAXN];
int sizes[MAXN];
void init() {
    for (int i = 0; i < MAXN; i++) {
        parents[i] = i;
        sizes[i] = 1;
    }
}

int find(int x) { return parents[x] == x ? x : (parents[x] = find(parents[x])); }

bool unite(int x, int y) {
    int x_root = find(x);
    int y_root = find(y);
    if (x_root == y_root) { return false; }
    if (sizes[x_root] < sizes[y_root]) { swap(x_root, y_root); }
    sizes[x_root] += sizes[y_root];
    parents[y_root] = x_root;
    return true; // (some condition met for component);
}

// (0, n) means friends (n , 2n) means enemies
bool areFriends(int x, int y) {
    return find(x )== find(y);
}
bool areEnemies(int x, int y, int ex, int ey) {
    return find(x )== find(ey) || find(y )== find(ex);
}

void setFriends(int x, int y, int ex, int ey) {
    if (areEnemies(x, y, ex, ey)) {
        cout << -1 << '\n';
        return;
    }
    unite(ex, ey);
    unite(x, y);
}
void setEnemies(int x, int y, int ex, int ey) {
    if (areFriends(x, y)) {
        cout << -1 << '\n';
        return;
    }
    unite(x, ey);
	unite(y, ex);
}

void solve() {
    int n, c, x, y;
    cin >> n;
    init();
    while((cin >> c >> x >> y)) {
        if (!c && !x && !y) break;
        int xr = find(x), yr = find(y);
        int exr = find(x + n), eyr = find(y + n);
        if (c == 1) {
			setFriends(xr, yr, exr, eyr);
		} else if (c == 2) {
			setEnemies(xr, yr, exr, eyr);
		} else if (c == 3) {
			cout << (areFriends(xr, yr) ? 1 : 0) << '\n';
		} else {
			cout << (areEnemies(xr, yr, exr, eyr) ? 1 : 0) << '\n';
		}
    }
}

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1; // cin >> tt;
    for (int t = 1; t <= tt; t++) {
         solve();
    }
}