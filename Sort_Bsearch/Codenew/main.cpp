#include<bits/stdc++.h>
using namespace std;

#define MAX 100010
#define int long long
const int mod=1e9+7;
int a[MAX];
int n;

int32_t main()
{
    cin>>n;
    for(int i=1;i<=n;++i) cin>>a[i];
    sort(a+1,a+n+1);
    int res=1;
    for(int i=1;i<=n;++i) res=(res*(a[i]-(i-1)))%mod;
    cout<<res<<endl;
    return 0;
}
