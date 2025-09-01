#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define MOD 1000000007
#define ii pair<int, int>
#define fi first
#define se second

vector<int> a(2000000), b (2000000);
vector<int> ta(2000000), tb(2000000);
#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int maxn = 4e6 + 5;
vector<ll> bit(maxn);

void add(int pos, int val) {
	++pos; 
	while (pos <= maxn) {
		bit[pos] += val;
		pos += (pos & (-pos));
	}
}

int query(int pos) {
	++pos;
	int sum = 0;
	while(pos > 0) {
		sum += bit[pos];
		pos -= (pos & (-pos));
	}
	return sum;
}

void solve() {
    int n; cin >> n;

    for (int i = 0; i < (n); i++) {
        add(i, 1);
    }

    for (int i = 0; i < n / 2; i++) cin >> a[i];
    for (int i = 0; i < n / 2; i++) cin >> b[i];

    for (int i = 0; i < n / 2; i++) {
        // achar kesimo da bit
        // soma acumulada de 1 ate uma posicao qlqr se for k é pq é o kesimo
        // quando achar tiro -1 pra empurrar pra frente
        // soma sempre aumenta qnd eu ando pra frente ent monotonico
        int l = 0, h = maxn, ans = -1;
        while(h >= l) {
            int m = l + (h - l) / 2;
            if (query(m) >= a[i]) {
                ans = m;
                h = m - 1;
            } else {
                l = m + 1;
            }
        }

        int va = ans;
        ta[i] = va;
        add(ans, -1);

        l = 0, h = maxn, ans = -1;
        while(h >= l) {
            int m = l + (h - l) / 2;
            if (query(m) >= b[i]) {
                ans = m;
                h = m - 1;
            } else {
                l = m + 1;
            }
        }

        int vb = ans;
        tb[i] = vb;
        add(ans, -1);
    }

    for (int i = 0; i < n / 2; i++) cout << ta[i] + 1 << ' ';
    cout << '\n';
    for (int i = 0; i < n / 2; i++) cout << tb[i]  + 1<< ' ';
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