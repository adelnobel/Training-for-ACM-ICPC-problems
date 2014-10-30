#include <vector>
#include <cstdio>
#include <cstring>
#include <queue>
#include <cctype>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <bitset>
#include <map>
#include <complex>
#include <ctime>
#include <numeric>
#include <set>

using namespace std;

#define EPS 1e-7

vector<double> multiplyByScalar(const double &s, const vector<double> &op){
    vector<double> ret(op.begin(), op.end());
    for(int i = 0; i < ret.size(); i++){
        ret[i] *= s;
    }
    return ret;
}

void addVectors(const vector<double> &v1, vector<double> &v2){
    for(int i = 0; i < v1.size(); i++){
        v2[i] += v1[i];
    }
}

int findRow(const vector< vector< double > > &mat, int col, int to){
    for(int i = 0; i <= to; i++){
        if(fabs(mat[i][col]) > EPS){
            return i;
        }
    }
    return -1;
}

void printMatrix(const vector< vector< double > > &mat){
        for(int i = 0; i < mat.size(); i++){
            for(int j = 0; j < mat.size(); j++){
                cout << mat[i][j] << " ";
            }
            cout << endl;
        }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.in", "r", stdin);
#endif
    
    int n;
    while(scanf("%d", &n), n){
        if(n == 1){
            scanf("%d", &n);
            printf("%d\n", n);
            continue;
        }
        vector< vector< double > > mat(n, vector<double>(n, 0));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                scanf("%lf", &mat[i][j]);
            }
        }
        
        double det = 1;
        
        for(int i = 0; i < n-1; i++){ //For all columns except the last one!
            int to = n-i-1;
            int pivotRow = findRow(mat, i, to);
            if(pivotRow == -1) {
                continue;
            }
            if(to != pivotRow){
                det *= -1;
                swap(mat[to], mat[pivotRow]);
            }
            
            for(int j = 0; j < to; j++){
                if(fabs(mat[j][i]) < EPS) continue;
                vector<double> temp = multiplyByScalar(-mat[j][i] / mat[to][i] , mat[to]);
                addVectors(temp, mat[j]);
            }
            //printMatrix(mat);
        }
        //printMatrix(mat);
        for(int i = 0; i < n-2; i++){
            det *= mat[i][n-i-1];
            if( ((n-i-1) & 1)) det *= -1;
        }
        det *= -(mat[n-1][0] * mat[n-2][1]);
        if(fabs(det) < EPS) printf("0\n");
        else printf("%.0lf\n", det);
    }
    
    printf("*\n");
    
    return 0;
}