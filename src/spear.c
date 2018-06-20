#include <stdio.h>

int n;
int k;
int A[100000];

int p(int m){
  int q = 0;	/* quantity of makeable spears given their length is m */
  int i;
  for(i = 1; i <= n; i++){
  	q += A[i] / m;
  }
  return k <= q ? 0 : 1;	/* 0: achievable; 1: not achievable */
}

int main(){
  int i, lb, ub;
  int max = 0;
  scanf("%d%d", &n, &k);
  for(i = 1; i <= n; i++){ 
  /* data starting from index 1 to correspond to the question */
    scanf("%d", &A[i]);
    if(A[i] > max) max = A[i];
  }


  lb = 0;
  ub = max + 1;
  while(ub - lb > 1) {
    int m = (lb + ub) / 2;
    if(p(m)){
      ub = m;
    }
    else {
      lb = m;
    }
  }
  printf("%d\n", lb);	
  return 0;
}
