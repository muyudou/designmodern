//装饰模式：动态的给一个对象添加一些额外的规则
#include <iostream>
#include <string>
using namespace std;

//对象接口，可以给这些对象动态的添加职责
class VisualComponent
{
public:
    virtual void Draw() = 0;
    virtual void Resize() = 0;
};

//具体组建类，可以被修饰
class Component : public VisualComponent
{
public:
    Component(string nm) : name(nm)
    {
    }

    void Draw()
    {
        cout << name << "绘制" << endl;
    }

    void Resize()
    {
        cout << name << "扩大化" << endl;
    }
private:
    string name;
};

//装饰类
class Decorator : public VisualComponent
{
public:
    Decorator(VisualComponent* comp)
    {
        _component = comp;
    }

    //只是转发动作给_component
    void Draw()
    {
        _component->Draw();
    }

    void Resize()
    {
        _component->Resize();
    }
protected:
    //装饰的父类中指向组件的指针，用于进行动作的转发
    //之后在动作之前之后可以添加不同的修饰
    VisualComponent* _component;
};

//添加边框子类
class BorderDecorator : public Decorator
{
public:
    BorderDecorator(VisualComponent* comp, int w)
        : Decorator(comp), _width(w)
    {

    }

    //先调用父类的Draw，父类再调用被修饰的组件的draw
    //之后在调用自己新的操作
    void Draw()
    {  
        Decorator::Draw();  
        DrawBorder(_width);
    }
private:
    int _width;
    void DrawBorder(int _width)
    {
        cout << "画" << _width << "宽的边框 " << endl;
    }
};

//添加滚动条
class ScrollDecorator : public Decorator
{
public:
    ScrollDecorator(VisualComponent *comp)
       : Decorator(comp)
    {}

    void Draw()
    {
        _component->Draw();
        ScrollTo();
    }

private:
    void ScrollTo()
    {
        cout << "添加滚动条 " << endl;
    }
};

//嵌套调用
int main()
{
    Component c("组件1");
    BorderDecorator border(&c, 3);
    ScrollDecorator scroll(&border);

    scroll.Draw();

    return 0;
}
