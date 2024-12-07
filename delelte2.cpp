#include<iostream>
#include<string>
#include<string.h>

using namespace std;

struct Date {
    int ngay;
    int thang;
    int nam;
};

class NuocGiaiKhat {
private:
    string maNuoc;
    string tenNuoc;
    Date hanSuDung;
    float trongLuong;

public:
    NuocGiaiKhat() {};

    string getMaNuoc() { return maNuoc; }
    string getTenNuoc() { return tenNuoc; }
    Date getHanSuDung() { return hanSuDung; }
    float getTrongLuong() { return trongLuong; }

    void setMaNuoc(string ma) { maNuoc = ma; }

    void nhap() {
        cout << "Nhap ten nuoc" << endl;
        getline(cin, tenNuoc);
        cout << "Nhap han su dung" << endl;
        cin >> hanSuDung.ngay >> hanSuDung.thang >> hanSuDung.nam;
        cout << "Nhap trong luong " << endl;
        cin >> trongLuong;
    }

    void xuat() {
        cout << "--------------------------------------------------------" << endl;
        cout << "Thong tin san pham:" << endl;
        cout << "Ma nuoc: " << maNuoc << endl;
        cout << "Ten Nuoc: " << tenNuoc << endl;
        cout << "Han SU Dung: " << hanSuDung.ngay << "/" << hanSuDung.thang << "/" << hanSuDung.nam << endl;
        cout << "TrongLuong: " << trongLuong << endl;
    }

    float getGiaNuocNgot() {
        return trongLuong * 300;
    }
};

class NuocNgot : public NuocGiaiKhat {
private:
    float doNgot;
    static int demNuocNgot;  // Biến static để đếm số lượng nuoc ngọt

public:
    NuocNgot() {
        demNuocNgot++;  // Tăng biến đếm mỗi khi tạo đối tượng mới
        setMaNuoc("NN" + to_string(100 + demNuocNgot));  // Tạo mã nuoc ngọt tự động
    }

    float getDoNgot() { return doNgot; }

    void nhap() {
        NuocGiaiKhat::nhap();
        cout << "Nhap do ngot " << endl;
        cin >> doNgot;
    }

    void xuat() {
        NuocGiaiKhat::xuat();
        cout << "Do ngot: " << doNgot << endl;
        cout << "Co gia tien: " << getGiaNuocNgot() << endl;
    }

    static int getDemNuocNgot() {
        return demNuocNgot;
    }
};

// Khởi tạo static biến
int NuocNgot::demNuocNgot = 0;

class NuocCoGas : public NuocGiaiKhat {
private:
    string xuatXu;
    static int demNuocCoGas;  // Biến static để đếm số lượng nuoc có gas

public:
    NuocCoGas() {
        demNuocCoGas++;  // Tăng biến đếm mỗi khi tạo đối tượng mới
        setMaNuoc("NG" + to_string(100 + demNuocCoGas));  // Tạo mã nuoc có gas tự động
    }

    string getXuatXu() { return xuatXu; }

    void nhap() {
        NuocGiaiKhat::nhap();
        cin.ignore();
        cout << "Nhap xuat xu:" << endl;
        getline(cin, xuatXu);
    }

    float getGiaNuocCoGas() {
        if (xuatXu == "Chau A") {
            return getGiaNuocNgot() * 0.95;
        } else if (xuatXu == "Chau Au") {
            return getGiaNuocNgot() * 1.5;
        } else {
            cout << "Xuat xu khong hop le" << endl;
            return 0;
        }
    }
    void xuat() {
        NuocGiaiKhat::xuat();
        cout << "Xuat xu: " << xuatXu << endl;
        cout << "Co gia tien la: " << getGiaNuocCoGas() << endl;
    }

    static int getDemNuocCoGas() {
        return demNuocCoGas;
    }
    void thongKeDanhSach(NuocCoGas a[],int n){};
};

// Khởi tạo static biến
int NuocCoGas::demNuocCoGas = 0;

void nhapDSNuocNgot(NuocNgot a[], int &n) {
    a[n].nhap();  // Gọi nhap() cho từng đối tượng trong mảng
    n++;  // Tăng số lượng nước ngọt đã nhập
}

void nhapDSNuocCoGas(NuocCoGas a[], int &n) {
    a[n].nhap();  // Gọi nhap() cho từng đối tượng trong mảng
    n++;  // Tăng số lượng nước có gas đã nhập
}

void xuatDSNuocNgot(NuocNgot a[], int n) {
    cout << "Danh sach san pham nuoc ngot la:" << endl;
    for (int i = 0; i < n; i++) {
        a[i].xuat();  // Gọi xuat() cho từng đối tượng trong mảng
    }
}

void xuatDSNuocCoGas(NuocCoGas a[], int n) {
    cout << "Danh sach san pham nuoc co gas la: " << endl;
    for (int i = 0; i < n; i++) {
        a[i].xuat();  // Gọi xuat() cho từng đối tượng trong mảng
    }
}
void tinhTongTien(NuocGiaiKhat a[],NuocCoGas b[], int n) {
    double tongTien=0;
    for(int i=0;i<n;i++){
        tongTien+=a[i].getGiaNuocNgot()+b[i].getGiaNuocCoGas();
    }
    cout<<"Tong tien phai tra la: "<<tongTien<<endl;
}
void timKiemTheoHanSD(NuocGiaiKhat a[], int n) {
    cout << "Nhap han su dung can tim kiem: " << endl;
    Date hanSD;
    bool found = false;
    cin >> hanSD.ngay >> hanSD.thang >> hanSD.nam;

    cout << "Danh sach san pham co han su dung " << hanSD.ngay << "/" << hanSD.thang << "/" << hanSD.nam << " la:" << endl;
    
    // Duyệt qua danh sách sản phẩm và so sánh hạn sử dụng
    for (int i = 0; i < n; i++) {
        Date temp = a[i].getHanSuDung();  // Lấy hạn sử dụng của sản phẩm
        if (temp.ngay == hanSD.ngay && temp.thang == hanSD.thang && temp.nam == hanSD.nam) {
            a[i].xuat();  // Xuất thông tin sản phẩm nếu trùng khớp
            found = true;
        }
    }
    
    // Nếu không tìm thấy sản phẩm nào, thông báo
    if (!found) {
        cout << "Khong tim thay san pham co han su dung " << hanSD.ngay << "/" << hanSD.thang << "/" << hanSD.nam << endl;
    }
}
// void timKiemNuocHetHan8Ngay(NuocGiaiKhat ds[], int n) {
//     time_t now = time(0);
//     tm* ltm = localtime(&now);
//     int ngayHienTai = ltm->tm_mday;
//     int thangHienTai = ltm->tm_mon + 1;
//     int namHienTai = ltm->tm_year + 1900;

//     for (int i = 0; i < n; i++) {
//         int soNgayConLai = (ds[i].getHanSuDung().nam - namHienTai) * 365 +
//                            (ds[i].getHanSuDung().thang - thangHienTai) * 30 +
//                            (ds[i].getHanSuDung().ngay - ngayHienTai);
//         if (soNgayConLai < 8) {
//             ds[i].xuat();
//         }
//     }
// }

// void timKiemNuocCoGasHetHanThang10_2024(NuocCoGas ds[], int n) {
//     for (int i = 0; i < n; i++) {
//         if (ds[i].getHanSuDung().nam == 2024 && ds[i].getHanSuDung().thang == 10) {
//             ds[i].xuat();
//         }
//     }
// }

// void timKiemNuocCoGasChauA(NuocCoGas ds[], int n) {
//     for (int i = 0; i < n; i++) {
//         if (ds[i].getXuatXu() == "Chau A" && ds[i].getTrongLuong() >= 1000) {
//             ds[i].xuat();
//         }
//     }
// }

void tinmKiemNuocTheoTen(NuocGiaiKhat a[],int n){
    bool found = false;
    string stringF;
    cout<<"Nhap ten can tim kiem:"<<endl;
    getline(cin,stringF);
    cin.ignore();
    for(int i = 0; i<n;i++){
        if(a[i].getTenNuoc().find(stringF) != string::npos)
        {
            a[i].xuat();
            found = true;
        }
    }
    if(!found){
        cout<<"Khong tim thay san pham co ten "<<stringF<<endl;
    }
}
void thongKeDanhSach(NuocCoGas a[],int n){
    int soLuong=0;
    float tongTien=0;
    for(int i=0;i<n;i++){
        if(a[i].getXuatXu()=="Chau A"){
            soLuong+=1;
            tongTien+=a[i].getGiaNuocCoGas();
            a[i].xuat();
        }
    }
}
void xoaNuocTheoMa(NuocGiaiKhat a[],int n){
    string ma;
    bool found= false;
    cout<<"Nhap ma can xoa"<<endl;
    getline(cin,ma);
    cin.ignore();
    for(int i=0;i<n;i++){
        if(a[i].getMaNuoc()==ma){
            found=true;
            for(int j=i;j<n-1;j++){
                a[j]=a[j+1];
            }
            n--;
            cout<<"Da xoa nuoc co ma "<<ma<<endl;
            break;
        }
    }
    if(!found){
        cout<<"Khong tim thay ma nuoc "<<ma<<endl;
    }
}
// void xoaNuocTheoMa(NuocGiaiKhat ds[], int& n, const string& ma) {
//     for (int i = 0; i < n; i++) {
//         if (ds[i].getMaNuoc() == ma) {
//             for (int j = i; j < n - 1; j++) {
//                 ds[j] = ds[j + 1];
//             }
//             n--;
//             cout << "Da xoa nuoc co ma " << ma << endl;
//             return;
//         }
//     }
//     cout << "Khong tim thay ma nuoc " << ma << endl;
// }

// void sapXepGiaTien(NuocGiaiKhat ds[], int n) {
//     for (int i = 0; i < n - 1; i++) {
//         for (int j = i + 1; j < n; j++) {
//             if (ds[i].getGiaNuoc() > ds[j].getGiaNuoc()) {
//                 swap(ds[i], ds[j]);
//             }
//         }
//     }
// }
int main() {
    NuocGiaiKhat a[100];
    NuocNgot n[100];
    NuocCoGas n1[100];
    int demNuocNgot = 0;  // Biến đếm nước ngọt
    int demNuocCoGas = 0; // Biến đếm nước có gas
    int choice;

    // Menu và lựa chọn
    while (true) {
        cout << "\n---- MENU ----\n";
        cout << "1. Nhap nuoc ngot\n";
        cout << "2. Nhap nuoc co gas\n";
        cout << "3. Xuat danh sach nuoc ngot\n";
        cout << "4. Xuat danh sach nuoc co gas\n";
        cout << "5.Tinh tong tien can cha \n";
        cout << "6.Tim kiem theo han su dung\n";
        cout << "0. Thoat\n";
        cout << "Chon thao tac: ";
        cin >> choice;
        cin.ignore();  // Để tránh vấn đề khi dùng getline sau khi dùng cin

        if (choice == 1) {
            nhapDSNuocNgot(n, demNuocNgot);
            cout << "Nuoc ngot da duoc nhap!\n";
        }
        else if (choice == 2) {
            nhapDSNuocCoGas(n1, demNuocCoGas);
            cout << "Nuoc co gas da duoc nhap!\n";
        }
        else if (choice == 3) {
            xuatDSNuocNgot(n, demNuocNgot);
        }
        else if (choice == 4) {
            xuatDSNuocCoGas(n1, demNuocCoGas);
        }
        else if (choice == 5) {
            cout<<"so tien phai tra la :"<<endl;
            tinhTongTien(a,n1,demNuocCoGas+demNuocNgot); ///
                  // Thoát khỏi vòng lặp khi chọn "Thoat"
        } 
        else if(choice == 6){
            cout<<"Nhap han su dung can tim kiem cua nuoc ngot"<<endl;
            timKiemTheoHanSD(n, demNuocNgot);
            cout<<"Nhap han su dung can tim kiem cua nuoc co gas"<<endl;
            timKiemTheoHanSD(n1, demNuocCoGas);
            // timKiemTheoHanSD(a,demNuocCoGas+demNuocNgot);
        }
        else if(choice == 7){
            cout<<"Nhap ten san pham can tim kiem cua nuoc ngot"<<endl;
            tinmKiemNuocTheoTen(n, demNuocNgot);
            cout<<"Nhap ten san pham can tim kiem cua nuoc co gas"<<endl;
            tinmKiemNuocTheoTen(n1, demNuocCoGas);
            // timKiemTheoHanSD(a,demNuocCoGas+demNuocNgot);
        }
         else if (choice == 8) {
            cout<<"Thong ke nuoc co xuat xu chau a"<<endl;
            thongKeDanhSach(n1, demNuocCoGas); 
        }
         else if (choice == 9) {
            xoaNuocTheoMa(n1, demNuocCoGas); 
        }
        else {
            cout << "Chon sai! Vui long chon lai.\n";
        }
    }

    return 0;
}
