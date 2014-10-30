/*
ID: adelnob1
PROG: holstein
LANG: C++
*/

#include <vector>
#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long ll;

int vitamins[26];

typedef struct package{
    int feeds[26];
}package;

vector<package> ve;

int taken[16];

vector< vector<int> > best;

bool mycmp(const vector<int> &v1, const vector<int> &v2)
{
    if(v1.size() != v2.size()) return v1.size() < v2.size();
    return v1 < v2;
}

int main()
{
    freopen("holstein.in", "r", stdin);
    freopen("holstein.out", "w", stdout);
    
    int v, g;
    
    scanf("%d", &v);
    
    for(int i = 0; i < v; i++){
        scanf("%d", &vitamins[i]);
    }
    
    scanf("%d", &g);
    
    for(int i = 0; i < g; i++){
        package p;
        for(int j = 0; j < v; j++){
            scanf("%d", &p.feeds[j]);
        }
        ve.push_back(p);
    }
    
    int to = 1 << g;
    
    int miniSoFar = 1 << 30;
    
    for(int i = 0; i < to; i++){
        int tot = 0;
        for(int j = 0; j < g; j++){
            if(i & (1 << j)){
                taken[tot++] = j;
            }
        }
        bool valid = false;
        if(tot <= miniSoFar){
            valid = true;
            for(int w = 0; w < v; w++){
                int totOfCurVitamin = 0;
                for(int k = 0; k < tot; k++){
                    totOfCurVitamin += ve[taken[k]].feeds[w];
                }
                if(vitamins[w] > totOfCurVitamin){
                    valid = false;
                    break;
                }
            }
            if(valid){
                miniSoFar = tot;
                best.push_back(vector<int>(taken, taken+tot));
                sort(best[best.size() - 1].begin(), best[best.size() - 1].end());
            }
        }
    }
    
    sort(best.begin(), best.end(), mycmp);
    
    printf("%d", best[0].size());
    
    for(int i = 0; i < best[0].size(); i++){
        printf(" %d", best[0][i]+1);
    }
    
    printf("\n");
    
    return 0;
}