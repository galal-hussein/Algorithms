//============================================================================
// Name        : PascalTriangleOfDeath.cpp
// Author      : Hussein Galal
// ACM NO      : 485
// Description : PascalTriangleOfDeath in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cmath>
#include <stack>

using namespace std;
char tr[2][1000][62];
char temp[62];


void buildPascalTree();
bool addtn(char n[],char m[]);

void buildPascalTree(){
	int j=1,f=1,k;
	printf("1\n");
	printf("1 1\n");
	strcpy(tr[0][0],"1");
	strcpy(tr[0][1],"2");
	strcpy(tr[0][2],"1");
	strcpy(tr[0][3],"s");
	printf("%s %s %s\n",tr[0][0],tr[0][1],tr[0][2]);

	while(1){
		//printf("(%s)",tr[0][j]);
		if(!strcmp(tr[0][j],"s")){
			j=1;
			strcpy(tr[0][0],"1");
			printf("%s ",tr[0][0]);
			for(k=1;strcmp(tr[0][k],"s");k++){
				strcpy(tr[0][k],tr[1][k]);
				printf("%s ",tr[0][k]);
			}
			strcpy(tr[0][k],"1");
			strcpy(tr[0][k+1],"s");
			printf("%s\n",tr[0][k]);

		}
		else{
			//printf("(%s,%s)",tr[0][j],tr[0][j-1]);

		f=addtn(tr[0][j],tr[0][j-1]);
		//printf("(%s)",temp);
		if(!f)break;
		strcpy(tr[1][j],temp);
		j++;
		unsigned long long len = strlen(temp);
		while(--len){
				temp[len] = '\0';
				}
		}

	}
}
int main() {
	//freopen("/home/hussein/Programming/a.out","wa+",stdout);
	buildPascalTree();
	/*char a[] = "5";
	char b[] = "10";
	addtn(a,b);
	printf("%s\n", temp);*/
	fclose(stdout);
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
		if(addstack.size() >61){
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


	if(addstack.size() >= 61){
		return false;
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
