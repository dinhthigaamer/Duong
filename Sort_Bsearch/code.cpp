#include<bits/stdc++.h>
using namespace std;

#define MAX 100010
#define ll long long
int n;
int a[MAX];

int main()
{
    cin>>n;
    for(int i=1; i<=n; ++i) cin>>a[i];

    sort(a+1, a+n+1);
    ll sum = 0;
    int cnt = 0;

    for(int i=n; i>=1; --i)
    {
        ++cnt;
        sum += a[i];

        if(cnt == 3)
        {
            sum -= a[i];
            cnt = 0;
            continue;
        }
    }

    cout<<sum<<endl;
    return 0;
}
