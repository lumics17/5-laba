#include <iostream>
#include <iomanip>
#include <vector>
#include "newfile.h" 
using namespace std;
const double PI=3.14159;
int main() {
    double a=0,b=1.047;
    double(*func)(double)=Task;
    cout<<"Enter N:"<<endl;
    int N=0;
    cin>>N;
    printAnswer(TPIntegral(a,b,func,N));
    printAnswer(SMIntegral(a,b,func,N));
//    cout<<TPIntegral(a,b,func,N);
    
    
    a=0,b=0;
    double A=PI/2,B=PI/3;
     cout<<"Enter M:"<<endl;
    int M=0;
    cin>>M;
    double (*func2)(double,double)=TaskDoubleIN;
    printAnswer(DISMIntegral(a,A,b,B,func2,N,M));
   
}