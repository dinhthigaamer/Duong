#include<bits/stdc++.h>
using namespace std;
#define ll long long

int n;
ll a[20][20];
int x[20];
int mask[20];
ll result;

void backtrack(int pos, ll sum)
{
    if(sum > res) return;
    if(pos==n+1)
    {
        //for(int i=1;i<=n;++i) cout<<x[i]<<' ';
        //cout<<sum + a[x[pos]][x[1]]<<endl;
        result = min(result, sum + a[x[n]][x[1]]);
        return ;
    }

    for(int u=1;u<=n;++u) if(!mask[u])
    {
        x[pos] = u;
        mask[u] = 1;
        if(pos>1) backtrack(pos+1, sum + a[x[pos-1]][u]);
        else
            backtrack(pos+1, sum);

        mask[u] = 0;
    }
}

int main()
{
    cin>>n;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j) cin>>a[i][j];

    result = 1e18;
    backtrack(1, 0);

    cout<<result<<endl;
    return 0;
}
