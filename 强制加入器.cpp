#include <iostream>
#include <cstdlib>
#include <cstdio>

using namespace std;
/*把想要添加的内容放进txt文件中  运行本程序可以将txt内容写入bin中*/
struct mRna
{
    char str[120];
    mRna* next;
};
typedef mRna *m;

int main()
{
    freopen("result.txt","r",stdin);
    m mg,L;
    mg=new mRna;
    L=mg;
    while (gets(mg->str))
    {
        mg->next=new mRna;
        mg=mg->next;
    }
    fclose(stdin);
    freopen("result.bin","a",stdout);
    mg=L;
    while (mg->next!=NULL)
    {
        puts(mg->str);
        mg=mg->next;
    }
    fclose(stdout);
    freopen("CON","w",stdout);
    cout<<"偷梁换柱已完毕 o(>﹏<)o"<<endl;
    system("pause");
    return 0;
}
