#include "DocGia.h"
using namespace std;
// Base Class DocGia
DocGia::DocGia(const string& hoten, const string& ngaylapthe, int sothanghl)
    : hoten(hoten), ngaylapthe(ngaylapthe), sothanghl(sothanghl) {}

void DocGia::nhap() {
    cout << "Nhap ho ten: ";
    getline(cin, hoten);
    cout << "Nhap ngay lap the (dd/mm/yyyy): ";
    getline(cin, ngaylapthe);
    cout << "Nhap so thang hieu luc: ";
    cin >> sothanghl;
    cin.ignore(); // Ignore the newline character left in the buffer
}

void DocGia::xuat() const {
    cout << "Ho ten: " << hoten << endl;
    cout << "Ngay lap the: " << ngaylapthe << endl;
    cout << "So thang hieu luc: " << sothanghl << endl;
}

string DocGia::getHoten() const {
    return hoten;
}

// Derived Class TreEm
TreEm::TreEm(const string& hoten, const string& ngaylapthe, int sothanghl, const string& ngbaoho)
    : DocGia(hoten, ngaylapthe, sothanghl), ngbaoho(ngbaoho) {}

void TreEm::nhap() {
    DocGia::nhap();
    cout << "Nhap ten nguoi bao ho: ";
    getline(cin, ngbaoho);
}

void TreEm::xuat() const {
    DocGia::xuat();
    cout << "Nguoi bao ho: " << ngbaoho << endl;
    cout << "Tien the: " << tinhTien() << endl;
}

int TreEm::tinhTien() const {
    return sothanghl * 5000;
}

// Derived Class NguoiLon
NguoiLon::NguoiLon(const string& hoten, const string& ngaylapthe, int sothanghl, const string& cmnd)
    : DocGia(hoten, ngaylapthe, sothanghl), cmnd(cmnd) {}

void NguoiLon::nhap() {
    DocGia::nhap();
    cout << "Nhap CMND: ";
    getline(cin, cmnd);
}

void NguoiLon::xuat() const {
    DocGia::xuat();
    cout << "CMND: " << cmnd << endl;
    cout << "Tien the: " << tinhTien() << endl;
}

int NguoiLon::tinhTien() const {
    return sothanghl * 10000;
}