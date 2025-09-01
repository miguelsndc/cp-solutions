#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n; cin >> n;
    int a[32] = {0};
    for (int i = 0; i < 30; i++) {
        if((1<<i)&n) {
            a[i] = 1;
        } else {
            a[i]=0;
        }
    }

    for (int i = 0; i < 30;i++) {
        if(a[i]&&a[i+1]){
            int carry=i;
            while(a[carry])a[carry]=0, carry++;
            a[i]=-1;
            a[carry]=1;
        }
    }
    cout <<32<<'\n';
    for(int i=0;i<32;i++){
        cout<<(a[i])<<" ";
    }
    cout <<'\n';
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1; cin >> T;
    while(T--) solve();
}