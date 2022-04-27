#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>


struct FilmBilgileri
{
	char *FilmAdi;
	char *YayinlanmaYili;
	char *Yonetmeni;
	char *Senaristi;
	char *BasrolOyuncusu;
};


int main()
{
	typedef FilmBilgileri xyz;
	int secim;
	while(1)
	{
		menu:
			system("cls");
		printf("\n* * * * * * MENU * * * * * *\n");
		printf("\n1. Film ekleyin\n");
		printf("2. Filmleri listele(yayinlanma yilina gore)\n");
		printf("3. Film guncelleyin\n");
		printf("4. Film silin\n");
		printf("5. Film ara(film adi, yayinlanma yili, yonetmeni, senaristi, bas rol oyuncusuna gore)\n");
		printf("0. Cikis\n");
		printf("\nLutfen seciminizi giriniz: ");
		scanf("%d", &secim);
		
		if(secim==1)
		{
			printf("\n---------------------- FILM EKLEME ------------------------------\n");
			
			
			
			xyz okunan;
			okunan.FilmAdi=(char*)malloc(sizeof(char)*100);
			printf("\nFilm adi: ");
			scanf("%s",okunan.FilmAdi);
			okunan.YayinlanmaYili=(char*)malloc(sizeof(char)*100);
			printf("Yayinlanma yilini giriniz: ");
			scanf("%s",okunan.YayinlanmaYili);
			okunan.Yonetmeni=(char*)malloc(sizeof(char)*100);
			printf("Filmin yonetmenini giriniz: ");
			scanf("%s",okunan.Yonetmeni);
			okunan.Senaristi=(char*)malloc(sizeof(char)*100);
			printf("Filmin senaristini giriniz: ");
			scanf("%s",okunan.Senaristi);
			okunan.BasrolOyuncusu=(char*)malloc(sizeof(char)*100);
			printf("Filmin basrol oyuncusunu giriniz: ");
			scanf("%s",okunan.BasrolOyuncusu);
			FILE *dosya=fopen("Film.txt","a");
			fprintf(dosya,"%s %s %s %s %s\n",okunan.FilmAdi,okunan.YayinlanmaYili,okunan.Yonetmeni,okunan.Senaristi,okunan.BasrolOyuncusu);
			fclose(dosya);
			
				printf("\nFilm basariyla eklendi ! Ana menuye donmek icin herhangi bir tusa basiniz.");
				
			goto menu;
		}
		if(secim==2)
		{
			printf("\n	***************************** Film Listesi ************************ \n");
			printf("Film Adi \t Yayinlanma Yili \t Yonetmeni \t Senaristi\tBasrol oyuncusu \n");
			
		FILE *dosya=fopen("Film.txt","r"); 	
		char a[20],b[20],c[20],d[20],e[20];
		
		while(!feof(dosya))
        { 
		
        fscanf(dosya,"%s %s %s %s %s\n",&a,&b,&c,&d,&e); 
        printf("%s\t          %s\t		 %s\t	 %s\t		 %s\n",a,b,c,d,e);
		}
			
		fclose(dosya);
		printf("\nTum filmler listelendi ! Ana menuye donmak icin herhangi bir tusa basin..");
		getch();	
		goto menu;
	
		
		
		
		}
		if(secim==3)
		{
			FILE *dosya=fopen("Film.txt","r");
			xyz okunan;
			okunan.FilmAdi=(char*)malloc(sizeof(char)*100);
			okunan.YayinlanmaYili=(char*)malloc(sizeof(char)*100);
			okunan.Yonetmeni=(char*)malloc(sizeof(char)*100);
			okunan.Senaristi=(char*)malloc(sizeof(char)*100);
			okunan.BasrolOyuncusu=(char*)malloc(sizeof(char)*100);
			
			
			printf("\nGuncelleyeceginiz filmin adini giriniz: ");
			char aranan[30];
			scanf("%s",aranan);
		
			printf("\nFilm Adi \t Yayinlanma Yili \t Yonetmeni \t Senaristi\tBasrol oyuncusu \n");
			
			while(!feof(dosya))
			{
				fscanf(dosya,"%s %s %s %s %s\n",okunan.FilmAdi,okunan.YayinlanmaYili,okunan.Yonetmeni,okunan.Senaristi,okunan.BasrolOyuncusu);
				
				if(strcmp(okunan.FilmAdi,aranan)==0)
				{
					printf("\n%s \t \t %s \t\t\t %s \t %s \t\t %s \t\t \n",okunan.FilmAdi,okunan.YayinlanmaYili,okunan.Yonetmeni,okunan.Senaristi,okunan.BasrolOyuncusu);
				}
			}
			fclose(dosya);
						
						
						
						
						
						
						
						
			
		FILE *dosya2;
		 dosya=fopen("Film.txt","r");
		 dosya2=fopen("Film2.txt","w");
		int sec;
		printf("\n1. Film adi \n");
		printf("2.Film yayinlanma yili \n");
		printf("3.Film yonetmeni \n");
		printf("4.Film senaristi \n");
		printf("5.Film basrol oyuncusu \n");
		printf("\nFilmin hangi bilgisini guncellemek istiyorsunuz: ");
		
		scanf("%d",&sec);
		char a[20],b[20],c[20],d[20],e[20];
		switch(sec)
		{
		
		case 1:
			{
				char ad[20];
				char yeniad[20];
				printf("Guncelleyeceginiz filmin adini giriniz: ");
				scanf("%s",ad);
				printf("Filmin yeni adini giriniz: ");
				scanf("%s",yeniad);
				while(!feof(dosya))
				{
					fscanf(dosya,"%s %s %s %s %s\n",a,b,c,d,e);
					if(strcmp(ad,a)!=0)
					{
						fprintf(dosya2,"%s %s %s %s %s\n",a,b,c,d,e);
						
					}
					else
					{
						fprintf(dosya2,"%s %s %s %s %s\n",yeniad,b,c,d,e);
					}
				}
				fclose(dosya);
				fclose(dosya2);
				remove("Film.txt");
				rename("Film2.txt","Film.txt");
				printf("Film guncellendi ! Ana menuye donmek icin herhangi bir tusa basiniz.");
				getch();
				goto menu;
				break;
			}
			case 2:
				{
					char yil[20],yeniyil[20];
					printf("Guncellegeceginiz filmin yilini giriniz: ");
					scanf("%s",yil);
					printf("Filmin yeni yilini giriniz: ");
					scanf("%s",yeniyil);
					while(!feof(dosya))
					{
						fscanf(dosya,"%s %s %s %s %s\n",a,b,c,d,e);
						if(strcmp(yil,b)!=0)
						{
							fprintf(dosya2,"%s %s %s %s %s\n",a,b,c,d,e);
						}
						else
						{
							fprintf(dosya2,"%s %s %s %s %s\n",a,yeniyil,c,d,e);
						}
					}
					fclose(dosya);
					fclose(dosya2);
					remove("Film.txt");
					rename("Film2.txt","Film.txt");
					printf("Film guncellendi ! Ana menuye donmek icin herhangi bir tusa basiniz.");
					getch();
					goto menu;
					break;
					
				}
				case 3:
					{
						char yonetmen[20],yeniyonetmen[20];
						printf("Guncellegeceginiz filmin yonetmenini giriniz: ");
						scanf("%s",yonetmen);
						printf("Filmin yeni yonetmenini giriniz: ");
						scanf("%s",yeniyonetmen);
						while(!feof(dosya))
						{
							fscanf(dosya,"%s %s %s %s %s\n",a,b,c,d,e);
							if(strcmp(yonetmen,c)!=0)
							{
								fprintf(dosya2,"%s %s %s %s %s\n",a,b,c,d,e);
							}
							else
							{
								fprintf(dosya2,"%s %s %s %s %s\n",a,b,yeniyonetmen,d,e);
							}
						}
						fclose(dosya);
						fclose(dosya2);
						remove("Film.txt");
						rename("Film2.txt","Film.txt");
						printf("Film guncellendi ! Ana menuye donmek icin herhangi bir tusa basiniz.");
						getch();
						goto menu;
						break;
						
					}
					case 4:
						{
						char senarist[20],yenisenarist[20];
						printf("Guncellegeceginiz filmin senaristini giriniz: ");
						scanf("%s",senarist);
						printf("Filmin yeni senaristini giriniz: ");
						scanf("%s",yenisenarist);
						while(!feof(dosya))
						{
						fscanf(dosya,"%s %s %s %s %s\n",a,b,c,d,e);
							if(strcmp(senarist,d)!=0)
							{
								fprintf(dosya2,"%s %s %s %s %s\n",a,b,c,d,e);
							}
							else
							{
								fprintf(dosya2,"%s %s %s %s %s\n",a,b,c,yenisenarist,e);
							}
						}
						fclose(dosya);
						fclose(dosya2);
						remove("Film.txt");
						rename("Film2.txt","Film.txt");
						printf("Film guncellendi ! Ana menuye donmek icin herhangi bir tusa basiniz.");
						getch();
						goto menu;
						break;
						
			}
			case 5:
				{
					char basrol[20],yenibasrol[20];
					printf("Guncellegeceginiz filmin basrol oyuncusunu giriniz: ");
					scanf("%s",basrol);
					printf("Filmin yeni basrol oyuncusunu giriniz: ");
					scanf("%s",yenibasrol);
					while(!feof(dosya))
					{
						fscanf(dosya,"%s %s %s %s %s\n",a,b,c,d,e);
						if(strcmp(basrol,e)!=0)
						{
							fprintf(dosya2,"%s %s %s %s %s\n",a,b,c,d,e);
							
						}
						else
						{
							fprintf(dosya2,"%s %s %s %s %s\n",a,b,c,d,yenibasrol);
						}
					}
					fclose(dosya);
						fclose(dosya2);
						remove("Film.txt");
						rename("Film2.txt","Film.txt");
						printf("\nFilm guncellendi ! Ana menuye donmek icin herhangi bir tusa basiniz.");
						getch();
						goto menu;
						break;
						
				}
		}
	
}
			
			
		
		if(secim==4)
		{
			FILE *dosya2,*dosya;
			dosya=fopen("Film.txt","r");
			dosya2=fopen("Film2.txt","w");
			char sil[30];
			printf("Silinecek filmin adini girin: ");
			scanf("%s",&sil);
			
			
			char a[30],b[30],c[30],d[30],e[30];
			
			int secim;
			printf("\nFilm silinecektir devam etmek icin | 1 | e, iptal etmek icin | 2 | ye basiniz:");
			scanf("%d",&secim);
			if(secim==1)
			{
			
			while(!feof(dosya))
			{
				fscanf(dosya,"%s %s %s %s %s \n",&a,&b,&c,&d,&e);
				if(strcmp(sil,a)!=0)
				{
				fprintf(dosya2,"%s %s %s %s %s\n",a,b,c,d,e);
				}
		}
			fclose(dosya);
			fclose(dosya2);
			remove("Film.txt");
			rename("Film2.txt","Film.txt");
		}
		else
		{
			printf("\nFilmi silmeyi iptal ettiniz. Ana menuye yonlendiriliyorsunuz.\n");
			getch();
			goto menu;
		}
		
			printf("\nFilm silindi ! Ana menuye yonlendiriliyorsunuz.\n");
			getch();
			goto menu;
		}
		
		
		
	
			


//***********************************************************************************************************************************************************************************************************************************************
		if(secim==5)
		{
			
			basa:
			char secim;
			printf("------------- Film Arama ------------------\n");
			printf("1.Film adina gore \n");
			printf("2.Yayinlanma yilina gore\n");
			printf("3.Yonetmenine gore\n");
			printf("4.Senaristine gore\n");
			printf("5.Basrol oyuncusuna gore\n");
			printf("\nFilmi neye gore aratmak istiyorsunuz: ");
			scanf("%s",&secim);
			FILE *dosya=fopen("Film.txt","r");
			xyz okunan;
			okunan.FilmAdi=(char*)malloc(sizeof(char)*100);
			okunan.YayinlanmaYili=(char*)malloc(sizeof(char)*100);
			okunan.Yonetmeni=(char*)malloc(sizeof(char)*100);
			okunan.Senaristi=(char*)malloc(sizeof(char)*100);
			okunan.BasrolOyuncusu=(char*)malloc(sizeof(char)*100);
			if(secim=='1')
			{
			printf("\nAranan filmin adini giriniz: ");
			char aranan[30];
			scanf("%s",aranan);
		
			printf("\nFilm Adi \t Yayinlanma Yili \t Yonetmeni \t Senaristi\tBasrol oyuncusu \n");
			
			while(!feof(dosya))
			{
				fscanf(dosya,"%s %s %s %s %s\n",okunan.FilmAdi,okunan.YayinlanmaYili,okunan.Yonetmeni,okunan.Senaristi,okunan.BasrolOyuncusu);
				
				if(strcmp(okunan.FilmAdi,aranan)==0)
				{
					printf("\n%s \t \t %s \t\t\t %s \t %s \t\t %s \t\t \n",okunan.FilmAdi,okunan.YayinlanmaYili,okunan.Yonetmeni,okunan.Senaristi,okunan.BasrolOyuncusu);
				}
			}
			fclose(dosya);
		
			}
			if(secim=='2')
			{
					printf("\nAranan filmin yayinlanma yilinii giriniz: ");
			char aranan[30];
			scanf("%s",aranan);
		
			printf("\nFilm Adi \t Yayinlanma Yili \t Yonetmeni \t Senaristi\tBasrol oyuncusu \n");
			
			while(!feof(dosya))
			{
				fscanf(dosya,"%s %s %s %s %s",okunan.FilmAdi,okunan.YayinlanmaYili,okunan.Yonetmeni,okunan.Senaristi,okunan.BasrolOyuncusu);
				
				if(strcmp(okunan.YayinlanmaYili,aranan)==0)
				{
					printf("\n%s \t \t %s \t\t\t %s \t %s \t\t %s \t\t \n",okunan.FilmAdi,okunan.YayinlanmaYili,okunan.Yonetmeni,okunan.Senaristi,okunan.BasrolOyuncusu);
				}
			}
			fclose(dosya);
			}
			if(secim=='3')
			{
				printf("\nAranan filmin yonetmenini giriniz: ");
			char aranan[30];
			scanf("%s",aranan);
		
			printf("\nFilm Adi \t Yayinlanma Yili \t Yonetmeni \t Senaristi\tBasrol oyuncusu \n");
			
			while(!feof(dosya))
			{
				fscanf(dosya,"%s %s %s %s %s",okunan.FilmAdi,okunan.YayinlanmaYili,okunan.Yonetmeni,okunan.Senaristi,okunan.BasrolOyuncusu);
				
				if(strcmp(okunan.Yonetmeni,aranan)==0)
				{
					printf("\n%s \t \t %s \t\t\t %s \t %s \t\t %s \t\t \n",okunan.FilmAdi,okunan.YayinlanmaYili,okunan.Yonetmeni,okunan.Senaristi,okunan.BasrolOyuncusu);
				}
			}
			fclose(dosya);	
			}
			if(secim=='4')
			{
					printf("\nAranan filmin senaristini giriniz: ");
			char aranan[30];
			scanf("%s",aranan);
		
			printf("\nFilm Adi \t Yayinlanma Yili \t Yonetmeni \t Senaristi\tBasrol oyuncusu \n");
			
			while(!feof(dosya))
			{
				fscanf(dosya,"%s %s %s %s %s",okunan.FilmAdi,okunan.YayinlanmaYili,okunan.Yonetmeni,okunan.Senaristi,okunan.BasrolOyuncusu);
				
				if(strcmp(okunan.Senaristi,aranan)==0)
				{
					printf("\n%s \t \t %d \t\t\t %s \t %s \t\t %s \t\t \n",okunan.FilmAdi,okunan.YayinlanmaYili,okunan.Yonetmeni,okunan.Senaristi,okunan.BasrolOyuncusu);
				}
			}
			fclose(dosya);
			}
			if(secim=='5')
			{
					printf("\nAranan filmin basrol oyuncusunu giriniz: ");
			char aranan[30];
			scanf("%s",aranan);
		
			printf("\nFilm Adi \t Yayinlanma Yili \t Yonetmeni \t Senaristi\tBasrol oyuncusu \n");
			
			while(!feof(dosya))
				{
				fscanf(dosya,"%s %s %s %s %s",okunan.FilmAdi,okunan.YayinlanmaYili,okunan.Yonetmeni,okunan.Senaristi,okunan.BasrolOyuncusu);
				
					if(strcmp(okunan.BasrolOyuncusu,aranan)==0)
					{	
					printf("\n%s \t \t %s \t\t\t %s \t %s \t\t %s \t\t \n",okunan.FilmAdi,okunan.YayinlanmaYili,okunan.Yonetmeni,okunan.Senaristi,okunan.BasrolOyuncusu);
					}	
				}
			}
			if(secim>'5' || secim<'0' )
			{
			
				printf("\nLutfen seciminizi dogru giriniz.\n");
				goto basa;
			}
			fclose(dosya);
			printf("\nAna menuye gitmek icin herhangi bir tusa basiniz..");
			getch();
			goto menu;
			}
		
//*********************************************************************************************************************************************************************************************************************************************************
			if(secim==0)
			{
				printf("\nGULE GULE");
				getch();
			break;
			}
	


}
	return 0;
}




	



