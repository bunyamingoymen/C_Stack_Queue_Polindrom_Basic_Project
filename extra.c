/*
Bunyamin Goymen
*/

#include<stdio.h>
#include<stdlib.h>


main(){
	int a = 0, boyut = 0, ayrac = -1;
	int i, j, control = 0;
	int boyut2;
	char kelime[100], dizi[15] = {'a','b','c','d','z','0','1','2','3','4','5','6','7','8','9'};
	printf("Istediginiz degerleri giriniz.");
	scanf("%s",kelime);
	
	while(kelime[boyut] != '\0')
		boyut++; //kelimenin boyutunu buluyoruz.
	for(i = 0;i<boyut;i++){ // Girilen kelimelerin ilk sarta uygun olup olmadigini kontrol ediyoruz.
		for(j=0;j<15;j++){
			if(kelime[i] == dizi[j]){
				a++;
				j = 15;
			}
			else{
				a = a;
			}
		}
	}
	boyut2 = boyut / 2;
	
	if(a == boyut){ //eger a= boyut ise ilk sart saglanmis demektir. Ona gore islemlerimizi yapiyoruz.
			j = boyut-1;
			i=0;
			for(i=0;i<boyut2;i++){
				if(kelime[i] != kelime[j-i]){ //Eger herhangi bir kelime bile exit olmazsa bu donguden cikacak ve kontrol edilecek.
					boyut2=0;
				}
			}
			printf("Girdiginiz Deger: ");
			for(i=0;i<boyut;i++)
				printf("%c",kelime[i]);
			
			if(boyut2 != 0) // Eger boyut2 = 0 ise palindrom olumuyor. Eger degilse palindrom oluyor.
				printf("\nPalindromdur.");
			else printf("\nPalindrom Degildir");
	}
	else{
		printf("Yanlis deger girdiniz. Sadece: a,b,c,d,z,0,1,2,3,4,5,6,7,8,9 degerleri girilebilir.");
	}	
}
