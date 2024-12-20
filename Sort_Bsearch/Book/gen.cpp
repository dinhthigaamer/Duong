#include "testlib.h"
#include <iostream>
#include <vector>
using namespace std;
#define ll long long
#define MAX 200010

long long ran(long long L,long long R)
{
    long long res = 0;
    for(int i=0;i<4;++i)
        res = (res*(1<<15))^(rnd.next(0, 32627)&((1<<15)-1));

    return L + res%(R-L+1);
}

void Gen(int limit)
{
    int n,m,p;
    if(limit <= 20){
         n = ran(3, 1000);
         m = ran(n,1000);
         p = ran(1, n);
    }
    else
    if(limit <= 36) {
        n = ran(3, 100000);
        m = ran(n, 100000);
        p = ran(1, n);
    }
    else
    if(limit <= 40){
        n = 100000;
        m = 6000;
        p = ran(1, n);
    }
    cout<<n<<endl;

    for(int i=1;i<=n;++i)
    {
        int x = ran(1, 1e9);
        cout<<x;
        if(i<n) cout<<' ';
    }
    cout<<endl;
}

void File()
{
    freopen("file.inp","w",stdout);
}

int main(int argc, char* argv[])
{
    registerGen(argc, argv, 1);
    prepareOpts(argc, argv);
    //File();
    int value_t = opt<int>("value_t");
    int order = opt<int>("order");

    Gen(value_t);


    return 0;
}


