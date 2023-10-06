
/* The Composite design pattern is a structural pattern that allows you to compose objects 
into tree structures to represent part-whole hierarchies. It lets clients treat individual 
objects and compositions of objects uniformly. Here's a simple example of the Composite 
design pattern in C++.
Let's say we want to model a hierarchy of shapes, where a shape can be either a simple shape
like a circle or a rectangle or a composite shape consisting of multiple shapes. The composite
shape can also contain other composite shapes, creating a tree-like structure.*/

#include<iostream>
#include<vector>

using namespace std;

//Component base class
class shape{
    public:
    virtual void draw()=0;
};

//Component base class
class circle:public shape{
    public:
    void draw() override {
        cout<<"Drawing circle\n";
    }
};

//Component base class
class rectangle:public shape{
    public:
    void draw() override {
        cout<<"drawing rectangle\n";
    }
};

class composite:public shape{
    private:
    vector<shape*> shapes;
    public:
    void add(shape *s) {shapes.push_back(s);}

    void draw() override {
        for(auto it:shapes){
            it->draw();
        }
    }
};

int main(){
   circle c1;
   circle c2;
   rectangle r1;
   rectangle r2;
   composite ob;
   ob.add(&c1);
   ob.add(&c2);
   ob.add(&r1);
   ob.add(&r2);
   ob.draw();
   return 0;
}

