#include<bits/stdc++.h>
using namespace std;
int main()
{
    cout<<"AND GATE FROM ADALINE METHOD\n";
    int i,j;
    int x1[]={-1,-1,1,1};
    int x2[]={-1,1,-1,1};
    int t[]={-1,-1,-1,1};
    double b,w1,w2,ip,alpha,minr,t1,t2,t3;
    w1=w2=b=0.1;
    cout<<"Enter Learning Rate: ";
    cin>>alpha;
    cout<<"Enter Minimum Rate of Error: ";
    cin>>minr;
    double dw1,dw2,db;
    double e[4];
    bool ch;
    cout<<"x1\tx2\tb\tt\ti/p\tdw1\tdw2\tdb\tnew w1\tnew w2\tnew b\tError\n";
    do
    {
        for(i=0;i<4;i++)
        {
            ip=x1[i]*w1+x2[i]*w2+b;
            e[i]=pow(t[i]-ip,2);
            dw1=alpha*(t[i]-ip)*x1[i];
            dw2=alpha*(t[i]-ip)*x2[i];
            db=alpha*(t[i]-ip);
            w1+=dw1;
            w2+=dw2;
            b+=db;
            cout.precision(3);
            cout<<x1[i]<<"\t"<<x2[i]<<"\t"<<1<<"\t"<<t[i]<<"\t"<<ip<<"\t"<<dw1<<"\t"<<dw2<<"\t"<<db<<"\t"<<w1<<"\t"<<w2<<"\t"<<b<<"\t"<<e[i]<<"\n";
        }
        ch=true;
        double sum=0;
        for(j=0;j<4;j++)
        {
            sum+=e[j];
        }
        if(sum/2>minr)
            ch=false;
        cout<<"\n";
    }while(!ch);
    cout<<"End w1 w2 b: "<<w1<<" "<<w2<<" "<<b<<"\n";
    cout<<"Training Done\nEnter Input: ";
    cin>>t1>>t2;
    cout<<"Output: ";
    t3=t1*w1+t2*w2+b;
    if(t3>=0.0)
        cout<<1;
    else
        cout<<-1;
}
