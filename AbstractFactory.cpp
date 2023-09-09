/****************Factory Pattern********************************* 
The Abstract Factory Design Pattern is a creational design pattern that provides 
an interface for creating families of related or dependent objects without specifying
their concrete classes. It allows you to create objects based on a common theme or category
while keeping the system decoupled from the actual implementation details of those objects.
This pattern is particularly useful when you need to ensure that the created objects are
compatible with each other.
 *****************************************************************/

#include<iostream>

using namespace std;

class MySQL{
    public:
    virtual void connect()=0;
};
class CentOSMySQL:public MySQL{
    void connect() override {
        cout<<"CentOS: Connected to MySQL DB\n";
    }
};
class CaviumMySQL:public MySQL{
    void connect() override{
        cout<<"Cavium: Connected to Cavium DB\n";
    }
};

class MongoDB{
    public:
    virtual void connect()=0;
};
class CentOSMongoDB:public MongoDB{
    void connect() override {
        cout<<"CentOS: Connected to MongoDB DB\n";
    }
};
class CaviumMongoDB:public MongoDB{
    void connect() override{
        cout<<"Cavium: Connected to MongoDB DB\n";
    }
};

class DBfactory{
    public:
    virtual MySQL *createMySQLOb()=0;
    virtual MongoDB *createMongoDBLOb()=0;
};

class centosOSDBfactory:public DBfactory{
    public:
    MySQL *createMySQLOb(){
        return new CentOSMySQL();
    }
     MongoDB *createMongoDBLOb(){
        return new CentOSMongoDB();
    }
};
class caviumOSDBfactory:public DBfactory{
    public:
    MySQL *createMySQLOb(){
        return new CaviumMySQL();
    }
     MongoDB *createMongoDBLOb(){
        return new CaviumMongoDB();
    }
};

int main(){
    //Suppose OS is CentOS then need to initilize CentOS database only
    DBfactory *ob=new centosOSDBfactory();
    MySQL *mysql = ob->createMySQLOb();
    MongoDB *mongodb=ob->createMongoDBLOb();
    mysql->connect();
    mongodb->connect();
    return 0;
}
