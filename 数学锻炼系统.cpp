#include <iostream>
#include <ctime>
#include <cmath>
#include <cstdlib>
#include <cstdio>

using namespace std;

int flag[6];

int choose()
{
    int choice;
    cout<<"��ӭ������ѧ��ϰϵͳ��by Mars"<<endl<<"ˮ��ʯ������ֻ�ǹ��¡�"<<endl;

    while (cout<<"ѡ����ϰ���ͣ�"<<endl<<"1.������ϰ"<<endl<<"2.�䷽��ϰ"<<endl<<"3.ʮ����˲����ϰ"<<endl<<"4.�˳�"<<endl,cin>>choice,!(choice>0 && choice<=4) || cin.fail())
    {
        system("cls");
        cout<<"����ȷ���롣"<<endl;
        cin.clear();
        cin.sync();
    }
    return choice;
}


void prints(int printhing)//���������  ǰ���ӡ����
{
    if (printhing>= 0)
    {
        cout<<"+"<<printhing;
    }
    else cout<<printhing;
    return;
}
int rand_ex(int absl ,int ex)//����һ���ھ���ֵabsl��ģ�����ex �������
{

    int a;
    a=rand()%(absl*2)-5;
    if (a==ex)
        a=absl;
    return a;
}

void caculate(int addn)
{
    int n,nw;
    if (addn == -1)
    {
        do
        {
            //cout << "�����������������Ŀ��"<<endl;
            //cin >> n;
            while (cout << "�����������������Ŀ��"<<endl,cin>>n,!(n>=1 && n<=100) || cin.fail())
            {
                cout<<"��������1��100������ɡ�"<<endl;
                cin.clear();
                cin.sync();
            }
            //cout <<"�������ݴ�����"<<endl;
            //cin>>nw;
            while (cout <<"�������ݴ�����"<<endl,cin>>nw,!(nw>=1 && nw<=100) || cin.fail())
            {
                cout<<"����1-100�����֡�"<<endl;
                cin.clear();
                cin.sync();
            }
            if (nw>=n)
                cout<<"�ݴ���������Ŀ����"<<endl;
        }while (nw>=n);
        cout << "�Ӽ�����ϵͳ��������by Mars" << endl <<"����⣺"<<endl;
    }
    else
    {
        n=addn *10;
        nw=5;
        cout<<"���Ӵ���ϵͳ��������"<<endl<<"����⣺"<<endl;
    }
    int a,b,i,nWrong,cOpt,nAns,nRes;
    char opt;
    i=1;
    nWrong=0;
    while (i<=n)
    {
        a=rand()%100;
        b=rand()%100;
        cOpt=rand()%2;
        switch (cOpt)
        {
        case 0:
            opt='+';
            nRes=a+b;
            break;
        case 1:
            opt='-';
            nRes=a-b;
            break;
        }
        cout<<a<<opt<<b<<"=";
        cin>>nAns;
        if (nRes != nAns)
        {
            cout<<"��"<<endl;
            nWrong++;
        }
        else cout<<"��"<<endl;
        cout << "�Ѿ�����"<<i<<"����"<<endl;
        if (nWrong>nw)
        {
            cout<<"��ĳ���"<<nw<<"���ˡ�"<<endl;
            break;
        }
        i++;
    }
    flag[0]+=i-1;
    flag[1]+=nWrong;
    cout<<"���Խ���������"<<nWrong<<"����"<<endl;
    if (nWrong>=1)
        caculate(nWrong);
    return;
}

void allocation(int addn)//����
{
    int n,nw;
    if (addn == -1)
    {
        do
        {
            //cout << "�����������������Ŀ��"<<endl;
            //cin >> n;
            while (cout << "�����������������Ŀ��"<<endl,cin>>n,!(n>=1 && n<=100) || cin.fail())
            {
                cout<<"��������1��100������ɡ�"<<endl;
                cin.clear();
                cin.sync();
            }
            //cout <<"�������ݴ�����"<<endl;
            //cin>>nw;
            while (cout <<"�������ݴ�����"<<endl,cin>>nw,!(nw>=1 && nw<=100) || cin.fail())
            {
                cout<<"����1-100�����֡�"<<endl;
                cin.clear();
                cin.sync();
            }
            if (nw>=n)
                cout<<"�ݴ���������Ŀ����"<<endl;
        }while (nw>=n);
        cout << "�䷽ϵͳ��������by Mars" << endl <<"����⣺"<<endl;
    }
    else
    {
        n=addn *10;
        nw=5;
        cout<<"���Ӵ���ϵͳ��������"<<endl<<"����⣺"<<endl;
    }
    int i,a,b,c,nWrong,cOpt,aPre,aAns,bAns,cAns,aRes,bRes,cRes;
    char Opt;
    nWrong=0;
    for (i=1;i<=n;i++)
    {
        a=rand()%5+1;
        aPre=a;
        bRes=rand()%9+1;
        b=2*a*bRes;
        a=a*a;
        c=rand()%100-50;
        cOpt=rand()%2;
        aRes=aPre;
        cRes=c-bRes*bRes;
        if (cOpt==0)
        {
            Opt='+';
            cout<<a<<"x^2"<<Opt<<b<<"x";
            if (c>=0) cout<<"+";
            cout<<c<<"=0        <---���ǵ�"<<i<<"�⣻"<<endl;
            cout<<"-->";
            cin>>aAns>>bAns>>cAns;
            if (aAns==aRes && bAns==bRes &&cAns==cRes)
                cout<<"��"<<endl;
            else
            {
                cout<<"��"<<endl;
                nWrong++;
            }
        }
        else
        {
            Opt='-';
            cout<<a<<"x^2"<<Opt<<b<<"x";
            if (c>=0) cout<<"+";
            cout<<c<<"=0        <---���ǵ�"<<i<<"�⣻"<<endl;
            cout<<"-->";
            cin>>aAns>>bAns>>cAns;
            if (aAns==aRes && bAns==-bRes &&cAns==cRes)
                cout<<"��"<<endl;
            else
            {
                cout<<"��"<<endl;
                nWrong++;
            }
        }
        if (nWrong>nw)
        {
            cout<<"�����ѳ���"<<nw<<"����"<<endl;
            break;
        }

    }
    flag[2]+=i-1;
    flag[3]+=nWrong;
    cout<<"���Խ���.����"<<nWrong<<"�⡣"<<endl;
    if (nWrong>=1)
        allocation(nWrong);
    return;
}

void crosseparate(int addn)//ʮ�ֲ��
{
    int n,nw;
    if (addn == -1)
    {
        do
        {
            //cout << "�����������������Ŀ��"<<endl;
            //cin >> n;
            while (cout << "�����������������Ŀ��"<<endl,cin>>n,!(n>=1 && n<=100) || cin.fail())
            {
                cout<<"��������1��100������ɡ�"<<endl;
                cin.clear();
                cin.sync();
            }
            //cout <<"�������ݴ�����"<<endl;
            //cin>>nw;
            while (cout <<"�������ݴ�����"<<endl,cin>>nw,!(nw>=1 && nw<=100) || cin.fail())
            {
                cout<<"����1-100�����֡�"<<endl;
                cin.clear();
                cin.sync();
            }
            if (nw>=n)
                cout<<"�ݴ���������Ŀ����"<<endl;
        }while (nw>=n);
        cout << "ʮ����˲��ϵͳ��������by Mars" << endl <<"����⣺"<<endl;
    }
    else
    {
        n=addn *10;
        nw=5;
        cout<<"���Ӵ���ϵͳ��������"<<endl<<"����⣺"<<endl;
    }
    int i,a,b,c,d,nWrong,cOpt,aAns,bAns,cAns,dAns,aRes,bRes,cRes;
    char Opt;
    nWrong=0;
    for (i=1;i<=n;i++)
    {
        a=abs(rand_ex(5,0));
        b=abs(rand_ex(5,0));
        c=rand_ex(5,0);
        d=rand_ex(5,0);

        aRes=a*b;
        bRes=a*d+b*c;
        cRes=c*d;
        cout<<aRes<<"x^2";
        prints(bRes);
        cout<<"x";
        prints(cRes);
        cout<<"=0"<<"    <--���ǵ�"<<i<<"�⡣"<<endl;
        cin>>aAns>>bAns>>cAns>>dAns;
        if (aAns*bAns==aRes && aAns*dAns+bAns*cAns==bRes && cAns*dAns ==cRes)
        {
            cout <<"��"<<endl;
        }
        else
        {
            cout<<"��"<<endl;
            cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
            nWrong++;
        }

        if (nWrong>nw)
        {
            cout<<"�����ѳ���"<<nw<<"����"<<endl;
            break;
        }

    }
    flag[4]+=i-1;
    flag[5]+=nWrong;
    cout<<"���Խ���.����"<<nWrong<<"�⡣"<<endl;
    if (nWrong>=1)
        crosseparate(nWrong);
    return;
}

int main()
{
    srand(time(NULL));
    int nChoice=0,nCount;
    for (int i=0;i<=6;i++)
        flag[i]=0;
    while(nChoice!=4)
    {
        nChoice=choose();
        switch (nChoice)
        {
        case 1:
            caculate(-1);
            break;
        case 2:
            allocation(-1);
            break;
        case 3:
            crosseparate(-1);
            break;
        default:
            break;
        }
        cout<<"���ֲ����ѽ��������س����������˵���"<<endl;
        system("pause");
        system("cls");
    }
    freopen("result.bin","a",stdout);
    time_t tTime;
    tTime=time(NULL);
    cout<<tTime<<endl;
    for (nCount=0;nCount<=5;nCount+=2)
    {
        cout<<flag[nCount]<<"   "<<flag[nCount+1]<<endl;
    }
    fclose(stdout);
    freopen("CON","w",stdout);
    system("pause");
    return 0;
}
