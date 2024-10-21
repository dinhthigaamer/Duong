/*
    Ta quay lui cac can nha. Moi can nha co the la 0(khong co nguoi mua) hoac i neu nguoi thu i mua.
*/

#include<bits/stdc++.h>
using namespace std;

int n, l;
int a[25];
int cnt;
int x[25], mask[25];
int house[105];
int p;

void xuat()
{
    for(int i=1; i<=l;)
    {
        if(house[i] > 0)
        {
            for(int j=1; j<=a[house[i]]; ++j) cout<<house[i]<<' ';
            i = i + a[house[i]];
        }
        else
        {
            cout<<0<<' ';
            i++;
        }
    }
    cout<<'\n';
}

void backTrack(int pos, int sum)
{
    //cout<<pos<<' '<<sum<<endl;
    if(cnt == 1000) return ;

    if(l-pos+1 < sum) return ;

    if(pos == l+1)
    {
        ++cnt;
        xuat();
        return ;
    }

    for(int i=0; i<=n; ++i)
    {
        if(i>0 && mask[i]) continue;

        if(i==0)
        {
            house[i] = 0;
            backTrack(pos+1, sum);
        }
        else
        {
            mask[i] = 1;
            house[pos] = i;
            backTrack(pos + a[i], sum-a[i]);

            mask[i] = 0;
            house[pos] = 0;
        }
    }
}

int main()
{
    cin>>l>>n;
    for(int i=1;i<=n;++i) cin>>a[i];

    for(int i=1; i<=n; ++i)
    {
        if(cnt == 1000) break;
        mask[i] = 1;
        house[1] = i;
        int sum = 0;
        for(int j=1; j<=n; ++j) if(i!=j) sum += a[j];
        backTrack(a[i]+1, sum);

        mask[i] = 0;
        house[1] = 0;
    }

    return 0;
}
