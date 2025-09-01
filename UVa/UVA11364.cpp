#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int main() {
    int tc, l, r, x, store_no;
    scanf("%d", &tc);
    while (tc--) {
        scanf("%d", &store_no);
        int l = INT_MAX, r = INT_MIN;
        for (int i = 0; i < store_no; i++) {
            scanf("%d", &x);
            l = min(l, x), r = max(r, x);
        }
        printf("%d\n", (2 * (r - l)));
    }
    return 0;
}