/*
Bunyamin Goymen

Ayrintili aciklama en alt kisimda bulunmakta.
*/

#include<stdio.h>
#include<stdlib.h>

struct kuyruk{
	char x;
	struct kuyruk *k;
}; //kuyruk yapisini olusturmak icin struct olusturuyoruz.

struct yigit{
	char t;
	struct kuyruk *y;
}; //yigit yapisini olusturmak icin struct olucturuyoruz.

int yigitbos(int sayac2, int sayac){
	if(sayac2 == sayac){
		if (sayac2 == 0) return 1;
		else return 0;
	}
	else{
		return 0;
	}
	
} // Yigitin ve kuyrugun bos olup olmadigini kontrol eden fonksiyon. Sayac2 burada yigitin boyutunu temsil ediyor, sayac ise kuyruk fonksiyonunun boyutunu temsil ediyor. ve eger sayac2 = sayac ise kuyruk ve yigittaki toplam deger sayisi ayni demektir. Sayac2 = Sayac sifira esitse yigit bostur demektir.
void denqueue(struct kuyruk *kuyrukb, int *sayac){
	
	if(kuyrukb->k != NULL){
			struct kuyruk *gecici = kuyrukb;
			kuyrukb = kuyrukb->k;
			free(gecici);
	}
	else{
			free(kuyrukb);
			kuyrukb = NULL;
	}
	*sayac = *sayac + 1;
}		//Bu fonksyon kuyruktaki degerleri silmek icin kullaniliyor.

void pop(struct yigit *yigitb, int *sayac2){
	int i;
	struct yigit *gecici = yigitb;
	if(yigitb->y == NULL){
		free(yigitb);
		yigitb = NULL;
	}
	else{
		while(gecici->y->k != NULL){
			gecici = gecici->y;
		}
		struct node *silinecek = gecici->y;
		free(silinecek);
		gecici->y = NULL;
	}
	*sayac2 = *sayac2 - 1;
}//Bu fonksiyon yigittaki degerleri silmek icin kullaniliyor.

struct kuyruk *enqueue(char eleman, struct kuyruk *kuyrukb, int *sayac ){
	if(*sayac == 0){ // ilk deger giriliyor.
		struct kuyruk *kuyrukb1=(struct kuyruk *)malloc(sizeof(struct kuyruk));
		kuyrukb1->x = eleman;
		kuyrukb1->k = NULL; // x= data, k=sonraki
		kuyrukb = kuyrukb1;
		kuyrukb1 = NULL;
		*sayac = *sayac + 1;
		return kuyrukb;
	}
	else{ //ilk degerden farkli degerler giriliyor.
		struct kuyruk *gecici = kuyrukb;
		while(gecici->k != NULL)
			gecici = gecici->k;
		struct kuyruk *kuyrukb1 = (struct kuyruk *)malloc(sizeof(struct kuyruk));
		kuyrukb1->x = eleman;//x= data, k=sonraki
		kuyrukb1->k = NULL;
		gecici->k = kuyrukb1;
		kuyrukb1 = NULL;
		*sayac = *sayac + 1;
		return NULL;
		
	}
} // Bu fonksiyon girilen degerleri kuyruk yapisina ekliyor.
struct yigit *push (char eleman, struct yigit *yigitb, int *sayac2){
	struct yigit *yigitb1 = (struct yigit *)malloc(sizeof(struct yigit));
	yigitb1->t = eleman; //t: eleman, y: sonraki
	yigitb1->y = NULL;
	
	if(*sayac2 == 0){ //ilk deger giriliyorsa
		yigitb = yigitb1;
		yigitb1 = NULL;
		*sayac2 = *sayac2 + 1;
		return yigitb;
	}
	else{ //ilk degerden sonraki yaziliyorsa
		struct yigit *gecici = yigitb;
		while(gecici->y != NULL)
			gecici = gecici->y;
		gecici->y = yigitb1;
		yigitb1 = NULL;
		*sayac2 = *sayac2 + 1;
		return NULL;
	}
}//Bu fonksiyon girilen degerleri kuyruk yapisindan yigit yapisina yolluyor.

main(){
	char *kelime=(char *)malloc(sizeof(char)*100);
	char kelime2[100], dizi[15] = {'a','b','c','d','z','0','1','2','3','4','5','6','7','8','9'}; //deger girme sartini dizi olusturup kontrol ederek yapiyoruz.
	char eleman;
	int i,j,boyut = 0;
	int a = 0;
	int sayac = 0, sayac2 = 0, sayac3, sayac4; //sayac = kuyruk yapisinin bouyut, sayac2= yigit yapisinin boyutu, sayac3 ve sayac 4 de kontrol ederken degerleri sabit tutmak icin.
	
	struct kuyruk *kuyrukb = NULL;
	struct kuyruk *kuyrukb2 = NULL;
	struct yigit *yigitb = NULL;
	struct yigit *yigitb2 = NULL;
	
	printf("Istediginiz deger veya degerleri giriniz.({a, b, c, d, z, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9} degerleri girilebilir.)\n(z ayractir.)\n");
	scanf("%s",kelime);//kullanicidan istedigi degerleri soruyoruz.
	
	while(*kelime != NULL){// Bu dongude kullanicinin girdigi degerlerin toplam kac boyut oldugunu ogreniyoruz ve alinan degerleri diziye aktariyoruz.
		kelime2[boyut] = *kelime;
		*kelime++;
		boyut++;
	}
	
	for(i=0;i<boyut;i++){//Bu dongude girilen degerlerin sartlari dogrulayip dogrulamadigi kontrol ediliyor. Ve her dogru kelime icin a degeri bir artiyor ve butun kelimeler uygun ise a boyuta esit oldugu icin a=boyut dendiinde sartlar yerine getirilmistir demektir.
		for(j=0;j<15;j++){
			if(kelime2[i] == dizi[j]){
				a++;
				j = 15; //Bir tanesinin dogru oldugunu anladigimiz anda donguye devam etmenin bir sebebi olmadigi icin bu direk donguyu sonlandiriyor. 
			}
		}
	}
	
	if(a == boyut ){//Giris sartlari saglanirsa bu if'e giriyor.
		sayac = 0;
		for(i=0; i<boyut;i++){ //bu dongude butun degerleri ilk basta eleman degiskenine ardindan kuyruk yapisina yolluyoruz.
			eleman = kelime2[i];
			struct kuyruk *ilk = enqueue(eleman,kuyrukb,&sayac);
			if (sayac == 1) kuyrukb = ilk;
		}
		
		kuyrukb2 = kuyrukb;
		for(i=0;i<boyut;i++){ // Burada kuyruk yapisindaki elemanlardan biri z ise, oraya kadar yigita ekliyoruz. z yok ise, butun girilen degerleri aktariyor.
				if(kuyrukb2->x !='z'){
					eleman = kuyrukb2->x;
					struct yigit *ilk2= push(eleman,yigitb,&sayac2); 
					if(sayac2 == 1) yigitb = ilk2;
					if(kuyrukb2->k != NULL) kuyrukb2 = kuyrukb2->k;
				}
		}
		kuyrukb2 = kuyrukb;
		printf("Girdiginiz degerler: "); // Kullancinin girdigi degerleri ekrana yazdiriyoruz.
		for(i=0; i<boyut; i++){
			printf("%c",kuyrukb2->x);
			kuyrukb2 = kuyrukb2->k;
		}
		printf("\n");
		kuyrukb2 = kuyrukb;
		yigitb2 = yigitb;
		if(sayac == sayac2){ // eger sayac = sayac2 ise z harfi yoktur ve ona gore islem yapiyoruz.
			while(yigitb2->y != NULL){ //burada yigitb2 yi silinecek ilk degere getiriyoruz. 
				yigitb2 = yigitb2->y;
			}
			for(i=0;i<boyut-1;i++){
				if(yigitb2->t == kuyrukb2->x){ //eger yigitb2=kuyrukb2 ise yigittaki ve kuyruktaki bir degeri siliyoruz. ve pointerlar� bir sonraki silinecek degere gonderiyoruz.
					pop(yigitb, &sayac2);
					yigitb2 = yigitb;
					while(yigitb2->y != NULL){
						yigitb2 = yigitb2->y;
					}
					if(kuyrukb2->k != NULL)kuyrukb2= kuyrukb2->k;
					else kuyrukb2 = kuyrukb =NULL;
					sayac--;
			}
			else i = boyut; //eger herhangi bir deger bile esit degilse bu else giriyor ve i = boyut oldugundan donguden cikip diger degerleri hic karsilastirmiyor. 
			
		}
			sayac2--;
			sayac--;
		}
		else{//eger sayac=sayac2 degilse, z ayraci vardir demektir ve ona gore islem yapiyoruz.
			sayac3 = sayac;
			sayac4 = sayac2; 
			for(i=0; i<sayac3-sayac4; i++){ // burada kuyruk yapisini z ye kadar siliyoruz. z dahil.
				kuyrukb = kuyrukb->k;
				sayac--;
			}
			yigitb2 = yigitb;
			while(yigitb2->y != NULL){//burada yigit yapisinda ilk silinecek degeri pointer ile isaretliyoruz.
				yigitb2 = yigitb2->y;
			}
			for(i=0;i<sayac4-1;i++){ //burada yigit ile kuyruk yapisina karsilastiriyoruz. eger bir tanesi bile yanlis olursa direk donguden cikyor.
				
				if(yigitb2->t == kuyrukb->x){
					pop(yigitb, &sayac2);
					yigitb2 = yigitb;
					while(yigitb2->y != NULL){
						yigitb2 = yigitb2->y;
					}
					kuyrukb = kuyrukb->k;
					sayac--;
				}
				else i = boyut;
			
			}
			sayac--;
			sayac2--;
		}
		
		if(yigitbos(sayac2, sayac)) // sayac2, yigiten boyutunu temsil ediyordu. eger sayac2 =0 ise yigit bostur anlamina geliyor ve bu Palindrom oldugu anlamina geliyor.
			printf("Polindromdur.");
		else printf("Polindrom Degildir.");
	
}
else printf("\n\nYanlis deger veya degerleri yanlis girdiniz. Sadece {a, b, c, d, z, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9} degerleri girilebilir.");//Burada ilk sarti saglamaz ise uyari veriyoruz.
}

/*
Ayrintili Aciklama:

Not: Kuyruk Ve yigit yapilara bagli liste ile yapilmistir. Diziye gore yapilan diger dosyada bulunmaktadir.


- Program ilk defa acildiginda kullanici hangi harf veya rakamlar, girecegini soruyoruz. Kullanicinin istedigi degerleri char * ile alip dongu icinde hem boyutunu
ogreniyoruz hemde bir diziye aktariyoruz.

- Girilen karakterlerin kurala uygun olup olmadigini kontrol ediyoruz. (Sadece a,b,c,d ve rakamlar girilebiliyor.).

- eger girilen karakterler kurala uygun ise devam ediyoruz. degilse yanlis karakterler girdiniz diye programi sonlandiriyoruz.

- Karakterler kurala uygun ise butun degerleri kuyruk yapisina yolluyoruz. Kuyruk yapisindan sonra kuyruktaki degerleri yigit yapisina aktarmaya basliyoruz.

- eger kuyruk yapisinda herhangi bir yerde z var ise yigita oraya kadar gonderiyoruz. z yok ise butun degerleri ekliyor. (z ayrac gorevi goruyor.)

- Sayac, kuyruktaki boyutu gosteriyor. Sayac2 ise yigittaki boyutu gosteriyor. Yani eger 'sayac = sayac2' olursa kelimenin herhangi bir yerinde z harfi yok 
demektir. eger esit degiller se de z harfi var demektir. 

- eger sayac = sayac2 ise yigitta 'son giren ilk cikar', kuyrukta 'ilk giren ilk cikar' mantigi ile yigit ile kuyruktaki ilk cikacak degerleri karsilastiriyoruz.
Ve eger yigittaki degerler ile kuyruktaki degerler ayniysa teker teker siliyoruz. eger bir tane harf veya rakam bile uyusmazsa otomatik olarak donguden cikiyor.

- eger sayac != sayac2 ise kuyruktaki z ye kadar olan kismi (z dahil) siliyoruz. Daha sonra yigit ile karsilastiriyoruz. eger z varsa buradaki boyut sayac2 nin 
boyutu oluyor cunku kuyrukta z degerini silene kadar kuyrugu siliyoruz ve sayac, sayac2 ye esitleniyor.

- Bunu kontrol ettikten sonra Kullanicinin girdigi degerleri ekrana yazdiriyoruz. Ve girilen degerlerin Palindrom olup olmadigini kontrol ediyoruz. eger sayac ve sayac2, 0(sifir)'a esitse Palindrom oldugu, degilse Palindrom olmadigi sonucu cikartiliyor cunku butun degerler ayniysa sayac lar sifirlanacak. Ve en son 
olarak cikan sonuca gore "Palindromdur." veya "Palindrom Degildir." yaziyoruz ve programi sonlandiriyoruz.
*/
