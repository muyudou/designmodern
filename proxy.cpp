//代理模式：为其他对象提供一种代理以控制对这个对象的访问

#include <iostream>
#include <string>
using namespace std;

struct Point
{
    int x;
    int y;
    Point() : x(0), y(0)
    {
    }
    Point(int xx, int yy) : x(xx), y(yy)
    {}
};
//代理和实际对象的接口 
class  Graphic
{
public:
    virtual ~Graphic() {}
    
    virtual void Draw(const Point& at) = 0;
    virtual void HandleMouse(string event) = 0;
    
    virtual const Point& GetExtent() = 0;
    
    virtual void Load() = 0;
    virtual void Save() = 0;
protected:
    //构造函数是保护的，不能创建对象 
    Graphic(){}
};

//真实对象 
class Image : public Graphic
{
public:
    //从一个文件下载图片 
    Image(string file)
    {
        _fileName = file;
        Point p(3, 4);
        _extent = p; 
    }
    ~Image(){}
    
    void Draw(const Point& at)
    {
        cout << "在点 (" << at.x << ","
             << at.y << ")处画" << endl; 
    }
    
    void HandleMouse(string event)
    {
        cout << "执行事件" << event << endl;
    }
    
    const Point& GetExtent()
    {
        cout << "图像的尺寸是：" << _extent.x 
             << "," << _extent.y << endl;
        return _extent; 
    }
    
    void Load()
    {
        cout << "载入图像..." << _fileName << endl; 
    }
    
    void Save()
    {
        cout << "保存图像" << _fileName << endl;
    }
private:
    Point _extent;
    string _fileName;
};

//代理 
class ImageProxy : public Graphic
{
public:
    //从一个文件下载图片 
    ImageProxy(string file) : _fileName(file), _image(0)
    {

    }
    ~ImageProxy()
    {
        delete _image;
    }
    
    void Draw(const Point& at)
    {
       GetImage()->Draw(at);
    }
    
    void HandleMouse(string event)
    {
        GetImage()->HandleMouse(event); 
    }
    
    const Point& GetExtent()
    {
        if (_extent.x == 0 && _extent.y == 0)
            _extent = GetImage()->GetExtent();
        return _extent; 
    }
    
    void  Load()
    {
        GetImage()->Load();
    }
    
    void Save()
    {
        GetImage()->Save();
    }
protected:
    Image* GetImage()
    {
        if (_image == 0)
            _image = new Image(_fileName);
        return _image;
    }
private:
    Image* _image;
    Point _extent;
    string _fileName;
};

int main()
{
    Point p(5, 9);
    ImageProxy imp("picture1");
    imp.Draw(p);
    imp.HandleMouse("event1");
    imp.GetExtent();
    imp.Load();
    imp.Save();
    
    return 0; 
}

