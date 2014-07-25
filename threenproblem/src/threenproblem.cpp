//============================================================================
// Name        : threen+3problem.cpp
// UVA	       : 100
//============================================================================

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;

long long max3n(long long low, long long high);

int main() {
	int i , j;
	while (scanf("%d %d", &i, &j) != EOF) {
	cout << i << " " << j << " " << max3n(i, j) << endl;
	}
	return 0;
}
long long max3n(long long low, long long high) {

	long long max = 0;
	long long maxtemp = 0;
	long long m;
    long long i,temp;
    if(low>high){
    	temp = high;
    	high = low;
    	low = temp;
    }
	for (i = low; i <= high; i++) {
		m = i;
		while (m > 1) {
			if (m % 2 == 0) {
				m = m / 2;
				maxtemp++;
			} else {
				m = 3 * m + 1;
				m /= 2;
				maxtemp += 2;
			}
		}
		maxtemp+=1;
		if (maxtemp > max)
			max = maxtemp;
		maxtemp = 0;
	}

	return max;
}
