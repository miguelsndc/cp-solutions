#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

// -----------

int main() {
    int tc, divx, divy, x, y;
    scanf("%d", &tc);
    while (tc) {
        scanf("%d %d", &divx, &divy);
        for (int i = 0; i < tc; i++) {
            scanf("%d %d", &x, &y);
            if (x == divx || y == divy) {
                printf("divisa\n");
            } else if (x > divx && y > divy) {
                printf("NE\n");
            } else if (x > divx && y < divy) {
                printf("SE\n");
            } else if (x < divx && y > divy) {
                printf("NO\n");
            } else {
                printf("SO\n");
            }
        }

        scanf("%d", &tc);
    }
    return 0;
}