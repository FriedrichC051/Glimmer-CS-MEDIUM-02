#include<stdio.h>
#include<string.h>
#include<math.h>
#define maxn 110000
char s[maxn];
int b[maxn];
double num=0.0;
int ans;
double to_dec(char s[],int len)
{
    double ans=0.0;
    int pos=len;
    for(int i=0;i<=len-1;++i)
        if(s[i]=='.')
        {
            pos=i;
            break;
        }
    for(int i=pos-1;i>=0;--i)
    {
        if(s[i]=='1')
        {
            ans+=pow(2,pos-1-i);
        }
    }
    for(int i=pos+1;i<=len-1;++i)
    {
        if(s[i]=='1')
        {
            ans+=pow(2,-(i-pos));
        }
    }
    return ans;
}
void to_bin(int ans)
{
    int i=0;
    for(;ans;++i)
    {
        b[i]=ans&1;
        ans>>=1;
    }
    for(;i>=1;--i)
        if(b[i])break;
    for(;i>=0;--i)
        printf("%d",b[i]);
    printf("\n");
}
int main()
{
    freopen("CS_M_02.in","r",stdin);
    freopen("CS_M_02_2.out","w",stdout);
    int n=15;
    while(n--)
    {
        scanf("%s",s);
        int l=strlen(s);
        if(s[l-1]=='B')
        {

            num=to_dec(s,l-1);
            printf("%g\n",num);
        }
        else if(s[l-1]=='D')
        {
            s[l-1]='E';
            sscanf(s,"%lf",&num);
            ans=(int)num;
            to_bin(ans);
        }
        memset(s,0,sizeof(s));
        num=0.0;
        ans=0;
    }

    return 0;
}
