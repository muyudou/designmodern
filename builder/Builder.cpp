//构造者模式:将一个复杂对象的构建与它的表示分离，使得同样的构建过程可以创建不同的表示
#include "mapsite.h"

//Builder
class MazeBuilder
{
public:
    virtual void BuildMaze()
    {
    }

    virtual void BuildRoom(int room)
    {
    }

    virtual void BuildDoor(int roomFrom, int foomTo)
    {
    }

    //提供一个构建好的Maze
    virtual Maze* GetMaze()
    {
        return 0;
    }
};

class StandardMazeBuilder : public MazeBuilder
{
public:
    StandardMazeBuilder() 
    {
        _currentMaze = 0;
	cout << "StandardMazeBuilder" << endl;
    }

    void BuildMaze()
    {
        _currentMaze = new Maze;
    }

    void BuildRoom(int n)
    {
        Room *room = new Room(n);
	_currentMaze->AddRoom(room);

	room->SetSide(North, new Wall);
	room->SetSide(South, new Wall);
	room->SetSide(East, new Wall);
	room->SetSide(West, new Wall);
    }

    void BuildDoor(int n1, int n2)
    {
        Room r1(n1);
        Room r2(n2);
	Door *d = new Door(&r1, &r2);

	r1.SetSide(CommonWall(&r1, &r2), d);
	r2.SetSide(CommonWall(&r2, &r1), d);
    }

    Maze* GetMaze()
    {
        return _currentMaze;   
    }
private:
    Direction CommonWall(Room*, Room*)
    {
        return North;
    }
    Maze* _currentMaze;
};

//用于计数的类
class CountingMazeBuilder : public MazeBuilder
{
public:
    CountingMazeBuilder()
    {
        _doors = _rooms = 0;
        cout << "CountingMazeBuilder" << endl;
    }

    void BuildMaze()
    {
            
    }

    void BuildRoom(int n)
    {
        _rooms++;
    }

    void BuildDoor(int , int)
    {
       _doors++;
    }

    void GetCounts(int &rooms, int &doors) const
    {
        rooms = _rooms;
	doors = _doors;
    }
private:
    int _doors;
    int _rooms;
};

//构建迷宫的类,director,导向类，引导builder的生成
class MazeGame
{
public:
    Maze* CreateMaze(MazeBuilder& builder)
    {
        builder.BuildMaze();
	builder.BuildRoom(1);
	builder.BuildRoom(2);
	builder.BuildDoor(1, 2);

	return builder.GetMaze();
    }
};

int main()
{
    Maze *maze;
    MazeGame game;
    StandardMazeBuilder builder;

    game.CreateMaze(builder);
    maze = builder.GetMaze();

    int rooms, doors;
    CountingMazeBuilder cbuilder;
    game.CreateMaze(cbuilder);
    cbuilder.GetCounts(rooms, doors);

    cout << "The maze has " << rooms 
         << " rooms and " << doors << " doors" << endl;
    
    return 0;
}
