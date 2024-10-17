#include<bits/stdc++.h>
using namespace std;

int n;
int a[25];
int u[25];
int c[25][25];
int choose[25];
int res;

void check() {
    if(nt[a[2*n]+a[1]]) ++res;
}

void hoanvi(int pos) {
    //for(int i=1; i<pos; ++i) cout<<a[i]<<' ';
    //cout<<endl;
    if(pos == 2*n+1) {
        check();
        return ;
    }

    int start = 0;
    if(a[pos-1]%2==0) start = 3;
    else start = 2;

    for(int i=start; i<=2*n; i+=2) {
        if(choose[i] == 1) {
            continue;
        }

        // gia su dien a[pos] = i
        if(nt[a[pos-1]+i]) {
            choose[i] = 1;
            a[pos] = i;
            hoanvi(pos+1);
            choose[i] = 0;
        }
    }
}

int main() {
    cin>>n;
    for(int i=1; i<=n; ++i){
        for(int j=1; j<=n; ++j) cin>>c[i][j];
    }

    a[1] = 1;
    hoanvi(1);

    return 0;
}

