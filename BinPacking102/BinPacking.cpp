//============================================================================
// Name        : BinPacking.cpp
// UVA	       : 102
//============================================================================

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#define BCG 0;
#define BGC 1;
#define CBG 2;
#define CGB 3;
#define GBC 4;
#define GCB 5;
using namespace std;

int wbottles[6];

void calcWeights(int* in){
	int i;
	int min;
	int index;
	wbottles[0] = in[3]+in[6]+in[2]+in[8]+in[1]+in[4];//BCG
	 wbottles[1] = in[3]+in[6]+in[2]+in[5]+in[1]+in[7];//BCG
	 wbottles[2] = in[5]+in[8]+in[0]+in[6]+in[1]+in[4];//CBG
	 wbottles[3] = in[5]+in[8]+in[1]+in[7]+in[0]+in[3];//CGB
	 wbottles[4] = in[4]+in[7]+in[0]+in[6]+in[2]+in[5];//GBC
	 wbottles[5] = in[4]+in[7]+in[2]+in[8]+in[0]+in[3];//GCB
	 min = wbottles[0];
	 index=0;
	 for(i=1;i<6;i++){
		 if(wbottles[i] < min)
		 {
			 min = wbottles[i];
			 index = i;
		 }
	 }
	 switch(index){
	 case 0:
		 cout<<"BCG "<<min<<endl;
		 break;
	 case 1:
		 cout<<"BGC "<<min<<endl;
		 break;
	 case 2:
		 cout<<"CBG "<<min<<endl;
		 break;
	 case 3:
		 cout<<"CGB "<<min<<endl;
		 break;
	 case 4:
		 cout<<"GBC "<<min<<endl;
		 break;
	 case 5:
		 cout<<"GCB "<<min<<endl;
		 break;
	 default :
		 break;
	 }

}

int main() {
	int in[9];
	while ( scanf ("%d", &in [0]) != EOF ) {

	        for ( int i = 1; i < 9; i++ )
	            scanf ("%d", &in [i]);
	calcWeights(in);
	}
	return 0;
}
