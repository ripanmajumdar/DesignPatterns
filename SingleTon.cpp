
/*
Singleton design pattern ensures that a class has only one instance 
and provides a global point of access to that instance. It is commonly 
used when you want to limit the number of instances of a class and provide 
a single point of access to that instance throughout your application.

Here's a C++ implementation of the Singleton design pattern.
*/
#include<iostream>
#include<mutex>

using namespace std;
mutex mtx;
class singleton{
    private:
    inline static singleton *instance=nullptr;
    //make default constructor private
    singleton()=default;
    ~singleton()=default;
    public:
    //delete all default constructor & operator overload funtion
    singleton(const singleton&)=delete;
    singleton(const singleton&&)=delete;
    singleton operator=(const singleton&)=delete;
    static singleton *getInstance();
};
singleton *singleton::getInstance(){
    if(instance==nullptr){
        mtx.lock();
        if(instance==nullptr){
            cout<<"Created a new instance\n";
            return instance = new singleton();
        }
        mtx.unlock();
    }
    cout<<"Returning existing instance\n";
    return instance;
}

int main()
{
    singleton *ins1=singleton::getInstance();
    singleton *ins2=singleton::getInstance();
    return 0;
}
