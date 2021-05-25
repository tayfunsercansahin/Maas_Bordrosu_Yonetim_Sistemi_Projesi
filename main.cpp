#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

struct tarih{int gun, ay, yil;};
int calisanNumarasiOlustur();

int telefonDogrulama(char n[]){
    int f=1;

    for(int k=0;k<10 && (f);k++){
        if(!(n[k]>'0' && n[k]<='9')){
            f=0;
        }
    }

    return f;
}

void gunSayisiDogrulama(int n, int gun, int y){
    int ayinGunu;

    switch(gun){
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        ayinGunu=31;
        break;
    case 4:
    case 6:
    case 9:
    case 11:
        ayinGunu=30;
        break;
    case 2:
        if(y%4==0 && y%100!=0 || y%400==0){
            ayinGunu=29;
        }
        else{
            ayinGunu=28;
        }

        break;
    }

    int gecerliGunSayisi;

    if(n<0 || n>ayinGunu){
        cout<<"Gecersiz Gun Sayisi. Gecerli Gun Sayisini Giriniz: ";
        cin>>gecerliGunSayisi;
        gunSayisiDogrulama(gecerliGunSayisi,gun,y);
    }
}

class calisan{
    char calisanAtama[10];
    int calisanNumarasi;
    char isim[20];
    char cinsiyet;
    char telefonNumarasi;
    char dogumTarihi, katilmaTarihi;
    char mobilNumarasi;
         double temelMaas;
         char adres[12];

public:
    calisan(){

    }

private:
    void _numaraAl(char gecici[], char* girisMesaji, char* gecersizMesaj){
        int gecerli=0;

        do{
            cout<<girisMesaji;
            cin>>gecici;
            gecerli=telefonDogrulama(gecici);

            if(!gecerli){
                cout<<gecersizMesaj;
            }
        }while(!gecerli);
    }

public:
    void mobilGiris(){
        _numaraAl(mobilNumarasi,"Mobil Numarasini Giriniz: ","Gecersiz Mobil Numara, Tekrar Deneyiniz");
    }

    void yeniMobilGiris(){
        _numaraAl(mobilNumarasi,"Yeni Mobil Numarasini Giriniz: ","Gecersiz Mobil Numara, Tekrar Deneyiniz");
    }

    void yeniTelefonNumarasiGiris(){
        _numaraAl(telefonNumarasi,"Yeni Telefon Numarasini Giriniz: ","Gecersiz Telefon Numarasi, Tekrar Deneyiniz");
    }

    void TelefonNumarasiGiris(){
        _numaraAl(telefonNumarasi,"Telefon Numarasini Giriniz: ","Gecersiz Telefon Numarasi, Tekrar Deneyiniz");
    }

    void dogumTarihiGiris(tarih dogumTarihi){
        cout<<"Dogum Gununu Giriniz (22 Mart Ise 22 Giriniz): ";
        cin>>dogumTarihi.gun;
        cout<<"Dogum Ayini Giriniz (22 Mart Ise 3 Giriniz): ";
        cin>>dogumTarihi.ay;
        cout<<"Dogum Yilini Giriniz (Mart 1997 Ise 1997 Giriniz): ";
        cin>>dogumTarihi.yil;

        int ayinGunu;

        switch(dogumTarihi.ay){
        case 1:
        case 3:
        case 5:
        case 7:
        case 10:
        case 12:
            ayinGunu=31;
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            ayinGunu=30;
            break;
        case 2:

        if(dogumTarihi.yil%4==0 && dogumTarihi.yil%100!=0 || dogumTarihi.yil%400==0){
            ayinGunu=29;
        }
        else{
            ayinGunu=28;
        }

        break;
        }

        tarih nd;

        if(!(dogumTarihi.gun>=1 && dogumTarihi.gun<=ayinGunu && dogumTarihi.ay<=12)){
            cout<<"Gecersiz Tarih, Tekrar Deneyiniz";
            dogumTarihiGiris(dogumTarihi);
        }
    }

    void katilmaTarihiGiris(tarih katilmaTarihi){
        cout<<"Katilma Gununu Giriniz (22 Mart Ise 22 Giriniz): ";
        cin>>katilmaTarihi.gun;
        cout<<"Katilma Ayini Giriniz (22 Mart Ise 3 Giriniz): ";
        cin>>katilmaTarihi.ay;
        cout<<"Katilma Yilini Giriniz (Mart 1997 Ise 1997 Giriniz): ";
        cin>>katilmaTarihi.yil;

        int ayinGunu;

        switch(katilmaTarihi.ay){
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            ayinGunu=31;
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            ayinGunu=30;
            break;
        case 2:
            if(katilmaTarihi.yil%4==0 && katilmaTarihi.yil%100!=0 || katilmaTarihi.yil%400==0){
                ayinGunu=29;
            }
            else{
                ayinGunu=28;
            }

            break;
        }

        tarih nd;

        if(!(katilmaTarihi.gun>=1 && katilmaTarihi.gun<=ayinGunu && katilmaTarihi.ay>0 && katilmaTarihi.ay<=12)){
            cout<<"Gecersiz Tarih, Tekrar Deneyiniz";
            katilmaTarihiGiris(katilmaTarihi);
        }
    }

    void calisanGiris(){
        cout<<"Adini Giriniz: ";
        gets(isim);
        calisanNumarasi=calisanNumarasiOlustur();
        cout<<"Cinsiyetini Giriniz (Erkek Icin 'E', Kadin Icin 'K'): ";
        cin>>cinsiyet;

        dogumTarihiGiris(dogumTarihi);
        katilmaTarihiGiris(katilmaTarihi);

        cout<<"Atamasini Giriniz: ";
        gets(calisanAtama);
        cout<<"Temel Maasini Giriniz: ";
        cin>>temelMaas;

        telefonNumarasiGiris();
        mobilGiris();

        cout<<"Adresini Giriniz: ";
        gets(adres);
    }

    void calisaniGoster(){
        cout<<"Calisan Numarasi: "<<calisanNumarasi<<endl;
        cout<<"Isim: "<<isim<<endl;
        cout<<"Atama: "<<calisanAtama<<endl;
        cout<<"Cinsiyet: "<<cinsiyet<<endl;
        cout<<"Dogum Tarihi: "<<dogumTarihi.gun<<"."<<dogumTarihi.ay<<"."<<dogumTarihi.yil<<endl;
        cout<<"Katilma Tarihi: "<<katilmaTarihi.gun<<"."<<katilmaTarihi.ay<<"."<<katilmaTarihi.yil<<endl;
        cout<<"Temel Maas: "<<temelMaas<<endl;
        cout<<"Telefon Numarasi: "<<telefonNumarasi<<endl;
        cout<<"Mobil Numarasi: "<<mobilNumarasi<<endl;
    }

    void goster1(){
        double brut=temelMaas+.55*temelMaas+.35*temelMaas+.15*temelMaas;
        double kesinti=0;
        double net=brut-kesinti;

        cout<<"CalisanNumarasi Isim Atama Temel Brut";
        cout<<"Kesinti Net"<<endl;

        print("%5i %-17s %-14s %-10.2lf %-10.2lf %-10.2lf %-8.2lf",calisanNumarasi,isim,calisanAtama,temelMaas,brut,kesinti,net);
        cout<<endl;
    }

    char* isimDondur(){
        return isim;
    }

    int calisanNumarasiDondur(){
        return calisanNumarasi;
    }

    char* atamaDondur(){
        return calisanAtama;
    }

    void atamaDuzenle(char* calisanAtama2){
        strcpy(calisanAtama,calisanAtama2);
    }

    void cinsiyetDuzenle(char c){
        cinsiyet=c;
    }

    void dogumTarihiDuzenle(tarih t){
        dogumTarihi=t;
    }

    void katilmaTarihiDuzenle(tarih t){
        katilmaTarihi=t;
    }

    void temelMaasDuzenle(double m){
        temelMaas=m;
    }

    void adresDuzenle(char* a){
        strcpy(adres,a);
    }
};

int calisanNumarasiOlustur(){
    calisan a;
    int calisanSayisi, uzunluk=sizeof(calisan);

    ifstream dosya("calisan.txt");

    if(!dosya){
        calisanSayisi;
    }
    else{
        dosya.seekg(0,ios::end);
        int sayi=dosya.tellg()/uzunluk;

        if(sayi==0){
            calisanSayisi=0;
        }
        else{
            dosya.seekg(uzunluk*(sayi-1), ios::beg);
            dosya.read((char*)&a, sizeof(a));
            calisanSayisi=a.calisanNumarasiDondur();
        }
    }

    dosya.close();
    return calisanSayisi+1;
}

class aylikOdeme{
    int calisanNumarasi;
    char isim[35];
    int yill, ayy, gunn;
    double aylikTemelMaas;
    double esOdenegi;
    double kiraOdenegi;
    double tasit;
    double brut;
    double kesinti;
    double net;

public:
    void maasHesapla(){
        double enFazlaGun;

        switch(ayy){
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            enFazlaGun=31;
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            enFazlaGun=30;
            break;
        case 2:
            if(yill%4==0 && yill%100!=0 || yil%400==0){
                enFazlaGun=29;
            }
            else{
                enFazlaGun=28;
            }
        }

        aylikTemelMaas*=gunn/enFazlaGun;
        esOdenegi=.55*aylikTemelMaas;
        kiraOdenegi=.35*aylikTemelMaas;
        tasit=.15*aylikTemelMaas;
        brut=aylikTemelMaas+esOdenegi+kiraOdenegi+tasit;
        kesinti=0;
        net=brut-kesinti;
    }

    void maasHesaplaGiris(){
        cout<<"Calisan Numarasini Giriniz: ";
        cin>>calisanNumarasi;
        cout<<"Calisan Ismini Giriniz: ";
        gets(isim);
        cout<<"Ayi Giriniz (1-12): ";
        cin>>ayy;
        cout<<"Yili Giriniz: ";
        cin>>yill;
        cout<<"Calisilan Gun Sayisini Giriniz: ";
        cin>>gunn;

        gunSayisiDogrulama(gunn,ayy,yill);

        cout<<"Temel Maasi Giriniz: ";
        cin>>aylikTemelMaas;
        maasHesapla();
    }

    void goster2(){
        cout<<this->ayy<<" "<<this->yill<<" "<<"Tarihli Maas Bodrosu"<<endl;
        cout<<"Calisan Numarasi: "<<this->calisanNumarasi<<endl;
        cout<<"Calisan Adi: "<<this->isim<<endl;
        cout<<"Temel Maas: "<<this->aylikTemelMaas<<endl;
        cout<<"Kesintiler: "<<this->kesinti<<endl;
        cout<<"Es Odenegi: "<<this->esOdenegi<<endl;
        cout<<"Kira Odenegi: "<<this->kiraOdenegi<<endl;
        cout<<"Tasit: "<<this->tasit<<endl;
        cout<<"Brut Odeme: "<<this->brut<<endl;
        cout<<"Net: "<<this->net<<endl;
    }
};

void tekKayitEkle(){
    ofstream dosya("calisan.txt",ios::out|ios::app);
    calisan a;

    a.calisanGiris();
    dosya.write((char*)&a,sizeof(a));
    dosya.close();
}

void kayitEkle(){
    int n;
    cout<<"Eklenecek Kayit Sayisini Giriniz: ";
    cin>>n;

    for(int k=0;k<n;k++){
        tekKayitEkle();
    }
}

void degistir(){
    int f=0;
    char tercih;

    cout<<"Bilgileri Degistirilecek Calisani Adiyla veya Numarasiyla Belirtiniz."<<endl;
    cout<<"Adiyla Belirtmek Icin 'A'ya Basiniz"<<endl;
    cout<<"Numarasiyla Belirtmek Icin 'B'ye Basiniz"<<endl;
    cin>>tercih;

    if(tercih=='A'){
        calisan a;
        char isim[35], tercih2;

        cout<<"Calisanin Adini Giriniz: ";
        gets(name);
        cout<<"Degistirmek Istediginiz Bilginin Turunu Giriniz."<<endl;
        cout<<"Atama Bilgisi Icin 'D' Giriniz."<<endl;
        cout<<"Dogum Tarihi Bilgisi Icin 'B' Giriniz."<<endl;
        cout<<"Katilma Tarihi Bilgisi Icin 'J' Giriniz."<<endl;
        cout<<"Cinsiyet Bilgisi Icin 'S' Giriniz."<<endl;
        cout<<"Temel Maas Bilgisi Icin 'L' Giriniz."<<endl;
        cout<<"Telefon Numara Bilgisi Icin 'P' Giriniz."<<endl;
        cout<<"Mobil Numara Bilgisi Icin 'M' Giriniz."<<endl;
        cout<<"Adres Bilgisi Icin 'A' Giriniz."<<endl;
        cin>>tercih2;

        ifstream dosyaGirisi("calisan.txt");
        ofstream dosyaCikisi("gecici.txt",ios::out|ios::app);

        switch(tercih2){
        case 'D':
            {
                char d[35];
                cout<<"Yeni Atama Bilgisini Giriniz: ";
                gets(d);

                while(dosyaGirisi.read((char*)&a,sizeof(a))){
                    if(strcmp(a.isimDondur(),isim)==0){
                        a.atamaDuzenle(d);
                        f=1;
                    }
                    dosyaCikisi.write((char*)&a,sizeof(a));
                }
            }
            break;

        case 'B':
            {
                tarih d;
                cout<<"Dogum Gununu Giriniz (22 Mart Ise 22 Giriniz): ";
                cin>>d.gun;
                cout<<"Dogum Ayini Giriniz (22 Mart Ise 3 Giriniz): ";
                cin>>d.ay;
                cout<<"Dogum Yilini Giriniz (Mart 1997 Ise 1997 Giriniz): ";
                cin>>d.yil;

                a.dogumTarihiGiris();

                while(dosyaGirisi.read((char*)&a,sizeof(a))){
                    if(strcmp(a.isimDondur(),isim)==0){
                        a.dogumTarihiDuzenle(d);
                        f=1;
                    }
                    dosyaCikisi.write((char*)&a,sizeof(a));
                }
            }
            break;

        case 'J':
            {
                tarih d;
                cout<<"Katilma Gununu Giriniz (22 Mart Ise 22 Giriniz): ";
                cin>>d.gun;
                cout<<"Katilma Ayini Giriniz (22 Mart Ise 3 Giriniz): ";
                cin>>d.ay;
                cout<<"Katilma Yilini Giriniz (Mart 1997 Ise 1997 Giriniz): ";
                cin>>d.yil;

                a.katilmaTarihiGiris(d);

                while(dosyaGirisi.read((char*)&a,sizeof(a))){
                    if(strcmp(a.isimDondur(),isim)==0){
                        a.katilmaTarihiDuzenle(d);
                        f=1;
                    }
                    dosyaCikisi.write((char*)&a,sizeof(a));
                }
            }
            break;

        case 'S':
            {
                char d;
                cout<<"Yeni Cinsiyeti Giriniz: ";
                cin>>d;

                while(dosyaGirisi.read((char*)&a,sizeof(a))){
                    if(strcmp(a.isimDondur(),isim)==0){
                        a.cinsiyetDuzenle(d);
                        f=1;
                    }
                    dosyaCikisi.write((char*)&a,sizeof(a));
                }
            }
            break;

        case 'L':
            {
                double d;
                cout<<"Yeni Temel Maasi Giriniz: ";
                cin>>d;

                while(dosyaGirisi.read((char*)&a,sizeof(a))){
                    if(strcmp(a.isimDondur(),name)==0){
                        a.temelMaasDuzenle(d);
                        f=1;
                    }
                    dosyaCikisi.write((char*)&a,sizeof(a));
                }
            }
            break;

        case 'P':
            {
                char d[11];

                while(dosyaGirisi.read((char*)&a,sizeof(a))){
                    if(strcmp(a.isimDondur(),name)==0){
                        a.yeniTelefonNumarasiGiris();
                        f=1;
                    }
                    dosyaCikisi.write((char*)&a,sizeof(a));
                }
            }
            break;

        case 'M':
            {
                char d[11];

                while(dosyaGirisi.read((char*)&a,sizeof(a))){
                    if(strcmp(a.isimDondur(),isim)==0){
                        a.yeniMobilGiris();
                        f=1;
                    }
                    dosyaCikisi.write((char*)&a,sizeof(a));
                }
            }
            break;

        case 'A':
            {
                char d[45];
                cout<<"Yeni Adresi Giriniz: ";
                gets(d);

                while(dosyaGirisi.read((char*)&a,sizeof(a))){
                    if(strcmp(a.isimDondur(),isim)==0){
                        a.adresDuzenle(d);
                        f=1;
                    }
                    dosyaCikisi.write((char*)&a,sizeof(a));
                }
            }
            break;
        }

        dosyaGirisi.close();
        dosyaCikisi.close();
    }

    if(tercih=='B'){
        int calisanNumarasi;
        calisan a;

        char isim[35], tercih2;

        cout<<"Calisan Numarasini Giriniz: ";
        cin>>calisanNumarasi;
        cout<<"Degistirmek Istediginiz Bilginin Turunu Giriniz."<<endl;
        cout<<"Atama Bilgisi Icin 'D' Giriniz."<<endl;
        cout<<"Dogum Tarihi Bilgisi Icin 'B' Giriniz."<<endl;
        cout<<"Katilma Tarihi Bilgisi Icin 'J' Giriniz."<<endl;
        cout<<"Cinsiyet Bilgisi Icin 'S' Giriniz."<<endl;
        cout<<"Temel Maas Bilgisi Icin 'L' Giriniz."<<endl;
        cout<<"Telefon Numara Bilgisi Icin 'P' Giriniz."<<endl;
        cout<<"Mobil Numara Bilgisi Icin 'M' Giriniz."<<endl;
        cout<<"Adres Bilgisi Icin 'A' Giriniz."<<endl;
        cin>>tercih2;

        ifstream dosyaGirisi("calisan.txt");
        ofstream dosyaCikisi("gecici.txt",ios::out|ios::app);

        switch(tercih2){
        case 'D':
            {
                char d[35];
                cout<<"Yeni Atamayi Giriniz: ";
                gets(d);

                while(dosyaGirisi.read((char*)&a,sizeof(a))){
                    if(a.calisanNumarasiDondur()==calisanNumarasi){
                        a.atamaDuzenle(d);
                        f=1;
                    }
                    dosyaCikisi.write((char*)&a,sizeof(a));
                }
            }
            break;

        case 'B':
            {
                tarih d;
                cout<<"Dogum Gununu Giriniz (22 Mart Ise 22 Giriniz): ";
                cin>>d.gun;
                cout<<"Dogum Ayini Giriniz (22 Mart Ise 3 Giriniz): ";
                cin>>d.ay;
                cout<<"Dogum Yilini Giriniz (Mart 1997 Ise 1997 Giriniz): ";
                cin>>d.yil;

                while(dosyaGirisi.read((char*)&a,sizeof(a))){
                    if(a.calisanNumarasiDondur()==calisanNumarasi){
                        a.dogumTarihiDuzenle(d);
                        f=1;
                    }
                    dosyaCikisi.write((char*)&a,sizeof(a));
                }
            }
            break;

        case 'J':
            {
                tarih d;
                cout<<"Katilma Gununu Giriniz (22 Mart Ise 22 Giriniz): ";
                cin>>d.gun;
                cout<<"Katilma Ayini Giriniz (22 Mart Ise 3 Giriniz): ";
                cin>>d.ay;
                cout<<"Katilma Yilini Giriniz (Mart 1997 Ise 1997 Giriniz): ";
                cin>>d.yil;

                while(dosyaGirisi.read((char*)&a,sizeof(a))){
                    if(a.calisanNumarasiDondur()==calisanNumarasi){
                        a.katilmaTarihiDuzenle(d);
                        f=1;
                    }
                    dosyaCikisi.write((char*)&a,sizeof(a));
                }
            }
            break;

        case 'S':
            {
                char d;
                cout<<"Cinsiyeti Giriniz: ";
                cin>>d;

                while(dosyaGirisi.read((char*)&a,sizeof(a))){
                    if(a.calisanNumarasiDondur()==calisanNumarasi){
                        a.cinsiyetDuzenle(d);
                        f=1;
                    }
                    dosyaCikisi.write((char*)&a,sizeof(a));
                }
            }
            break;

        case 'L':
            {
                double d;
                cout<<"Temel Maasi Giriniz: ";
                cin>>d;

                while(dosyaGirisi.read((char*)&a,sizeof(a))){
                    if(a.calisanNumarasiDondur()==calisanNumarasi){
                        a.temelMaasDuzenle(d);
                        f=1;
                    }
                    dosyaCikisi.write((char*)&a,sizeof(a));
                }
            }
            break;

        case 'P':
            {
                char d[11];

                while(dosyaGirisi.read((char*)&a,sizeof(a))){
                    if(a.calisanNumarasiDondur()==calisanNumarasi){
                        a.telefonNumarasiGiris();
                        f=1;
                    }
                    dosyaCikisi.write((char*)&a,sizeof(a));
                }
            }
            break;

        case 'M':
            {
                char d[11];

                while(dosyaGirisi.read((char*)&a,sizeof(a))){
                    if(a.calisanNumarasiDondur()==calisanNumarasi){
                        a.mobilGiris();
                        f=1;
                    }
                    dosyaCikisi.write((char*)&a,sizeof(a));
                }
            }
            break;

        case 'A':
            {
                char d[45];
                cout<<"Adresi Giriniz: ";
                gets(d);

                while(dosyaGirisi.read((char*)&a,sizeof(a))){
                    if(a.calisanNumarasiDondur()==calisanNumarasi){
                        a.adresDuzenle(d);
                        f=1;
                    }
                    dosyaCikisi.write((char*)&a,sizeof(a));
                }
            }
            break;
        }

        dosyaGirisi.close();
        dosyaCikisi.close();
    }

    remove("calisan.txt");
    rename("gecici.txt","calisan.txt");

    if(f!=0){
        cout<<"Kayit Degistirildi"<<endl;
    }
    else{
        cout<<"Kayit Bulunamadi"<<endl;
    }
}

void ara(){
    char tercih;

    cout<<"Arama Turunu Giriniz."<<endl;
    cout<<"Calisan Ismi Ile Aramak Icin 'N' Giriniz."<<endl;
    cout<<"Calisan Numarasi Ile Aramak Icin 'U' Giriniz."<<endl;
    cin>>tercih;

    int f=0;

    switch(tercih){
    case 'N':
        {
            calisan a;
            char n[35];

            ifstream dosyaGirisi("calisan.txt");
            cout<<"Ismi Giriniz: ";
            gets(n);

            while(dosyaGirisi.read((char*)&a,sizeof(a))){
                if(strcmp(a.isimDondur(),n)==0){
                    f=1;
                    a.calisaniGoster();
                }
            }
            dosyaGirisi.close();
        }

        break;

    case 'U':
        {
            calisan a;
            int e;

            ifstream dosyaGirisi("calisan.txt");
            cout<<"Calisan Numarasini Giriniz: ";
            cin>>e;

            while(dosyaGirisi.read((char*)&a,sizeof(a))){
                if(a.calisanNumarasiDondur()==e){
                    f=1;
                    a.calisaniGoster();
                }
            }
            dosyaGirisi.close();
        }

        break;
    }

    if(f){
        cout<<"Arama Basarili"<<endl;
    }
    else{
        cout<<"Arama Basarisiz"<<endl;
    }
}

void giris(){
    ofstream dosyaCikisi("aylikOdeme.txt",ios::out|ios::app);
    aylikOdeme a;
    a.maasHesaplaGiris();

    dosyaCikisi.write((char*)&a,sizeof(a));
    dosyaCikisi.close();
}

void rapor(){
    int tercih;

    cout<<"1 -> Calisan Dosyasindan Her Calisanin Ayrintilari"<<endl;
    cout<<"2 -> Maas Beyani"<<endl;
    cout<<"3 -> Maas Bordrosu"<<endl;
    cout<<"Tercihinizi Giriniz (1-3): ";
    cin>>tercih;

    switch(tercih){
    case 1:
        {
            calisan a;
            ifstream dosyaGirisi("Calisan.txt");

            while(dosyaGirisi.read((char*)&a,sizeof(a))){
                a.calisaniGoster();
            }
            dosyaGirisi.close();
            break;
        }

    case 2:
        {
            calisan a;
            ifstream dosyaGirisi("Calisan.txt");

            while(dosyaGirisi.read((char*)&a,sizeof(a))){
                a.goster1();
            }
            dosyaGirisi.close();
            break;
        }

    case 3:
        {
            aylikOdeme a;
            ifstream dosyaGirisi("aylikOdeme.txt");

            while(dosyaGirisi.read((char*)&a,sizeof(a))){
                a.goster2();
            }

            dosyaGirisi.close();
            break;
        }

    default:
        cout<<"Gecersiz Tercih"<<endl;
    }
}

int main(){
    int tercih;

    do{
        cout<<"1 -> Calisan Dosyasina Yeni Calisanlar Icin Kayitlarin Eklenmesi"<<endl;
        cout<<"2 -> Calisan Dosyasindaki Mevcut Kayitlarin Degistirilmesi (Calisan Numarasi ve Adi Haric)"<<endl;
        cout<<"3 -> Calisan Dosyalarinda Arama (Calisan Numarasini ve Adini Kullanarak)"<<endl;
        cout<<"4 -> Aylik Odeme Dosyasina Her Calisanin Calistigi Gun Sayisi ve Diger Kesintilerin Girilmesi"<<endl;
        cout<<"5 -> Rapor (Ekran/Yazici)"<<endl;
        cout<<"0 -> Menuden Cik"<<endl;
        cout<<"Tercihinizi Giriniz: ";
        cin>>tercih;

        switch(tercih){
        case 1:
            kayitEkle();
            break;
        case 2:
            degistir();
            break;
        case 3:
            ara();
            break;
        case 4:
            giris();
            break;
        case 5:
            rapor();
            break;
        default:
            cout<<"Gecersiz Giris"<<endl;
        }

        cout<<endl;
    }

    while(tercih);
    getch();
}



















