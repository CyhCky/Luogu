#include<bits/stdc++.h>
using namespace std;
inline int read()
{
    int x=0,f=1;char c=getchar();
    while(c<'0'||c>'9') c=getchar();
    while(c>='0'&&c<='9') {x=(x<<1)+(x<<3)+(c&15); c=getchar();}
    return x*f;
}
int stmax[50005][19],stmin[50005][19];
int main()
{
    int n=read(),m=read();
    for(int i=1;i<=n;i++) stmax[i][0]=stmin[i][0]=read();
    for(int j=1;j<=18;j++)
    {
        int s=1<<(j-1);
        for(int i=1;i<=n;i++)
        {
            if(i+s>n)
            {
                stmax[i][j]=stmax[i][j-1];
                stmin[i][j]=stmin[i][j-1];
            }
            else 
            {
                stmax[i][j]=max(stmax[i][j-1],stmax[i+s][j-1]);
                stmin[i][j]=min(stmin[i][j-1],stmin[i+s][j-1]);
            }
        }
    }
    for(int i=1;i<=m;i++)
    {
        int l=read(),r=read();
        int p=log2(r-l+1);
        int ansmax=max(stmax[l][p],stmax[r-(1<<p)+1][p]);
        int ansmin=min(stmin[l][p],stmin[r-(1<<p)+1][p]);
        printf("%d\n",ansmax-ansmin);
    }
    return 0;
}