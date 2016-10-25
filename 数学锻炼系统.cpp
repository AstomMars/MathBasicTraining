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
    cout<<"欢迎来到数学练习系统。by Mars"<<endl<<"水滴石穿，不只是故事。"<<endl;

    while (cout<<"选择练习类型："<<endl<<"1.口算练习"<<endl<<"2.配方练习"<<endl<<"3.十字相乘拆分练习"<<endl<<"4.退出"<<endl,cin>>choice,!(choice>0 && choice<=4) || cin.fail())
    {
        system("cls");
        cout<<"请正确输入。"<<endl;
        cin.clear();
        cin.sync();
    }
    return choice;
}


void prints(int printhing)//如果是正数  前面打印正号
{
    if (printhing>= 0)
    {
        cout<<"+"<<printhing;
    }
    else cout<<printhing;
    return;
}
int rand_ex(int absl ,int ex)//生成一个在绝对值absl间的，除了ex 的随机数
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
            //cout << "请输入想做的题的数目："<<endl;
            //cin >> n;
            while (cout << "请输入想做的题的数目："<<endl,cin>>n,!(n>=1 && n<=100) || cin.fail())
            {
                cout<<"还是输入1到100间的数吧。"<<endl;
                cin.clear();
                cin.sync();
            }
            //cout <<"请输入容错数："<<endl;
            //cin>>nw;
            while (cout <<"请输入容错数："<<endl,cin>>nw,!(nw>=1 && nw<=100) || cin.fail())
            {
                cout<<"输入1-100的数字。"<<endl;
                cin.clear();
                cin.sync();
            }
            if (nw>=n)
                cout<<"容错数大于题目数。"<<endl;
        }while (nw>=n);
        cout << "加减运算系统已启动。by Mars" << endl <<"请答题："<<endl;
    }
    else
    {
        n=addn *10;
        nw=5;
        cout<<"补加错题系统已启动。"<<endl<<"请答题："<<endl;
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
            cout<<"错"<<endl;
            nWrong++;
        }
        else cout<<"对"<<endl;
        cout << "已经做完"<<i<<"道；"<<endl;
        if (nWrong>nw)
        {
            cout<<"错的超过"<<nw<<"个了。"<<endl;
            break;
        }
        i++;
    }
    flag[0]+=i-1;
    flag[1]+=nWrong;
    cout<<"测试结束。共错"<<nWrong<<"道。"<<endl;
    if (nWrong>=1)
        caculate(nWrong);
    return;
}

void allocation(int addn)//分配
{
    int n,nw;
    if (addn == -1)
    {
        do
        {
            //cout << "请输入想做的题的数目："<<endl;
            //cin >> n;
            while (cout << "请输入想做的题的数目："<<endl,cin>>n,!(n>=1 && n<=100) || cin.fail())
            {
                cout<<"还是输入1到100间的数吧。"<<endl;
                cin.clear();
                cin.sync();
            }
            //cout <<"请输入容错数："<<endl;
            //cin>>nw;
            while (cout <<"请输入容错数："<<endl,cin>>nw,!(nw>=1 && nw<=100) || cin.fail())
            {
                cout<<"输入1-100的数字。"<<endl;
                cin.clear();
                cin.sync();
            }
            if (nw>=n)
                cout<<"容错数大于题目数。"<<endl;
        }while (nw>=n);
        cout << "配方系统已启动。by Mars" << endl <<"请答题："<<endl;
    }
    else
    {
        n=addn *10;
        nw=5;
        cout<<"补加错题系统已启动。"<<endl<<"请答题："<<endl;
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
            cout<<c<<"=0        <---这是第"<<i<<"题；"<<endl;
            cout<<"-->";
            cin>>aAns>>bAns>>cAns;
            if (aAns==aRes && bAns==bRes &&cAns==cRes)
                cout<<"对"<<endl;
            else
            {
                cout<<"错"<<endl;
                nWrong++;
            }
        }
        else
        {
            Opt='-';
            cout<<a<<"x^2"<<Opt<<b<<"x";
            if (c>=0) cout<<"+";
            cout<<c<<"=0        <---这是第"<<i<<"题；"<<endl;
            cout<<"-->";
            cin>>aAns>>bAns>>cAns;
            if (aAns==aRes && bAns==-bRes &&cAns==cRes)
                cout<<"对"<<endl;
            else
            {
                cout<<"错"<<endl;
                nWrong++;
            }
        }
        if (nWrong>nw)
        {
            cout<<"错误已超过"<<nw<<"个。"<<endl;
            break;
        }

    }
    flag[2]+=i-1;
    flag[3]+=nWrong;
    cout<<"测试结束.共错"<<nWrong<<"题。"<<endl;
    if (nWrong>=1)
        allocation(nWrong);
    return;
}

void crosseparate(int addn)//十字拆分
{
    int n,nw;
    if (addn == -1)
    {
        do
        {
            //cout << "请输入想做的题的数目："<<endl;
            //cin >> n;
            while (cout << "请输入想做的题的数目："<<endl,cin>>n,!(n>=1 && n<=100) || cin.fail())
            {
                cout<<"还是输入1到100间的数吧。"<<endl;
                cin.clear();
                cin.sync();
            }
            //cout <<"请输入容错数："<<endl;
            //cin>>nw;
            while (cout <<"请输入容错数："<<endl,cin>>nw,!(nw>=1 && nw<=100) || cin.fail())
            {
                cout<<"输入1-100的数字。"<<endl;
                cin.clear();
                cin.sync();
            }
            if (nw>=n)
                cout<<"容错数大于题目数。"<<endl;
        }while (nw>=n);
        cout << "十字相乘拆分系统已启动。by Mars" << endl <<"请答题："<<endl;
    }
    else
    {
        n=addn *10;
        nw=5;
        cout<<"补加错题系统已启动。"<<endl<<"请答题："<<endl;
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
        cout<<"=0"<<"    <--这是第"<<i<<"题。"<<endl;
        cin>>aAns>>bAns>>cAns>>dAns;
        if (aAns*bAns==aRes && aAns*dAns+bAns*cAns==bRes && cAns*dAns ==cRes)
        {
            cout <<"对"<<endl;
        }
        else
        {
            cout<<"错"<<endl;
            cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
            nWrong++;
        }

        if (nWrong>nw)
        {
            cout<<"错误已超过"<<nw<<"个。"<<endl;
            break;
        }

    }
    flag[4]+=i-1;
    flag[5]+=nWrong;
    cout<<"测试结束.共错"<<nWrong<<"题。"<<endl;
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
        cout<<"本轮测试已结束，按回车键返回主菜单。"<<endl;
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
