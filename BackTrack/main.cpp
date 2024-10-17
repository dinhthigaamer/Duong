#include<bits/stdc++.h>
using namespace std;
long long const N=10;
long long a[N],y[N],x[N];
long long n,m;
long long dem=0;
void ktra()
{
    for(long long i = 1; i<= n ; i++) y[i]=x[i];
    for(long long i = 1 ; i <= n ; i++)
    {
        if(a[i]==0) y[i]=x[i],dem++; //trang thai k thay doi;
        else if (a[i]==1) y[i]=1-y[i],dem++;//trang thai thay doi giua 0 va 1
        else if (a[i]==2)
        {
            for(long long  x = 1 ; x <=n/m;x++)
            { //trang thai thay doi giua 0 va 1 cho den vi tri n*m
                for(int i = 1 ; i<= x*m;i++) y[i]=1-y[i];

        }
    }
}
void duyet(int i )
{
    if (i == n+1) ktra();
    else
{
    for(int j = 0 ; j<= 2 ; j++)
    {
        x[i] = j;
        duyet(i+1);
    }
}
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();
    cin>>n>>m;
    char s;
    cin >> s;
    duyet(1);
    cout << dem;
}
