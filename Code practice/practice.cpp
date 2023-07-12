#include<iostream>
using namespace std;

class complex{
   int real,imag;
   public:
   complex(int r=0,int i=0){
      real = r;
      imag = i;
   }
   complex operator + (complex& obj){
      complex res;
      res.real = real + obj.real;
      res.imag = imag + obj.imag;
      return res;
   }
   void display(){
      cout<<real<<"+"<<imag<<"i"<<endl;
   }

};
int main(){
   complex a(5,9);
   complex b(4,8);
   complex c = a + b;
   c.display();
}