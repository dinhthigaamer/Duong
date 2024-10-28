#include<bits/stdc++.h>
using namespace std;

#define int long long
int n;
int a[1005],b[1005],c[1005];

int32_t main()
{
    cin>>n;
    for(int i=1;i<=n;++i) cin>>a[i];
    for(int i=1;i<=n;++i) cin>>b[i];
    for(int i=1;i<=n;++i) cin>>c[i];

    sort(c+1,c+n+1);
    int res=0;
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=n;++j)
        {
            int pos=lower_bound(c+1,c+n+1,a[i]+b[j])-upper_bound(c+1,c+n+1,abs(a[i]-b[j]));
            //cout<<pos<<' ';
            res+=pos;
        }
        //cout<<endl;
    }
    cout<<res<<endl;
    return 0;
}
