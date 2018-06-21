#include <stdio.h>

int n;
int k;
int A[100000];

int p(int m){
  int q = 0;	/* necessary quantity of bags given the size of bags is m */
  int i;
  for(i = 0; i < n; i++){
  	q += A[i] / m;
	if(A[i] % m != 0) ++q; 
  }
  return k >= q;		/* 0: cannot bring back; 1: can bring back */
}

int main(){
  int i, lb, ub;
  int max = 0;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){ 
    scanf("%d", &A[i]);
    if(A[i] > max) max = A[i];
  }


  lb = 0;
  ub = max;
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
