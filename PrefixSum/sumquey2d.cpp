
#include<bits/stdc++.h>
using namespace std;

#define MAX 200010
#define ll long long

int n, m, q;
ll a[1005][1005];
ll sum[1005][1005];

ll getsum(int x, int y, int z, int t) {
    return sum[y][t] - sum[x-1][t] - sum[y][z-1] + sum[x-1][z-1];
}

int main() {
    ios_base::sync_with_stdio(NULL); cin.tie(NULL);
    cin>>n>>m>>q;
    for(int i=1; i<=n; ++i) {
        for(int j=1; j<=m; ++j) cin>>a[i][j];
    }

    for(int i=1; i<=n; ++i) {
        for(int j=1; j<=m; ++j) {
            sum[i][j] = sum[i-1][j] + sum[i][j-1] + a[i][j] - sum[i-1][j-1];
        }
    }

    for(int i=1; i<=q; ++i) {
        int x, y, z, t;
        cin>>x>>y>>z>>t;
        cout<<getsum(x,y,z,t)<<'\n';
    }

    return 0;
}
