#include <iomanip>
#include <vector>
#include <iostream>
#include <math.h>
using namespace std;

double TPIntegral(double a,double b,double(*func)(double),int N){
    double answer = 0,x1 = 0, x2 = 0;
    double width=(b-a)/N;
    for(int i=1;i<N+1;i++){
      x1 = a + i*width;
      x2 = a + (i+1)*width;
        answer+=(x2-x1)*0.5*(func(x1)+func(x2));
    }
    return answer;
}
double SMIntegral(double a,double b,double(*func)(double),int N){
    double answer=0,x1 = 0, x2 = 0;
    double width=(b-a)/N;
    for(int i=1;i<N+1;i++){
      x1 = a + i*width;
      x2 = a + (i+1)*width;
        answer+= (x2-x1)/6.0*(func(x1) + 4.0*func(0.5*(x1+x2)) + func(x2));
    }
    return answer;
}



double xi(int i,double widthx,double a){
    double xi=a+i*widthx;
    return xi;
}

double yj(int j,double widthy,double b){
    double yj=b+j*widthy;
    return yj;
}
double DISMIntegral(double a,double A,double b,double B,double(*func)(double,double),int N,int M){
    double answer=0;
//    double xi=0,yj=0;
    double widthx=(A-a)/(2*N);
    double widthy=(B-b)/(2*M);
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
//            xi=a+i*widthx;
//            yj=b+j*widthy;
//           answer+=func(2*xi,2*yj) + 4*func(2*xi+1,2*yj) + func(2*xi+2,2*yj) + 4*func(2*xi,2*yj+1) + 16*func(2*xi+1,2*yj+1) + 4*func(2*xi+2,2*yj+1) + func(2*xi,2*yj+2) + 4*func(2*xi+1,2*yj+2) + func(2*xi+2,2*yj+2);
             answer+=  func(xi(2*i,widthx,a),yj(2*j,widthy,b)) 
                     
                     + 4*func(xi(2*i+1,widthx,a),yj(2*j,widthy,b)) 
                     
                     + func(xi(2*i+2,widthx,a),yj(2*j,widthy,b)) 
                     
                     + 4*func(xi(2*i,widthx,a),yj(2*j+1,widthy,b)) 
                     
                     + 16*func(xi(2*i+1,widthx,a)+1,yj(2*j+1,widthy,b))
                     
                     + 4*func(xi(2*i+2,widthx,a),yj(2*j+1,widthy,b)) 
                     
                     + func(xi(2*i,widthx,a),yj(2*j+2,widthy,b)) 
                     
                     + 4*func(xi(2*i+1,widthx,a),yj(2*j+2,widthy,b)) 
                     
                     + func(xi(2*i+2,widthx,a),yj(2*j+2,widthy,b));
        }
    }
   answer*=((widthx*widthy)/9);
    return answer;
}


double Task(double x){
    return (exp(x/2))/sqrt(x+1);
}
double TaskDoubleIN(double x,double y){
    return sin(x+y);
}
void printAnswer(double answer){
    cout<<"Answer = "<<answer<<endl;
}

