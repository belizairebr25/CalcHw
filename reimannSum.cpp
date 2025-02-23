#include <iostream>
#include <stdio.h>
#include <vector>
#include <cmath>
#include <functional>

using namespace std;

//user input vars
double upperLimit = 0;
int func;
double lowerLimit = 0;
double step = 0;
double protostep = 0;
int rectNumb;
vector<double> yvalues;
vector<double> midYvalues;
vector<double> xvalues;
double areaR = 0;
double areaM = 0;
double areaL = 0;

//function from problem 8 in the hw
void funcA(){
  yvalues.clear();
  yvalues.resize(rectNumb);

  for (int i =0; i < rectNumb; i++) {
    double x = lowerLimit + i * step;
    if (x == 0) {
      cerr << "Divide zero 3:\n; Function not differentiable within selected domain";
      yvalues[i] = 0;

    }else{
      yvalues[i] = 1.0 / (x * x);
    }
  }
}

//function from problem 9a in the hw
void funcB(){
  yvalues.clear();
  yvalues.resize(rectNumb);

  for (int i = 0; i < rectNumb; i++){
    double x = lowerLimit + i * step;
    if (x >= 0){
      yvalues[i] = sqrt(x);
    } else {
      cerr << "Invalid Domain for funciton";
    }
  }
}

void funcC(){
  xvalues.clear();
  xvalues.resize(rectNumb);
  yvalues.clear();
  yvalues.resize(rectNumb);
  for(int i = 0; i < rectNumb + 1; i++){
    cout << "input x value: \n";
    cin >> xvalues[i];

    cout << "input y value: \n";
    cin >> yvalues[i];
  } 
  
}

void area(){
  midYvalues.clear();
  midYvalues.resize(rectNumb);
  //left rectangles
  for(int i = 0; i < rectNumb; i++){
    areaL += yvalues[i] * step;
  }

  //right rectangles
  for(int i =0; i < rectNumb; i++){
    areaR += yvalues[i + 1] * step;
  }
  //middle rectangles
  for(int i = 0; i < rectNumb; i++){
    midYvalues[i] = (yvalues[i] + yvalues[i + 1]) / 2;
    areaM += midYvalues[i] * step;
  }
}

int main() {

  //get user inputs
  cout << "Select a Function? \n 1). 1/(x^2)\n 2). x^(1/2) \n 3). Input x and y values \n ";
  cin >> func;
  cout << "Upper Limit: \n";
  cin >> upperLimit;
  cout << "Lower Limit: \n";
  cin >> lowerLimit;
  cout << "Number of rectangles: \n";
  cin >> rectNumb;

  //calculate interval length
  protostep = upperLimit - lowerLimit;
  step = protostep / rectNumb;

  //call Y value calculator
  if(func == 1){
    funcA();
  } else if(func == 2){
    funcB();
  } else if(func == 3){
    funcC();
  }
  

  //output Y values for verification
  for (int i = 0; i < rectNumb; i++) {
    cout << "y[" << i << "]" << yvalues [i] << "\n";
  }

  //calculate Area
  
  area();

  //output
  cout << "The area under the curve using " << rectNumb << " Rectangles is: " << "\n L: "<< areaL << "\n R: " << areaR << "\n M: " << areaM << "\n";
  return 0;
}
