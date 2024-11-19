#include<bits/stdc++.h>
using namespace std;

#define MAX 100010
#define ll long long

int n, m;
int a[MAX];
ll sumv[MAX], sumu[MAX];

int main() {
    cin >> n;
    for(int i=1; i<=n; ++i) cin >> a[i];

    for(int i=1; i<=n; ++i) sumv[i] = sumv[i-1] + a[i];

    sort(a+1, a+n+1);
    for(int i=1; i<=n; ++i) sumu[i] = sumu[i-1] + a[i];

    cin >> m;

    for(int i=1; i<=m; ++i) {
        int type, l, r;
        cin >> type >> l >> r;

        if(type == 1) cout << (sumv[r] - sumv[l-1]);
        else
            cout << (sumu[r] - sumu[l-1]);

        cout << '\n';
    }

    return 0;
}
