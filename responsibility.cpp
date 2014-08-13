/*职责链：使多个对象都有机会处理请求，从而避免请求的发送者和接受者之间的耦合
  关系，将这些对象形成一条链，并沿着这条链传递该请求，知道有一个对象处理它
  为止*/
#include <iostream>
using namespace std;

typedef int Topic;
const Topic NO_HELP_TOPIC = -1;
const Topic PRINT_TOPIC = 1;
const Topic PAPER_ORIENTATION_TOPIC = 2;
const Topic APPLICATION_TOPIC = 3;

//处理帮助请求的接口，维护一个帮助请求（缺省为空）,
//并保持对请求链中后继者的请求
class HelpHandler
{
public:
    HelpHandler(HelpHandler* h = 0, Topic t = NO_HELP_TOPIC)
        : _successor(h), _topic(t)
    {

    }

    virtual bool HasHelp()
    {
        return _topic != NO_HELP_TOPIC;
    }

    virtual void SetHandler(HelpHandler* h, Topic t)
    {
        _successor = h;
        _topic = t;
    }

    //处理请求，可被子类重定义
    virtual void HandleHelp()
    {
        if (_successor != 0)
            _successor->HandleHelp();
    }
private:
    HelpHandler *_successor;
    Topic _topic;
};

//窗口组件的基类，所有的用户界面元素都可有相关的帮助
class Widget : public HelpHandler
{
protected:
    Widget(Widget* parent, Topic t = NO_HELP_TOPIC)
        : HelpHandler(parent, t)
    {
        _parent = parent;
    }
private:
    Widget* _parent;
};

//按钮是链上的第一个请求者
class Button : public Widget
{
public:
    //一个是包含它的窗口的组件的引用和其自身的帮助请求
    Button(Widget* d, Topic t = NO_HELP_TOPIC)
        : Widget(d, t)
    {}

    //重写该函数:如果本身有help,则直接演示，否则调用HelpHandler
    //的操作将该请求转发给它的后继者
    void HandleHelp()
    {
        if (HasHelp())
            cout << "Button Help" << endl;
        else
            HelpHandler::HandleHelp();
    }
};

class Dialog : public Widget
{
public:
    //后继者不是一个窗口组件而是任意的帮助请求处理对象
    Dialog(HelpHandler* h, Topic t = NO_HELP_TOPIC)
        : Widget(0)
    {
        SetHandler(h, t);
    }

    void HandleHelp()
    {
        if (HasHelp())
            cout << "Dialog Help" << endl;
        else
            HelpHandler::HandleHelp();
    }
};

//链的末端是Application的实例
class Application : public HelpHandler
{
public:
    Application(Topic t) : HelpHandler(0, t)
    {}

    void HandleHelp()
    {
        cout << "剩下所有的帮助主题" << endl;
    }
};

int main()
{
    Application* app = new Application(APPLICATION_TOPIC);
    Dialog* dialog = new Dialog(app, PRINT_TOPIC);
    Button* button = new Button(dialog, PAPER_ORIENTATION_TOPIC);
    button->HandleHelp();
    
    button = new Button(dialog);
    button->HandleHelp();
    
    dialog = new Dialog(app);
    button = new Button(dialog);
    button->HandleHelp();
    
    return 0;
}
