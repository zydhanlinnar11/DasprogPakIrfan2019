#include <stdio.h>
#include <time.h>

int iterativeResults(int n, int *sum);
int recursiveResults(int n);
int recursiveSum(int n);

int main() {
	int n;
	int s;
	scanf("%d", &n);
	clock_t begin, end;
	double recursiveTime, iterativeTime;
	
	begin = clock();
	// Recursive begin
	s = 0;
	printf("Recursive method:\n");
	printf("%d%s Fibbonaci = %d\n", n,(n>=11 && n<=20) ? "th" : ((n%10==1) ? "st" : ((n%10==2) ? "nd" : ((n%10==3) ? "rd" : "th"))), recursiveResults(n));
	s = recursiveSum(n);
	printf("Sum of Fibonacci until %d%s term = %d\n",n,(n>=11 && n<=20) ? "th" : ((n%10==1) ? "st" : ((n%10==2) ? "nd" : ((n%10==3) ? "rd" : "th"))),s);
	// Recursive end
	end = clock();
	recursiveTime = ((double)end - (double)begin)/CLOCKS_PER_SEC;
	
	printf("\n");
	
	begin = clock();
	// Iterative begin
	s = 0;
	printf("Iterative method:\n");
	printf("%d%s Fibbonaci = %d\n", n,(n>=11 && n<=20) ? "th" : ((n%10==1) ? "st" : ((n%10==2) ? "nd" : ((n%10==3) ? "rd" : "th"))), iterativeResults(n, &s));
	printf("Sum of Fibonacci until %d%s term = %d\n",n,(n>=11 && n<=20) ? "th" : ((n%10==1) ? "st" : ((n%10==2) ? "nd" : ((n%10==3) ? "rd" : "th"))),s);
	// Iterative end
	end = clock();
	iterativeTime = ((double)end - (double)begin)/CLOCKS_PER_SEC;
	
	printf("Recursive time: %llf, Iterative time: %llf\n", recursiveTime, iterativeTime);
	printf("%s\n", (iterativeTime<recursiveTime) ? "Iterative method faster than recursive": (recursiveTime!=iterativeTime)?"Recursive method is faster than iterative":"Both have same speed");
		
	return 0;
}

int recursiveResults(int n) {
	if(n==0) {
		return 0;
	} else if (n==1){
		return 1;
	} else {
		return recursiveResults(n-1) + recursiveResults(n-2);
	}
}

int recursiveSum(int n) {
    if (n == 0) {
        return 0;
	} else if (n == 1) {
        return 1;
	} else {
		return recursiveSum(n-1) + recursiveSum(n-2) + 1;
	}
}

int iterativeResults(int n, int *sum) {
	int i;
	int u1;
	int u2=0;
	int un=1;
	*sum=1;
	if(n==0) {
		*sum=0;
		return 0;
	}
	for (i=1; i<n; i++) {
		u1=u2;
		u2=un;
		un= u1+u2;
		*sum+=un;
	}
	return un;
}
