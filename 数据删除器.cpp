#include <iostream>
#include <cstdio>
#include <string>
#include <cstdlib>

using namespace std;

int main()
{
    cout <<"确定删除以前的所有记录请输入“1”："<<endl;
    int ans;
    while (cin>>ans,cin.fail())
    {
        cout<<"能不能好好输，你这样的能找到女朋友吗？"<<endl;
        cin.clear();
        cin.sync();
    }
    if (ans==1)
    {
        freopen("result.bin","w",stdout);
        fclose(stdout);
        freopen("CON","w",stdout);
        cout<<"删完了  再也找不回来了  拜拜"<<endl;
    }
    else
        cout<<"不删就好  拜拜。"<<endl;
    system("pause");
    return 0;
}
