#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define MOD 1000000007
#define ii pair<int, int>
#define fi first
#define se second

const int maxn = 1e6 + 5;
vector<ll> bit_left(maxn), bit_right(maxn);

void add(vector<ll>&bit, int pos, int val) {
	++pos; 
	while (pos <= maxn) {
		bit[pos] += val;
		pos += (pos & (-pos));
	}
}

int query(vector<ll> &bit, int pos) {
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
    vector<int> v(n);
    for (int &x: v) cin >> x;
    vector<int> a = v;
    sort(begin(a), end(a));
    /**
     * Comprimir as coordenadas de v pra ter tudo <= 10^6
     * pra todo cara em v a gnt conta quantos maiores a esquerda e quantos menores a direita e multiplica
     * duas bits left and right
     * constroi a bitleft da esquerda pra direita e bitright da direita pra esquerda
     * pra cada cara em v eu faço uma query do indice em cada bit
     * 1 5 4 3
     * 0 3 2 1
     * 1 3 4 5
     * 0 1 2 3
     * bit fica 1 1 1 1
     * pra buscar o 5:
     * 1 3 4 5
     * busca binaria acha 3
     * queryleft(3) acha 0 queryright acha 2 * 0 = 0
     * primeiro tenho q achar quantos caras a esquerda de x sao maiores que x
     * a direita menor é provavelmente analogo
     * 
     * 1 5 4 3 foca ;o 5
     * sortado: 1 3 4 5
     * comprimido: 0 3 2 1
     * 
     */
    // bitleft query -> quantos maiores existem a esquerda
    // basta query(0, k) se k for 3 com coordenada comprimida
    vector<ll> left(n), right(n);
    for (int i = 0; i < n; i++) {
        int idx = lower_bound(begin(a), end(a), v[i]) - begin(a);
        left[i] = query(bit_left, maxn) - query(bit_left, idx);
        add(bit_left, idx, 1);
    }

    // bitright quantos menores existem a direita
    for (int i = n - 1; i >= 0; i--) {
        int idx = lower_bound(begin(a), end(a), v[i]) - begin(a);
        right[i] = query(bit_right, idx);
        add(bit_right, idx, 1);
    }
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        sum += left[i] * right[i];
    }
    cout << sum;
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