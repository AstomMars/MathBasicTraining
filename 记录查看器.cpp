#include <iostream>
#include <cstdio>
#include <string>
#include <cstdlib>

using namespace std;
struct wtshow
{
    char s[120];
    wtshow *next;
};
typedef wtshow* wt;
int main()
{
    cout <<"哟。来看分啦？"<<endl<<"那输入密码吧：（123）"<<endl;
    int nk;
    while(cin>>nk,cin.fail())
    {
        cin.clear();
        cin.sync();
        cout<<"水平有限，我的密码是数字。┑(￣Д ￣)┍"<<endl<<"再试试吧："<<endl;
    }
    wt show,L;
    show=new wtshow;
    L=show;
    if (nk==123)
    {
        freopen("result.bin","r",stdin);
        while (gets(show->s))
        {
            show->next=new wtshow;
            show=show->next;
        }

        fclose(stdin);
        freopen("CON","r",stdin);
        show=L;
        while (show->next!=NULL)
        {
            puts(show->s);
            show=show->next;
        }
    }
    else
        cout<<"密码不对啊  再见2333."<<endl;

    system("pause");
    return 0;
}
