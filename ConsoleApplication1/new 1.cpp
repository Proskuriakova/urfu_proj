#include <iostream>
#include <cmath>
#include <fstream>
#include "stdafx.h"

using namespace std;


double D;
double X[n];
double Y[n];
double K1[n];
double K2[n];
double K3[n];
double K4[n];
double L1[n];
double L2[n];
double L3[n];
double L4[n];

double F(double x, double y){
	return y;
}

double G(double x, double y){
	return (D*(1-pow(x,2))*y)-x;
}



int main{
	double h = 0.01;
	int n = 1000;
	X[0] = 2;
	Y[0] = 2;
	D = 1;



	for (int i = 0; i < n; i++){

		K1[i] = h*F(X[i], Y[i]);
		L1[i] = h*G(X[i], Y[i]);
		K2[i] = h*F(X[i] + K1[i] / 2.0, Y[i] + L1[i] / 2.0);
		L2[i] = h*G(X[i] + K1[i] / 2.0, Y[i] + L1[i] / 2.0);
		K3[i] = h*F(X[i] + K2[i] / 2.0, Y[i] + L2[i] / 2.0);
		L3[i] = h*G(X[i] + K2[i] / 2.0, Y[i] + L2[i] / 2.0);
		K4[i] = h*F(X[i] + K3[i], Y[i] + L3[i]);
		L4[i] = h*G(X[i] + K3[i], Y[i] + L3[i]);

		X[i + 1] = X[i] + (K1[i] + 2 * K2[i] + 2 * K3[i] + K4[i]) / 6;
		Y[i + 1] = Y[i] + (L1[i] + 2 * L2[i] + 2 * L3[i] + L4[i]) / 6;
	}




	for (int i = 0; i <= n; i++){
		cout << 'X[' << i << ']=' << X[i] << ' ';
	}
	return 0;
}