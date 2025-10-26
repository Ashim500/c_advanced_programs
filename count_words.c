#include<stdio.h>
#include<stdbool.h>
#include<ctype.h>

int main(){
	char filename[100];
	printf("File:");
	scanf("%s",filename);
	FILE*file = fopen(filename,"r");
	
	if(file==NULL){
		printf("Error opening file");
		return 1;
	}
	int c;
	int characters=0;
	int words=0;
	bool whitespace=true;
	
	while(true)
	{
		c=fgetc(file);
		
		if(feof(file))break;
		else if(ferror(file))
		{
			printf("Error reading file.\n");
			return 1;
		}
		
		characters++;
		if(whitespace && !isspace(c))

{
	words++;
	whitespace=false;
		}		
		else if(!whitespace && isspace(c))
		{
			whitespace=true;
		}
	}
	fclose(file);
	printf("Analysis:\n");
	printf("Characters:%d\n",characters);
	printf("Words:%d\n",words);
	return 0;
}