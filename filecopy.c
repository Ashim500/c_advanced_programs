#include<stdio.h>
int main(){
    FILE *fp1,*fp2;
    char ch;
    fp1=fopen("filecopy.c","r");
    fp2=fopen("temp.text","w");
    
    if(fp1==NULL || fp2==NULL){
        printf("Error opening files\n");
        return 1;
    }
    
    while((ch = fgetc(fp1)) != EOF) {
        fputc(ch,fp2);
    }
    
    printf("file copied successfully\n");
    fclose(fp1);
    fclose(fp2);
    return 0;
}