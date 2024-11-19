#include<bits/stdc++.h>
using namespace std;

#define MAX 200010
#define ll long long

int n, k, q;
int cnt[MAX];

int main() {
    cin >> n >> k >> q;

    for(int i=1; i<=n; ++i) {
        int l, r;
        cin >> l >> r;

        cnt[l]++;
        cnt[r+1]--;
    }

    for(int i=1; i<=2e5; ++i) {
        cnt[i] += cnt[i-1];
    }

    for(int i=1; i<=2e5; ++i) {
        if(cnt[i] >= k) cnt[i] = 1;
        else cnt[i] = 0;

        cnt[i] += cnt[i-1];
    }

    for(int i=1; i<=q; ++i) {
        int l, r;
        cin >> l >> r;

        cout << cnt[r] - cnt[l-1] <<'\n';
    }

    return 0;
}

