#include <iostream>
#include <string>

using namespace std

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
        cout << "Nhap han su dung (dd/mm/yyyy): ";
        getline(cin, hansudung);
    }

    void xuat() const {
        cout << "Ma: " << mathuoc 
             << " | Ten: " << tenthuoc 
             << " | Hoat chat: " << hoatchat 
             << " | DVT: " << donvitinh 
             << " | Gia: " << giaban 
             << " | SL Ton: " << soluongton 
             << " | HSD: " << hansudung << endl;
    }

    string getmathuoc() const {
        return mathuoc;
    }

    string gettenthuoc() const {
        return tenthuoc;
    }

    string gethansudung() const {
        return hansudung;
    }
};

void nhapDanhSach(Thuoc ds[], int &n) {
    do {
        cout << "Nhap so luong thuoc (toi da 200): ";
        cin >> n;
        if (n <= 0 || n >= 200) {
            cout << "So luong khong hop le! Vui long nhap lai! .\n";
        }
    } while (n <= 0 || n >= 200);

    cout << "\n=== NHAP DANH SACH THUOC ===\n";
    for (int i = 0; i < n; i++) {
        cout << "\nNhap thong tin cho thuoc thu " << i + 1 << ":\n";
        ds[i].nhap();
    }
}

void inDanhSach(Thuoc ds[], int n) {
    if (n == 0) {
        cout << "\nDanh sach thuoc hien dang rong!\n";
        return;
    }

    cout << "\n=== DANH SACH THUOC HIEN CO (" << n << " mat hang) ===\n";
    for (int i = 0; i < n; i++) {
        cout << i + 1 << ". ";
        ds[i].xuat();
    }
}

int layNgay(string s) {
    if (s.length() < 10) return 0;
    return (s[0] - '0') * 10 + (s[1] - '0');
}

int layThang(string s) {
    if (s.length() < 10) return 0;
    return (s[3] - '0') * 10 + (s[4] - '0');
}

int layNam(string s) {
    if (s.length() < 10) return 0;
    return (s[6] - '0') * 1000 + (s[7] - '0') * 100 + (s[8] - '0') * 10 + (s[9] - '0');
}

void sapXepTheoHSD(Thuoc ds[], int n) {
    if (n == 0) {
        cout << "\nDanh sach rong, khong the sap xep!\n";
        return;
    }

    Thuoc temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            int nam1 = layNam(ds[i].gethansudung());
            int nam2 = layNam(ds[j].gethansudung());  
            int thang1 = layThang(ds[i].gethansudung());
            int thang2 = layThang(ds[j].gethansudung());
            int ngay1 = layNgay(ds[i].gethansudung());
            int ngay2 = layNgay(ds[j].gethansudung());
            
            if (nam1 > nam2 || (nam1 == nam2 && thang1 > thang2) || (nam1 == nam2 && thang1 == thang2 && ngay1 > ngay2)) {
                temp = ds[i];
                ds[i] = ds[j];
                ds[j] = temp;
            }
        }
    }
    cout << "\nDA SAP XEP DANH SACH THEO HAN SU DUNG TANG DAN!\n";
    inDanhSach(ds, n);
}

void timKiemThuoc(Thuoc ds[], int n) {
    if (n == 0) {
        cout << "\nDanh sach rong, khong th? tim kiem!\n";
        return;
    }

    string tuKhoa;
    cout << "NHAP MA HOAC TEN THUOC CAN TIM KIEM: ";
    cin.ignore();
    getline(cin, tuKhoa);
    
    bool timThay = false;
    for (int i = 0; i < n; i++) {
        if (ds[i].getmathuoc() == tuKhoa || ds[i].gettenthuoc() == tuKhoa) {
            if (!timThay) {
                cout << "\nTHONG TIN THUOC CAN TIM KIEM:\n";
                timThay = true;
            }
            ds[i].xuat();
        }
    }

    if (!timThay) {
        cout << "\nKHONG TIM THAY THUOC HOAC MA THUOC KHONG TON TAI!\n";
    }
}

void boSungThuoc(Thuoc ds[], int &n) {
    if (n >= 200) {
        cout << "\nDanh sach da day, khong the them thuoc moi!\n";
        return;
    }

    int viTri;
    cout << "Nhap vi tri can bo sung (1 den " << n + 1 << "): ";
    cin >> viTri;

    if (viTri < 1 || viTri > n + 1) {
        cout << "Vi tri khong hop le!\n";
        return;
    }

    Thuoc tMoi;
    cout << "\nNhap thong tin thuoc moi can bo sung:\n";
    tMoi.nhap();

    int idx = viTri - 1;
    for (int i = n; i > idx; i--) {
        ds[i] = ds[i - 1];
    }
    ds[idx] = tMoi;
    n++;

    cout << "==> Bo sung thuoc thanh cong vao vi tri " << viTri << "!\n";
}

void xoaThuoc(Thuoc ds[], int &n) {
    if (n == 0) {
        cout << "\nDanh sach rong, khong the xoa!\n";
        return;
    }

    int viTri;
    cout << "Nhap vi tri thuoc me xoa (1 den " << n << "): ";
    cin >> viTri;

    if (viTri < 1 || viTri > n) {
        cout << "Vi tri xoa khong hop le!\n";
        return;
    }

    int idx = viTri - 1;
    for (int i = idx; i < n - 1; i++) {
        ds[i] = ds[i + 1];
    }
    n--;

    cout << "==> Xoa thuoc tai vi tri " << viTri << " thanh cong!\n";
}

void hienThiMenu() {
    cout << "\n==================================================\n";
    cout << "        QUAN LY DANH SACH THUOC                   \n";
    cout << "==================================================\n";
    cout << " 1. Nhap danh sach thuoc (0 < n < 200)            \n";
    cout << " 2. Hien thi danh sach thuoc                      \n";
    cout << " 3. Sap xep danh sach theo han su dung (tang dan) \n";
    cout << " 4. Tim kiem thuoc (theo Ma thuoc hoac Ten thuoc) \n";
    cout << " 5. Bo sung 1 loai thuoc vao vi tri cho truoc     \n";
    cout << " 6. Xoa 1 loai thuoc tai vi tri cho truoc        \n";
    cout << " 0. Thoat chuong trinh                            \n";
    cout << "==================================================\n";
    cout << "Vui long chon (0-6): ";
}

int main() {
    Thuoc ds[200]; 
    int n = 0;     
    int luaChon;

    do {
        hienThiMenu();
        cin >> luaChon;

        switch (luaChon) {
            case 1:
                nhapDanhSach(ds, n);
                break;
            case 2:
                inDanhSach(ds, n);
                break;
            case 3:
                sapXepTheoHSD(ds, n);
                break;
            case 4:
                timKiemThuoc(ds, n);
                break;
            case 5:
                boSungThuoc(ds, n);
                break;
            case 6:
                xoaThuoc(ds, n);
                break;
            case 0:
                cout << "\nDa thoat chuong trinh. Cam on ban!\n";
                break;
            default:
                cout << "\nLua chon khong hop le! Vui long chon tu 0 den 6.\n";
        }
    } while (luaChon != 0);

    return 0;
}
