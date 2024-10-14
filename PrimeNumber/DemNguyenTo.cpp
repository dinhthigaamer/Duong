#include<bits/stdc++.h>
using namespace std;

#define MAXN 100010
#define MAXM 1000010

int n;
int nt[MAXM];

void snt() {
    for(int i=0; i<=1e6; ++i) nt[i] = 1;
    nt[0]=nt[1]=0;

    for(int i=2; i<=1e6; ++i) if(nt[i] == 1){
        for(int j=i*2; j<=1e6; j+=i) nt[j] = 0;
    }
}

int main() {
    snt();

    cin>>n;
    for(int i=1; i<=n; ++i) {
        int x;
        cin>>x;

        if(nt[x]) cout<<"YES\n";
        else cout<<"NO\n";
    }

    return 0;
}
