#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// Định nghĩa số nhân viên tối đa
const int MAX_NHANVIEN = 100;

// Lớp ConNguoi
class ConNguoi {
protected:
    string maSo;
    string hoTen;
    string ngaySinh;

public:
    ConNguoi() {}

    void nhap() {
        cout << "Nhap ma so: ";
        cin >> maSo;
        cin.ignore();
        cout << "Nhap ho ten: ";
        getline(cin, hoTen);
        cout << "Nhap ngay sinh (dd/mm/yyyy): ";
        cin >> ngaySinh;
    }

    void xuat() {
        cout << "Ma so: " << maSo << ", Ho ten: " << hoTen << ", Ngay sinh: " << ngaySinh;
    }

    string getMaSo() { return maSo; }
};

// Lớp NhanVien kế thừa từ ConNguoi
class NhanVien : public ConNguoi {
private:
    double luong;
    string ngayNhanViec;

public:
    void nhap() {
        ConNguoi::nhap();
        cout << "Nhap luong: ";
        cin >> luong;
        cout << "Nhap ngay nhan viec (dd/mm/yyyy): ";
        cin >> ngayNhanViec;
    }

    void xuat() {
        ConNguoi::xuat();
        cout << ", Luong: " << fixed << setprecision(2) << luong << ", Ngay nhan viec: " << ngayNhanViec << endl;
    }

    double getLuong() { return luong; }
    string getNgayNhanViec() { return ngayNhanViec; }

    void setLuong(double l) { luong = l; }
    void setNgayNhanViec(string date) { ngayNhanViec = date; }
};

// Lớp quản lý nhân viên
class QLNhanVien {
private:
    NhanVien danhSach[MAX_NHANVIEN];
    int soLuong;

public:
    QLNhanVien() { soLuong = 0; }

    void nhapDanhSach() {
        cout << "Nhap so luong nhan vien: ";
        cin >> soLuong;
        for (int i = 0; i < soLuong; i++) {
            cout << "\nNhap thong tin nhan vien thu " << i + 1 << ":\n";
            danhSach[i].nhap();
        }
    }

    void inDanhSach() {
        cout << "\nDanh sach nhan vien:\n";
        for (int i = 0; i < soLuong; i++) {
            danhSach[i].xuat();
        }
    }

    void sapXepTheoLuongGiamDan() {
        for (int i = 0; i < soLuong - 1; i++) {
            for (int j = i + 1; j < soLuong; j++) {
                if (danhSach[i].getLuong() < danhSach[j].getLuong()) {
                    swap(danhSach[i], danhSach[j]);
                }
            }
        }
    }

    void timNhanVien() {
        string ma;
        cout << "\nNhap ma so nhan vien can tim: ";
        cin >> ma;
        for (int i = 0; i < soLuong; i++) {
            if (danhSach[i].getMaSo() == ma) {
                danhSach[i].xuat();
                return;
            }
        }
        cout << "Khong tim thay nhan vien!\n";
    }

    void xuatNhanVienSauNgay() {
        string ngay;
        cout << "\nNhap ngay (dd/mm/yyyy): ";
        cin >> ngay;
        cout << "\nDanh sach nhan vien vao lam sau " << ngay << ":\n";
        for (int i = 0; i < soLuong; i++) {
            if (danhSach[i].getNgayNhanViec() > ngay) {  // So sánh chuỗi
                danhSach[i].xuat();
            }
        }
    }

    void demNhanVienTheoNam() {
        string nam;
        cout << "\nNhap nam (yyyy): ";
        cin >> nam;
        int count = 0;
        for (int i = 0; i < soLuong; i++) {
            if (danhSach[i].getNgayNhanViec().substr(6, 4) == nam) {  // So sánh năm
                count++;
            }
        }
        cout << "So luong nhan vien vao lam trong nam " << nam << ": " << count << endl;
    }

    void suaNhanVien() {
        string ma;
        cout << "\nNhap ma so nhan vien can sua: ";
        cin >> ma;
        for (int i = 0; i < soLuong; i++) {
            if (danhSach[i].getMaSo() == ma) {
                cout << "Nhap thong tin moi cho nhan vien:\n";
                danhSach[i].nhap();
                return;
            }
        }
        cout << "Khong tim thay nhan vien!\n";
    }

    void xoaNhanVien() {
        string ma;
        cout << "\nNhap ma so nhan vien can xoa: ";
        cin >> ma;
        for (int i = 0; i < soLuong; i++) {
            if (danhSach[i].getMaSo() == ma) {
                for (int j = i; j < soLuong - 1; j++) {
                    danhSach[j] = danhSach[j + 1];
                }
                soLuong--;
                cout << "Da xoa nhan vien.\n";
                return;
            }
        }
        cout << "Khong tim thay nhan vien!\n";
    }
};

// Hàm menu
int main() {
    QLNhanVien ql;
    int choice;
    do {
        cout << "\n--- MENU QUAN LY NHAN VIEN ---\n";
        cout << "1. Nhap danh sach nhan vien\n";
        cout << "2. In danh sach nhan vien\n";
        cout << "3. Sap xep danh sach theo luong giam dan\n";
        cout << "4. Tim nhan vien theo ma so\n";
        cout << "5. Xuat nhan vien vao lam sau ngay nhap vao\n";
        cout << "6. Dem nhan vien vao lam theo nam\n";
        cout << "7. Sua thong tin nhan vien theo ma so\n";
        cout << "8. Xoa thong tin nhan vien theo ma so\n";
        cout << "0. Thoat\n";
        cout << "Lua chon cua ban: ";
        cin >> choice;

        switch (choice) {
            case 1:
                ql.nhapDanhSach();
                break;
            case 2:
                ql.inDanhSach();
                break;
            case 3:
                ql.sapXepTheoLuongGiamDan();
                cout << "Da sap xep theo luong giam dan.\n";
                break;
            case 4:
                ql.timNhanVien();
                break;
            case 5:
                ql.xuatNhanVienSauNgay();
                break;
            case 6:
                ql.demNhanVienTheoNam();
                break;
            case 7:
                ql.suaNhanVien();
                break;
            case 8:
                ql.xoaNhanVien();
                break;
            case 0:
                cout << "Thoat chuong trinh.\n";
                break;
            default:
                cout << "Lua chon khong hop le.\n";
        }
    } while (choice != 0);

    return 0;
}
