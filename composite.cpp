/*组合模式:部分与整体关系
 */

#include <iostream>
#include <list>
#include <string>
using namespace std;

class Company
{
public:
    Company(string nm)
        : name(nm)
    {}

    virtual void Add(Company *c)
    {
    }

    virtual void Remove(Company *c)
    {
    }

    virtual void Display(int depth)
    {}

    virtual void LineofDuty()
    {}
protected:
    string name;
};

class ConcreteCompany : public Company
{
public:
    ConcreteCompany(string name)
        : Company(name)
    {}

    void Add(Company *c)
    {
        children.push_back(c);
    }

    void Remove(Company *c)
    {
        children.remove(c);
    }

    void Display(int depth)
    {
        cout << string(depth, '-') << name << endl;
        typename list<Company*>::iterator it;
        for (it = children.begin(); it != children.end(); it++)
            (*it)->Display(depth+2);
    }

    void LineofDuty()
    {
        typename list<Company*>::iterator it;
        for (it = children.begin(); it != children.end(); it++)
            (*it)->LineofDuty();
    }
private:
    list<Company*> children;
};

class HRDepartment : public Company
{
public:
    HRDepartment(string nm) : Company(nm)
    {}

    void Display(int depth)
    {
        cout << string(depth, '-') << name << endl;
    }

    void LineofDuty()
    {
        cout << name << " 员工招聘培训管理" << endl;
    }
};

class FinanceDepartment : public Company
{
public:
    FinanceDepartment(string nm) : Company(nm)
    {}

    void Display(int depth)
    {
        cout << string(depth, '-') << name << endl;
    }

    void LineofDuty()
    {
        cout << name << " 公司财务收支管理" << endl;
    }
};

int main()
{
    ConcreteCompany root("北京总公司");
    root.Add(new HRDepartment("总公司人力资源部"));
    root.Add(new FinanceDepartment("总公司财务部"));

    ConcreteCompany comp("上海华东分公司");
    comp.Add(new HRDepartment("华东分公司人力资源部"));
    comp.Add(new FinanceDepartment("华东分公司财务部"));
    root.Add(&comp);

    ConcreteCompany comp1("南京办事处");
    comp1.Add(new HRDepartment("南京办事处人力资源部"));
    comp1.Add(new FinanceDepartment("南京办事处财务部"));
    comp.Add(&comp1);

    ConcreteCompany comp2("杭州办事处");
    comp2.Add(new HRDepartment("杭州办事处人力资源部"));
    comp2.Add(new FinanceDepartment("杭州办事处财务部"));
    comp1.Add(&comp2);

    cout << "\n结构图: " << endl;
    root.Display(1);

    cout << "\n职责: " << endl;
    root.LineofDuty();

    return 0;
}
