#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define MOD 1000000007
#define vi vector<int>
#define fi first
#define se second
#define sz(x) int(x.size())
#define all(a) (a).begin(), (a).end()
#define INF 1000000009
bool prime(ll a) { if (a==1) return 0; for (int i=2;i<=round(sqrt(a));++i) if (a%i==0) return 0; return 1; }
int main(void)
{
    int N;
    int k;
    scanf("%d", &N);
    vi a(N);
    for (int i = 0; i < N; i++)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        a[i] = (x + y) % 10;
        int carry = (x + y)/10;
        k = i - 1;
        while (carry != 0)
        // bubble carry backwards
        {
            a[k] += carry;
            carry = a[k] / 10;
            a[k] %= 10;
            k--;
        }
    }
    for (k = 0; k < N; k++)
        printf("%d", a[k]);
return 0;
}