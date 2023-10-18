#include<stdio.h>
#include<ctype.h>
#include<string.h>
int main(){
	char plain[100];
	char key[10];
	printf("Enter the plain text : ");
	scanf("%[^\n]s",plain);
	printf("Enter the key value : ");
	scanf("%s",key);
	char alpha[]="abcdefghijklmnopqrstuvwxyz";
	int j=0;
	char ak[100];
	int i=0;
	while(i<strlen(plain)){
		ak[i]=key[j];
		j++;
		if(j==strlen(key)){
			j=0;
		}
		i++;
	}
printf("Encrypted value : ");
	for(int i=0;i<strlen(plain);i++){
		int sum=0;
		for(int k=0;k<26;k++){	
			if(plain[i]==alpha[k]){
				sum+=k;
			}
			if(ak[i]==alpha[k]){
				sum+=k;
		    }				
		} 
 


printf("%c",alpha[sum%26]);
	}
}
