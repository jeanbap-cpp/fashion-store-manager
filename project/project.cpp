#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

using namespace std;

//--------------------------------San pham-------------------------------------
class SanPham {
public:
    int     MaSanPham;
    string  TenSanPham;
    string  Size;
    string  ChatLieu;
    string  MauSac;
    float   GiaBan;
    float   GiaNhap;

    bool Nhap(){
        cout<<"Nhap ma san pham: "; // kiểm trâ xem người dùng có nhập đúng kiểu dữ liệu hay không
        if(!(cin>>MaSanPham)){
            cin.clear(); cin.ignore(10000, '\n');
            cout<<"error !!";
            return false;
        }
        cin.ignore();

        cout<<"Nhap ten: ";                     getline(cin, TenSanPham);
        cout<<"Nhap size: ";                    getline(cin, Size);
        cout<<"Nhap chat lieu: ";               getline(cin, ChatLieu);
        cout<<"Nhap mau sac: ";                 getline(cin, MauSac);

        cout<<"Nhap gia ban: ";
        if(!(cin>>GiaBan)){ // kiểm trâ xem người dùng có nhập đúng kiểu dữ liệu hay không
            cin.clear(); cin.ignore(10000, '\n');
            cout<<"error";
            return false;
        }

        cout<<"Nhap gia nhap: ";
        if(!(cin>>GiaNhap)){ // kiểm trâ xem người dùng có nhập đúng kiểu dữ liệu hay không
            cin.clear(); cin.ignore(10000, '\n');
            cout<<"error";
            return false;
    }
    cin.ignore();
    return true;
    }

    void GhiVaoFile1(fstream &filetopwearnam) const{
        filetopwearnam<<MaSanPham<<";"
            <<TenSanPham<<";"
            <<Size<<";"
            <<ChatLieu<<";"
            <<MauSac<<";"
            <<GiaBan<<";"
            <<GiaNhap<<"\n";
    }

    void GhiVaoFile2(fstream &filebottomwearnam) const{
        filebottomwearnam<<MaSanPham<<";"
            <<TenSanPham<<";"
            <<Size<<";"
            <<ChatLieu<<";"
            <<MauSac<<";"
            <<GiaBan<<";"
            <<GiaNhap<<"\n";
    }

    void GhiVaoFile3(fstream &filetopwearnu) const{
        filetopwearnu<<MaSanPham<<";"
            <<TenSanPham<<";"
            <<Size<<";"
            <<ChatLieu<<";"
            <<MauSac<<";"
            <<GiaBan<<";"
            <<GiaNhap<<"\n";
    }

    void GhiVaoFile4(fstream &filebottomwearnu) const{
        filebottomwearnu<<MaSanPham<<";"
            <<TenSanPham<<";"
            <<Size<<";"
            <<ChatLieu<<";"
            <<MauSac<<";"
            <<GiaBan<<";"
            <<GiaNhap<<"\n";
    }

    void GhiVaoFile5(fstream &filegiaynam) const{
        filegiaynam<<MaSanPham<<";"
            <<TenSanPham<<";"
            <<Size<<";"
            <<ChatLieu<<";"
            <<MauSac<<";"
            <<GiaBan<<";"
            <<GiaNhap<<"\n";
    }

    void GhiVaoFile6(fstream &filegiaynu) const{
        filegiaynu<<MaSanPham<<";"
            <<TenSanPham<<";"
            <<Size<<";"
            <<ChatLieu<<";"
            <<MauSac<<";"
            <<GiaBan<<";"
            <<GiaNhap<<"\n";
    }

    void HienThi() const{
        cout<<"Ma: "<<MaSanPham<<" | Ten: " <<TenSanPham
            <<" | Size: "<<Size
            <<" | Chat lieu: "<< ChatLieu<<" | Mau sac: "<<MauSac
            <<" | Gia ban: "<<GiaBan<<" | Gia nhap: "<<GiaNhap<<"\n";
    }
};

class QuanLySanPham:public SanPham{
public:
    void ThemSanPhamtopwearnamVaoFile(){
        SanPham sp;
        sp.Nhap();

        fstream filetopwearnam("filetextproduct/man/topwear.txt", ios::out | ios::app); //truy cập vào file
        if (!filetopwearnam.is_open()){  // kiểm tra xem file có mở được không
            cout<<"Khong the mo file!"<<endl;
            return;
        }

        sp.GhiVaoFile1(filetopwearnam); //lưu dữ liệu đã nhập vào file
        filetopwearnam.close();
        cout<<"==> Da luu san pham vao file!"<<endl;
    }

    void HienThiSanPhamTuFiletopwearnam(){
        fstream filetopwearnam("filetextproduct/man/topwear.txt", ios::in); //truy cập vào file để lấy dữ liệu ra
        if (!filetopwearnam.is_open()){
            cout<<"Khong the mo file!"<<endl;
            return;
        }

        string line; //line dùng để lưu từ dòng đọc được từ file
        cout<<"--- Danh sach san pham ---"<<endl;
        while(getline(filetopwearnam, line)){ // đọc từng dòng của file sanpham
            if(line.empty()){continue;}//bỏ qua dòng trống

            stringstream ss(line); //tạo đối tượng stringstream từ dòng vừa đọc và dễ dàng phân tách dữ liệu bằng dấu ";"
            SanPham sp;
            string temp;

            getline(ss, temp, ';'); sp.MaSanPham = stoi(temp);
            getline(ss, sp.TenSanPham, ';');
            getline(ss, sp.Size, ';');
            getline(ss, sp.ChatLieu, ';');
            getline(ss, sp.MauSac, ';');
            getline(ss, temp, ';'); sp.GiaBan = stof(temp);
            getline(ss, temp);     sp.GiaNhap = stof(temp);
            sp.HienThi();
        }
        filetopwearnam.close();
    }
//-------------
    void ThemSanPhambottomwearnamVaoFile(){
        SanPham sp;
        sp.Nhap();

        fstream filebottomwearnam("filetextproduct/man/bottomwear.txt", ios::out | ios::app); //truy cập vào file
        if (!filebottomwearnam.is_open()){  // kiểm tra xem file có mở được không
            cout<<"Khong the mo file!"<<endl;
            return;
        }

        sp.GhiVaoFile2(filebottomwearnam); //lưu dữ liệu đã nhập vào file
        filebottomwearnam.close();
        cout<<"==> Da luu san pham vao file!"<<endl;
    }

    void HienThiSanPhamTuFilebottomwearnam(){
        fstream filebottomwearnam("filetextproduct/man/bottomwear.txt", ios::in); //truy cập vào file để lấy dữ liệu ra
        if (!filebottomwearnam.is_open()){
            cout<<"Khong the mo file!"<<endl;
            return;
        }

        string line; //line dùng để lưu từ dòng đọc được từ file
        cout<<"--- Danh sach san pham ---"<<endl;
        while(getline(filebottomwearnam, line)){ // đọc từng dòng của file sanpham
            if(line.empty()){continue;}//bỏ qua dòng trống

            stringstream ss(line); //tạo đối tượng stringstream từ dòng vừa đọc và dễ dàng phân tách dữ liệu bằng dấu ";"
            SanPham sp;
            string temp;

            getline(ss, temp, ';'); sp.MaSanPham = stoi(temp);
            getline(ss, sp.TenSanPham, ';');
            getline(ss, sp.Size, ';');
            getline(ss, sp.ChatLieu, ';');
            getline(ss, sp.MauSac, ';');
            getline(ss, temp, ';'); sp.GiaBan = stof(temp);
            getline(ss, temp);     sp.GiaNhap = stof(temp);
            sp.HienThi();
        }
        filebottomwearnam.close();
    }
//------------
void ThemSanPhamtopwearnuVaoFile(){
        SanPham sp;
        sp.Nhap();

        fstream filetopwearnu("filetextproduct/woman/topwear.txt", ios::out | ios::app); //truy cập vào file
        if (!filetopwearnu.is_open()){  // kiểm tra xem file có mở được không
            cout<<"Khong the mo file!"<<endl;
            return;
        }

        sp.GhiVaoFile3(filetopwearnu); //lưu dữ liệu đã nhập vào file
        filetopwearnu.close();
        cout<<"==> Da luu san pham vao file!"<<endl;
    }

    void HienThiSanPhamTuFiletopwearnu(){
        fstream filetopwearnu("filetextproduct/woman/topwear.txt", ios::in); //truy cập vào file để lấy dữ liệu ra
        if (!filetopwearnu.is_open()){
            cout<<"Khong the mo file!"<<endl;
            return;
        }

        string line; //line dùng để lưu từ dòng đọc được từ file
        cout<<"--- Danh sach san pham ---"<<endl;
        while(getline(filetopwearnu, line)){ // đọc từng dòng của file sanpham
            if(line.empty()){continue;}//bỏ qua dòng trống

            stringstream ss(line); //tạo đối tượng stringstream từ dòng vừa đọc và dễ dàng phân tách dữ liệu bằng dấu ";"
            SanPham sp;
            string temp;

            getline(ss, temp, ';'); sp.MaSanPham = stoi(temp);
            getline(ss, sp.TenSanPham, ';');
            getline(ss, sp.Size, ';');
            getline(ss, sp.ChatLieu, ';');
            getline(ss, sp.MauSac, ';');
            getline(ss, temp, ';'); sp.GiaBan = stof(temp);
            getline(ss, temp);     sp.GiaNhap = stof(temp);
            sp.HienThi();
        }
        filetopwearnu.close();
    }
//---------------------------
    void ThemSanPhambottomwearnuVaoFile(){
        SanPham sp;
        sp.Nhap();

        fstream filebottomwearnu("filetextproduct/woman/bottomwear.txt", ios::out | ios::app); //truy cập vào file
        if (!filebottomwearnu.is_open()){  // kiểm tra xem file có mở được không
            cout<<"Khong the mo file!"<<endl;
            return;
        }

        sp.GhiVaoFile4(filebottomwearnu); //lưu dữ liệu đã nhập vào file
        filebottomwearnu.close();
        cout<<"==> Da luu san pham vao file!"<<endl;
    }

    void HienThiSanPhamTuFilebottomwearnu(){
        fstream filebottomwearnu("filetextproduct/woman/bottomwear.txt", ios::in); //truy cập vào file để lấy dữ liệu ra
        if (!filebottomwearnu.is_open()){
            cout<<"Khong the mo file!"<<endl;
            return;
        }

        string line; //line dùng để lưu từ dòng đọc được từ file
        cout<<"--- Danh sach san pham ---"<<endl;
        while(getline(filebottomwearnu, line)){ // đọc từng dòng của file sanpham
            if(line.empty()){continue;}//bỏ qua dòng trống

            stringstream ss(line); //tạo đối tượng stringstream từ dòng vừa đọc và dễ dàng phân tách dữ liệu bằng dấu ";"
            SanPham sp;
            string temp;

            getline(ss, temp, ';'); sp.MaSanPham = stoi(temp);
            getline(ss, sp.TenSanPham, ';');
            getline(ss, sp.Size, ';');
            getline(ss, sp.ChatLieu, ';');
            getline(ss, sp.MauSac, ';');
            getline(ss, temp, ';'); sp.GiaBan = stof(temp);
            getline(ss, temp);     sp.GiaNhap = stof(temp);
            sp.HienThi();
        }
        filebottomwearnu.close();
    }
//--------------------------
    void ThemGiayNamFile(){
        SanPham sp;
        sp.Nhap();

        fstream filegiaynam("filetextproduct/giay/GiayNam.txt", ios::out | ios::app); //truy cập vào file
        if (!filegiaynam.is_open()){  // kiểm tra xem file có mở được không
            cout<<"Khong the mo file!"<<endl;
            return;
        }

        sp.GhiVaoFile5(filegiaynam); //lưu dữ liệu đã nhập vào file
        filegiaynam.close();
        cout<<"==> Da luu san pham vao file!"<<endl;
    }

    void HienThiGiayNam(){
        fstream filegiaynam("filetextproduct/giay/GiayNam.txt", ios::in); //truy cập vào file để lấy dữ liệu ra
        if (!filegiaynam.is_open()){
            cout<<"Khong the mo file!"<<endl;
            return;
        }

        string line; //line dùng để lưu từ dòng đọc được từ file
        cout<<"--- Danh sach san pham ---"<<endl;
        while(getline(filegiaynam, line)){ // đọc từng dòng của file sanpham
            if(line.empty()){continue;}//bỏ qua dòng trống

            stringstream ss(line); //tạo đối tượng stringstream từ dòng vừa đọc và dễ dàng phân tách dữ liệu bằng dấu ";"
            SanPham sp;
            string temp;

            getline(ss, temp, ';'); sp.MaSanPham = stoi(temp);
            getline(ss, sp.TenSanPham, ';');
            getline(ss, sp.Size, ';');
            getline(ss, sp.ChatLieu, ';');
            getline(ss, sp.MauSac, ';');
            getline(ss, temp, ';'); sp.GiaBan = stof(temp);
            getline(ss, temp);     sp.GiaNhap = stof(temp);
            sp.HienThi();
        }
        filegiaynam.close();
    }
//------------------------
    void ThemGiayNuFile(){
        SanPham sp;
        sp.Nhap();

        fstream filegiaynu("filetextproduct/giay/GiayNu.txt", ios::out | ios::app); //truy cập vào file
        if (!filegiaynu.is_open()){  // kiểm tra xem file có mở được không
            cout<<"Khong the mo file!"<<endl;
            return;
        }

        sp.GhiVaoFile6(filegiaynu); //lưu dữ liệu đã nhập vào file
        filegiaynu.close();
        cout<<"==> Da luu san pham vao file!"<<endl;
    }

    void HienThiGiayNu(){
        fstream filegiaynu("filetextproduct/giay/GiayNu.txt", ios::in); //truy cập vào file để lấy dữ liệu ra
        if (!filegiaynu.is_open()){
            cout<<"Khong the mo file!"<<endl;
            return;
        }

        string line; //line dùng để lưu từ dòng đọc được từ file
        cout<<"--- Danh sach san pham ---"<<endl;
        while(getline(filegiaynu, line)){ // đọc từng dòng của file sanpham
            if(line.empty()){continue;}//bỏ qua dòng trống

            stringstream ss(line); //tạo đối tượng stringstream từ dòng vừa đọc và dễ dàng phân tách dữ liệu bằng dấu ";"
            SanPham sp;
            string temp;

            getline(ss, temp, ';'); sp.MaSanPham = stoi(temp);
            getline(ss, sp.TenSanPham, ';');
            getline(ss, sp.Size, ';');
            getline(ss, sp.ChatLieu, ';');
            getline(ss, sp.MauSac, ';');
            getline(ss, temp, ';'); sp.GiaBan = stof(temp);
            getline(ss, temp);     sp.GiaNhap = stof(temp);
            sp.HienThi();
        }
        filegiaynu.close();
    }
};

//--------------------------------Nguoi-------------------------------------
class Nguoi{ //đây là class người chính
    protected:
        int    MaKhachHang;
        int    MaNhanVien;
        string ChucVu;
        string HoTen;
        string NgaySinh;
        string SDT;
        string Email;
    public:
        bool NhapThongTin(){
            cout<<"Nhap ma nhan vien: "; // kiểm tra xem người dùng nhập đúng thông tin theo int không
            if(!(cin>>MaNhanVien)){
                cin.clear(); cin.ignore(10000, '\n');
                cout<<"error !!";
                return false;
            }
            cin.ignore();

            cout<<"Nhap ho va ten: "; getline(cin, HoTen);
            cout<<"Nhap ngay thang nam sinh: "; getline(cin, NgaySinh);
            cout<<"Nhap so dien thoai: "; getline(cin, SDT);
            cout<<"Nhap email: "; getline(cin, Email);
            cout<<"Nhap chuc vu: "; getline(cin, ChucVu);
            return true;
        }

        bool NhapThongTinKH(){
            cout<<"Nhap ma khach hang: ";
            if(!(cin>>MaKhachHang)){
                cin.clear(); cin.ignore(10000, '\n');
                cout<<"error !!";
                return false;
            }
            cin.ignore();

            cout<<"Nhap ho va ten: "; getline(cin, HoTen);
            cout<<"Nhap ngay thang nam sinh: "; getline(cin, NgaySinh);
            cout<<"Nhap so dien thoai: "; getline(cin, SDT);
            cout<<"Nhap email: "; getline(cin, Email);
            return true;
        }

        void HienThiThongTin() const{
            cout<<"-----------------------------"<<"\n";
            cout<<"Ma nhan vien: "<<MaNhanVien<<"\n";
            cout<<"Ho va ten: "<<HoTen<<"\n";
            cout<<"Ngay thang nam sinh: "<<NgaySinh<<"\n";
            cout<<"So dien thoai: "<<SDT<<"\n";
            cout<<"Email: "<<Email<<"\n";
            cout<<"Chuc vu: "<<ChucVu<<"\n";
        }
        void HienThiThongTinKH() const{
            cout<<"-----------------------------"<<"\n";
            cout<<"Ma khach hang: "<<MaKhachHang<<"\n";
            cout<<"Ho va ten: "<<HoTen<<"\n";
            cout<<"Ngay thang nam sinh: "<<NgaySinh<<"\n";
            cout<<"So dien thoai: "<<SDT<<"\n";
            cout<<"Email: "<<Email<<"\n";
        }
};

class NhanVien:public Nguoi{ //class con kế thừa của class người
    public:
        void NhapNhanVien(){
            NhapThongTin();//gọi hàm nhập thông tin từ lớp trên
        }
        void GhiVaoFile(fstream &file1) const{ //ghi thông tin vào file
            file1<<MaNhanVien<<";"
                 <<HoTen<<";"
                 <<NgaySinh<<";"
                 <<SDT<<";"
                 <<Email<<";"
                 <<ChucVu<<"\n";
        }

        void ThemNhanVienVaoFile(){
            NhanVien nv;
            nv.NhapNhanVien();

            fstream file1("filetextpeople/NhanVien.txt", ios::out | ios::app); // mở file nhân viên để thêm dữ liệu vào file
            if(!file1.is_open()){   //kiểm tra xem file có mở được không
                cout<<"Khong the mo file!"<<endl;
                return;
            }
            nv.GhiVaoFile(file1);
            file1.close();
            cout<<"==> Da luu nhan vien vao file!"<<endl;
        }

        void HienThiNhanVien() const{
            fstream file1("filetextpeople/NhanVien.txt", ios::in); //mở file nhân viên để đọc dữ liệu từ file
            if(!file1.is_open()){ //kiểm tra xem file có mở được không
                cout<<"Khong the mo file!"<<endl;
                return;
            }

            string line1; //line dùng để lưu từ dòng đọc được từ file
            cout<<"---- Danh sach nhan vien ----"<<endl;

            while(getline(file1, line1)){ // đọc từng dòng của file sanpham
                if(line1.empty()){continue;} //bỏ qua dòng trống

                stringstream ss(line1); //tạo đối tượng stringstream từ dòng vừa đọc và dễ dàng phân tách dữ liệu bằng dấu ";"
                NhanVien nv;
                string temp;

                getline(ss, temp, ';'); nv.MaNhanVien = stoi(temp);
                getline(ss, nv.HoTen, ';');
                getline(ss, nv.NgaySinh, ';');
                getline(ss, nv.SDT, ';');
                getline(ss, nv.Email, ';');
                getline(ss, nv.ChucVu, '\n');

                nv.HienThiThongTin();
            }
            file1.close();
        }
};

class KhachHang:public Nguoi{ //class con kế thừa của class người
    public:
        void NhapKhachHang(){
            NhapThongTinKH();//gọi hàm nhập thông tin từ lớp trên
        }
        void GhiVaoFile(fstream &file2) const{ //ghi thông tin vào file
            file2<<MaKhachHang<<";"
                 <<HoTen<<";"
                 <<NgaySinh<<";"
                 <<SDT<<";"
                 <<Email<<";";
        }

        void HienThikhachang() const{
            fstream file2("filetextpeople/KhachHang.txt", ios::in); //mở file khách hàng để đọc dữ liệu từ file
            if(!file2.is_open()){ //kiểm tra xem file có mở được không
                cout<<"Khong the mo file!"<<endl;
                return;
            }

            string line2; //line dùng để lưu từ dòng đọc được từ file
            cout<<"---- Danh sach khach hang ----"<<endl;

            while(getline(file2, line2)){ // đọc từng dòng của file sanpham
                if(line2.empty()){continue;} //bỏ qua dòng trống

                stringstream ss(line2); //tạo đối tượng stringstream từ dòng vừa đọc và dễ dàng phân tách dữ liệu bằng dấu ";"
                KhachHang nv;
                string temp;

                getline(ss, temp, ';'); nv.MaKhachHang = stoi(temp);
                getline(ss, nv.HoTen, ';');
                getline(ss, nv.NgaySinh, ';');
                getline(ss, nv.SDT, ';');
                getline(ss, nv.Email, ';');

                nv.HienThiThongTinKH();
            }
            file2.close();
        }
};

//-------------------------Hoa don---------------------------------

class HoaDonBanHang:public KhachHang {
private:
    int MaHDBH;
    string NgayThanhToan;
    string KieuThanhToan;
    int SoSanPham;
    float GiamGia;
    float TongTienBanHang;
    string NhanVienTaoHoaDon;
    KhachHang khach;

public:
    bool Nhap(){
    cout<<"Nhap ma hoa don ban hang: ";
    if(!(cin>>MaHDBH)){
        cin.clear(); cin.ignore(10000, '\n');
        cout<<"Loi: Ma hoa don khong hop le!\n";
        return false;
    }
    cin.ignore();

    cout<<"Nhap ngay thanh toan: ";
    getline(cin, NgayThanhToan);
    cout<<"Nhap kieu thanh toan: ";
    getline(cin, KieuThanhToan);
    cout<<"Nhap so san pham da mua: ";

    if(!(cin>>SoSanPham)){
        cin.clear(); cin.ignore(10000, '\n');
        cout<<"Loi: So san pham khong hop le!\n";
        return false;
    }
    cin.ignore();

    cout<<"Nhap giam gia (%): ";
    if(!(cin>>GiamGia)){
        cin.clear(); cin.ignore(10000, '\n');
        cout<<"Loi: Giam gia khong hop le!\n";
        return false;
    }
    cin.ignore();

    cout<<"Nhap tong tien ban hang: ";
    if(!(cin>>TongTienBanHang)) {
        cin.clear(); cin.ignore(10000, '\n');
        cout<<"Loi: Tong tien khong hop le!\n";
        return false;
    }
    cin.ignore();

    cout<<"Nhap ten nhan vien tao hoa don: ";
    getline(cin, NhanVienTaoHoaDon);

    cout<<"--- Nhap thong tin khach hang ---\n";
    if(khach.NhapThongTinKH()){//Ghi thông tin khách hàng vào file sau khi nhập
        fstream file2("filetextpeople/KhachHang.txt", ios::out | ios::app);
        if(file2.is_open()){
            khach.GhiVaoFile(file2);
            file2.close();
            cout<<"==> Da luu khach hang vao file!\n";
        }
        else{
            cout<<"Khong the mo file KhachHang.txt de ghi!"<<endl;
        }
        return true;
    }
    return false;
}

    void HienThiHoaDon() const{
        cout<<"---- Hoa don ban hang ----\n";
        cout<<"Ma hoa don: "<<MaHDBH<<"\n";
        cout<<"Ngay thanh toan: "<<NgayThanhToan<<"\n";
        cout<<"Kieu thanh toan: "<<KieuThanhToan<<"\n";
        cout<<"So san pham: "<<SoSanPham<<"\n";
        cout<<"Giam gia: "<<GiamGia<<"%\n";
        cout<<"Tong tien: "<<TongTienBanHang<<"\n";
        cout<<"Nhan vien tao hoa don: "<<NhanVienTaoHoaDon<<"\n";
        cout<<"--- Thong tin khach hang ---\n";
        khach.HienThiThongTinKH();
    }
};

class HoaDonNhapHang{
    private:
        int     MaHDNH;
        string  NhaCungCap;
    public:
        string  NgayNhapHang;
        float   TongTienNhapHang;
};

class KhuyenMai{
    private:
    public:
        string  MoTaKhuyenMai;
        float   GiamBaoNhieu;
        string  NgayBatDau;
        string  NgayKetThuc;
        float   GiaTriDonHangToiThieu;
};

//--------------------------------Doanh Thu-------------------------------------
class DoanhThu{ //class cha cua doanh thu
    protected:
        int     TongHoaDon;
        int     TongSanPhamBanRa;
        float   TongDoanhThu;
        float   TongGiamGia;
    public: 
        DoanhThu(int HoaDon=0, int SanPham=0, float DoanhThu=0, float GiamGia=0):
        TongHoaDon(HoaDon), TongSanPhamBanRa(SanPham), TongDoanhThu(DoanhThu), TongGiamGia(GiamGia){} //gan cac gia tri ban dau la 0 

        void HienThiThongTinDoanhThu() const {
            cout<<"Tong hoa don: "<<TongHoaDon<<"\n";
            cout<<"Tong san pham ban ra: "<<TongSanPhamBanRa<<"\n";
            cout<<"Tong doanh thu: "<<TongDoanhThu<<"\n";
            cout<<"Tong giam gia: "<<TongGiamGia<<"\n";

        }
};

class DoanhThuNgay:public DoanhThu{
    private:
        string NgayThongKe;
    public:
        DoanhThuNgay():DoanhThu(0, 0, 0, 0), NgayThongKe("Chua xac dinh."){}//khởi tạo các constructor có thông tin của lớp cha với các giá trị là 0
        DoanhThuNgay(string Ngay, int HoaDon, int SanPham, float Doanhthu, float GiamGia):
            DoanhThu(HoaDon, SanPham, Doanhthu, GiamGia), NgayThongKe(Ngay){}//cho phép khởi tạo các thông tin trong thời gian cụ thể 
    
    void HienThiThongTinDoanhThuNgay() const{
        cout<<"--- Doanh thu theo ngay ---"<<"\n";
        cout<<"Ngay thong ke: "<<NgayThongKe<<"\n";
        HienThiThongTinDoanhThu();
    }
};

class DoanhThuThang:public DoanhThu{
    private:
        string ThangThongKe;
    public:
        DoanhThuThang():DoanhThu(0, 0, 0, 0), ThangThongKe("Chua xac dinh."){} //khởi tạo các constructor có thông tin của lớp cha với các giá trị là 0
        DoanhThuThang(string Thang, int HoaDon, int SanPham, float Doanhthu, float GiamGia):
            DoanhThu(HoaDon, SanPham, Doanhthu, GiamGia), ThangThongKe(Thang){} //cho phép khởi tạo các thông tin trong thời gian cụ thể 
    
    void HienThiThongTinDoanhThuThang() const{
        cout<<"--- Doanh thu theo thang ---"<<"\n";
        cout<<"Thang thong ke: "<<ThangThongKe<<"\n";
        HienThiThongTinDoanhThu();
    }
};

class DoanhThuNam:public DoanhThu{
    private:
        string NamThongKe;
    public:
        DoanhThuNam():DoanhThu(0, 0, 0, 0), NamThongKe("Chua xac dinh."){}//khởi tạo các constructor có thông tin của lớp cha với các giá trị là 0
        DoanhThuNam(string Nam, int HoaDon, int SanPham, float Doanhthu, float GiamGia):
            DoanhThu(HoaDon, SanPham, Doanhthu, GiamGia), NamThongKe(Nam){}//cho phép khởi tạo các thông tin trong thời gian cụ thể 
    
    void HienThiThongTinDoanhThuNam() const{
        cout<<"--- Doanh thu theo nam ---"<<"\n";
        cout<<"Nam thong ke: "<<NamThongKe<<"\n";
        HienThiThongTinDoanhThu();
    }
};

int main(){
    string PhanLoai;
    QuanLySanPham ql;
    NhanVien nv;
    DoanhThuNgay dtngay;
    DoanhThuThang dtthang;
    DoanhThuNam dtnam;
    KhachHang kh;
    HoaDonBanHang hdbh;
        int luaChon;
        do{
            cout<<"\n|========= MENU QUAN LY CUA HANG =========|\n";
            cout<<"|------------ QUAN LY SAN PHAM -----------|\n";
            cout<<"|1. Danh muc san pham                     |\n";
            cout<<"|----------- QUAN LY NHAN VIEN -----------|\n";
            cout<<"|2. Nhap thong tin nhan vien              |\n";
            cout<<"|3. Hien thi thong tin nhan vien          |\n";
            cout<<"|----------- QUAN LY KHACH HANG ----------|\n";
            cout<<"|4. Hien thi thong tin khach hang         |\n";
            cout<<"|----------- QUAN LY DOANH THU -----------|\n";
            cout<<"|5. Hien thi doanh thu theo ngay          |\n";
            cout<<"|6. Hien thi doanh thu theo thang         |\n";
            cout<<"|7. Hien thi doanh thu theo nam           |\n";
            cout<<"|------------ HOA DON BAN HANG -----------|\n";
            cout<<"|8. Nhap hoa don ban hang                 |\n";
            cout<<"|9. Hien thi hoa don ban hang             |\n";
            cout<<"|-----------------------------------------|\n";
            cout<<"|0. Thoat|\n";

            cout<<"Nhap lua chon: "; cin>>luaChon;

            switch(luaChon){
                case 1:
                    cout<<"Phan loai san pham (nam/nu/giay): "; cin>>PhanLoai;
                    if      (PhanLoai == "nam"){
                        int stt;
                        do{
                            cout<<"|========== MENU SAN PHAM NAM ==========|\n";
                            cout<<"|1. topwear                             |\n";
                            cout<<"|2. bottomwear                          |\n";
                            cout<<"|3. Them topwear                        |\n";
                            cout<<"|4. Them bottomwear                     |\n";
                            cout<<"|---------------------------------------|\n";
                            cout<<"|0. Thoat|\n";

                            cout<<"Nhap lua chon: "; cin>>stt;
                            switch(stt){
                                case 1:
                                    ql.HienThiSanPhamTuFiletopwearnam();
                                    break;
                                case 2:
                                    ql.HienThiSanPhamTuFilebottomwearnam();
                                    break;
                                case 3:
                                    ql.ThemSanPhamtopwearnamVaoFile();
                                    break;
                                case 4:
                                    ql.ThemSanPhambottomwearnamVaoFile();
                                    break;
                                case 0:
                                    cout<<"Thoat chuong trinh !\n";
                                    break;
                                default:
                                    cout<<"Lua chon khong hop le!\n";
                                    break;
                            }
                        }while(stt != 0);
                    }
                    else if (PhanLoai == "nu") {
                        int STT;
                        do{
                            cout<<"|========== MENU SAN PHAM NU ==========|\n";
                            cout<<"|1. topwear                             |\n";
                            cout<<"|2. bottomwear                          |\n";
                            cout<<"|3. Them topwear                        |\n";
                            cout<<"|4. Them bottomwear                     |\n";
                            cout<<"|---------------------------------------|\n";
                            cout<<"|0. Thoat|\n";

                            cout<<"Nhap lua chon: "; cin>>STT;
                            switch(STT){
                                case 1:
                                    ql.HienThiSanPhamTuFiletopwearnu();
                                    break;
                                case 2:
                                    ql.HienThiSanPhamTuFilebottomwearnu();
                                    break;
                                case 3:
                                    ql.ThemSanPhamtopwearnuVaoFile();
                                    break;
                                case 4:
                                    ql.ThemSanPhambottomwearnuVaoFile();
                                    break;
                                case 0:
                                    cout<<"Thoat chuong trinh !\n";
                                    break;
                                default:
                                    cout<<"Lua chon khong hop le!\n";
                                    break;
                            }
                        }while(STT != 0);
                    }
                    else if (PhanLoai == "giay") {
                        int StT;
                        do{
                            cout<<"|========== MENU GIAY ==========|\n";
                            cout<<"|1. Giay nam                    |\n";
                            cout<<"|2. Giay nu                     |\n";
                            cout<<"|3. Them giay nam               |\n";
                            cout<<"|4. Them giay nu               |\n";
                            cout<<"|-------------------------------|\n";
                            cout<<"|0. Thoat|\n";

                            cout<<"Nhap lua chon: "; cin>>StT;
                            switch(StT){
                                case 1:
                                    ql.HienThiGiayNam();
                                    break;
                                case 2:
                                    ql.HienThiGiayNu();
                                    break;
                                case 3:
                                    ql.ThemGiayNamFile();
                                    break;
                                case 4:
                                    ql.ThemGiayNuFile();
                                    break;
                                case 0:
                                    cout<<"Thoat chuong trinh !\n";
                                    break;
                                default:
                                    cout<<"Lua chon khong hop le!\n";
                                    break;
                            }
                        }while(StT != 0);
                    }
                    else cout<<"Phan loai khong hop le !!"<<"\n";
                    break;
                    

                case 2:
                    nv.ThemNhanVienVaoFile();
                    break;
                case 3:
                    nv.HienThiNhanVien();
                    break;
                case 4:
                    kh.HienThikhachang();
                    break;
                case 5:
                    dtngay.HienThiThongTinDoanhThuNgay();
                    break;
                case 6:
                    dtthang.HienThiThongTinDoanhThuThang();
                    break;
                case 7:
                    dtnam.HienThiThongTinDoanhThuNam();
                    break;
                case 8:
                    hdbh.Nhap();
                    break;
                case 9:
                    hdbh.HienThiHoaDon();
                case 0:
                    cout<<"Thoat chuong trinh.\n";
                    break;
                default:
                    cout<<"Lua chon khong hop le!\n";
                    break;
            }
        }while(luaChon != 0);
    return 0;
}