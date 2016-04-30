const int N = 55;
class Tarjan {
	public:
		int low[N],dfn[N],fa[N],stack[N];
		int top,sig,t;
		vector<int> head[N];

		void init(int n) {
			memset(dfn,0,sizeof(dfn));
		    memset(fa,0,sizeof(fa));
		    t=sig=top=0;
			FOR(i, 0, n) head[i].clear();
		}

		void add(int u, int v) {head[u].push_back(v); }

		void dfs(int pos) {
		    stack[++top]=pos;
		    low[pos]=dfn[pos]=++t;
			REP(i, head[pos].size()) {
		        int to=head[pos][i];
		        if(!dfn[to]) dfs(to);
		        if(!fa[to]) low[pos]=min(low[pos],low[to]);
		    }
		    if(low[pos]==dfn[pos]) {
		        ++sig;
		        do {
		            fa[stack[top]]=sig;
		        }while(stack[top--]!=pos);
		    }
		}
		void tarjan(int n) {
		    REP(i, n) if(!dfn[i]) dfs(i);
		}
}T;


//2-sat专用版
#define N 3010
vector<int>head[N],rehead[N];
vector<int>vs;
bool visit[N];
int fa[N];
void add(int u,int v)
{
    head[u].pb(v);
    rehead[v].pb(u);
}
void dfs(int pos)
{
    visit[pos]=1;
    for(int i=0;i<head[pos].size();++i)
    {
        if(!visit[ head[pos][i] ]) dfs(head[pos][i]);
    }
    vs.pb(pos);
}
void redfs(int pos,int sig)
{
    visit[pos]=1;
    fa[pos]=sig;
    for(int i=0;i<rehead[pos].size();++i)
    {
        if(!visit[ rehead[pos][i] ]) redfs(rehead[pos][i],sig);
    }
}
void tarjan(int n)
{
    memset(visit,0,sizeof(visit));
    vs.clear();
    FOR(i,1,n+n) if(!visit[i]) dfs(i);

    memset(visit,0,sizeof(visit));
    int sig=0;
    DSC(i,vs.size()-1,0)
    {
        if(!visit[ vs[i] ]) redfs(vs[i],sig++);
    }
}
