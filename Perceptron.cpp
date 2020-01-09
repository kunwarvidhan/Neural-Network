#include<bits/stdc++.h>
using namespace std;
int main()
{
    int i,j,choice;
    int nt[]={0,1};
    int x1[]={0,0,1,1};
    int x2[]={0,1,0,1};
    int b,w1,w2,nw,ip,op;
    w1=w2=b=nw=0;
    int dw1,dw2,dnw,db;
    bool f[]={false,false,false,false};
    bool ch;
    cout<<"PERCEPTRON METHOD\n1-AND\n2-OR\n3-NOT\nEnter your choice: ";
    cin>>choice;
    switch(choice)
    {
        case 1:
    {
        cout<<"x1\t"<<"x2\t"<<"b\t"<<"t\t"<<"i/p\t"<<"o/p\t"<<"dw1\t"<<"dw2\t"<<"db\t"<<"nw1\t"<<"nw2\t"<<"nb\t"<<endl;
        int t[]={0,0,0,1};
        do
        {
            for(i=0;i<4;i++)
            {
                ip=x1[i]*w1+x2[i]*w2+b;
                if(ip>=0)
                    op=1;
                else
                    op=0;
                if(t[i]==op)
                {
                    f[i]=true;
                    dw1=dw2=db=0;
                }
                else
                {
                    dw1=(t[i]-op)*x1[i];
                    dw2=(t[i]-op)*x2[i];
                    db=t[i]-op;
                }
                w1+=dw1;
                w2+=dw2;
                b+=db;
                cout<<x1[i]<<"\t"<<x2[i]<<"\t"<<1<<"\t"<<t[i]<<"\t"<<ip<<"\t"<<op<<"\t"<<dw1<<"\t"<<dw2<<"\t"<<db<<"\t"<<w1<<"\t"<<w2<<"\t"<<b<<"\t\n";
            }
            ch=true;
            for(j=0;j<4;j++)
            {
                if(f[j]==false)
                    ch=false;
                f[j]=false;
            }
            cout<<"\n";
        }while(!ch);
        cout<<"End w1 w2 b: "<<w1<<" "<<w2<<" "<<b;
    }break;
    case 2:
    {
        cout<<"x1\t"<<"x2\t"<<"b\t"<<"t\t"<<"i/p\t"<<"o/p\t"<<"dw1\t"<<"dw2\t"<<"db\t"<<"nw1\t"<<"nw2\t"<<"nb\t"<<endl;
        int t[]={0,1,1,1};
        do
        {
            for(i=0;i<4;i++)
            {
                ip=x1[i]*w1+x2[i]*w2+b;
                if(ip>=0)
                    op=1;
                else
                    op=0;
                if(t[i]==op)
                {
                    f[i]=true;
                    dw1=dw2=db=0;
                }
                else
                {
                    dw1=(t[i]-op)*x1[i];
                    dw2=(t[i]-op)*x2[i];
                    db=t[i]-op;
                }
                w1+=dw1;
                w2+=dw2;
                b+=db;
            cout<<x1[i]<<"\t"<<x2[i]<<"\t"<<1<<"\t"<<t[i]<<"\t"<<ip<<"\t"<<op<<"\t"<<dw1<<"\t"<<dw2<<"\t"<<db<<"\t"<<w1<<"\t"<<w2<<"\t"<<b<<"\t\n";
            }
            ch=true;
            for(j=0;j<4;j++)
            {
                if(f[j]==false)
                    ch=false;
                f[j]=false;
            }
            cout<<"\n";
        }while(!ch);
        cout<<"End w1 w2 b: "<<w1<<" "<<w2<<" "<<b;
    }break;
    case 3:
    {
        cout<<"x\t"<<"b\t"<<"t\t"<<"i/p\t"<<"o/p\t"<<"dw\t"<<"db\t"<<"nw\t"<<"nb\t\n";
        int t[]={1,0};
        do
        {
            for(i=0;i<2;i++)
            {
                ip=nt[i]*nw+b;
                if(ip>=0)
                    op=1;
                else
                    op=0;
                if(t[i]==op)
                {
                    f[i]=true;
                    dnw=db=0;
                }
                else
                {
                    dnw=(t[i]-op)*nt[i];
                    db=t[i]-op;
                }
                nw+=dnw;
                b+=db;
                cout<<nt[i]<<"\t"<<1<<"\t"<<t[i]<<"\t"<<ip<<"\t"<<op<<"\t"<<dnw<<"\t"<<db<<"\t"<<nw<<"\t"<<b<<"\t\n";
            }
            ch=true;
            for(j=0;j<2;j++)
            {
                if(f[j]==false)
                    ch=false;
                f[j]=false;
            }
            cout<<"\n";
        }while(!ch);
        cout<<"End w b: "<<nw<<" "<<b;
    }break;
    default:
        cout<<"WRONG INPUT";
    }
}