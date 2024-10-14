#include<bits/stdc++.h>
using namespace std;

#define MAX 200010

int nt[MAX];
int cnt[MAX];

void snt() {
    for(int i=2; i<=1e5; ++i) nt[i] = i;

    for(int i=2; i<=1e5; ++i) if(nt[i] == i) {
        for(int j=i*2; j<=1e5; j+=i) nt[j] = i;
    }
}

void prepare() {
    for(int i=1; i<=1e5; ++i) {
        int x = i;
        int minFactor = nt[x];

        while(x > 1) {
            minFactor = min(minFactor, nt[x]);
            x /= nt[x];
        }
        ++cnt[minFactor];
    }
}

void solve() {
    int test;
    cin>>test;

    while(test--) {
        long long x;
        cin>>x;

        if(x > 1e5) cout<<0;
        else
            cout<<cnt[x];

        cout<<'\n';
    }
}

int main() {
    snt();
    prepare();
    solve();

    return 0;
}
