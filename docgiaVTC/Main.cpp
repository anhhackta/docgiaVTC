#include <iostream>
#include <vector>
#include "DocGia.h"
using namespace std;
void nhapDocGia(vector<DocGia*>& ds);
void xuatDocGia(const vector<DocGia*>& ds);
void timKiemDocGia(const vector<DocGia*>& ds, const string& hoten);

int main() {
    vector<DocGia*> ds;
    int choice;

    do {
        cout << "\n--- Quan ly thu vien ---\n";
        cout << "1. Nhap thong tin doc gia\n";
        cout << "2. Xuat thong tin doc gia\n";
        cout << "3. Tim kiem doc gia theo ho ten\n";
        cout << "0. Thoat\n";
        cout << "Nhap lua chon: ";
        cin >> choice;
        cin.ignore(); // Ignore the newline character left in the buffer

        switch (choice) {
        case 1:
            nhapDocGia(ds);
            break;
        case 2:
            xuatDocGia(ds);
            break;
        case 3: {
            string hoten;
            cout << "Nhap ho ten can tim: ";
            getline(cin, hoten);
            timKiemDocGia(ds, hoten);
            break;
        }
        case 0:
            cout << "Thoat chuong trinh.\n";
            break;
        default:
            cout << "Lua chon khong hop le!\n";
            break;
        }
    } while (choice != 0);

    // Free dynamically allocated memory
    for (DocGia* docGia : ds) {
        delete docGia;
    }

    return 0;
}

void nhapDocGia(vector<DocGia*>& ds) {
    int type;
    cout << "Nhap loai doc gia (1 - Tre em, 2 - Nguoi lon): ";
    cin >> type;
    cin.ignore(); // Ignore the newline character left in the buffer

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
        cout << "Loai doc gia khong hop le!\n";
    }
}

void xuatDocGia(const vector<DocGia*>& ds) {
    for (const DocGia* docGia : ds) {
        docGia->xuat();
        cout << "----------------------\n";
    }
}

void timKiemDocGia(const vector<DocGia*>& ds, const string& hoten) {
    bool found = false;
    for (const DocGia* docGia : ds) {
        if (docGia->getHoten() == hoten) {
            docGia->xuat();
            found = true;
        }
    }

    if (!found) {
        cout << "Khong tim thay doc gia co ten: " << hoten << endl;
    }
}