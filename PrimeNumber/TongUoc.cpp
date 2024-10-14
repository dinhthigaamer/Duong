#include<bits/stdc++.h>
using namespace std;

#define MAXN 100010
#define MAXM 1000010
#define ll long long

int n;
int a[MAXN];
int nt[MAXM];

void snt() {
    for(int i=0; i<=1e6; ++i) nt[i] = i;

    for(int i=2; i<=1e6; ++i) if(nt[i] == i){
        for(int j=i*2; j<=1e6; j+=i) nt[j] = i;
    }
}

int main() {
    snt();

    cin>>n;
    for(int i=1; i<=n; ++i) cin>>a[i];

    for(int i=1; i<=n; ++i) {
        ll sum = 1;
        while(a[i]>1) {
            int x = nt[a[i]];
            ll y = x;

            while(a[i]%x == 0) {
                a[i] /= x;
                y *= x;
            }

            //cout<<y<<endl;
            sum *= (y-1)/(x-1);
        }

        cout<<sum<<' ';
    }

    return 0;
}

