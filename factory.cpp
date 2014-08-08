#include <iostream>
using namespace std;

//简单工厂：将对象的创建和逻辑全部放在工厂中。
//工厂模式与抽象工厂模式：在工厂的子类中创建对象，逻辑在客户端，但只使用
//Product与Factory提供的接口，把具体的类都隐藏了
class Product
{

};

class ConcreteProduct1 : public Product
{
public:
    ConcreteProduct1()
    {
        cout << "ConcreteProduct1" << endl;
    }
};

class ConcreteProduct2 : public Product
{
public:
    ConcreteProduct2()
    {
        cout << "ConcreteProduct2" << endl;
    }
};

//抽象工厂，为每种商品定一个构造接口
class Factory
{
public:
    //定义一个工厂方法接口，每个子类都实现，返回不同的具体的对象
    virtual Product* MakeConProduct() = 0;
};

//具体工厂：每个商品定义一个工厂来生产
class ConcreteFactory1 : public Factory
{
public:
    Product* MakeConProduct()
    {
        return new ConcreteProduct1;
    }
};

class ConcreteFactory2 : public Factory
{
public:
    Product* MakeConProduct()
    {
        return new ConcreteProduct2;
    }
};

int main()
{
    //在客户端用具体的工厂类来初始化工厂
    Factory *fac = new ConcreteFactory1;
    Product *p = fac->MakeConProduct();

    //用另一个工厂子类初始化
    fac = new ConcreteFactory2;
    p = fac->MakeConProduct();

    return 0;
}
