#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[]) {
    int width=0;
	printf("Podaj szerokosc: ");
	scanf("%d",&width);
	FILE*F;
	F=fopen("inwokacja.txt","r");
	if (F==NULL) printf("Blad pliku!");
	char character,text[200];
	int wordCount=0,firstWord=0;
	int length=0;
		while(!feof(F)){
		character=getc(F);

		int repeats=0;

            while(character!=' ' && character!='\n'&& !feof(F)){
                text[repeats]=character;
                repeats++;
                character=getc(F);
                }
                firstWord++;
            if((length+repeats+1)>width){
                printf("\n");
                length=0;
                }
            else if (firstWord!=1){
                printf(" ");
                length++;
                }
            int i;

            for(i=0; i<repeats; i++){
                printf("%c",text[i]);

                }
            length =length+repeats;
            wordCount++;



        }
        printf("\n");
        fflush(stdin);
        getchar();
            fclose(F);
		return 0;
}

