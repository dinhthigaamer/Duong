#include<bits/stdc++.h>
using namespace std;

#define MAXN 100010
#define MAXM 1000010
#define ll long long

const int mod = 1e9+7;

int n;
int a[MAXN];
int nt[MAXM];
int cnt[MAXN];

void snt() {
    for(int i=0; i<=1e6; ++i) nt[i] = i;

    for(int i=2; i<=1e6; ++i) if(nt[i] == i){
        for(int j=i*2; j<=1e6; j+=i) nt[j] = i;
    }
}

void solve() {
    int N;
    cin>>N;

    for(int i=2; i<=N; ++i) {
        int tmp = i;

        while(tmp > 1) {
            int x = nt[tmp];

            while(tmp%x == 0) {
                tmp /= x;
                ++cnt[x];
            }
        }
    }

    int res=1;

    for(int i=1;i<=N;++i) if(cnt[i]%2) {
        cnt[i]--;
    }
    else {
        res = 1ll*res*i%mod;
    }
    cout<<res<<endl;
}

int main() {
    snt();
    solve();

    return 0;
}



