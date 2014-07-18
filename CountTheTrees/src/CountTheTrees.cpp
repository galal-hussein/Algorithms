//============================================================================
// Name        : CountTheTrees.cpp
// UVA	       : 10007
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <algorithm>
#include <set>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <stack>

using namespace std;
char N[10000];
char tempadd[1000];
char tempmul[1000];
char multot [1][2][1000];

bool addtn(char*, char*);
bool multn(char*, char*);
void countTheTrees(void);

int main() {
	//freopen("/home/hussein/in.in","r",stdin);
	countTheTrees();
	return 0;
}

void countTheTrees(void){
	char nplus2[1000];
	char nmul2[1000];
	char ntemp[1000];
	char sum[1000];
	scanf("%s\n",&N);
	while(strcmp(N,"0")){

			addtn("2",N);
			strcpy(nplus2, tempadd);
			multn("2",N);
			strcpy(nmul2, tempmul);
			//printf("%s %s\n", nplus2, nmul2);
			strcpy(ntemp,nplus2);
			strcpy(sum,nplus2);
			while(1){
				if(!strcmp(N,"1")){strcpy(sum,"1");break;}
				if(!strcmp(N,"2")){strcpy(sum,"4");break;}
				addtn(ntemp,"1");
				strcpy(ntemp,tempadd);
				multn(sum,ntemp);
				strcpy(sum,tempmul);
				if(!strcmp(ntemp,nmul2))break;

			}
			printf("%s\n", sum);
			scanf("%s\n",&N);
		}
}
bool multn(char* f, char* s){
	int flen, slen, smlen, bglen, i, j=-1, k, l;
	stack<char> mulstack;
	char sm[1000];
	char bg[1000];
	int smdump,bgdump,ac,carry=0;
	flen = strlen(f);
	slen = strlen(s);
	//to check for the biggest number
	if(flen<slen){
		strcpy(sm,f);
		strcpy(bg,s);
		smlen = flen;
		bglen = slen;
	}
	else{
		strcpy(sm,s);
		strcpy(bg,f);
		smlen = slen;
		bglen = flen;
	}
	//printf("\n");
	for(i=smlen-1;i>=0;i--){
		carry=0;
		j++;
		smdump = sm[i]-'0';
		//printf("%d\t",smdump);
		l=j;
		while(l--)mulstack.push('0');
		for(l=bglen-1;l>=0;l--){
			bgdump = bg[l]-'0';

			ac = ((smdump*bgdump)+carry)%10;
			carry = ((smdump*bgdump)+carry)/10;
			mulstack.push(ac + '0');
			//printf("[%d-%d-%d]",bgdump,ac,carry);
		}
		//printf("\t");
		if(carry)mulstack.push(carry + '0');
		k=0;
		while (!mulstack.empty())
		{
			tempmul[k] = mulstack.top();
			//printf("%c",mulstack.top());
			mulstack.pop();
			k++;
	    }
		tempmul[k]= '\0';
		if(!j){
			strcpy(multot[0][0],tempmul);
			//printf("(%s)\n",multot[0][0]);
		}
		else{
			//printf("(%s) ",multot[0][0]);
			strcpy(multot[0][1],tempmul);
			//printf("[%s]\n",multot[0][1]);
			addtn(multot[0][0],multot[0][1]);
			strcpy(multot[0][0],tempadd);
			//printf("%s\n%s\n",multot[0][0],multot[0][1]);
		}


	}
	//printf("(%s) ",multot[0][0]);
	strcpy(tempmul,multot[0][0]);
	return true;
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
		if(addstack.size() >=1000){
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


	if(addstack.size() >= 1000){
		return false;
	}
	}
	if(carry==1)addstack.push('1');

	//printf("size is %d\n",(int)addstack.size());
	int k=0;
	while (!addstack.empty())
	  {
		tempadd[k] = addstack.top();
		//printf("%c",addstack.top());
	    addstack.pop();
	     k++;
	  }
	  tempadd[k]= '\0';

	//printf("\n");
	return true;

}
