#include <iostream>
#include <cmath>
#include <locale.h>

using namespace std;

// Temel sýnýf
class Sekil {
    public:
      // arayüz çerçevesi saðlayan saf sanal iþlev (virtual).
        virtual int getAlan() = 0;
        virtual int getCevre() = 0;
      
        void setKenar1(int k) {
            kenar1 = k;
        }
        
        void setKenar2(int k2){
            kenar2 = k2;
        }
   
        void setYukseklik(int y) {
            yukseklik = y;
        }
        
        void setTaban(int t) {
            taban = t;
        }
        
        void setUcgenKenar1(int uk1){
            ucgenKenar1 = uk1;
        }
        
        void setUcgenKenar2(int uk2){
            ucgenKenar2 = uk2;
        }
        
        void setUcgenKenar3(int uk3){
            ucgenKenar3 = uk3;
        }
        
        void setHipotenus(int h){
            hipotenus = h;
        }
        
    protected:
        int kenar1;
        int kenar2;
        int yukseklik;
        int taban;
        int ucgenKenar1;
        int ucgenKenar2;
        int ucgenKenar3;
        int hipotenus;
        
    
};
 
// Türetilmiþ sýnýflar
//inheritance(miras) özelliðini kullandýk
//mathAlan ve mathCevre fonksiyonlarýmýza gerek kalmadanda yapýlabilirdi!
class Dikdortgen: public Sekil {
    public:
    
        inline int mathAlan(){
            return (kenar1 * yukseklik);
        }
        
        inline int mathCevre(){
            return (2*kenar1) + (2*yukseklik);
        }
        
        int getAlan() { 
            return mathAlan(); 
        }
        
        int getCevre() {
          return mathCevre();
        }
};

//inheritance(miras) özelliðini kullandýk
//Sekil classýmýzýn içinden deðerleri kullanabildik
class Ucgen: public Sekil {//üçgen için 3 kenar girdisi alacaðýz ve  
   public:                      //Alaný bulmak için heron formülünü kullanacaðýz.
   
        inline int mathAlan(){
            int s = (ucgenKenar1 + ucgenKenar2 + ucgenKenar3)/2;
            return sqrt(s*(s - ucgenKenar1)*(s - ucgenKenar2)*(s - ucgenKenar3));
        }
        
        inline int mathCevre(){
            return ucgenKenar1 + ucgenKenar2 + ucgenKenar3;
        }
        
        int getAlan() { 
            return mathAlan();
        }
        
        int getCevre(){
            return mathCevre();
        }
};

//inheritance(miras) özelliðini kullandýk
//Sekil classýmýzýn içinden deðerleri kullanabildik
class Kare: public Sekil {
    public:
    
        inline int mathAlan(){
            return (kenar1 * kenar2);
        }
        
        inline int mathCevre(){
            return (2*kenar1 + 2*kenar2);  
        }
    
        int getAlan() { 
            return mathAlan();
        }
        
        int getCevre() {
            return mathCevre();
        }
};

//inheritance(miras) özelliðini kullandýk
//Sekil classýmýzýn içinden deðerleri kullanabildik
class dikUcgen: public Sekil {
   public:
   
    	inline int mathAlan(){
            return (taban * yukseklik)/2;
        }
        
        inline int mathCevre(){
        	if((sqrt(pow(taban,2) + pow(yukseklik,2))) != hipotenus){
        		return taban + yukseklik + hipotenus;
			}else{
				hipotenus = sqrt(pow(taban,2) + pow(yukseklik,2));  
            	return taban + yukseklik + hipotenus;//hipotenüs formülü ile hipotenüsü bulduk dik üçgen çevresi için
													// ve hesabýmýzý yaptýk
			}
        }
        int getAlan() { 
             return mathAlan();
        }
        int getCevre(){
            return mathCevre();
        }
};

 
int main(void) {
    setlocale(LC_ALL, "Turkish");//Türkçe karakter için setlocale kullandýk kütüphanesini include ettik.
    
    //classlarýmýzdan nesnelerimizi oluþturduk.
    Dikdortgen Dikt;
    Ucgen  Ucg;
    dikUcgen dikUcg;
    Kare kare;
    
    int sayi, k, k2, y, t, uk1, uk2, uk3, h;
    
    //Kullanýcý menüsünü bu þekilde tasarladýk
    cout << 
    "1-Dikdörtgen hesabý için 1 giriniz" << "\n" <<
    "2-Üçgen hesabý için 2 giriniz\n"<<
    "3-Kare hesabý için 3 giriniz"<<"\n"<<
    "4-Dik Üçgen hesabý için 4 giriniz \n" << endl;
    
    cin >> sayi;
    
    //Kullanýcýnýn girdiði sayýya göre iþlemlerimizi yaptýk.
    //iþlemleri yaparken taban,kenar,yükseklik vb. bilgilerini kullanýcýdan case içinde aldýk
    switch(sayi){
        case 1:
        	cout << "Dikdörtgen Hesabýný Seçtiniz!!! " << endl;
            cout << "Dikdörtgenin Kenar Uzunluðunu Giriniz " << endl;
            cin >>k;
            Dikt.setKenar1(k);
            
            cout << "Dikdörtgenin Yüksekliðini Giriniz: " << endl;
            cin >>y;
            Dikt.setYukseklik(y);
            
            if(!(k==y)){//Kenarlar eþit deðilse dikdörtgen oldu ve aþaðýsý çalýþtý
                cout << "Dikdörtgen Çevresi: " << Dikt.getCevre() << endl;
                cout << "Dikdörtgen Alaný: " << Dikt.getAlan() << endl;
            }else{//eðer girilen kenarlar eþit ise kare olur burada onun kontrolünü yaptýk.
                cout << "Girilen Bilgi Kareye Aittir" << endl;
                cout << "Karenin Çevresi Çevresi: " << Dikt.getCevre() << endl;
                cout << "Karenin Alaný: " << Dikt.getAlan() << endl;
            }
                
            break;
            
        case 2:
        	cout << "Üçgen Hesabýný Seçtiniz!!! " << endl;
            cout << "Üçgenin 1.Kenarýnýn Uzunluðunu Giriniz: " << endl;
            cin >>uk1;
            Ucg.setUcgenKenar1(uk1);
            
            cout << "Üçgenin 2.Kenarýný Uzunluðunu Giriniz: " << endl;
            cin >>uk2;
            Ucg.setUcgenKenar2(uk2);
            
            cout << "Üçgenin 3.Kenarýný Uzunluðunu Giriniz: " << endl;
            cin >>uk3;
            Ucg.setUcgenKenar3(uk3);
            
            if(!(sqrt(pow(uk1,2) + pow(uk2,2))==uk3)){//dik üçgen deðil ise burasý çalýþtý baþýna ! koyduðumuz için.
                cout << "Üçgenin Çevresi: " << Ucg.getCevre() << endl;
                cout << "Üçgenin Alaný: " << Ucg.getAlan() << endl;
            }else{//girilen deðerlerin kontrol edip dik üçgen ise aþaðýyý çalýþtýrdýk
                cout << "Girilen Deðer Dik Üçgendir!" << endl;
                cout << "Dik Üçgenin Çevresi: " << Ucg.getCevre() << endl;
                cout << "Dik Üçgenin Alaný: " << Ucg.getAlan() << endl;
            }
            break;
            
            
        case 3:
        	cout << "Kare Hesabýný Seçtiniz!!! " << endl;
            cout << "Karenin 1.Kenarýnýn Uzunluðunu Giriniz: " << endl;
            cin >>k;
            kare.setKenar1(k);
            
            cout << "Karenin 2.Kenarýnýn Uzunluðunu Giriniz: " << endl;
            cin >>k2;
            kare.setKenar2(k2);
            
            
            if(k==k2){
               
                cout << "Karenin Çevresi Çevresi: " << kare.getCevre() << endl;
                cout << "Karenin Alaný: " << kare.getAlan() << endl;
                
            }else{//eðer girilen kenarlar eþit deðil ise bu iþlem yapýlýr. 
            		//ve dikdörtgen olduðu yazýlýyor
                cout << "Girilen Bilgi Dikdörtgene Aittir" << endl;
                cout << "Dikdörtgen Çevresi: " << kare.getCevre() << endl;
                cout << "Dikdörtgen Alaný: " << kare.getAlan() << endl;
            }
            break;
            
        case 4:
        	cout << "Dik Üçgen Hesabýný Seçtiniz!!!" << endl;
            cout << "Dik Üçgenin Tabanýnýn Uzunluðunu Giriniz: " << endl;
            cin >>t;
            dikUcg.setTaban(t);
            
            cout << "Dik Üçgenin Yüksekliðinin Uzunluðunu Giriniz: " << endl;
            cin >>y;
            dikUcg.setYukseklik(y);
            
            cout << "Dik Üçgenin Hipotenüsünü Giriniz: " << endl;
            cin >>h;
            dikUcg.setHipotenus(h);
            
            if((sqrt(pow(t,2) + pow(y,2)))==h){//girilen deðerlerin kontrol edip dik üçgen ise aþaðýyý çalýþtýrdýk
                cout << "Dik Üçgenin Çevresi: " << dikUcg.getCevre() << endl;
                cout << "Dik Üçgenin Alaný: " << dikUcg.getAlan() << endl;
                
            }else{//dik üçgen deðil ise burasý çalýþtý.
                cout << "Girilen Deðer Normal Üçgendir!" << endl;
                cout << "Üçgenin Çevresi: " << dikUcg.getCevre() << endl;
                cout << "Üçgenin Alaný: " << dikUcg.getAlan() << endl;
                
            }
            break;
            
            default:
                cout << "Yanlýþ deðer girdiniz!!!\n Lütfen istenilen rakamlardan birini giriniz!" << endl;
        }
       return 0;
}
