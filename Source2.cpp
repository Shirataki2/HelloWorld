/*最長共通部分列*/
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
#define rep(i, n) for(int i=0;i<n;i++)
#define rep1(i, n) for(int i=1;i<=n;i++)
#define MAX 2000

int c[MAX][MAX];

/*
    最長共通部分列(LCS)のDPアルゴリズム
    x[i]==y[j]:
        x[i-1]とy[j-1]のLCS + 1
    x[i]!=y[j]:
        max(x[i-1]とy[j]のLCS,x[i]とy[j-1]のLCS)
*/
int LCS(string X,string Y){
    int n=X.size();
    int m=Y.size();
    int maxl=0;
    X=' ' +X;
    Y=' ' +Y;
    rep1(i, n) c[i][0]=0;
    rep1(j, m) c[0][j]=0;
    rep1(i,n){
        rep1(j,m){
            if(X[i]==Y[j])  c[i][j] = c[i - 1][j - 1] + 1;
            else            c[i][j] = max(c[i-1][j],c[i][j-1]);
            maxl = max(maxl,c[i][j]);
        }
    }

    return maxl;
}

int main(void){
    string X,Y;
    int n;cin>>n;
    rep(i,n){
        cin >> X >> Y;
        cout << LCS(X,Y)<<endl;
    }
    return 0;
}