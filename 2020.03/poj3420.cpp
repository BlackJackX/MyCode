/*
幂矩阵运算,轻松!!!
*/
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

typedef vector<int> vec;
typedef vector<vec> mat;

mat v0(1, vec(16));
mat A(16, vec(16));

int n, m;

mat transpose(mat &X) {
    mat Xt(X.size(), vec(X[0].size()));
    for(int i=0; i<X.size(); i++) {
        for(int j=0; j<X[0].size(); j++) {
            Xt[j][i] = X[i][j];
        }
    }
    return Xt;
}

mat mul(mat &X, mat &Y) {
    mat Z(X.size(), vec(Y[0].size()));
    mat Yt = transpose(Y);
    for(int i=0; i<X.size(); i++) {
        for(int j=0; j<Yt.size(); j++) {
            for(int k=0; k<X[i].size(); k++) {
                Z[i][j] += X[i][k] * Yt[j][k];
                Z[i][j] %= m;
            }
        }
    }
    return Z;
}

mat pow(mat X, int n) {
    int num = n;
    mat Xn(X.size(), vec(X[0].size()));
    for(int i=0; i<X.size(); i++)
        Xn[i][i] = 1;
    while(num !=0) {
        if(num&1 == 1)
            Xn = mul(Xn, X);
        X = mul(X, X);
        num >>= 1;
    }
    return Xn;
}


int main() {
    freopen("input.txt", "r", stdin);
    while(scanf("%d%d", &n, &m) == 2) {
        if(n+m == 0)
            break;
        for(int i=0; i<16; i++)
            v0[0][i] = 0;
        v0[0][15] = 1;
        for(int i=0; i<16; i++)
            for(int j=0; j<16; j++)
                A[i][j] = 0;
        for(int i=0; i<16; i++) {
            int t = ~i & 15;
            int m = 3;
            A[i][t] = 1;
            for(int j=0; j<3; j++) {
                if((t&(m<<j)) == 0) {
                    A[i][t|(m<<j)] = 1;
                }
            }
            if(t == 0)
                A[i][15] = 1;
        }

        mat An = pow(A, n);
        mat vn = mul(v0, An);
        
        printf("%d\n", vn[0][15]);
    }

    return 0;
}