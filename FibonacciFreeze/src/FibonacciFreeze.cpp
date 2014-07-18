//============================================================================
// Name        : FibonacciFreeze.cpp
// Author      : Hussein Galal
// ACM BI      : 495,10579
// Description : Fibonacci Freeze in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <stack>
#include <string>
#include <cmath>

using namespace std;

char fab[1][5001][10001];
char temp[10001];

void createFab();
int main() {
	int in;
	createFab();
	//freopen("/home/hussein/in.in","r+",stdin);
	//freopen("/home/hussein/Programming/a.out","wa+",stdout);
	while(scanf("%d\n",&in)!=EOF){
		printf("%s\n",fab[0][in]);
	}

	return 0;
}
bool addtn(char* n, char *m){
	stack<char> addstack;
	int ac, carry=0,i,maxptr;
	int dumpN,dumpM;
	int min,f=0;
	if (strlen(m) < strlen(n))
		{min=strlen(m);maxptr=strlen(n)-1;f=1;
		}
	else
		{min=strlen(n);maxptr=strlen(m)-1;}


	for (i=min-1;i>=0;i--){

		if(f){
		dumpN = n[maxptr] - '0' + carry;
		dumpM = m[i] - '0';
		//printf("%d %d\n",dumpN,dumpM);
		}
		else{

			dumpN = n[i] - '0' + carry;
			dumpM = m[maxptr] - '0';


		}
		ac = (dumpN + dumpM)%10;
		carry = (dumpN + dumpM)/10;
		addstack.push(ac + '0');
		maxptr--;
		if(addstack.size() >100000){
			return false;
		}
	}

	for(int j=maxptr;j>=0;j--){

		if(f){
			dumpN=n[j] - '0' + carry;
			if(dumpN==10){dumpN=0;carry=1;}
			else carry=0;
			addstack.push(dumpN + '0');
			//printf("((%c))\n",addstack.top());
		}else{
			dumpM=m[j] - '0' + carry;
			if(dumpM==10){dumpM=0;carry=1;}
			else carry=0;
			addstack.push(dumpM + '0');
		}



	}
	if(carry==1)addstack.push('1');

	//printf("size is %d\n",(int)addstack.size());
	int k=0;
	while (!addstack.empty())
	  {
		temp[k] = addstack.top();
		//printf("%c",addstack.top());
	    addstack.pop();
	     k++;
	  }

	//printf("\n");
	return true;

}
void createFab(){
	int i;
	strcpy(fab[0][0],"0");
	strcpy(fab[0][1],"1");
	for(i=2;i<=5000;i++){
		addtn(fab[0][i-1],fab[0][i-2]);
		strcpy(fab[0][i],temp);
	}
}
