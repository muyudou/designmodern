//原型模式:用原型实例指定创建对象的种类，并且通过拷贝这些原型创建新的对象
#include "clonemapsite.h"

class MazeFactory
{
public:
    MazeFactory() {}
    virtual Maze *MakeMaze() const
    {
        return new Maze;
    }

    //每个都克隆一个原型，然后有自己的状态的要初始化
    virtual Wall* MakeWall() const
    {
        return new Wall;
    }

    //通过克隆产生对象
    virtual Room* MakeRoom(int n) const
    {
        return new Room;
    }

    virtual Door* MakeDoor(Room* r1, Room* r2) const
    {
        return new Door;
    }
};

//用一个以原型为参数的构造器来扩充MazeFactory接口
class MazePrototypeFactory : public MazeFactory
{ 
public:
    MazePrototypeFactory(Maze* m, Wall* w, Room* r, Door* d)
    {
        _prototypeMaze = m;
        _prototypeWall = w;
        _prototypeRoom = r;
        _prototypeDoor = d;
    }

    Maze *MakeMaze() const
    {
        return new Maze;
    }

    //每个都克隆一个原型，然后有自己的状态的要初始化
    Wall* MakeWall() const
    {
        return _prototypeWall->Clone();
    }

    //通过克隆产生对象
    Room* MakeRoom(int n) const
    {
        Room* r = _prototypeRoom->Clone();
        r->Initialize(n);
        return r;
    }

    Door* MakeDoor(Room* r1, Room* r2) const
    {
        Door* door = _prototypeDoor->Clone();
        door->Initialize(r1, r2);
        return door;
    }
private:
    Maze* _prototypeMaze;
    Room* _prototypeRoom;
    Wall* _prototypeWall;
    Door* _prototypeDoor;
};

//以下这个类建立一个迷宫：有两个房间和他们之间的门组成
class MazeGame
{
public:
    Maze* CreateMaze(MazeFactory& factory)
    {
        //生成一个迷宫：两个房间一个门
        Maze* aMaze = factory.MakeMaze();
        Room* r1 = factory.MakeRoom(1);
        Room* r2 = factory.MakeRoom(2);
        Door* aDoor = factory.MakeDoor(r1, r2);

        aMaze->AddRoom(r1);
        aMaze->AddRoom(r2);

        r1->SetSide(North, factory.MakeWall());
        r1->SetSide(East, aDoor);
        r1->SetSide(South, factory.MakeWall());
        r1->SetSide(West, factory.MakeWall());
        r2->SetSide(North, factory.MakeWall());
        r2->SetSide(West, aDoor);
        r2->SetSide(East, factory.MakeWall());
        r2->SetSide(South, factory.MakeWall());

        return aMaze;
    }
};

int main()
{
    MazeGame game;
    MazePrototypeFactory simpleMazeFactory
        (new Maze, new Wall, new Room, new Door);
    Maze* maze = game.CreateMaze(simpleMazeFactory);

    //构造一个有炸弹的迷宫
    MazePrototypeFactory bombedMazeFactory
        (new Maze, new BombedWall, new RoomWithABomb, new Door);

    maze = game.CreateMaze(bombedMazeFactory);

    return 0;
}
