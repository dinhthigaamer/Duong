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

void solve() {
    int L, R;
    cin>>L>>R;

    int res = 0;
    for(int i=L; i<=R; ++i) {
        int tmp = i;
        ll sum = 1;
        while(tmp > 1) {
            int x = nt[tmp];
            ll y = x;

            while(tmp%x == 0) {
                tmp /= x;
                y *= x;
            }

            //cout<<y<<endl;
            sum *= (y-1)/(x-1);
        }

        if(sum - i > i) ++res;
    }
    cout<<res<<endl;
}

int main() {
    snt();
    solve();

    return 0;
}


