#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int main() {
    int tc, a, b;
    scanf("%d", &tc);
    while (tc--) {
        scanf("%d %d", &a, &b);
        if (a == b) {
            printf("=\n");
        } else if (a < b) {
            printf("<\n");
        } else {
            printf(">\n");
        }
    }
    return 0;
}