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
    string  LoaiSanPham;
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

        cout<<"Nhap ten: "; getline(cin, TenSanPham);
        cout<<"Nhap loai: "; getline(cin, LoaiSanPham);
        cout<<"Nhap size: "; getline(cin, Size);
        cout<<"Nhap chat lieu: "; getline(cin, ChatLieu);
        cout<<"Nhap mau sac: "; getline(cin, MauSac);

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

    void GhiVaoFile(fstream &file) const{
        file<<MaSanPham<<";"
            <<TenSanPham<<";"
            <<LoaiSanPham<<";"
            <<Size<<";"
            <<ChatLieu<<";"
            <<MauSac<<";"
            <<GiaBan<<";"
            <<GiaNhap<<"\n";
    }

    void HienThi() const{
        cout<<"Ma: "<<MaSanPham<<" | Ten: " <<TenSanPham
            <<" | Loai: " <<LoaiSanPham<<" | Size: "<<Size
            <<" | Chat lieu: "<< ChatLieu<<" | Mau sac: "<<MauSac
            <<" | Gia ban: "<<GiaBan<<" | Gia nhap: "<<GiaNhap<<"\n";
    }
};

class QuanLySanPham{
public:
    void ThemSanPhamVaoFile(){
        SanPham sp;
        sp.Nhap();

        fstream file("SanPham.txt", ios::out | ios::app); //truy cập vào file
        if (!file.is_open()){  // kiểm tra xem file có mở được không
            cout<<"Khong the mo file!"<<endl;
            return;
        }

        sp.GhiVaoFile(file); //lưu dữ liệu đã nhập vào file
        file.close();
        cout<<"==> Da luu san pham vao file!"<<endl;
    }

    void HienThiSanPhamTuFile(){
        fstream file("SanPham.txt", ios::in); //truy cập vào file để lấy dữ liệu ra
        if (!file.is_open()){
            cout<<"Khong the mo file!"<<endl;
            return;
        }

        string line; //line dùng để lưu từ dòng đọc được từ file
        cout<<"--- Danh sach san pham ---"<<endl;
        while(getline(file, line)){ // đọc từng dòng của file sanpham
            if(line.empty()){continue;}//bỏ qua dòng trống

            stringstream ss(line); //tạo đối tượng stringstream từ dòng vừa đọc và dễ dàng phân tách dữ liệu bằng dấu ";"
            SanPham sp;
            string temp;

            getline(ss, temp, ';'); sp.MaSanPham = stoi(temp);
            getline(ss, sp.TenSanPham, ';');
            getline(ss, sp.LoaiSanPham, ';');
            getline(ss, sp.Size, ';');
            getline(ss, sp.ChatLieu, ';');
            getline(ss, sp.MauSac, ';');
            getline(ss, temp, ';'); sp.GiaBan = stof(temp);
            getline(ss, temp);     sp.GiaNhap = stof(temp);
            sp.HienThi();
        }
        file.close();
    }
};

//--------------------------------Nguoi-------------------------------------
class Nguoi{ //đây là class người chính
    protected:
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
            cin.ignore();
            return true;
        }

        void HienThiThongTin() const{
            cout<<"Ma nhan vien: "<<MaNhanVien<<"\n";
            cout<<"Ho va ten: "<<HoTen<<"\n";
            cout<<"Ngay thang nam sinh: "<<NgaySinh<<"\n";
            cout<<"So dien thoai: "<<SDT<<"\n";
            cout<<"Email: "<<Email<<"\n";
            cout<<"Chuc vu: "<<ChucVu<<"\n";
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

            fstream file1("NhanVien.txt", ios::out | ios::app); // mở file nhân viên để thêm dữ liệu vào file
            if(!file1.is_open()){   //kiểm tra xem file có mở được không
                cout<<"Khong the mo file!"<<endl;
                return;
            }
            nv.GhiVaoFile(file1);
            file1.close();
            cout<<"==> Da luu nhan vien vao file!"<<endl;
        }

        void HienThiNhanVien() const{
            fstream file1("NhanVien.txt", ios::in); //mở file nhân viên để đọc dữ liệu từ file
            if(!file1.is_open()){ //kiểm tra xem file có mở được không
                cout<<"Khong the mo file!"<<endl;
                return;
            }

            string line1; //line dùng để lưu từ dòng đọc được từ file
            cout<<"--- Danh sach nhan vien ---"<<endl;

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

//-------------------------Hoa don---------------------------------
class HoaDonBanHang{
    private:
        int     MaHDBH;
        string  KieuThanhToan;
    public:
        string  NhanVienTaoHoaDon;
        string  ThoiGianBanHang;
        float   GiamGia;
        float   TongTienBanHang;
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
        DoanhThuNgay():DoanhThu(0, 0, 0, 0), NgayThongKe("Chua xac dinh."){}
        DoanhThuNgay(string Ngay, int HoaDon, int SanPham, float Doanhthu, float GiamGia):
            DoanhThu(HoaDon, SanPham, Doanhthu, GiamGia), NgayThongKe(Ngay){}
    
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
        DoanhThuNam():DoanhThu(0, 0, 0, 0), NamThongKe("Chua xac dinh."){}
        DoanhThuNam(string Nam, int HoaDon, int SanPham, float Doanhthu, float GiamGia):
            DoanhThu(HoaDon, SanPham, Doanhthu, GiamGia), NamThongKe(Nam){}
    
    void HienThiThongTinDoanhThuNam() const{
        cout<<"--- Doanh thu theo nam ---"<<"\n";
        cout<<"Nam thong ke: "<<NamThongKe<<"\n";
        HienThiThongTinDoanhThu();
    }
};

int main(){
    QuanLySanPham ql;
    NhanVien nv;
    DoanhThuNgay dtngay;
    DoanhThuThang dtthang;
    DoanhThuNam dtnam;
        int luaChon;
        do{
            cout<<"\n======= MENU QUAN LY SAN PHAM =======\n";
            cout<<"1. Hien thi danh sach san pham\n";
            cout<<"2. Them san pham moi\n";
            cout<<"3. Nhap thong tin nhan vien\n";
            cout<<"4. Hien thi thong tin nhan vien\n";
            cout<<"5. Hien thi doanh thu theo ngay\n";
            cout<<"6. Hien thi doanh thu theo thang\n";
            cout<<"7. Hien thi doanh thu theo nam\n";
            cout<<"0. Thoat\n";
            cout<<"Nhap lua chon: ";
            cin>> luaChon;

            switch(luaChon){
                case 1:
                    ql.HienThiSanPhamTuFile();
                    break;
                case 2:
                    ql.ThemSanPhamVaoFile();
                    break;
                case 3:
                    nv.ThemNhanVienVaoFile();
                    break;
                case 4:
                    nv.HienThiNhanVien();
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