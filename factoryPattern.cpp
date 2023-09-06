/****************Factory Pattern********************************* 
The Factory Design Pattern aims to provide an interface for 
creating objects in a way that is decoupled from the client code.
 It ensures that the client code does not need to know the specific
classes of objects it's creating but instead relies on a common interface
 provided by the factory.
 *****************************************************************/

#include<iostream>

using namespace std;
enum class dbType{MYSQL,SQLITE,CASANDRA};
class database{
    public:
    virtual void connect()=0;
};
class mySql:public database{
    void connect() override {
        cout<<"Connected to MySQL DB\n";
    }
};
class sqLite:public database{
    void connect() override{
        cout<<"Connected to SQlite DB\n";
    }
};
class casandra:public database{
    void connect() override{
        cout<<"Connected to Casandra DB\n";
    }
};

class factory{
    private:
    database *db;
    public:
    factory(dbType e){
        switch(e){
            case dbType::MYSQL:
                db = new mySql();
            break;

            case dbType::SQLITE:
                db = new sqLite();
            break;

            case dbType::CASANDRA:
                 db = new casandra();
            break;
        }
    }
    database *getDBHandle(){return db;}
};
int main(){
    factory ob(dbType::CASANDRA);
    database *dbh = ob.getDBHandle();
    dbh->connect();
    return 0;
}
