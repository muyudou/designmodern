//原型模式用到的原型类
#include <iostream>
using namespace std;

//原型基类
class MapSite 
{
public:
    virtual void Enter() = 0;
    virtual MapSite* Clone() const
    {
    }
};

enum Direction {North, South, East, West};

//具体原型，需要定义Clone,必要时定义拷贝构造函数，
//或添加一个intialize初始化自己的状态，因为无法在clone传入特定的状态
class Room : public MapSite
{
public:
    Room()
    {
        cout << "Room" <<  endl; 
    }

    Room(const Room& r)
    {
         _roomNumber = r._roomNumber;
        int i;
        for (i = 0; i < 4; i++)
            _sides[i] = r._sides[i];
    }

    virtual void Initialize(int n)
    {
        _roomNumber = n;
    }

    Room* Clone() const
    {
        //通过拷贝自己产生一个新的对象，状态和自己一样
        return new Room(*this); 
    }

    MapSite* GetSide(Direction d) const
    {
        return _sides[d];
    }

    void SetSide(Direction d, MapSite* m)
    {
        _sides[d] = m;
    }

    void Enter()
    {
        cout << "Enter Room" << endl;
    }
private:
    MapSite* _sides[4];
    int _roomNumber;
};

class Wall : public MapSite
{
public:
    Wall()
    {
        cout << "Wall()" << endl;
    }

    Wall* Clone() const
    {
        return new Wall(*this);
    }

    void Enter()
    {
        cout << "Enter Wall" << endl;
    }
};

class Door : public MapSite
{
public:
    Door() : _room1(0), _room2(0)
    {
    }

    //要定义拷贝构造函数，因为是通过拷贝构造函数进行clone
    Door(const Door& d)
    {
        //都写的浅拷贝埃。。
        _room1 = d._room1;
        _room2 = d._room2;
        
    }

    virtual void Initialize(Room* r1, Room* r2)
    {
         _room1 = r1;
         _room2 = r2;
    }

    Door* Clone()
    {
        return new Door(*this);
    }

    void Enter()
    {
        cout << "Enter Door" << endl;
    }

    Room* OtherSideFrom(Room*)
    {
        return NULL;
    }
private:
    Room* _room1;
    Room* _room2;
};

//一个有炸弹的墙
class BombedWall : public Wall
{
public:
    BombedWall() : _bomb(true)
    {
        cout << "BombedWall" << endl;
    }

    BombedWall(const BombedWall& bw)
    {
        _bomb = bw._bomb;
    }

    Wall* Clone() const
    {
        return new BombedWall(*this);
    }
private:
    bool _bomb;
};

//有炸弹的房间
class RoomWithABomb : public Room 
{
public:
    RoomWithABomb() : _bomb(true)
    {
        cout << "BombedWall" << endl;
    }

    RoomWithABomb(const RoomWithABomb& bw)
    {
        _bomb = bw._bomb;
    }

    //返回值虽然是基类类型，但实现返回了一个BombedWall*, 这样定义是为了
    //保证克隆客户的原型不需要知道具体的子类。
    Room* Clone() const
    {
        return new RoomWithABomb(*this);
    }
private:
    bool _bomb;
};

class Maze
{
public:
    Maze()
    {
        cout << "Maze" << endl;
    }
    void AddRoom(Room* r)
    {
        cout << "增加一个新的Room,id是" << endl;
    }

    Room* RoomNo(int id) const
    {
        cout << "返回id为: " << id << "的房间" << endl;
    }
};
