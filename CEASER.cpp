#include<stdio.h>  
#include<string.h>
int main(){
	char a[100];
int k;
	printf("Enter the string : ");
	scanf("%[^\n]s",a);
	printf("Enter the key value : ");
	scanf("%d",&k);
	char alpha[]="abcdefghijklmnopqrstuvwxyz";
	for(int i=0;i<strlen(a);i++){
		for(int j=0;j<strlen(alpha);j++){
			if(a[i]==alpha[j]){
				j=j+k;
				a[i]=alpha[j];
			}
			else if(a[i]==' '){
				continue;
			}
		}	
	}
	printf("Enter the Encryted value : %s\n",a);
	for(int i=0;i<strlen(a);i++){
		for(int j=0;j<strlen(alpha);j++){
			if(a[i]==alpha[j]){
				j=j-k;
				a[i]=alpha[j];
			}
			else if(a[i]==' '){
				continue;
			}
		}
	}
	printf("Enter the decrypted value : %s ",a);
}
