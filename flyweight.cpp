//享元模式:运用共享计数有效的支持大量细粒度的对象
#include <iostream>
#include <string>
#include <map>
#include <utility>
using namespace std;

//用户类，相当于外部状态，要传给flyweight
class User
{
public:
    User(string name) : _name(name)
    {}

    string GetName()
    {
        return _name;
    }
private:
    string _name;      
};

//网站抽象类，享元基类
class WebSite
{
public:
    virtual void Use(User user) = 0;
};

//具体网站类，享元对象，共享的
class ConcreteWebSite : public WebSite
{
public:
    ConcreteWebSite(string name)
    {
        _name = name;
    }

    void Use(User user)
    {
        cout << "网站分类: " << _name << " 用户: " << user.GetName() << endl; 
    }
private:
    string _name;
};

//网站工厂类:维护所有的享元对象的使用
class WebSiteFactory
{
public:
    WebSite* GetWebSiteCategory(string key)
    {
        if (webs.find(key) == webs.end())
            webs.insert(make_pair(key, new ConcreteWebSite(key)));
        return (WebSite*)webs[key];
    }

    int GetWebSiteCount()
    {
        return webs.size();
    }
private:
    /*每个企业对应一个网站模板，企业不同用User类来表示，
    表示不同的外部状态，维护一个User到WebSite的map*/
    map<string, ConcreteWebSite*> webs;
};

int main()
{
    WebSiteFactory f;

    WebSite *fx = f.GetWebSiteCategory("产品展示");
    fx->Use(User("小菜"));

    WebSite *fy = f.GetWebSiteCategory("产品展示");
    fy->Use(User("大鸟"));
    
    WebSite *fz = f.GetWebSiteCategory("产品展示");
    fz->Use(User("娇娇"));
    
    WebSite *fl = f.GetWebSiteCategory("博客");
    fl->Use(User("老顽童"));

    WebSite *fm = f.GetWebSiteCategory("博客");
    fm->Use(User("桃谷六仙"));
    
    WebSite *fn = f.GetWebSiteCategory("博客");
    fn->Use(User("南海神鄂"));

    cout << "网站总数分类有: " << f.GetWebSiteCount() << endl;
    return 0;
}

