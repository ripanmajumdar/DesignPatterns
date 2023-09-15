#include <iostream>
#include <string>
using namespace std;

/* Car parts */
class product{
    private:
    int wheelSize;
    int engineCapacity;
    double carLength;
    public:
    void setWheelSize(int s){wheelSize=s;}
    void setengineCapacity(int e){engineCapacity=e;}
    void setcarLength(double l){carLength=l;}
    void displayCarDetails(){
        cout<<"Car Length:"<<carLength<<"\n";
        cout<<"Engine Capacity:"<<engineCapacity<<"\n";
        cout<<"Car Wheel Size:"<<wheelSize<<"\n";
    }
};

class builder{
    protected:
      product p;
    public:
    virtual void buildWheel()=0;
    virtual void buildEngine()=0;
    virtual void buildBody()=0;
    virtual void displayCar()=0;
  };

//build seden Car
class sedan:public builder{
    public:
    void buildWheel() {
        p.setWheelSize(15);
     }
    void buildEngine(){
        p.setengineCapacity(1200);
    }
    void buildBody(){
        p.setcarLength(4.2);
    }
    void displayCar(){
        p.displayCarDetails();
    }
};
//build SUV Car
class suv:public builder{
    public:
    void buildWheel(){
        p.setWheelSize(17);
     }
    void buildEngine(){
        p.setengineCapacity(2000);
    }
    void buildBody(){
        p.setcarLength(4.8);
    }
    void displayCar(){
        p.displayCarDetails();
    }
};

/* Director is responsible for the whole process */
class Director
{
    builder* ob;
    public:
        Director(builder *tmp):ob(tmp){}
        void construct(){
          ob->buildWheel();
          ob->buildEngine();
          ob->buildBody();
        }
        void displayObject(){
         ob->displayCar();
        }
};


int main()
{
     /* A director who controls the process */
     //Construct sedan car
    Director d1(new sedan());
    cout<<"-------SEDAN CAR DETAILS------\n";
    d1.construct();
    d1.displayObject();
    
      //Construct SUV car
    Director d2(new suv());
    cout<<"\n-------SUV CAR DETAILS------\n";
    d2.construct();
    d2.displayObject();
    return 0;
}
