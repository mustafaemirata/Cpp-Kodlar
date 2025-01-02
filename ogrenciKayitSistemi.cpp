#include <iostream>
#include <string>
using namespace std;

// Öğrenci yapısı (Node)
template <class T>
struct Ogrenci
{
    string ad;
    string soyad;
    int yas;
    string sinif;
    Ogrenci<T> *next; // Bir sonraki öğrenciye işaretçi

    // Yapıcı
    Ogrenci(string a, string s, int y, string sinif)
        : ad(a), soyad(s), yas(y), sinif(sinif), next(nullptr) {}
};

// Bağlı liste (Linked List)
template <class T>
class OgrenciListesi
{
private:
    Ogrenci<T> *head; // Listenin başı

public:
    // Yapıcı
    OgrenciListesi() : head(nullptr) {}

    // Yeni bir öğrenci ekleme
    void ekle(string ad, string soyad, int yas, string sinif)
    {
        Ogrenci<T> *yeniOgrenci = new Ogrenci<T>(ad, soyad, yas, sinif);
        if (head == nullptr)
        {
            head = yeniOgrenci; // Liste boşsa başı yeni öğrenci yap
        }
        else
        {
            Ogrenci<T> *temp = head;
            while (temp->next != nullptr)
            {
                temp = temp->next; // Son düğüme kadar ilerle
            }
            temp->next = yeniOgrenci; // Son düğüme ekle
        }
    }

    // Öğrenci listesini yazdırma
    void yazdir()
    {
        Ogrenci<T> *temp = head;
        while (temp != nullptr)
        {
            cout << "Ad: " << temp->ad << ", Soyad: " << temp->soyad
                 << ", Yas: " << temp->yas << ", Sinif: " << temp->sinif << endl;
            temp = temp->next; // Bir sonraki düğüme geç
        }
    }

    // Bir öğrenciyi silme
    void sil(string ad)
    {
        if (head == nullptr)
        {
            cout << "Liste bos, silinecek ogrenci yok!" << endl;
            return;
        }

        if (head->ad == ad)
        {
            Ogrenci<T> *temp = head;
            head = head->next; // Başı bir sonraki düğüme kaydır
            delete temp;
            cout << ad << " isimli ogrenci silindi." << endl;
            return;
        }

        Ogrenci<T> *temp = head;
        while (temp->next != nullptr && temp->next->ad != ad)
        {
            temp = temp->next; // Silinecek düğümü bul
        }

        if (temp->next == nullptr)
        {
            cout << ad << " isimli ogrenci bulunamadi." << endl;
        }
        else
        {
            Ogrenci<T> *silinecek = temp->next;
            temp->next = temp->next->next; // Aradaki düğümü atla
            delete silinecek;
            cout << ad << " isimli ogrenci silindi." << endl;
        }
    }

    // Yapıcı
    ~OgrenciListesi()
    {
        while (head != nullptr)
        {
            Ogrenci<T> *temp = head;
            head = head->next;
            delete temp; // Bellek temizleme
        }
    }
};

int main()
{
    // Template tabanlı öğrenci listesi
    OgrenciListesi<string> liste;

    // Öğrenci ekleme
    liste.ekle("Ali", "Veli", 16, "10-A");
    liste.ekle("Ayse", "Demir", 17, "11-B");
    liste.ekle("Mehmet", "Çelik", 15, "9-C");

    // Listeyi yazdır
    cout << "Ogrenci Listesi:" << endl;
    liste.yazdir();

    // Öğrenci silme
    liste.sil("Ayse");

    // Listeyi tekrar yazdır
    cout << "\nGuncel Ogrenci Listesi:" << endl;
    liste.yazdir();

    return 0;
}
