#include<bits/stdc++.h>
using namespace std;
inline int read()
{
    int x=0,f=1;char c=getchar();
    while(c<'0'||c>'9'){if(c=='-') f=-1; c=getchar();}
    while(c>='0'&&c<='9'){x=x*10+(c&15); c=getchar();}
    return x*f;
}
int f[1000005]={1,1};
int g[1000005]={0,1};
int main()
{
    int n=read();
    bool forward_zero=0;
    if(n<2) 
    {
        printf("%d\n",f[n]);
        return 0;
    }
    for(int i=2;i<=n;i++)
    {
        f[i]=f[i-1]+f[i-2]+2*g[i-2];
        g[i]=(f[i-1]+g[i-1])%10000;
        if(f[i]>10000)
        {
            forward_zero=1;
            f[i]%=10000;
        }
    }
    if(forward_zero)
    {
        printf("%04d\n",f[n]);
    }
    else
    {
        printf("%d\n",f[n]);
    }
}