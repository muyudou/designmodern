#include <iostream>
#include <pthread.h>
using namespace std;

//解决懒汉式单例模式的多线程同步问题，即在new对象前加上锁，锁的实现在
//linux下采用mutex就够了，因为与顺序无关，只要保证一个时间只有一个线程就行了

class ThreadLazySingleton
{
public:
    static ThreadLazySingleton* getInstance(pthread_mutex_t mutex)
    {
        if (instance == NULL)
        {
            pthread_mutex_lock(&mutex);
            //双重检查，因为如果有两个线程同时通过第一个条件判断，进入到
            //内部条件，然后一个线程先申请到互斥量，之后如果为NULL，创建，
            //但它退出后，已经分配了一个，所以必须再次重新判断一次是否为
            //NULL，否则会再次分配一个对象。
            if (instance == NULL)
            {
                instance = new ThreadLazySingleton;
                cout << "getInstance():" << instance << endl;
            }
            pthread_mutex_unlock(&mutex);
            return instance;
        }
    }
private:
    ThreadLazySingleton() {}
    static ThreadLazySingleton *instance;
};

ThreadLazySingleton* ThreadLazySingleton::instance = NULL;

void *th_fn1(void *args)
{
    cout << "线程" << pthread_self() << "开始运行" << endl;
    pthread_mutex_t *mutex = (pthread_mutex_t*)args;
    ThreadLazySingleton *p = ThreadLazySingleton::getInstance(*mutex);
    cout << p << endl;
    pthread_exit((void*)p);
}

int main()
{
    pthread_mutex_t mutex;
    pthread_mutex_init(&mutex, NULL); //初始化互斥量

    int err;
    pthread_t tid1, tid2;
    ThreadLazySingleton* p1;
    ThreadLazySingleton* p2;
    err = pthread_create(&tid1, NULL, th_fn1, &mutex);
    if (err != 0)
        cout << "创建线程" << tid1 << "错误！" << endl;
    err = pthread_create(&tid2, NULL, th_fn1, &mutex);
    if (err != 0)
        cout << "创建线程" << tid2 << "错误！" << endl;
    pthread_join(tid1, (void**)&p1);
    pthread_join(tid2, (void**)&p2);
    //pthread_mutex_destory(&mutex);

    if (p1 == p2)
        cout << "同一个对象，同步正确" << endl;
    cout << p1 <<" " << p2 << endl;
    return 0;
}
