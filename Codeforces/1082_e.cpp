#include <bits/stdc++.h>
using namespace std;
using ll = long long;

template<typename T> ostream& operator<<(ostream &os, const vector<T> &v){os<<"{";string sep="";for(const auto &x:v)os<<sep<<x,sep=", ";return os<<"}";}
template<typename T,size_t N> ostream& operator<<(ostream &os,const array<T,N> &a){os<<"{";string sep="";for(const auto &x:a)os<<sep<<x,sep=", ";return os<<"}";}
template<typename T> ostream& operator<<(ostream &os,const set<T> &s){os<<"{";string sep="";for(const auto &x:s)os<<sep<<x,sep=", ";return os<<"}";}
template<typename K,typename V> ostream& operator<<(ostream &os,const map<K,V> &m){os<<"{";string sep="";for(const auto &x:m)os<<sep<<"("<<x.first<<": "<<x.second<<")",sep=", ";return os<<"}";}
template<typename A,typename B> ostream& operator<<(ostream &os,const pair<A,B> &p){return os<<"("<<p.first<<", "<<p.second<<")";}

void dbg_out(){cerr<<endl;}
template<typename Head,typename... Tail>void dbg_out(Head H,Tail... T){cerr<<" "<<H;dbg_out(T...);}

#ifdef MIGUEL_DEBUG
    #define dbg(...) cerr<<"("<<#__VA_ARGS__<<"):" , dbg_out(__VA_ARGS__)
#else
    #define dbg(...)
#endif

void solve(){
    int n; cin >> n;
    map<int,int> mp;
    for (int i = 0; i < n; i++) {
        mp[i % 4] += i * i;
    }
    dbg(mp);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T=1; // cin>>T;
    while(T--)solve();
}