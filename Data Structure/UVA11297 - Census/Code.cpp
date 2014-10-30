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

typedef long long ll;

#define INF (1 << 29)
#define LEFT(x) (x << 1)
#define RIGHT(x) (LEFT(x) + 1)

pair<int, int> tree[2 << 18];
int arr[502][502];

void mergee(int c){
    tree[c].first = max(tree[LEFT(c)].first, tree[RIGHT(c)].first);
    tree[c].second = min(tree[LEFT(c)].second, tree[RIGHT(c)].second);
}

void construct(int c, int x1, int x2, int y1, int y2, bool vertical){
    if(x1 == x2 && y1 == y2){
        tree[c].first = tree[c].second = arr[x1][y1];
        return;
    }
    if(x1 == x2) vertical = false;
    if(y1 == y2) vertical = true;
    if(vertical){
        int mid = (x1 + x2) / 2;
        construct(LEFT(c), x1, mid, y1, y2, !vertical);
        construct(RIGHT(c), mid+1, x2, y1, y2, !vertical);
    }else{
        int mid = (y1 + y2) / 2;
        construct(LEFT(c), x1, x2, y1, mid, !vertical);
        construct(RIGHT(c), x1, x2, mid+1, y2, !vertical);
    }
    mergee(c);
}

void update(int c, int x, int y, int x1, int x2, int y1, int y2, bool vertical){
    if(y < y1 || y > y2 || x < x1 || x > x2){
        return;
    }
    if(x == x1 && x == x2 && y == y1 && y == y2){
        tree[c].first = tree[c].second = arr[x][y];
        return;
    }
    if(x1 == x2) vertical = false;
    if(y1 == y2) vertical = true;
    if(vertical){
        int mid = (x1 + x2) / 2;
        update(LEFT(c), x, y, x1, mid, y1, y2, !vertical);
        update(RIGHT(c), x, y, mid+1, x2, y1, y2, !vertical);
    }else{
        int mid = (y1 + y2) / 2;
        update(LEFT(c), x, y, x1, x2, y1, mid, !vertical);
        update(RIGHT(c), x, y, x1, x2, mid+1, y2, !vertical);
    }
    mergee(c);
}

pair<int, int> query(int c, int x1, int x2, int y1, int y2, int cX1, int cX2, int cY1, int cY2, bool vertical){
    if(x2 < cX1 || x1 > cX2 || y2 < cY1 || y1 > cY2){
        return make_pair(-INF, INF);
    }
    if(cX1 >= x1 && cX2 <= x2 && cY1 >= y1 && cY2 <= y2){
        return tree[c];
    }
    if(cX1 == cX2) vertical = false;
    if(cY1 == cY2) vertical = true;
    pair<int, int> left, right;
    if(vertical){
        int mid = (cX1 + cX2) / 2;
        left = query(LEFT(c), x1, x2, y1, y2, cX1, mid, cY1, cY2, !vertical);
        right = query(RIGHT(c), x1, x2, y1, y2, mid+1, cX2, cY1, cY2, !vertical);
    }else{
        int mid = (cY1 + cY2) / 2;
        left = query(LEFT(c), x1, x2, y1, y2, cX1, cX2, cY1, mid, !vertical);
        right = query(RIGHT(c), x1, x2, y1, y2, cX1, cX2, mid+1, cY2, !vertical);
    }
    return make_pair(max(left.first, right.first), min(left.second, right.second));
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.in", "r", stdin);
#endif
    
    int N, N1, q, a, b, x, d;
    char c;
    
    scanf("%d %d", &N, &N1);
    
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N1; j++){
            scanf("%d", &arr[i][j]);
        }
    }
    
    construct(1, 0, N-1, 0, N1-1, true);

    scanf("%d", &q);
    for(int i = 0; i < q; i++){
        scanf(" %c", &c);
        if(c == 'q'){
            scanf("%d %d %d %d", &a, &b, &x, &d);
            --a, --b, --x, --d;
            pair<int, int> ret = query(1, a, x, b, d, 0, N-1, 0, N1-1, true);
            printf("%d %d\n", ret.first, ret.second);
        }else{
            scanf("%d %d %d", &a, &b, &x);
            --a, --b;
            arr[a][b] = x;
            update(1, a, b, 0, N-1, 0, N1-1, true);
        }
    }
    
    return 0;
}
