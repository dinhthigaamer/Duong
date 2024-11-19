#include <bits/stdc++.h>
#define nmax 1000005
#define int long long
using namespace std;

int n,k,ok;
int a[nmax],t[nmax];
int b[nmax],res;
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    res = 1e18;
    cin >> n >> k;
    for (int i=1;i<=n;++i)
    {
        cin >> a[i];
        if (a[i] >= k) ok = 1;
    }

    if (ok)
    {
        cout << 1;
        return 0;
    }
    t[0]=0;
    for (int i=1;i<=n;++i) t[i] = (long long) t[i-1] + a[i];

    for (int i=1;i<=n;++i)
    {
        b[i] = t[i];
        if (t[i]>=k)
        {
            int u = lower_bound(b,b+i,t[i]-k) - b - 1;
            if (u<0 || u>=i) continue;
            int kc = i - u;
            res = min(res,kc);
        }
    }
    if(res==1e18) res=n;
    cout << res;
}

