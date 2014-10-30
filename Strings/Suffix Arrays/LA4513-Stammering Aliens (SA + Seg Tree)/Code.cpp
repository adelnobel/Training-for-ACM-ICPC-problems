#include <vector>
#include <cstdio>
#include <cstring>
#include <queue>
#include <cctype>
#include <cmath>
#include <algorithm>

using namespace std;

typedef long long ll;

#define N 40010

int m;

char s[N];

int ranks[20][N];

int sArray[N];

int maxLog, curLog, len;

bool mycmp(const int& i1, const int& i2){
    if(ranks[curLog - 1][i1] != ranks[curLog - 1][i2]){
        return ranks[curLog - 1][i1] < ranks[curLog - 1][i2];
    }
    if(i1 + (1 << (curLog-1)) >= len){
        return true;
    }
    if(i2 + (1 << (curLog-1)) >= len){
        return false;
    }
    return ranks[curLog - 1][i1 + (1 << (curLog-1))] < ranks[curLog - 1][i2 + (1 << (curLog-1))];
}

int LCP[N];

int computeLCP(int suffIdx1, int suffIdx2)
{
    int tot = 0;
    int curLog = maxLog;
    while(tot + suffIdx1 < len && tot + suffIdx2 < len && curLog >= 0){
        if(ranks[curLog][suffIdx1+tot] == ranks[curLog][suffIdx2+tot]){
            tot += 1 << curLog;
        }
        curLog--;
    }
    
    return min(len - suffIdx1, min(tot, len - suffIdx2));
}

int tree[2<<17];

void build_st(int node, int l, int r){
    if(l == r){
        tree[node] = l;
        return;
    }
    
    int mid = (l+r) / 2;
    
    build_st(node*2, l, mid);
    build_st(node*2 +1, mid+1, r);
    
    if(LCP[tree[node*2]] < LCP[tree[node*2 + 1]]){
        tree[node] = tree[node*2];
    }else{
        tree[node] = tree[node*2 + 1];
    }
    
    return;  
}

int query_st(int node, int l, int r, int curL, int curR)
{
    if(curL > r || curR < l){
        return -1;
    }
    if(curL >= l && curR <= r){
        return tree[node];
    }
    
    int mid = (curL+curR) / 2;
    
    int left = query_st(node*2, l, r, curL, mid);
    int right = query_st(node*2 + 1, l, r, mid+1, curR);
    
    if(left == -1){
        return right;
    }
    if(right == -1){
        return left;
    }
    
    if(LCP[left] < LCP[right]){
        return left;
    }
    
    return right;
}

int tree2[2<<17];

void build_st2(int node, int l, int r){
    if(l == r){
        tree2[node] = l;
        return;
    }
    
    int mid = (l+r) / 2;
    
    build_st2(node*2, l, mid);
    build_st2(node*2 +1, mid+1, r);
    
    if(sArray[tree2[node*2]] > sArray[tree2[node*2 + 1]]){
        tree2[node] = tree2[node*2];
    }else{
        tree2[node] = tree2[node*2 + 1];
    }
    
    return;  
}

int query_st2(int node, int l, int r, int curL, int curR)
{
    if(curL > r || curR < l){
        return -1;
    }
    if(curL >= l && curR <= r){
        return tree2[node];
    }
    
    int mid = (curL+curR) / 2;
    
    int left = query_st2(node*2, l, r, curL, mid);
    int right = query_st2(node*2 + 1, l, r, mid+1, curR);
    
    if(left == -1){
        return right;
    }
    if(right == -1){
        return left;
    }
    
    if(sArray[left] > sArray[right]){
        return left;
    }
    
    return right;
}

int main()
{
    //freopen("in.in", "r", stdin);
    //freopen("in.out", "w", stdout);

    while(1){
        scanf("%d ", &m);
        if(m == 0) break;
        scanf("%s", s);

        len = strlen(s);
        
        if(m == 1){
            printf("%d %d\n", len, 0);
            continue;
        }

        maxLog = (int)(log(len) / log(2)) + 2;

        for(int i = 0; i < len; i++){
            ranks[0][i] = s[i];
            sArray[i] = i;
        }

        for(curLog = 1; curLog <= maxLog; curLog++){
            sort(sArray, sArray+len, mycmp);
            int curRank = 0;
            ranks[curLog][sArray[0]] = 0;
            for(int i = 1; i < len; i++){
                if(mycmp(sArray[i-1], sArray[i])) curRank++;
                ranks[curLog][sArray[i]] = curRank;
            }
        }

        
        for(int i = 1; i < len; i++){
            LCP[i] = computeLCP(sArray[i], sArray[i-1]);
            //printf("%d %s\n",LCP[i], s+sArray[i]);
        }
        
        build_st(1, 0, len-1);
        build_st2(1, 0, len-1);
        
        int maxi = 0;
        int right = -1;
        int numOfOcc;
        int best = 0;
        
        int inc = m-2;
        
        for(int i = 1; i < len; i++){
            if(i+inc >= len) break;
            int curMini = query_st(1, i, i+inc, 0, len-1);
            int curBestRight = query_st2(1, i-1, i+inc, 0, len-1);
            
            if(maxi == LCP[curMini]){
                right = max(right, sArray[curBestRight]);
            }
            if(maxi < LCP[curMini]){
                maxi = LCP[curMini];
                right = sArray[curBestRight];
            }
            
        }
        
        if(maxi == 0){
            printf("none\n");
        }else{
            printf("%d %d\n", maxi, right);
        }
    }
    
    return 0;
}