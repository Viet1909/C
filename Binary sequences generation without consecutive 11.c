#include<stdio.h>
#include<string.h>
#include<math.h>
int a[100];
void printsolution(int n){
	for(int i=0;i<n;i++){
		printf("%d",a[i]);
	}
	printf("\n");
}
int check(int i,int n){
	if(n==0){
		return 1;
	}
	if(a[n-1]==1 && i==1){
		return 0;
	}
	return 1;
}
void Try(int n,int k){
	for(int i=0;i<=1;i++){
		if(check(i,n)){
			a[n]=i;
			if(n<k-1){
				Try(n+1,k);
			}
			else{
				printsolution(k);
			}
		}
	}
}
int main(){
	int k; scanf("%d",&k);
	Try(0,k);
}
