#include <iostream>
using namespace std;

//抽象工厂模式：有不同的系列产品时。在工厂的子类中创建对象，
//逻辑在客户端，但只使用Product与Factory提供的接口，把具体的类都隐藏了
//A类型的产品，包含1系列和2系列，两种系列的商品
class ProductA
{

};

class ConcreteProductA1 : public ProductA
{
public:
    ConcreteProductA1()
    {
        cout << "ConcreteProductA1" << endl;
    }
};

class ConcreteProductA2 : public ProductA
{
public:
    ConcreteProductA2()
    {
        cout << "ConcreteProduct2" << endl;
    }
};

//B种类的商品：也有两个系列的东西
class ProductB
{

};

class ConcreteProductB1 : public ProductB
{
public:
    ConcreteProductB1()
    {
        cout << "ConcreteProductB1" << endl;
    }
};

class ConcreteProductB2 : public ProductB
{
public:
    ConcreteProductB2()
    {
        cout << "ConcreteProductB2" << endl;
    }
};

//抽象工厂，为每种商品定一个构造接口
class Factory
{
public:
    //定义一个工厂方法接口，每个子类都实现，返回不同的系列的对象
    virtual ProductA* CreateProductA() = 0;
    virtual ProductB* CreateProductB() = 0;
};

//具体工厂：为每一个系列的商品定义一个工厂
class ConcreteFactory1 : public Factory
{
public:
    ProductA* CreateProductA()
    {
        return new ConcreteProductA1;
    }

    ProductB* CreateProductB()
    {
        return new ConcreteProductB1;
    }
};

class ConcreteFactory2 : public Factory
{
public:
    ProductA* CreateProductA()
    {
        return new ConcreteProductA2;
    }

    ProductB* CreateProductB()
    {
        return new ConcreteProductB2;
    }
};

int main()
{
    //在客户端用具体的工厂类来初始化工厂
    Factory *fac = new ConcreteFactory1;
    ProductA *pa = fac->CreateProductA();
    ProductB *pb = fac->CreateProductB();

    //用另一个工厂子类初始化
    fac = new ConcreteFactory2;
    pa = fac->CreateProductA();
    pb = fac->CreateProductB();

    return 0;
}
