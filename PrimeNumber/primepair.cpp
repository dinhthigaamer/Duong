#include<bits/stdc++.h>
using namespace std;

#define MAX 10000100
#define ll long long

int nt[MAX];
int m;
ll prime[MAX];
int digit[MAX], cnt;

int check(ll x) {
    for(ll i=2; i*i<=x; ++i) if(x%i==0) return 0;
    return 1;
}

void ghep(long long x,long y) {
    cnt = 0;
    while(y > 0) {
        digit[++cnt] = y%10;
        y /= 10;
    }

    for(int i=cnt; i>=1; --i) {
        x = x*10 + digit[i];
    }
    if(x > 2e6) return ;
    //if((x > 2e6) && (!check(x))) return ;
    if(nt[x] != x) return ;
    prime[++m] = x;
}

void snt() {
    for(int i=2; i<=1e7; ++i) nt[i] = i;

    int tmp = 0;

    for(int i=2; i<=2e6; ++i) if(nt[i] == i) {
        for(int j=i*2; j<=2e6; j+=i) nt[j] = i;
    }
}

void solve() {
    int tmp = 0;
    for(int i=2; i<=2e6;++i) if(nt[i]==i){
        if(tmp == 0) tmp = i;
        else {
            ghep(tmp, i);
            tmp = 0;
        }
    }

    cout<<m<<endl;
    int k;
    cin>>k;
    cout<<prime[k]<<endl;
}

int main() {
    snt();
    //prepare();
    solve();

    return 0;
}

