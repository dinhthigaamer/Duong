#include<bits/stdc++.h>
using namespace std;

int n;
int a[1005];

void solve() {
    cin>>n;

    int amin=1e9, amax=-1e9;

    for(int i=1; i<=n; ++i) {
        cin>>a[i];
        amin = min(amin, a[i]);
        amax = max(amax, a[i]);
    }

    int res = (amax-amin)*(n-1)

    cout<<res<<'\n';
}

int main() {
    int test;
    cin>>test;

    while(test--) {
        solve();
    }
    return 0;
}
