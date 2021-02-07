#include <iostream>
#include <cmath>
#include <locale.h>

using namespace std;

// Temel s�n�f
class Sekil {
    public:
      // aray�z �er�evesi sa�layan saf sanal i�lev (virtual).
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
 
// T�retilmi� s�n�flar
//inheritance(miras) �zelli�ini kulland�k
//mathAlan ve mathCevre fonksiyonlar�m�za gerek kalmadanda yap�labilirdi!
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

//inheritance(miras) �zelli�ini kulland�k
//Sekil class�m�z�n i�inden de�erleri kullanabildik
class Ucgen: public Sekil {//��gen i�in 3 kenar girdisi alaca��z ve  
   public:                      //Alan� bulmak i�in heron form�l�n� kullanaca��z.
   
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

//inheritance(miras) �zelli�ini kulland�k
//Sekil class�m�z�n i�inden de�erleri kullanabildik
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

//inheritance(miras) �zelli�ini kulland�k
//Sekil class�m�z�n i�inden de�erleri kullanabildik
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
            	return taban + yukseklik + hipotenus;//hipoten�s form�l� ile hipoten�s� bulduk dik ��gen �evresi i�in
													// ve hesab�m�z� yapt�k
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
    setlocale(LC_ALL, "Turkish");//T�rk�e karakter i�in setlocale kulland�k k�t�phanesini include ettik.
    
    //classlar�m�zdan nesnelerimizi olu�turduk.
    Dikdortgen Dikt;
    Ucgen  Ucg;
    dikUcgen dikUcg;
    Kare kare;
    
    int sayi, k, k2, y, t, uk1, uk2, uk3, h;
    
    //Kullan�c� men�s�n� bu �ekilde tasarlad�k
    cout << 
    "1-Dikd�rtgen hesab� i�in 1 giriniz" << "\n" <<
    "2-��gen hesab� i�in 2 giriniz\n"<<
    "3-Kare hesab� i�in 3 giriniz"<<"\n"<<
    "4-Dik ��gen hesab� i�in 4 giriniz \n" << endl;
    
    cin >> sayi;
    
    //Kullan�c�n�n girdi�i say�ya g�re i�lemlerimizi yapt�k.
    //i�lemleri yaparken taban,kenar,y�kseklik vb. bilgilerini kullan�c�dan case i�inde ald�k
    switch(sayi){
        case 1:
        	cout << "Dikd�rtgen Hesab�n� Se�tiniz!!! " << endl;
            cout << "Dikd�rtgenin Kenar Uzunlu�unu Giriniz " << endl;
            cin >>k;
            Dikt.setKenar1(k);
            
            cout << "Dikd�rtgenin Y�ksekli�ini Giriniz: " << endl;
            cin >>y;
            Dikt.setYukseklik(y);
            
            if(!(k==y)){//Kenarlar e�it de�ilse dikd�rtgen oldu ve a�a��s� �al��t�
                cout << "Dikd�rtgen �evresi: " << Dikt.getCevre() << endl;
                cout << "Dikd�rtgen Alan�: " << Dikt.getAlan() << endl;
            }else{//e�er girilen kenarlar e�it ise kare olur burada onun kontrol�n� yapt�k.
                cout << "Girilen Bilgi Kareye Aittir" << endl;
                cout << "Karenin �evresi �evresi: " << Dikt.getCevre() << endl;
                cout << "Karenin Alan�: " << Dikt.getAlan() << endl;
            }
                
            break;
            
        case 2:
        	cout << "��gen Hesab�n� Se�tiniz!!! " << endl;
            cout << "��genin 1.Kenar�n�n Uzunlu�unu Giriniz: " << endl;
            cin >>uk1;
            Ucg.setUcgenKenar1(uk1);
            
            cout << "��genin 2.Kenar�n� Uzunlu�unu Giriniz: " << endl;
            cin >>uk2;
            Ucg.setUcgenKenar2(uk2);
            
            cout << "��genin 3.Kenar�n� Uzunlu�unu Giriniz: " << endl;
            cin >>uk3;
            Ucg.setUcgenKenar3(uk3);
            
            if(!(sqrt(pow(uk1,2) + pow(uk2,2))==uk3)){//dik ��gen de�il ise buras� �al��t� ba��na ! koydu�umuz i�in.
                cout << "��genin �evresi: " << Ucg.getCevre() << endl;
                cout << "��genin Alan�: " << Ucg.getAlan() << endl;
            }else{//girilen de�erlerin kontrol edip dik ��gen ise a�a��y� �al��t�rd�k
                cout << "Girilen De�er Dik ��gendir!" << endl;
                cout << "Dik ��genin �evresi: " << Ucg.getCevre() << endl;
                cout << "Dik ��genin Alan�: " << Ucg.getAlan() << endl;
            }
            break;
            
            
        case 3:
        	cout << "Kare Hesab�n� Se�tiniz!!! " << endl;
            cout << "Karenin 1.Kenar�n�n Uzunlu�unu Giriniz: " << endl;
            cin >>k;
            kare.setKenar1(k);
            
            cout << "Karenin 2.Kenar�n�n Uzunlu�unu Giriniz: " << endl;
            cin >>k2;
            kare.setKenar2(k2);
            
            
            if(k==k2){
               
                cout << "Karenin �evresi �evresi: " << kare.getCevre() << endl;
                cout << "Karenin Alan�: " << kare.getAlan() << endl;
                
            }else{//e�er girilen kenarlar e�it de�il ise bu i�lem yap�l�r. 
            		//ve dikd�rtgen oldu�u yaz�l�yor
                cout << "Girilen Bilgi Dikd�rtgene Aittir" << endl;
                cout << "Dikd�rtgen �evresi: " << kare.getCevre() << endl;
                cout << "Dikd�rtgen Alan�: " << kare.getAlan() << endl;
            }
            break;
            
        case 4:
        	cout << "Dik ��gen Hesab�n� Se�tiniz!!!" << endl;
            cout << "Dik ��genin Taban�n�n Uzunlu�unu Giriniz: " << endl;
            cin >>t;
            dikUcg.setTaban(t);
            
            cout << "Dik ��genin Y�ksekli�inin Uzunlu�unu Giriniz: " << endl;
            cin >>y;
            dikUcg.setYukseklik(y);
            
            cout << "Dik ��genin Hipoten�s�n� Giriniz: " << endl;
            cin >>h;
            dikUcg.setHipotenus(h);
            
            if((sqrt(pow(t,2) + pow(y,2)))==h){//girilen de�erlerin kontrol edip dik ��gen ise a�a��y� �al��t�rd�k
                cout << "Dik ��genin �evresi: " << dikUcg.getCevre() << endl;
                cout << "Dik ��genin Alan�: " << dikUcg.getAlan() << endl;
                
            }else{//dik ��gen de�il ise buras� �al��t�.
                cout << "Girilen De�er Normal ��gendir!" << endl;
                cout << "��genin �evresi: " << dikUcg.getCevre() << endl;
                cout << "��genin Alan�: " << dikUcg.getAlan() << endl;
                
            }
            break;
            
            default:
                cout << "Yanl�� de�er girdiniz!!!\n L�tfen istenilen rakamlardan birini giriniz!" << endl;
        }
       return 0;
}
