#include "DocGia.h"

// Base Class DocGia
DocGia::DocGia(const std::string& hoten, const std::string& ngaylapthe, int sothanghl)
    : hoten(hoten), ngaylapthe(ngaylapthe), sothanghl(sothanghl) {}

void DocGia::nhap() {
    std::cout << "Nhap ho ten: ";
    std::getline(std::cin, hoten);
    std::cout << "Nhap ngay lap the (dd/mm/yyyy): ";
    std::getline(std::cin, ngaylapthe);
    std::cout << "Nhap so thang hieu luc: ";
    std::cin >> sothanghl;
    std::cin.ignore(); // Ignore the newline character left in the buffer
}

void DocGia::xuat() const {
    std::cout << "Ho ten: " << hoten << std::endl;
    std::cout << "Ngay lap the: " << ngaylapthe << std::endl;
    std::cout << "So thang hieu luc: " << sothanghl << std::endl;
}

std::string DocGia::getHoten() const {
    return hoten;
}

// Derived Class TreEm
TreEm::TreEm(const std::string& hoten, const std::string& ngaylapthe, int sothanghl, const std::string& ngbaoho)
    : DocGia(hoten, ngaylapthe, sothanghl), ngbaoho(ngbaoho) {}

void TreEm::nhap() {
    DocGia::nhap();
    std::cout << "Nhap ten nguoi bao ho: ";
    std::getline(std::cin, ngbaoho);
}

void TreEm::xuat() const {
    DocGia::xuat();
    std::cout << "Nguoi bao ho: " << ngbaoho << std::endl;
    std::cout << "Tien the: " << tinhTien() << std::endl;
}

int TreEm::tinhTien() const {
    return sothanghl * 5000;
}

// Derived Class NguoiLon
NguoiLon::NguoiLon(const std::string& hoten, const std::string& ngaylapthe, int sothanghl, const std::string& cmnd)
    : DocGia(hoten, ngaylapthe, sothanghl), cmnd(cmnd) {}

void NguoiLon::nhap() {
    DocGia::nhap();
    std::cout << "Nhap CMND: ";
    std::getline(std::cin, cmnd);
}

void NguoiLon::xuat() const {
    DocGia::xuat();
    std::cout << "CMND: " << cmnd << std::endl;
    std::cout << "Tien the: " << tinhTien() << std::endl;
}

int NguoiLon::tinhTien() const {
    return sothanghl * 10000;
}