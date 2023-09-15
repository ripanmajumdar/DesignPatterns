/*--------------------------------------------------------------
Target: This is the interface with which the client interacts.

Adaptee: This is the interface the client wants to interact with, 
but can not interact without the help of the Adapter.

Adapter: This is derived from Target and contains the object of Adaptee.

    Adaptee------------------<>Adapter--------->Target
   Indian Plug(Round shape)            London Plug(Flat shape)   		 
----------------------------------------------------------------*/
#include <iostream>
using namespace std;

//Abstract Target
class EuropeanBoard{
public:
  void virtual flatSocket(){}
};
// Concrete Target
class socket : public EuropeanBoard{
public:
  void flatSocket() {
    cout << "Connected: I am flat socket\n" << endl;
  }
};

// Abstract Adaptee
class indianPin{
public:
  void virtual roundPin() {}
 };
// Concrete Adaptee
class pin: public indianPin{
public:
  void roundPin() {
        cout << " round Pin" << endl;
  }
};
// Adapter
class Adapter{
public:
  EuropeanBoard *T;
  Adapter(EuropeanBoard *TT) {
        T = TT;
  }
  void RoundPin() {
        T->flatSocket();
  }
};

// Client code
int main()
{
  Adapter *adapter = new Adapter(new socket());
  adapter->RoundPin(); //Round pin will be converted by adapter class to Flat pin
  return 0;
}
