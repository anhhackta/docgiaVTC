#ifndef DOCGIA_H
#define DOCGIA_H

#include <iostream>
#include <string>
#include <vector>

class DocGia {
protected:
    std::string hoten;
    std::string ngaylapthe;
    int sothanghl;

public:
    DocGia(const std::string& hoten, const std::string& ngaylapthe, int sothanghl);
    virtual ~DocGia() = default;

    virtual void nhap();
    virtual void xuat() const;
    virtual int tinhTien() const = 0;

    std::string getHoten() const;
};

class TreEm : public DocGia {
private:
    std::string ngbaoho;

public:
    TreEm(const std::string& hoten, const std::string& ngaylapthe, int sothanghl, const std::string& ngbaoho);
    void nhap() override;
    void xuat() const override;
    int tinhTien() const override;
};

class NguoiLon : public DocGia {
private:
    std::string cmnd;

public:
    NguoiLon(const std::string& hoten, const std::string& ngaylapthe, int sothanghl, const std::string& cmnd);
    void nhap() override;
    void xuat() const override;
    int tinhTien() const override;
};

#endif // DOCGIA_H