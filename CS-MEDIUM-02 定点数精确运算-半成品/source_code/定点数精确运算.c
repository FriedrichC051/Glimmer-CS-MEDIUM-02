#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdint.h>
#define maxn 110000
#define int int32_t
#define uint uint32_t
#define ull uint64_t
typedef struct {
    int intgr;
    uint frac;
}PointFixedNum;
PointFixedNum a,b,ans;
const ull scale=(1ULL<<32);
char s1[maxn],s2[maxn],op;
double num1=0.0,num2=0.0;
void init(PointFixedNum *a,double num)
{
    a->intgr=(int)num;
    a->frac=(uint)((num-a->intgr)*scale);
}
void clear()
{
    a.frac=b.frac=ans.frac=0;
    a.frac=b.frac=ans.frac=0;
    num1=0.0;
    num2=0.0;
}
void read()
{
    scanf(" %1100[^ ]",s1);
    scanf(" %c",&op);
    scanf("%1100s",s2);
    int len1=strlen(s1),len2=strlen(s2);
    s1[len1-1]='E';
    s2[len2-1]='E';
    sscanf(s1,"%lf",&num1);
    sscanf(s2,"%lf",&num2);
}
PointFixedNum add(PointFixedNum a,PointFixedNum b)
{
    PointFixedNum c;
    ull sum=(ull)a.frac+b.frac;
    c.frac=(uint)(sum%scale);
    c.intgr=a.intgr+b.intgr+(int)(sum/scale);
    return c;
}
PointFixedNum sub(PointFixedNum a,PointFixedNum b)
{
    PointFixedNum c;
    ull diff=(ull)a.frac-b.frac;
    c.frac=(uint)(diff%scale);
    c.intgr=a.intgr-b.intgr-(int)(diff/scale);
    return c;
}
PointFixedNum mul(PointFixedNum a,PointFixedNum b)
{
    PointFixedNum c={0,0};
    ull pro1=(ull)a.intgr*b.intgr;
    ull pro2=(ull)a.intgr*b.frac;
    ull pro3=(ull)a.frac*b.intgr;
    ull pro4=(ull)a.frac*b.frac;

    ull carry=pro4%scale>=scale/2;

    ull sum=pro4/scale+pro3%scale+pro2%scale+carry;
    c.frac=sum%scale;
    carry=sum/scale;

    sum=pro1%scale+pro2/scale+pro3/scale+carry;
    c.intgr=sum%scale;

    return c;
}
void print(PointFixedNum a)
{
    double fraction=(double)a.frac/scale;
    double fin=(double)a.intgr+fraction;
    printf("%.15lf",fin);
}
int main()
{
    read();
    init(&a,num1);
    init(&b,num2);
    if(op=='+')
    {
        ans=add(a,b);
    }
    else if(op=='-')
    {
        ans=sub(a,b);
    }
    else if(op=='*')
    {
        ans=mul(a,b);
    }
    print(ans);
    putchar('D');
    return 0;
}
