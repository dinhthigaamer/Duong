#include<bits/stdc++.h>
using namespace std;

#define MAX 200010
#define ll long long

int n, q;
ll a[MAX];
ll sum[MAX];

int main() {
    cin>>n>>q;
    for(int i=1; i<=n; ++i) cin>>a[i];

    for(int i=1; i<=n; ++i) sum[i] = sum[i-1] + a[i];

    for(int i=1; i<=q; ++i) {
        int l, r;
        cin>>l>>r;
        cout<<sum[r] - sum[l-1]<<'\n';
    }

    return 0;
}
