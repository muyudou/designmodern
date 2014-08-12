//观察者模式：定义对象间一种一对多的依赖关系，当一个对象的状态发生改变时，
//所有依赖于它的对象都得到通知并被自动更新
#include <iostream>
#include <list>
using namespace std;

class Subject;

//抽象观察者基类
class Observer
{
public:
    virtual ~Observer()
    {}

    virtual void Update(Subject* theChangedSubject) = 0;
protected:
    Observer()
    {}
};

//目标基类
class Subject
{
public:
    virtual ~Subject()
    {
    }
    virtual void Attach(Observer* o)
    {
        _observers.push_back(o);
    }

    virtual void Detach(Observer* o)
    {
        _observers.remove(o);
    }

    virtual void Notify()
    {
        typename list<Observer*>::iterator it;
        for(it = _observers.begin(); it != _observers.end(); it++)
        {
            //当状态更改的时候通知每一个观察者
            (*it)->Update(this);  
        }
    }
protected:
    Subject() {}
private:
    list<Observer*> _observers;
};

//具体目标类，存储和维护一天时间的具体目标，每秒钟通知一次它的观察者
//本例中所有观察着都观察这个目标，当它的时间变动的时候通知所有观察者
class ClockTimer : public Subject
{
public:
    ClockTimer() : hour(0), minute(0), second(0) 
    {
    }

    virtual int GetHour()
    {
        return hour;
    }

    virtual int GetMinute()
    {
        return minute;
    }

    virtual int GetSecond()
    {
        return second;
    }

    //每调用一次，更改状态，发出通知
    void Tick()
    {
        hour++;
        minute++;
        second++;
        Notify();   //调用该函数，通知所有的观察者
    }
private:
    int hour;
    int minute;
    int second;
};

//具体观察者类
class DigitalClock : public Observer
{
public:
    DigitalClock(ClockTimer* c)
    {
        _subject = c;
        _subject->Attach(this);  //将自己添加到目标的通知序列中
    }

    virtual ~DigitalClock()
    {
        _subject->Detach(this);  //将自己从通知序列中删除
    }

    void Update(Subject* s)     //更新函数，当自己观察的目标更改了状态的时候，该函数调用，然后输出
    {
        if (s == _subject)
            Draw();
    }

    void Draw()
    {
        cout << "画电子时钟" << endl;
        cout << "目前的时间是：" << _subject->GetHour() << ":"
            << _subject->GetMinute() << ":" 
            << _subject->GetSecond() << endl;
    }
private:
    ClockTimer* _subject; //目标者，观察它的状态变化
};

class AnalogClock : public Observer
{
public:
    AnalogClock(ClockTimer* c)
    {
        _subject = c;
        _subject->Attach(this);
    }

    virtual ~AnalogClock()
    {
        _subject->Detach(this);
    }

    void Update(Subject *s)
    {
        if (_subject == s)
            Draw();
    }

    void Draw()
    {
        cout << "画数字时钟" << endl;
        cout << "目前的时间是：" << _subject->GetHour() << ":"
            << _subject->GetMinute() << ":" 
            << _subject->GetSecond() << endl;
    }
private:
    ClockTimer* _subject;
};

int main()
{
    ClockTimer* timer = new ClockTimer;
    AnalogClock* analogClock = new AnalogClock(timer);
    DigitalClock* digitalClock = new DigitalClock(timer);

    int i;
    for (i = 0; i < 5; i++)
        timer->Tick();

    return 0;
}
