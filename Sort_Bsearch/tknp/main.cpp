#include<bits/stdc++.h>
using namespace std;

#define MAX 100010
int a[MAX];
int n,k;

int main()
{
    cin>>n>>k;
    for(int i=1;i<=n;++i) cin>>a[i];
    int pos=lower_bound(a+1,a+n+1,k)-a;
    if(a[pos]!=k) pos=-1;
    cout<<pos<<endl;
    return 0;
}
