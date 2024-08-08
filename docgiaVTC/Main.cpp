#include <iostream>
#include <vector>
#include "DocGia.h"

void nhapDocGia(std::vector<DocGia*>& ds);
void xuatDocGia(const std::vector<DocGia*>& ds);
void timKiemDocGia(const std::vector<DocGia*>& ds, const std::string& hoten);

int main() {
    std::vector<DocGia*> ds;
    int choice;

    do {
        std::cout << "\n--- Quan ly thu vien ---\n";
        std::cout << "1. Nhap thong tin doc gia\n";
        std::cout << "2. Xuat thong tin doc gia\n";
        std::cout << "3. Tim kiem doc gia theo ho ten\n";
        std::cout << "0. Thoat\n";
        std::cout << "Nhap lua chon: ";
        std::cin >> choice;
        std::cin.ignore(); // Ignore the newline character left in the buffer

        switch (choice) {
        case 1:
            nhapDocGia(ds);
            break;
        case 2:
            xuatDocGia(ds);
            break;
        case 3: {
            std::string hoten;
            std::cout << "Nhap ho ten can tim: ";
            std::getline(std::cin, hoten);
            timKiemDocGia(ds, hoten);
            break;
        }
        case 0:
            std::cout << "Thoat chuong trinh.\n";
            break;
        default:
            std::cout << "Lua chon khong hop le!\n";
            break;
        }
    } while (choice != 0);

    // Free dynamically allocated memory
    for (DocGia* docGia : ds) {
        delete docGia;
    }

    return 0;
}

void nhapDocGia(std::vector<DocGia*>& ds) {
    int type;
    std::cout << "Nhap loai doc gia (1 - Tre em, 2 - Nguoi lon): ";
    std::cin >> type;
    std::cin.ignore(); // Ignore the newline character left in the buffer

    if (type == 1) {
        TreEm* treEm = new TreEm("", "", 0, "");
        treEm->nhap();
        ds.push_back(treEm);
    }
    else if (type == 2) {
        NguoiLon* nguoiLon = new NguoiLon("", "", 0, "");
        nguoiLon->nhap();
        ds.push_back(nguoiLon);
    }
    else {
        std::cout << "Loai doc gia khong hop le!\n";
    }
}

void xuatDocGia(const std::vector<DocGia*>& ds) {
    for (const DocGia* docGia : ds) {
        docGia->xuat();
        std::cout << "----------------------\n";
    }
}

void timKiemDocGia(const std::vector<DocGia*>& ds, const std::string& hoten) {
    bool found = false;
    for (const DocGia* docGia : ds) {
        if (docGia->getHoten() == hoten) {
            docGia->xuat();
            found = true;
        }
    }

    if (!found) {
        std::cout << "Khong tim thay doc gia co ten: " << hoten << std::endl;
    }
}