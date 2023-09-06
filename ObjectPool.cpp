/*The Object Pool design pattern is a creational pattern that falls under the category
 of design patterns in software engineering. It is used to manage a pool of reusable objects,
 which can help improve the performance and resource utilization of an application,
 especially in scenarios where object creation and destruction are expensive operations.

Here's an example of how you can implement the Object Pool design pattern in C++:*/

#include<iostream>
#include<list>

using namespace std;

class resource{
    private:
    int i;
    public:
    void setResource(const int x) {i=x;}
    int getResource(){return i;}
    void resetResource(){i=0;}
    void display(){cout<<"Resource value is : "<<i<<endl;}
};

class objectPool{
    private:
    static objectPool *instance;
    list<resource*> pool;
    public:
    static objectPool *getInstance(){
        if(!instance){
            return instance=new objectPool();
        }
       return instance; 
    }
    resource *getResource(){
        if(pool.size()==0){
            cout<<"New created resource returning\n";
            return new resource();
        }
        else{
            resource *tmp=pool.front();
            pool.pop_front();
            cout<<"Resource returning from pool \n";
            return tmp;
        }
    }
    void returnResource(resource *r){
        r->resetResource();
        pool.push_back(r);
    }
};
objectPool *objectPool::instance=nullptr;

int main()
{
    //Newly created resource will return
    objectPool *ob=objectPool::getInstance();
    resource *r1 = ob->getResource();
    r1->setResource(100);
    r1->display();
    ob->returnResource(r1);
    cout<<"-----------------------------------------\n";
    //Resource must return from pool
    resource *r2 = ob->getResource();
    r2->setResource(500);
    r2->display();
    ob->returnResource(r2);
    return 0;
}