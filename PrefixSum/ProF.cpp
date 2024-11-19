#include<bits/stdc++.h>
using namespace std;

#define MAX 200010
#define ll long long

int n, m, k;
int a[MAX];
int L[MAX], R[MAX], D[MAX];
int cnt[MAX];
ll add[MAX];

int main() {
    cin >> n >> m >> k;

    for(int i=1; i<=n; ++i) cin >> a[i];

    for(int i=1; i<=m; ++i) {
        cin >> L[i] >> R[i] >> D[i];
    }

    for(int i=1; i<=k; ++i) {
        int x, y;
        cin >> x >> y;

        cnt[x]++;
        cnt[y+1]--;
    }

    for(int i=1; i<=m; ++i) {
        cnt[i] += cnt[i-1];
    }

    for(int i=1; i<=m; ++i) {
        add[L[i]] += 1ll*D[i]*cnt[i];
        add[R[i]+1] -= 1ll*D[i]*cnt[i];
    }

    for(int i=1; i<=n; ++i) {
        add[i] += add[i-1];
        cout << (long long) add[i] + a[i] <<' ';
    }

    return 0;
}


