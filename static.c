/*
Bunyamin Goymen

Ayrintili aciklama en alt kisimda bulunmakta.
*/


#include<stdio.h>
#include<stdlib.h>

int yigitbos(int sp2){
	if(sp2 == -1)
		return 1;
	else
		return 0;
} // yigitin bos olup olmadigini kontrol ediyor.

void enqueue(char kelime2[], char kuyruk2[], int *f2, int *r2, int boyut, int i){
	kuyruk2[*r2] = kelime2[i];
	(*r2) = (*r2) + 1;	
}//kuyruk ekleme fonksiyonu. Kullancinin girdigi degerleri kuyruga aktariyoruz.

int denqueue(char kuyruk2[],int*f2, int *r2){
	
	*f2 = (*f2) + 1;
	return(kuyruk2[*f2]);
	
} // Degerlerin palindrom olup olmadigini kontrol ederken kuyruktaki degerleri silmek icin kullandigimiz fonksiyon.

void push(char yigit2[], char kuyruk2[], int *sp2, int boyut, int i){	
		(*sp2) = (*sp2) + 1;
		yigit2[(*sp2)] = kuyruk2[i];
		
}//yigita deger ekleme fonksiyonu. Kuyruktaki degerleri yigita aktariyoruz.

int pop(int *sp3 ){
	(*sp3) = (*sp3) - 1;
	return -1;
}//degerlerin palindrom olup olmadigini kontrol ederken yigittaki degerleri silmek icin kullandigimiz fonksiyon.

main(){
	int f, r,boyut; //kuyruk icin gerekli olan degiskenler.
	int sp; // Yigit icin gerekli olan degisken.
	int a, i,j, s;
	int ayrac = -1;
	int c,d,e;
	char *kelime=(char *)malloc(sizeof(char)*100);
	char kelime2[100], dizi[15] = {'a','b','c','d','z','0','1','2','3','4','5','6','7','8','9'};
	
	boyut = 0;
	
	printf("Istediginiz harf veya rakamlari giriniz.(Sadece sunlari girebilirsiniz: a, b, c, d, z, 1, 2, 3, 4, 5, 6, 7, 8, 9)\n(z ayractir.)\n");
	scanf("%s",kelime);
	
	while(*kelime != NULL){
		kelime2[boyut] = *kelime;
		*kelime++;
		boyut++;
	}
	
	
 	
	a=0;
	for(i = 0;i<boyut;i++){
		for(j=0;j<15;j++){
			if(kelime2[i] == dizi[j]){
				a++;
				j = 15;
			}
			else{
				a = a;
			}
		}
	}
	
	if (a == boyut){
		char kuyruk[boyut], yigit[boyut];
		r = 0, f = -1; // Bunlar kuyruk icin gerekli olan degiskenler f: front, r:rear. f ilk silinecek degeri, r ise son eklenen degeri gosterir.
	
		sp = -1; // Bu degisken yigit icin gerekli olan degisken. ve ekleme ile silmeyi bu degisken ile yapicagiz.
		for(i=0;i<boyut;i++){
			enqueue(kelime2, kuyruk, &f, &r, boyut,i);
		}
	
		for(i=0;i<boyut;i++){
			if(kuyruk[i] != 'z'){
				push(yigit, kuyruk, &sp, boyut, i);
			}
			else{
				ayrac = i;
				i = boyut; 
			}
		}
		
		printf("Girdiginiz degerler: ");
		
		for(i=0; i<boyut; i++){
			printf("%c",kuyruk[i]);
		}//Bu for dongusunde kullanici hangi degerleri girdiyse onu yaziyor.

		s = boyut  - 1;
		c = ayrac + 1; 
		d = ayrac +1;
		e= ayrac -1;
		if(ayrac != -1){ //Eger ayrac -1 den farkliysa bir ayracin oldugu anlasiliyor eger -1 ise de bir ayracin olmadigi anlasiliyor ve ona gore islem yapiliyor
 			for(i=d; i<boyut; i++){
				if(yigit[e] == kuyruk[c]){ // Eger ayrac var ise kuyruk yapisina ayractan sonraki yerde yigit yapisina da ayractan onceki yerde baslatiyoruz.
					pop(&sp);
					denqueue(kuyruk, &f, &r);
					e--;// Burada yigitteki ilk cikacak (son giren) ile kuyruktaki ilk cikacak (ilk giren) olan degerleri karsilastiriyoruz. Aslinda bu kullanicinin girdigi son deger ile ilk degeri karsilastiriyor. Eger son deger ile ilk deger ayni ise o degerleri silip sonraki degerlere gegiyor.
					c++;
				
				}
				else
					i = boyut;// eger bir tane bile else olursa otomatik olarak for dongusu sonlanacagi anlamina geliyor.
			}		
		}//Bu if dongusu girilen degerlerde ayrac var mi ve varsa palindrom olup olmadigini inceliyor. Eger yigit ve kuyruk tamamen bosalirsa palindromdur anlamina geliyor. 

		else{ //Eger ayrac yoksa bu else girecek.
			for(i=0;i<boyut;i++){
				if(yigit[s] == kuyruk[i]){
					pop(&sp);
					denqueue(kuyruk, &f, &r);
					s--;
				} // yigit ve kuyruktaki ilk silinecek degerleri karsilastiriyoruz. Eger ayni ise teker teker silerek bitiriyor. Farkli ise direk donguden cikiyor.
				else i = boyut;
			}
		}
		if ( yigitbos(sp) ){
				printf ("\nPalindromdur.");//Burada yigit bos ise palindrom oldugu icin ekrana yazdirmadan once kontrol ediyor. Yigit bos ise palindrom, degilse palindrom degildir diyor.
		}
	
		else{
			printf("\nPalindrom Degildir.");
		}
		
		
	}
	else{
		printf("Yanlis deger veya degerleri girdiniz. Sadece su degerler  girilebilir: a, b, c, d, z, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9\n");//Eger ilk sarti saglamaz ise bu else giriyor ve uyari veriyor.
	}		
}

/*
Ayrintili Aciklama:

Not: Kuyruk Ve Yigit yapilari dizi ile yapilmistir. Baska listeye gore yapilan diger dosyada bulunmaktadir.


- Program ilk defa acildiginda kullanici hangi harf veya rakamlari girecegini soruyoruz. Kullanicinin istedigi degerleri char * ile alip dongu icinde hem boyutunu ogreniyoruz hemde bir diziye aktariyoruz.

- Girilen karakterlerin kurala uygun olup olmadigini kontrol ediyoruz. (Sadece a,b,c,d ve rakamlar girilebiliyor.).

- Eger girilen karakterler kurala uygun ise devam ediyoruz. Degilse yanlis karakterler girdiniz diye programi sonlandiriyoruz.

- Karakterler kurala uygun ise butun degerleri kuyruk yapisina yolluyoruz. Kuyruk yapisindan sonra kuyruktaki degerleri yigit yapisina aktarmaya basliyoruz.

- Eger kuyruk yapisinda herhangi bir yerde z var ise yigita oraya kadar gonderiyoruz. z yok ise butun degerleri ekliyor. (z ayrac gorevi goruyor.)

- Sayac, kuyruktaki boyutu gosteriyor. Sayac2 ise yigittaki boyutu gosteriyor. Yani eger 'sayac = sayac2' olursa kelimenin herhangi bir yerinde z harfi yok 
demektir. Eger esit degiller se de z harfi var demektir. 

- Eger sayac = sayac2 ise yigitta 'son giren ilk cikar', kuyrukta 'ilk giren ilk cikar' mantigi ile yigit ile kuyruktaki ilk cikacak degerleri karsilastiriyoruz.
Ve eger yigittaki degerler ile kuyruktaki degerler ayniysa teker teker siliyoruz. Eger bir tane harf veya rakam bile uyusmazsa otomatik olarak donguden cikiyor.

- Eger sayac != sayac2 ise kuyruktaki z ye kadar olan kismi (z dahil) siliyoruz. Daha sonra yigit ile karsilastiriyoruz. Eger z varsa buradaki boyut sayac2'nin boyutu oluyor cunku kuyrukta z degerini silene kadar kuyrugu siliyoruz ve sayac, sayac2 ye eşitleniyor.

- Bunu kontrol ettikten sonra kullanicinin girdigi degerleri ekrana yazdiriyoruz. Ve girilen degerlerin Palindrom olup olmadigini kontrol ediyoruz. Eger sayac ve sayac2, 0(sifir)'a esitse Palindrom oldugu, degilse Palindrom olmadigi sonucu cikartiliyor cunku butun degerler ayniysa sayac lar sifirlanacak. Ve en son 
olarak cikan sonuca gore "Palindromdur." veya "Palindrom Degildir." yaziyoruz ve programi sonlandiriyoruz.
*/
