#include<stdio.h>
#include<string.h>
int main(){
	char str[100];
	printf("enter the plain text:");
	scanf("%[^\n]s",str);
	char s[100];
	int count=0;
	for(int i=0;i<strlen(str);i++){
		if(i%2==0){
			s[count]=str[i];
			count++;
		}
	}
	for (int i=0;i<strlen(str);i++){
		if(i%2!=0){
			s[count]=str[i];
			count++;
		}
	}
	printf("%s",s);
}