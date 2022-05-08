// reference variables and typecasting.

#include<iostream>
using namespace std;

int c = 45;      // global variable

int main(){
// ***************************Built in DATA TYPES*******************
// int a, b, c;

// cout<< "Enter the value of a: "<<endl;
// cin>>a;

// cout<< "Enter the value of b: "<<endl;
// cin>>b;

// c= a+b;

// cout<< "The value of c is: "<<c<<endl;
// cout<< "The global c is:"<<::c<<endl;    // :: is used to call global variable

// *************************** float double and long double LITERALS**************************
// float d = 34.4;
// long double e = 34.4;

// cout<<"The size of 34.4 is: "<< sizeof(34.4)<<endl;
// cout<<"The size of 34.4f is: "<< sizeof(34.4f)<<endl;
// cout<<"The size of 34.4F is: "<< sizeof(34.4F)<<endl;
// cout<<"The size of 34.4l is: "<< sizeof(34.4l)<<endl;
// cout<<"The size of 34.4L is: "<< sizeof(34.4L)<<endl;

// cout<< "The value of d is: "<<d<<endl;
// cout<< "The value of e is: "<<e<<endl;


// ********************************REFERENCE VARIABLES****************************
// float x = 453;
// float & y = x;     //x ka hi doosra naam y rakha h iss tarike se

// cout<<"The value of x is: "<<x<<endl;
// cout<<"The value of y is: "<<y<<endl;


//*************TYPECASTING******************
int a= 45;
float b= 45.46;

cout<<"The value of a is: "<<(float)a<<endl;
cout<<"The value of a is: "<<float(a)<<endl;
cout<<"The value of b is: "<<(int)b<<endl;
cout<<"The value of b is: "<<int(b)<<endl;


cout<<"The expression is: "<<a+b<<endl;
cout<<"The expression is: "<<a+int(b)<<endl;
cout<<"The expression is: "<<a+(int)b<<endl;


    return 0;


}