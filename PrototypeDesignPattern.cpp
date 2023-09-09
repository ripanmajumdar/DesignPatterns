/*The Prototype Design Pattern is a creational design pattern that allows you 
to create new objects by copying an existing object, known as the prototype. 
This pattern is particularly useful when creating complex objects or when the 
cost of object creation is high. It promotes object reusability and reduces the 
need for creating objects from scratch.*/
#include<iostream>
#include<string>

using namespace std;

class prototype{
    public:
    virtual prototype* clone() const=0;
    virtual void display() const =0;
};

class prototypeA:public prototype{
    private:
    int i;
    public:
    prototypeA(int x):i(x){}
    prototype* clone() const {
        return new prototypeA(*this);
    }
    void display() const {
        cout<<"prototypeA (i): "<<i<<"\n";
    }
};

class prototypeB:public prototype{
    private:
    string s;
    public:
    prototypeB(string x):s(x){}
    prototype* clone() const {
        return new prototypeB(*this);
    }
    void display() const {
        cout<<"prototypeB (s): "<<s<<endl;
    }
};

int main()
{
    prototypeA pA(100);
    prototype *pAA = pA.clone();
    pAA->display();

    prototypeB pB("I M Clone of prototypeB");
    prototype *pBB = pB.clone();
    pBB->display();
    return 0;
}

