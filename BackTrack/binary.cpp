#include<bits/stdc++.h>
using namespace std;

int n;
int a[25];

void check() {
    for(int i=1; i<=n; ++i) {
        cout<<a[i];
    }
    cout<<endl;
}

void quaylui(int pos) {
    for(int i=1; i<pos; ++i) cout<<a[i];
    cout<<endl;
    // Da sinh xong day do dai n
    if(pos == n+1) {
        check();
        return ;
    }

    for(int i=0; i<=1; ++i) {
        a[pos] = i;

        quaylui(pos+1);
    }
}

int main() {
    cin>>n;

    quaylui(1);
    return 0;
}
