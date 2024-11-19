#include<bits/stdc++.h>
using namespace std;

#define MAX 200010
#define ll long long

int n, q;
int a[MAX];
int cnt[MAX];

int main() {
    cin >> n >> q;

    for(int i=1; i<=n; ++i) cin >> a[i];

    for(int i=1; i<=q; ++i) {
        int l, r;
        cin >> l >> r;

        cnt[l]++;
        cnt[r+1]--;
    }

    for(int i=1; i<=n; ++i) {
        cnt[i] += cnt[i-1];
    }

    ll sum = 0;

    sort(cnt+1, cnt+n+1);
    sort(a+1, a+n+1);

    for(int i=1; i<=n; ++i) sum += 1ll*a[i]*cnt[i];

    cout << sum << endl;

    return 0;
}


