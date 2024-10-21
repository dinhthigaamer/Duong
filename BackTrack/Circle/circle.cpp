#include<bits/stdc++.h>
using namespace std;

int n;
int nt[80];
int ans[22], mark[22];
int res = 0;

void backTrack(int pos) {
    //for(int i=1;i<=2*n;++i) cout<<ans[i]<<' ';cout<<endl;
    if(pos == 2*n+1) {
        //for(int i=1;i<=2*n;++i) cout<<ans[i];cout<<endl;
        if(nt[ans[1]+ans[2*n]]) ++res;
        return ;
    }

    int start = 3;
    if(ans[pos-1]%2==1) start=2;

    for(int i=start; i<=2*n; i+=2) if(!mark[i]) {
        if(nt[i+ans[pos-1]] == 0) continue;
        mark[i] = 1;
        ans[pos] = i;
        backTrack(pos+1);

        mark[i] = 0;
        ans[pos] = 0;
    }
}

int main() {
    cin>>n;

    for(int i=2; i<=4*n; ++i) {
        nt[i] = 1;
        for(int j=2; j*j<=i; ++j) if(i%j == 0) nt[i] = 0;
        //if(nt[i]==1) cout<<i<<' ';
    }

    ans[1] = 1;
    backTrack(2);

    cout<<res<<endl;
    return 0;
}
