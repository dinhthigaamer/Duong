#include<bits/stdc++.h>
using namespace std;

int n;
int a[25];
int choose[25];

void check() {
    for(int i=1; i<=n; ++i) {
        cout<<a[i]<<' ';
    }
    cout<<endl;
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
        // luc nay choose[i] == 0 => ta chon i => choose[i] = 1
        choose[i] = 1;
        a[pos] = i;
        hoanvi(pos+1);

        // khong chon i nua
        choose[i] = 0;
    }
}

int main() {
    cin>>n;

    hoanvi(1);

    return 0;
}
