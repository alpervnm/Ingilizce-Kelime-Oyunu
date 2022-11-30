#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include<locale.h>


struct a{
	char cevap[20];
	struct a* next;
};
typedef struct a node;
node *answers,*p,*yan,*k;
int main(){
	setlocale(LC_ALL,"Turkish");
	k=yan;
	int i=0,j=0,kelimesirasi[20],kontrol,kontrol2,puan=0,y=0,d=0;
	char trword[40][15],ingword[40][15],soruword[40];
	
	FILE* dosya=fopen("ingwords.txt","r");
	if(dosya==NULL){
		printf("Dosyaa yokkk ");
		getch();
	}
	else{
		printf("\n**********************************************************************************************************************\n");
		printf("BA�LAMADAN �NCE!\n\n1)L�tfen sorulan kelimelerin cevaplar�n� yazarken t�rk�e karakter kullanmay�n!   (�>c , �>g , �>i , �>s , �>u , �>o)");
		printf("\n2)Sorulan kelimenin kar��l��� iki kelimeden olu�uyorsa birle�ik yaz�n�z.");
		printf("\n\n**********************************************************************************************************************\n");
		printf("\nSorulacak kelime ve cevaplar�n� g�rmek i�in 1'e bas�n");
		scanf("%d",&kontrol);
		while(kontrol!=1){
		printf("\nHatal� tu�lama yapt�n�z, devam etmek i�in 1'e bas�n!");
		scanf("%d",&kontrol);
		}
		system("CLS");
		while(!feof(dosya)){
			fscanf(dosya,"%d %s %s",&kelimesirasi[i],&trword[i],&ingword[i]);
			printf("%d %s %s\n",kelimesirasi[i],trword[i],ingword[i]);
			i++;
		}
	}
		printf("\n\n\n\nYar��maya ba�lamak i�in 2'ye bas�n");
		scanf("%d",&kontrol2);
		
		while(kontrol2!=2){
		printf("\nHatal� tu�lama yapt�n�z, yar��maya ba�lamak i�in 2'ye bas�n!");
		scanf("%d",&kontrol2);
		}
		system("CLS");
		
	
			i=0;
			while(i!=10){
				fscanf(dosya,"%d %s",&kelimesirasi[i],&trword[i]);
				printf("\n'%s' kelimesinin t�rk�esi nedir?",trword[i]);
				scanf("%s",soruword);
				if(strcmp(soruword,ingword[i])==0){
					puan++;
					printf("\n\nTebrikler %d. kelimeyi do�ru bildiniz! (puan�n�z: %d)",i+1,puan);	
					d++;				
					printf("\n\n\nDevam etmek i�in 'Enter' a bas�n.");
					getch();
					system("CLS");	
				}
				
				else{
					puan--;
					printf("\n\nMaalesef %d. soruya yanl�� cevap verdiniz do�rusu '%s' olmal�yd�. (puan�n�z: %d)",i+1,ingword[i],puan);
					printf("\n\n\nDevam etmek i�in 'Enter' a bas�n.");
						if(yan->cevap==NULL){
							yan=(node*)malloc(sizeof(node));
							strcpy(yan->cevap,trword[i]);
							k=yan;	
						}
						else{
							yan->next=(node*)malloc(sizeof(node));
							strcpy(yan->next->cevap,trword[i]);
							yan=yan->next;						
						}
					y++;
					getch();
					system("CLS");
				}
						if(answers->cevap==NULL){
						answers=(node*)malloc(sizeof(node));
						strcpy(answers->cevap,soruword);
						p=answers;
						
						
						}
						else{
						answers->next=(node*)malloc(sizeof(node));
						strcpy(answers->next->cevap,soruword);
						answers=answers->next;						
						}
					i++;
			}
			system("CLS");
			printf("\n\n*******************************************************************************\n\n\n\n");
			printf("\t\t\t\tYARI�MA B�TT� PUAN: %d",puan);
			printf("\n\n\t\t\t\tDo�ru say�s�:  %d\n\t\t\t\tYanl�� say�s�: %d",d,y);
			printf("\n\n\n\n*******************************************************************************\n\n\n");
			
			dosya=fopen("ingwords.txt","r");
			if(dosya==NULL){
				printf("Dosyaa yokkk ");
				getch();
	}
				answers=p;
			printf("\n\n%-20s%-40s%-60s", "SORULAR", "CEVAPLAR", "S�Z�N CEVAPLARINIZ\n");
			
				while(!feof(dosya)){
					
				fscanf(dosya,"%d %s %s",&kelimesirasi[i],&trword[i],&ingword[i]);
				if(kelimesirasi[i]>=10)
				printf("\n%d %-17s%-40s%-44s",kelimesirasi[i],trword[i],ingword[i],answers->cevap);
				else
				printf("\n%d  %-17s%-40s%-44s",kelimesirasi[i],trword[i],ingword[i],answers->cevap);
				answers=answers->next;
				
				i++;
				}
				yan=k;
				i=0;
				printf("\n\n******************************************************************************\n");
				printf("\n\nYANLI� B�L�NENLER\n");
				while(yan->cevap!=NULL){
					printf("\n%d %s",i+1,yan->cevap);
					yan=yan->next;
					i++;
				}
			getch();
}
