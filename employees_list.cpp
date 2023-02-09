#include <stdio.h>
#include <conio.h>
#include<malloc.h>
#include <string.h>

#define MAX 20

typedef struct {
  char oib[11+1];
  char ime[50+1];
  char prezime[50+1];
  short int visina;
  float masa;
  char otac[20+1];
  char majka[20+1];
  char datum[20+1];
} Zaposlenik;  

typedef struct{
 int zadnji; 
 Zaposlenik elementi[MAX];
} Lista;

void ubaci (Zaposlenik x, int pozicija_ubacivanja, Lista *pokLista)
{
  int pozicija;
  if (pokLista->zadnji >= MAX-1)
    {
    printf("Lista je puna!");
	}
  else if ((pozicija_ubacivanja>pokLista->zadnji+1) || (pozicija_ubacivanja<0) )
    printf("Pozicija ne postoji!");
  else {
            for (pozicija=pokLista->zadnji; pozicija >= pozicija_ubacivanja; pozicija--)
                 pokLista->elementi[pozicija+1]= pokLista->elementi[pozicija];
            pokLista->zadnji++;
            pokLista->elementi[pozicija_ubacivanja] = x;
           }
}

void ispis(Lista *pokLista){
  int indeks;
  printf("\nR.Br.\t Ime\t Prezime\t Visina\t Masa\t OIB\t Otac\t Majka\t Datum");
  for (indeks=0; indeks <= pokLista->zadnji; indeks++){

    printf("\n%d.\t%s\t %s\t%d\t%.2f\t%s\t%s\t%s\t%s", 
    									 indeks+1,
										 pokLista->elementi[indeks].ime,
										 pokLista->elementi[indeks].prezime, 
										 pokLista->elementi[indeks].visina,
										 pokLista->elementi[indeks].masa,
										 pokLista->elementi[indeks].oib,
										 pokLista->elementi[indeks].otac,
										 pokLista->elementi[indeks].majka,
										 pokLista->elementi[indeks].datum);
    if (indeks < pokLista->zadnji)
      printf(", ");  
  }
}

void obrisi(int pozicija_brisanja, Lista *pokLista) {
  int pozicija;
  if ( (pozicija_brisanja>pokLista->zadnji ) || (pozicija_brisanja<0) )
    printf("Pozicija ne postoji!");
  else {
    pokLista->zadnji--;    
    for (pozicija=pozicija_brisanja; pozicija<=pokLista->zadnji; pozicija++)
       pokLista->elementi[pozicija] = pokLista->elementi[pozicija+1];
  
  }
}

void ispis_pretrage_ime(Lista *pokLista)
{
	char ime[50];
    int brojacPrazna=1;
    printf("\n");
    printf("Unesite ime zaposlenika: ");
    scanf("%s",&ime);
    printf("\n");
    printf("Ispis trazenih zaposlenika\n");
    printf("\n");
    for(int indeks=0; indeks<=pokLista->zadnji; indeks++)
     
{
        if (strcmp (ime, pokLista->elementi[indeks].ime)==0)
        {
			
			printf("\nR.Br.\tIme\tPrezime\tVisina\tMasa\tOIB\t Otac\tMajka\tDatum");
        	printf("\n%d.\t%s",indeks+1, pokLista->elementi[indeks].ime);
            printf("\t%s", pokLista->elementi[indeks].prezime);
            printf("\t%d", pokLista->elementi[indeks].visina);
            printf("\t%.2f", pokLista->elementi[indeks].masa);
            printf("\t%s", pokLista->elementi[indeks].oib);
			printf("\t%s", pokLista->elementi[indeks].otac);
			printf("\t%s",pokLista->elementi[indeks].majka);
			printf("\t%s",pokLista->elementi[indeks].datum);						
									
            brojacPrazna++;	
		}
        else if (brojacPrazna==0)
        {
            printf("Nema trazenog unosa!");
        }                                       
}
}

void ispis_pretrage_prezime(Lista *pokLista)
{
	char prezime[50];
    int brojacPrazna=1;
    printf("\n");
    printf("Unesite trazeno prezime zaposlenika: ");
    scanf("%s", &prezime);
    printf("\n");
    printf("Ispis trazenih zaposlenika\n");
    printf("\n");
    for(int indeks=0; indeks<=pokLista->zadnji; indeks++)
     
{
        if (strcmp (prezime, pokLista->elementi[indeks].prezime)==0)
        {
			
			printf("\nR.Br.\tIme\tPrezime\tVisina\tMasa\tOIB\t Otac\tMajka\tDatum");
        	printf("\n%d.\t%s",indeks+1, pokLista->elementi[indeks].ime);
            printf("\t%s", pokLista->elementi[indeks].prezime);
            printf("\t%d", pokLista->elementi[indeks].visina);
            printf("\t%.2f", pokLista->elementi[indeks].masa);
            printf("\t%s", pokLista->elementi[indeks].oib);
			printf("\t%s", pokLista->elementi[indeks].otac);
			printf("\t%s",pokLista->elementi[indeks].majka);
			printf("\t%s",pokLista->elementi[indeks].datum);	 						
									
            brojacPrazna++;	
		}
        else if (brojacPrazna==0)
        {
            printf("Nema trazenog unosa!");
        }                                       
}
}

void spremiDatoteku(Lista *pokLista)
{
	FILE *datoteka;
	datoteka = fopen("Evidencija_komunalnih_redara", "wb");
	if( datoteka == NULL ) 
	{
    printf("Problem u otvaranju datoteke!");
   	}
	else
	{
    	fwrite(pokLista , sizeof(*pokLista),1, datoteka);
   	}
   fclose( datoteka );
   printf("!!!Spremljena evidencija zaposlenika!!!");
}

void ucitajDatoteku (Lista *pokLista) {
	FILE *datoteka;
	datoteka = fopen("Evidencija_komunalnih_redara", "rb");
	if( datoteka == NULL ) 
	{
    printf("Problem u otvaranju datoteke!");
  	}
  	else
	{
    fread(pokLista,sizeof(*pokLista),1,datoteka);
  	}
  fclose(datoteka );
  printf("\t\tEvidencija zaposlenika je ucitana!\n");
}

main(){
		
	Zaposlenik zaposlenici;
	
	Lista mojaLista;
	mojaLista.zadnji = -1;
	
	int odabir;

	int brojUnesenihZaposlenika;
	

	do
	{
	printf("\nIzbornik:\n1. Unos\n2. Ispis\n3. Obrisi\n4. Pretrazi\n5. Spremi\n6. Ucitaj\n7. Izmjeni\n8. Izlaz\n\nOdaberite radnju koju zelite sa menu-a:\n");
	scanf("%d",&odabir);
		

	
	if(odabir==1)
	{
	printf("Koliko zaposlenika zelite unijeti?");
	scanf("%d",&brojUnesenihZaposlenika);
		
	for(int indeks=1;indeks<=brojUnesenihZaposlenika;indeks++){
		
	printf("Unesi ime %d osobe: ",indeks);
	scanf(" %s", &zaposlenici.ime);
	
	printf("Unesi prezime %d osobe: ",indeks);
	scanf(" %s", &zaposlenici.prezime);
	do{
		
	printf("Unesi visinu %d osobe: ",indeks);
	scanf(" %d", &zaposlenici.visina);
	if(zaposlenici.visina<0){
		printf("Unesena visina je pogrešna. Unesite ponovo!\n");
	}
	}while(zaposlenici.visina<0);	
    
    do{ 
    
	printf("Unesi masu %d osobe: ",indeks);
	scanf(" %f", &zaposlenici.masa);
	if(zaposlenici.masa<0){
		printf("Unesena masa je pogrešna. Unesite ponovo!\n");
	}
	
	}while(zaposlenici.masa<0);
	
	printf("Unesi OIB %d osobe: ",indeks);
	scanf(" %s", &zaposlenici.oib);
	
	printf("Unesi ime oca %d osobe: ",indeks);
	scanf(" %s", &zaposlenici.otac);
	
	printf("Unesi ime majke %d osobe: ",indeks);
	scanf(" %s", &zaposlenici.majka);
		
	printf("Unesi datum %d osobe: ",indeks);
	scanf(" %s", &zaposlenici.datum);
	

	
	ubaci(zaposlenici , mojaLista.zadnji+1, &mojaLista );
	}
}
		else if(odabir==2)
		{
			ispis(&mojaLista);
		}
		
		else if(odabir==3)
		{
			int red_brisanja;
			ispis(&mojaLista);
			printf("\nOdaberite redni broj koji zelite obrisati.");
			scanf("%d",&red_brisanja);
			obrisi(red_brisanja - 1, &mojaLista );
		}
		else if(odabir==4)
		{
			int izbor;
			printf("\n 1. Pretrazi prema imenu  \n 2. Pretrazi prema prezimenu ");
			scanf("%d",&izbor);
			if(izbor==1)
			{
				ispis_pretrage_ime(&mojaLista);
			}
			else if(izbor==2)
			{
				ispis_pretrage_prezime(&mojaLista);
			}
		
		}
		else if (odabir==5)
		{
			spremiDatoteku(&mojaLista);
		}
		else if(odabir==6)
		{
			ucitajDatoteku(&mojaLista);
		}
		else if(odabir==7)
		{
            printf("\nIzmjena zaposlenika\n");
			ispis(&mojaLista);
			
			int broj;
			printf("\nUnesite redni broj zaposlenika kojeg zelite izmjeniti:\n ");
			scanf("%d", &broj);
		
		if(broj>mojaLista.zadnji || broj<0){
			
			printf("Pozicija ne postoji!");
	
	}
		else{
			
		
			
			obrisi(broj - 1, &mojaLista);
			
			printf("\nUnesi ime osobe: ");
			scanf(" %s", &zaposlenici.ime);
	
			printf("\nUnesi prezime osobe: ");
			scanf(" %s", &zaposlenici.prezime);
		
			printf("\nUnesi visinu osobe: ");
			scanf(" %d", &zaposlenici.visina);	
	
			printf("\nUnesi masu osobe: ");
			scanf(" %f", &zaposlenici.masa);
	
			printf("\nUnesi OIB osobe (OIB SADRZI 11 ZNAMENKI): ");
			scanf(" %s", &zaposlenici.oib);
	
			printf("\nUnesi ime oca osobe: ");
			scanf(" %s", &zaposlenici.otac);
	
			printf("\nUnesi ime majke osobe: ");
			scanf(" %s", &zaposlenici.majka);
			
			printf("Unesi datum osobe: ");
	        scanf(" %s", &zaposlenici.datum);
		
		
			ubaci(zaposlenici, mojaLista.zadnji + broj, &mojaLista);

	}
		}
		
	}
	while(odabir !=8);

}



