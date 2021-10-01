#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int cnt1=1,cnt2=1,cnt3=1;

int euclid(unsigned long a,unsigned long b){
 cnt1++;
 if(a==0)
    return b;
 return euclid(b%a,a);

}

int consecutiveint(unsigned long a,unsigned long b){
 unsigned long c = a>=b?b:a;
 unsigned long ans;
 for(unsigned long i =c;i>=1;i--,cnt2++){
    if(a%i==0&&b%i==0){
        ans = i;
        break;
    }
 }
 return ans;

}

int middleschool(unsigned long a,unsigned int b){
    unsigned long i, c, ans=1, m=0, n=0;
    c=a>=b?b:a;
    for(i=2;i<=c;i++,cnt3++)
	{
        n=0;
        m=0;
        if(a%i==0)
		{
            n=1;
            a=a/i;
        }
        if(b%i==0)
		{
            m=1;
            b=b/i;
        }
        if(n==1 && m==1)
		{
            ans = ans*i;
        }
        if(n==1 || m==1)
		{
            i--;
        }
    }
    return ans;


}

int main()
{
    unsigned long x,y,out1,out2,out3;
    printf("Enter 2 numbers whose HCF is required\n");
    scanf("%lu%lu",&x,&y);
    out1 = euclid(x,y);
    out2 = consecutiveint(x,y);
    out3 = middleschool(x,y);
    printf("Euclid method: %lu Time: %d \n",out1,cnt1);
    printf("Consecutive integer method: %lu  Time: %d\n",out2,cnt2);
    printf("Middle school procedure: %lu  Time: %d \n",out3,cnt3);

}