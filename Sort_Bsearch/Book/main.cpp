#include<bits/stdc++.h>
using namespace std;

#define int long long
#define MAX 100010
int a[MAX],n;
int sum;

int32_t main()
{
    cin>>n;
    for(int i=1;i<=n;++i) cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;++i) sum+=a[i];
    for(int i=n-2;i>=1;i-=3)
    {
        sum-=a[i];
    }
    cout<<sum<<endl;
}
