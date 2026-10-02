#include <iostream>
#include <string>
using namespace std;

class Thuoc {
private:
    string mathuoc;
    string tenthuoc;
    string hoatchat;
    string donvitinh;
    float giaban;
    int soluongton;
    string hansudung;

public:
    Thuoc() {
        mathuoc = "";
        tenthuoc = "";
        hoatchat = "";
        donvitinh = "";
        giaban = 0;
        soluongton = 0;
        hansudung = "";
    }

    void nhap() {
        cout << "Nhap ma thuoc: ";
        cin >> mathuoc;

        cin.ignore();
        cout << "Nhap ten thuoc: ";
        getline(cin, tenthuoc);

        cout << "Nhap hoat chat: ";
        getline(cin, hoatchat);

        cout << "Nhap don vi tinh: ";
        getline(cin, donvitinh);

        cout << "Nhap gia ban: ";
        cin >> giaban;

        cout << "Nhap so luong ton: ";
        cin >> soluongton;

        cin.ignore();
        cout << "Nhap han su dung: ";
        getline(cin, hansudung);
    }

    void xuat() {
        cout << "Ma thuoc: " << mathuoc << endl;
        cout << "Ten thuoc: " << tenthuoc << endl;
        cout << "Hoat chat: " << hoatchat << endl;
        cout << "Don vi tinh: " << donvitinh << endl;
        cout << "Gia ban: " << giaban << endl;
        cout << "So luong ton: " << soluongton << endl;
        cout << "Han su dung: " << hansudung << endl;
    }

    string getmathuoc() {
        return mathuoc;
    }

    string gettenthuoc() {
        return tenthuoc;
    }

    string gethansudung() {
        return hansudung;
    }
};

