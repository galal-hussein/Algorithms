



//============================================================================
// Name        : Divisibility.cpp
// Author      : 
// UVA	       : 294
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <set>
using namespace std;


void Divisors(long L, long U);

int main() {
	//freopen("/home/hussein/in.in","r",stdin);
	long L,U;
	int n;
	scanf("%d\n",&n);

	for(int i=0;i<n;i++){
			scanf("%ld%ld\n",&L,&U);
			Divisors(L,U);
				}
	return 0;
}
void Divisors(long L,long U){
long lower,upper;
long sq,q;
long max=0,K,num=0;
lower = L;upper=U;
if(L==0&&U==1){
	printf("Between %ld and %ld, 1 has a maximum of 1 divisors.\n",L,U);
	return;
}
if(L==0 && U!=0 && U!=1){
	lower=2;
}

for(int i=lower;i<=upper;i++){
	K=0;
	sq = sqrt((double)i);
	for(int j=1;j<=sq;j++){
		if(i%j==0){
			K++;
			q=i/j;
			if(q>sq)
				K++;
			//printf("%ld,%ld\n",j,q);
		}
	}
	if(K>max){
			max = K;
			num = i;
		}
}
printf("Between %ld and %ld, %ld has a maximum of %ld divisors.\n",L,U,num,max);
return;


}

