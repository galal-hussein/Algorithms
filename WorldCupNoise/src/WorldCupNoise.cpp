//============================================================================
// Name 	   : WorldCupNoise.cpp
// Author      : Hussein Galal
// UVa BI      : 10450
//============================================================================

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <stack>
#include <string>
#include <cmath>
long long fibonacci(int n);
using namespace std;
long long fib[70];
long long fibonacci(int n){
	long long i,j,h,k,t;
	 i = h = 1;
	 j = k = 0;
	while (n > 0) {
	if (n%2 == 1) { // if n is odd
	t = j*h;
	j = i*h + j*k + t;
	i = i*k + t;
	}
	t = h*h;
	h = 2*k*h + t;
	k = k*k + t;
	n = (int) n/2;
	} return j;}

int main() {
//freopen("/home/hussein/in.in","r+",stdin);
int i,tc;
int n,temp;
fib[1] = 2;
fib[2] = 3;
for(i=3;i<70;i++){
	temp = i+2;
	fib[i] = fibonacci(temp);
}
i=1;
scanf("%d\n",&tc);
while(tc--){
	scanf("%d\n",&n);
	printf("Scenario #%d:\n%lld\n\n",i,fib[n]);
	i++;
}
}
