#ifndef DOCGIA_H
#define DOCGIA_H

#include <iostream>
#include <string>
#include <vector>
using namespace std;
class DocGia {
protected:
    string hoten;
    string ngaylapthe;
    int sothanghl;

public:
    DocGia(const string& hoten, const string& ngaylapthe, int sothanghl);
    virtual ~DocGia() = default;

    virtual void nhap();
    virtual void xuat() const;
    virtual int tinhTien() const = 0;

    string getHoten() const;
};

class TreEm : public DocGia {
private:
    string ngbaoho;

public:
    TreEm(const string& hoten, const string& ngaylapthe, int sothanghl, const string& ngbaoho);
    void nhap() override;
    void xuat() const override;
    int tinhTien() const override;
};

class NguoiLon : public DocGia {
private:
    string cmnd;

public:
    NguoiLon(const string& hoten, const string& ngaylapthe, int sothanghl, const string& cmnd);
    void nhap() override;
    void xuat() const override;
    int tinhTien() const override;
};

#endif // DOCGIA_H