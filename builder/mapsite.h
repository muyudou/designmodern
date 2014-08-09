//迷宫基类
#include <iostream>
using namespace std;

class MapSite 
{
public:
    virtual void Enter() = 0;
};

enum Direction {North, South, East, West};

class Room : public MapSite
{
public:
    Room(int roomNo) : _roomNumber(roomNo)
    {
        cout << "Room:" << roomNo << endl; 
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
    void Enter()
    {
        cout << "Enter Wall" << endl;
    }
};

class Door : public MapSite
{
public:
    Door(Room* r1= 0, Room* r2= 0)
        : _room1(r1), _room2(r2)
    {
        _isOpen = false;
	cout << "Door" << endl;
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
    bool _isOpen;
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

