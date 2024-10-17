#include<bits/stdc++.h>
using namespace std;

string S;
int mark[11], ans[11];
string save[400000];
int cnt;

void check() {
    ++cnt;
    save[cnt] = "";
    for(int i=1; i<=S.size(); ++i) save[cnt] = save[cnt] + S[ans[i]];
}

void backTrack(int pos) {
    if(pos == S.size() + 1) {
        check();
        return ;
    }

    for(int i=0; i<S.size(); ++i) if(!mark[i]){
        mark[i] = 1;
        ans[pos] = i;
        backTrack(pos+1);
        mark[i] = 0;
    }
}

int main() {
    cin>>S;
    sort(S.begin(), S.end());

    backTrack(1);
    sort(save+1, save+cnt+1);

    int dem = 1;

    for(int i=2; i<=cnt; ++i) {
        if(save[i] != save[i-1]) ++dem;
    }

    cout<<dem<<endl;
    cout<<save[1]<<'\n';
    for(int i=2; i<=cnt; ++i) {
        if(save[i] != save[i-1]) cout<<save[i]<<'\n';
    }

    return 0;
}
