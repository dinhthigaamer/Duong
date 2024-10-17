#include<bits/stdc++.h>
using namespace std;

int n;
int a[25];
int u[25];
int c[25][25];
int choose[25];
int res;

void check() {
    int distance = 0;

    for(int i=1; i<n; ++i) distance += c[a[i]][a[i+1]];
    distance += c[a[n]][a[1]];

    if(distance < res) {
        distance = res;
        // luu lai duong di toi uu
        for(int i=1;i<=n;++i) u[i] = a[i];
    }
}

void hoanvi(int pos) {
    //for(int i=1; i<pos; ++i) cout<<a[i]<<' ';
    //cout<<endl;
    if(pos == n+1) {
        check();
        return ;
    }

    for(int i=1; i<=n; ++i) {
        if(choose[i] == 1) {
            continue;
        }
        choose[i] = 1;
        a[pos] = i;
        hoanvi(pos+1);
        choose[i] = 0;
    }
}

int main() {
    cin>>n;
    for(int i=1; i<=n; ++i){
        for(int j=1; j<=n; ++j) cin>>c[i][j];
    }

    res = INT_MAX;
    hoanvi(1);

    cout<<distance<<endl;
    for(int i=1; i<=n; ++i) cout<<u[i]<<' ';
    cout<<u[1];

    return 0;
}
