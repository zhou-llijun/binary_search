#include <stdio.h>

int n;
int k;
int A[100000];

int p(int m){
  int block = 0, nblock = 1;	/* nblock: number of blocks of work given capacity m */
  int i;
  for(i = 0; i < n; i++){
  	if(block + A[i] <= m){
  	  block += A[i];
	}
	else{
	  ++nblock;
	  block = 0;
	  block += A[i];
	} 
  }
  return k >= nblock;	/* 0: not achievable; 1: achievable */
}

int main(){
  int i, lb, ub;
  int max = 0, sum = 0;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){ 
    scanf("%d", &A[i]);
    if(A[i] > max) max = A[i];
    sum += A[i];
  }


  lb = max - 1;
  ub = sum;
  while(ub - lb > 1) {
    int m = (lb + ub) / 2;
    if(p(m)){
      ub = m;
    }
    else {
      lb = m;
    }
  }
  printf("%d\n", ub);
  return 0;
}
