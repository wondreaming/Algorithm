#include<cstdio>
#include<queue>
#include<algorithm>
#define MAXN 705
#define par pair<int,int>
using namespace std;
const int f[8][2]={{1,1},{1,0},{1,-1},{0,1},{0,-1},{-1,1},{-1,0},{-1,-1}};
int n,m,Ans,a[MAXN][MAXN];
bool vis[MAXN][MAXN];
struct xcw{
    int h,x,y;
    bool operator <(const xcw b)const{return h<b.h;}
}P[MAXN*MAXN];
queue<par> que;
bool check(int x,int y,int t){
    if(x<1||x>n||y<1||y>m) return 0;
    if(vis[x][y]) return 0;
    return a[x][y]<=t;
}
void BFS(int x,int y){
    vis[x][y]=1;que.push(make_pair(x,y));
    while(!que.empty()){
        par p=que.front();que.pop();
        x=p.first,y=p.second;
        for(int i=0;i<8;i++)
        if(check(x+f[i][0],y+f[i][1],a[x][y])) vis[x+f[i][0]][y+f[i][1]]=1,que.push(make_pair(x+f[i][0],y+f[i][1]));
    }
}
int main(){
    #ifndef ONLINE_JUDGE
    freopen("prob.in","r",stdin);
    freopen("prob.out","w",stdout);
    #endif
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++) scanf("%d",&a[i][j]),P[(i-1)*m+j]=(xcw){a[i][j],i,j};
    sort(P+1,P+1+n*m);
    for(int i=n*m;i;i--)
    if(!vis[P[i].x][P[i].y]) Ans++,BFS(P[i].x,P[i].y);
    printf("%d\n",Ans);
    return 0;
}