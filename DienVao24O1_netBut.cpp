// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;
int L[5][5];
static int kqFinal = 0;
int sum(int a[5][5]) {
	int x = 0,N=5;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			x += a[i][j];
		}
	}
	return x;
}

void print(int L[5][5]) {
	int N = 5;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << L[i][j] << " ";
		}
		cout << "\r\n";
	}
	cout << "\r\n "; 
}
int run(int a[5][5], int L[5][5], int i, int j) {
	// cout<<"in ";
	int ma[5][5];
	int mL[5][5];
	int N = 5;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			 ma[i][j] = a[i][j];
			 mL[i][j] = L[i][j];
		}
	}
	if (ma[i][j] == 0) return 0;
	int f = 0;
	if (i<0 || i>4) f = 1;
	if (j<0 || j>4) f = 1;
	if (f) return 0;
	if (ma[i][j] == 1) {
		mL[i][j] = 1;
		ma[i][j] = 0;
		//int v = sum(mL);
		//cout << "add: "<<i<<","<<j<<":"<< v <<endl;
		//print(mL);		
	}
	int x = sum(mL);
	if (x == 23) {
		x = 23;
		++kqFinal;
		//cout << "  Final: " << ++kqFinal << endl;
		//cout << "KQ:======================================" << endl << endl;
		//cin >> N;
		//exit(1);
	}
	if (x == 24) {
		for (int i1=0;i1<100;i1++)cout << "KQ:============================================================"<<endl;
		cout << "Dap an la:" << endl;
		print(mL);
		cin >> N;
		exit(1);
	}	
	run(ma, mL, i - 1, j);
	run(ma, mL, i + 1, j);
	run(ma, mL, i, j - 1);
	run(ma, mL, i, j + 1);	
	return 0;
}
int main()
{
	cout << "Bai toan co 25 o vuong, xoa o [0,1] di, yeu cau noi 24 o con lai bang 1 net but" << endl;
	int N = 5;
	int gfg[5][5];// = new Array(N); 

	cout << "Starting...\n";
	// Loop to initialize 2D array elements.
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			gfg[i][j] = 1;
		}
	}

	gfg[0][1] = 0;
	cout << "gfg:\n\r";
	print(gfg);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (i == 0) {
				if (j == 1) {
					continue;
				}
			}
			
			cout << "i,j:" << i << j << endl;
			run(gfg, L, i, j);
			
		}
	}
	
	//print(L);
	cout << "Khong co dap an. Final:" << kqFinal;
	cin >> N;
}

