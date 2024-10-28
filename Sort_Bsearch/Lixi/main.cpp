#include<bits/stdc++.h>
using namespace std;
int n;
pair<int,int> a[105];

int main()
{
    cin>>n;
    for(int i=1;i<=n;++i) cin>>a[i].second>>a[i].first;
    sort(a+1,a+n+1);

    int A=0 , B=1;
    for(int i=n;i>=1;--i)
    {
        B+=a[i].first-1;
        if(B>=0) A+=a[i].second;
    }
    cout<<A<<endl;
    return 0;
}
