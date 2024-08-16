#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>
int mecung[1000][1000];
int row;// hang
int col;// cot
int idx[4]={0,0,-1,1};
int idy[4]={-1,1,0,0};
struct point{
	int hang; int cot; int step;
	struct point *next;
};
typedef struct point point;
point *makepoint(point *head,int hang,int cot, int buoc){
	point *newpoint=(point*)malloc(sizeof(point));
	newpoint->next=NULL; newpoint->hang=hang;
	newpoint->cot=cot; newpoint->step=buoc;
	return newpoint;
}
point *pushback(point *head,int hang,int cot,int buoc){// day ve cuoi
	if(head==NULL){
		return makepoint(head,hang,cot,buoc);
	}
	head->next=pushback(head->next,hang,cot,buoc);
	return head;
}
point *popfront(point *head){// xoa dau
	if(head==NULL){
		return NULL;
	}
	point *temp=head; head=head->next;
	free(temp); return head;
}
int check(int hang,int cot){
	if(mecung[hang][cot]==0 && hang>=0 && cot >=0 && hang <=row-1 && cot<=col-1){
		return 1;
	}
	return 0;
}
point *loang(point *head){
	mecung[head->hang][head->cot]=1;
	for(int i=0;i<4;i++){
		if(check(head->hang+idx[i],head->cot+idy[i])){
			head=pushback(head,head->hang+idx[i],head->cot+idy[i],head->step+1);
			mecung[head->hang+idx[i]][head->cot+idy[i]]=1;
		}
	}
	return head;
}
int check2(point *head){
	if(head->hang==0 || head->cot ==0 || head->hang ==row-1 || head->cot==col-1 ){
		return 1;
	}
	return 0;
}
int slove(point *head,int r0,int c0 ){
	head=pushback(head,r0,c0,0);
	while(head!=NULL){
		if(check2(head)){
			return head->step+1;
		}
		head=loang(head);
		head=popfront(head);
	}
	return -1;
}
int main(){
	int r0; int c0;
	point *head=NULL;
	scanf("%d%d%d%d",&row,&col,&r0,&c0);
	for(int i=0;i<row;i++){
		for(int j=0;j<col;j++){
			scanf("%d",&mecung[i][j]);
		}
	}
	printf("%d",slove(head,r0-1,c0-1));
}
