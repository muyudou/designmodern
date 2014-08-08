////单例模式：保证一个类仅有一个实例，并提供一个访问它的全局访问点
#include <iostream>
using namespace std;

//这种是饿汉式单例模式，即在类被构造出来后就将实例构造出来，
//会提前占用系统资源
class HungrySingleton
{
public:
    //这种是饿汉式单例模式，即在类被构造出来后就将实例构造出来，
    //会提前占用系统资源
    static HungrySingleton *getInstance()
    {
        return instance;
    }
private:
    HungrySingleton()
    {}
    static HungrySingleton* instance;
};
//这里是关键，直接初始化为类的对象，因为是类内数据，所以可以调用构造函数
HungrySingleton* HungrySingleton::instance = new HungrySingleton;


//这种是懒汉式单例模式，即在使用时才将实例构造出来，
//但这个会出现线程同步问题。
class LazySingleton
{
public:
    //函数必须是静态的，否则无法访问
    static LazySingleton *getInstance()
    {
        //如果两个线程同时进入getinstance,同时执行，则有两个实例被构造出来
        if (instance == NULL)
            instance = new LazySingleton();
        return instance;
    }
private:
    //构造函数私有的，不能再外部定义实例
    LazySingleton()
    {}
    static LazySingleton* instance;
};
//初始化为0
LazySingleton* LazySingleton::instance = 0;


int main()
{
    HungrySingleton *h1 = HungrySingleton::getInstance();
    HungrySingleton *h2 = HungrySingleton::getInstance();

    cout << "饿汉式单例模式运行结果:" << endl;
    if (h1 == h2)
        cout << "是同一个对象" << endl;
   
    LazySingleton *h3 = LazySingleton::getInstance();
    LazySingleton *h4 = LazySingleton::getInstance();

    cout << "懒汉式单例模式运行结果:" << endl;
    if (h3 == h4)
        cout << "是同一个对象" << endl;
    return 0;
}
