//代理模式的基本代码
#include <iostream>
using namespace std;

//定义RealSubject和Proxy的公共接口
class Subject
{
public:
    virtual void Request() = 0;
};

//定义Proxy所代表的真实实体
class RealSubject : public Subject
{
public:
    void Request()
    {
        cout << "真实的请求" << endl;
    }
};

//代理，保存一个指针指向实体，并且与Subject的接口相同
class Proxy
{
public:
    Proxy() : realSubject(NULL)
    {
    }

    void Request()
    {
        if (realSubject == NULL)
            realSubject = new RealSubject;
        realSubject->Request();
    }
private:
    RealSubject *realSubject;
};

int main()
{
    //直接使用代理来操作对象，不知道真实对象
    Proxy proxy;
    proxy.Request();

    return 0;
}


