//Find the total area covered by two rectilinear rectangles in a 2D plane.
#include<iostream>
#include<stdint.h>
#include<vector>
#include<algorithm>
#include<cstdlib>
#include<map>
#include<set>
#include<string>
using namespace std;
int computeArea(int A, int B, int C, int D, int E, int F, int G, int H);
int main()
{
	int A = -1500000001;
	int B = 0;
	int C = -1500000000;
	int D = 1;
	int E = 1500000000;
	int F = 0;
	int G = 1500000001;
	int H = 1;
	int result = computeArea(A, B, C, D, E, F, G, H);
	cout << result << endl;
	system("pause");
	return 0;
}
int computeArea(int A, int B, int C, int D, int E, int F, int G, int H)
{
	int area1 = (C - A)*(D - B);
	int area2 = (G - E)*(H - F);
	int area3 = 0;
	long long int x1 = max(A, E);
	long long int y1 = max(B, F);
	long long int x2 = min(C, G);
	long long int y2 = min(D, H);
	long long int x = x2 - x1;
	long long int y = y2 - y1;
	if (x >= 0 && y >= 0)
	{
		area3 = x*y;
	}
	else
	{
		area3 = 0;
	}
	return area1 + area2 - area3;
}

