#include <iostream>
#include <cstdlib>
#include <cstdio>

using namespace std;
/*����Ҫ��ӵ����ݷŽ�txt�ļ���  ���б�������Խ�txt����д��bin��*/
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
    cout<<"͵����������� o(>�n<)o"<<endl;
    system("pause");
    return 0;
}
