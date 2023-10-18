#include<stdio.h>
#include<math.h>
int main(){
	int n,p,q,dn,e,d,m;
	printf("enter the value of P:");
	scanf("%d",&p);
	printf("enter the value of Q:");
	scanf("%d",&q);
	printf("enter the value of E:");
	scanf("%d",&e);
	printf("enter the value of M:");
	scanf("%d",&m);
	n=p*q;
	dn=(p-1)*(q-1);
	for(int i=1;i<dn;i++){
		if((e%dn)*(i%dn)%dn==1){
			d=i;
			break;
		}
	}
	int x=pow(m,e);
	int c=x%n;
	printf("encryption = %d",c);
	int de=pow(c,d);
	printf("\ndecryption = %d",de%n);
}