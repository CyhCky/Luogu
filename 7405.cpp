#include<bits/stdc++.h>
using namespace std;
inline __int128_t read()
{
    __int128_t x=0,f=1; char c=getchar();
    while(c<'0'||c>'9'){if(c=='-') f=-1; c=getchar();}
    while(c>='0'&&c<='9'){x=x*10+(c&15); c=getchar();}
    return x*f;
}
struct rec{
    __int128_t dis;
    int id;    
}T[200005];
long long ans[200005];
bool comp_by_dis(rec a,rec b)
{
    return a.dis<b.dis;
}
bool comp_by_id(rec a,rec b)
{
    return a.id<b.id;
}
int main()
{
    int n=read(),q=read();
    __int128_t last=(1ll<<63);
    // printf("test=%lld\n",~(1ll<<63));

    for(int i=1;i<=n;i++)
    {
        __int128_t x=read();
        T[i-1].dis=(~(1ll<<63))-last;
        T[i-1].id=i-1;
        last=x;
    }
    T[n].dis=-last;
    T[n].id=n;
    sort(T,T+n+1,comp_by_dis);
    __int128_t L=0,R=0,pos=0;
    int j=0;
    for(int i=1;i<=q;i++)
    {
        __int128_t t=read();
        pos+=t;
        if(pos<L)
        {
            L=pos;
            while(T[j].dis<=R-L)
            {
                ans[T[j].id+1]+=T[j].dis-R;
                ans[T[j].id]+=R;
                j++;
            }
        }
        else if(pos>R)
        {
            R=pos;
            while(T[j].dis<=R-L)
            {
                ans[T[j].id]+=T[j].dis+L;
                ans[T[j].id+1]-=L;
                j++;
            }
        }
    }
    //printf("ans1=%lld,L=%lld,R=%lld\n",ans[1],L,R);
    for(int i=j;i<=n;i++)
    {//printf("T[%d].id=%d",i,T [i].id);
        ans[T[i].id]+=R;
        ans[T[i].id+1]-=L;
    }
    for(int i=1;i<=n;i++)
    {
        printf("%lld\n",ans[i]);
    }
    return 0;
}