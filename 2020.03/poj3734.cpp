/*
递推公式写错了, ...
背一下矩阵乘法
*/
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int M = 10007;
typedef vector<int> vec;
typedef vector<vec> mat;
int t, n;

mat mul(mat X, mat Y) {
    mat Z(X.size(), vec(Y[0].size()));
    for(int i=0; i<X.size(); i++) {
        for(int j=0; j<Y[0].size(); j++) {
            for(int k=0; k<Y.size(); k++) {
                Z[i][j] += X[i][k]*Y[k][j];
                Z[i][j] %= M;
            }
        }
    }
    return Z;
}

mat pow(mat A, int n) {
    mat B(A.size(), vec(A.size()));
    for(int i=0; i<A.size(); i++) {
        B[i][i] = 1;
    }
    while(n > 0) {
        if(n & 1)
            B = mul(B, A);
        A = mul(A, A);
        n >>= 1;
    }
    return B;
}

void print_mat(mat X) {
    for(int i=0; i<X.size(); i++) {
        for(int j=0; j<X[i].size(); j++) {
            cout << X[i][j] << ' ';
        }
        cout << endl;
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    cin >> t;

    while(t--) {
        mat A(3, vec(3));
        A[0][0]=2;A[0][1]=1;A[0][2]=0;
        A[1][0]=2;A[1][1]=2;A[1][2]=2;
        A[2][0]=0;A[2][1]=1;A[2][2]=2;

        cin >> n;
        A = pow(A, n);
        cout << A[0][0] << endl;
    }

    return 0;
}