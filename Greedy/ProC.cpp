#include<bits/stdc++.h>
using namespace std;

int n, r;
int a[1005];
int empty_row; // hang trong 2 cho
int half_row; // hang trong 1 cho
int happy;

void solve() {
    cin>>n>>r;

    empty_row = r;
    half_row = 0;
    happy = 0;

    for(int i=1; i<=n; ++i) {
        cin>>a[i];

        if(a[i]%2 == 0) {
            empty_row -= (a[i]/2);
            happy += a[i];
        }
    }

    for(int i=1; i<=n; ++i) if(a[i]%2) {
        if(empty_row >= (a[i]+1)/2) {
            empty_row -= (a[i]+1)/2;
            half_row += 1;
            happy += a[i];
        }
        else {
            int needy_row = min(a[i]/2 - empty_row, half_row/2);
            int people_left = a[i] - 2*(empty_row + needy_row);

            //cout<<empty_row<<' '<<half_row<<' '<<needy_row<<' '<<people_left<<endl;

            happy = happy - 2*needy_row + 2*(empty_row+needy_row) - people_left;

            half_row -= needy_row;
            empty_row = 0;
        }

        //cout<<empty_row<<endl;
        //cout<<happy<<endl;
    }

    cout<<happy<<'\n';
}

int main() {
    int test;
    cin>>test;

    while(test--) {
        solve();
    }
    return 0;
}

