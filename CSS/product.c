#include<stdio.h>
#include<string.h>
int main(){
	char text[50],enc[50];
	int i,rem,key,c=0;
	printf("Enter the text : ");
	scanf("%s",text);
	printf("Enter the key : ");
	scanf("%d",&key);
	for(i=0;i<strlen(text);i++){
		
		if(text[i]>='A' && text[i]<='Z')	 //checking whether alphabet is in upper case
			{
			rem=((text[i]+key)-65) % 26;
			enc[i] = 65+rem;
		}
		else{
		if(text[i]>='a' && text[i]<='z'){		//checking whether alphabet is in l case
			rem=((text[i]+key)-97) % 26;
			enc[i] = 97+rem;
		}
	}
	c++;
		}	
	printf("Cipher text : %s\n",enc);			//printing the cipher text
	int x,k=0;
	if((c%key)!=0)
		x=(c/key)+1;			//calculating the no. of rows 
	else
		x=c/key;
	char na[x][key];
	for(i=1;i<=x;i++){
		for(int j=1;j<=key;j++){
			if(enc[k]!='\0'){
				na[i][j]=enc[k];
				k++;
				}
			else{
				na[i][j]='X';}
			}}
			printf("Matrix :\n");
	for(i=1;i<=x;i++){				//printing the matrix
		for(int j=1;j<=key;j++){
			printf("%c",na[i][j]);
			}
			printf("\n");
			}
			printf("Transposition cipher: ");		
	for(i=1;i<=key;i++){			//calculating transpose
		for(int j=1;j<=x;j++){
			printf("%c",na[j][i]);
			}}
	return 0;
}
