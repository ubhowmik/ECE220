#include <iostream>     // used for IO
#include <cmath>

using namespace std;    // creates textual container for variables and functions

class vector {          // class is generalization of struct

  public:               
  // public identifies the 'public exposure' of this class to the 'outside'

  // functions that build instances, so-called 'constructors'
  vector(double a, double l) { 
	angle = a; length = l; cout<<"Parameterized Constructor Called"<<endl;}

  // notice "overloading" of function name
  vector() { angle =0.0; length = 0.0; cout<<"Default Constructor"<<endl;}  

  //function that delete instances, so-called 'destructor'
  ~vector() { cout << "vector object destructed" << endl;}

  // functions tied to variables of this class
   double getAngle() { return angle; }

   double getLength() { return length; }

   void scale(double a) { length *= a; }   // extend or contract vector

   vector operator + (const vector &b) {   
   // produce new vector by adding argument to variable
	vector c;
	double ax = length*cos(angle);
	double bx = b.length*cos(b.angle);
	double ay = length*sin(angle);
	double by = b.length*sin(b.angle);
	double cx = ax+bx;
	double cy = ay+by;
	c.length = sqrt(cx*cx+cy*cy);
	c.angle = acos( cx/c.length );

	return c;
   }

   protected:  
   double angle, length;

};
 
class orthovector : public vector{
   protected:
   int d; //direction can be 0,1,2,3, indicating r, l, u, d
   public:
   orthovector(int dir, double l){
		const double halfPI = 1.507963268;
		d = dir;
		angle = d*halfPI;
		length = l;
   }
   orthovector() {d = 0; angle = 0.0; length = 0.0;}
   double hypotenuse(orthovector b){
		if((d+b.d)%2 == 0) return length + b.length;
		return (sqrt(length*length + (b.length)*(b.length)));
   }
};

 
int main() {
 vector c(1.5,2);
 vector d(2.6,3);
 vector e = c+d;
 cout<<"vector e has angle: " << e.getAngle() << ", length: " << e.getLength() <<endl;

 orthovector f(0,5);
 orthovector h(1,4);
 cout << "f's length is " << f.getLength() << endl;
 cout << "f and h's hypotenuse is " << f.hypotenuse(h) << endl;

 return 0;
}