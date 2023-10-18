#include<stdio.h>
#include<string.h>
int main(){
	char a[100];
	printf("Enter the plain text : ");
	scanf("%s",a);
	int mat[2][2]={{3,2},{3,5}};
	char alpha[]="abcdefghijklmnopqrstuvwxyz";
	int plain[2][2];
int k=0;
	for(int i=0;i<2;i++){
		for(int j=0;j<2;j++){
			for(int l=0;l<strlen(alpha);l++){
				if(a[k]==alpha[l]){
					plain[j][i]=l;
					k++;				
					break;
				}
			}
		}
	}
	int e[2][2];
	for(int i=0;i<2;i++){
		for(int j=0;j<2;j++){
			e[i][j]=0;
			for(int k=0;k<2;k++){
				e[i][j]+=mat[i][k]*plain[k][j];
			}
		}
	}
	for(int i=0;i<2;i++){
		for(int j=0;j<2;j++){
			e[i][j]=e[i][j]%26;
			e[i][j]=alpha[e[i][j]];
		}
		printf("\n");
	}
	for(int i=0;i<2;i++){
		for(int j=0;j<2;j++){
			printf("%c ",e[i][j]);
			
		}
		printf("\n");
	}	
}

