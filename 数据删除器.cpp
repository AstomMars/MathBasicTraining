#include <iostream>
#include <cstdio>
#include <string>
#include <cstdlib>

using namespace std;

int main()
{
    cout <<"ȷ��ɾ����ǰ�����м�¼�����롰1����"<<endl;
    int ans;
    while (cin>>ans,cin.fail())
    {
        cout<<"�ܲ��ܺú��䣬�����������ҵ�Ů������"<<endl;
        cin.clear();
        cin.sync();
    }
    if (ans==1)
    {
        freopen("result.bin","w",stdout);
        fclose(stdout);
        freopen("CON","w",stdout);
        cout<<"ɾ����  ��Ҳ�Ҳ�������  �ݰ�"<<endl;
    }
    else
        cout<<"��ɾ�ͺ�  �ݰݡ�"<<endl;
    system("pause");
    return 0;
}
