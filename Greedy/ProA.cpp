#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define MAX 200010

int n,k;
int a[MAX];
ll sum[MAX];

void file()
{
    freopen("file.inp","r",stdin);
    freopen("file.out","w",stdout);
}

void solve()
{
    cin>>n>>k;
    for(int i=1;i<=n;++i) cin>>a[i];

    sort(a+1, a+n+1);
    for(int i=1;i<=n;++i) sum[i] = sum[i-1]+a[i];
    ll amount = 0;
    ll turn =0;
    int ptr = 0;

    while(k>0)
    {
        for(int i=ptr+1; i<=n;++i) if(a[i]>0)
        {
            turn += (i-ptr);
            if(ptr==0) --turn;
            ptr = i;
            break;
        }

        int need = min(a[ptr]-a[ptr-1], k/(n-ptr+1));
        turn += 1ll*need*(n-ptr+1); //cerr<<turn<<endl;
        k -= 1ll*need*(n-ptr+1);

        if(need < a[ptr]-a[ptr-1])
        {
            turn += k;
            break;
        }
    }

    cout<<turn<<'\n';
}

int main()
{
    //file();
    int test;
    cin>>test;

    while(test--)
    {
        solve();
    }
    return 0;
}

 
