#ifndef MATH_UTILS_H
#define MATH_UTILS_H
#define MAX 200

// 1. KHAI BAO KIEU DU LIEU
typedef struct {
    char mssv[10];
    char hoten[50];
    char sdt[15];
    char gioitinh[5];
    char ngaysinh[15];
    char malop[10];
    float diemtrungbinh;
} Sinhvien;

extern Sinhvien a[MAX];

// +------CAC HAM CHUC NANG-------+
void nhapChuoi(char str[], int size);
// Nhap , xuat
void nhap(Sinhvien a[], int n);
void xuat(Sinhvien a[], int n);
// Tim kiem
int TimKiemSinhVien(Sinhvien a[], int n, char Thongtincantim[]);
// Them
void ThemSinhVien(Sinhvien a[], int* n);
// Xoa
void XoaSinhVien(Sinhvien a[], int* n, char MSSVCanXoa[]);
// Sap Xep
void SapXepDTBTangDan(Sinhvien a[], int n);
void SapXepDTBGiamDan(Sinhvien a[], int n);
void SapXepSDTTangDan(Sinhvien a[], int n);
void SapXepSDTGiamDan(Sinhvien a[], int n);
void SapXepMSSVGiamDan(Sinhvien a[], int n);
void SapXepMSSVTangDan(Sinhvien a[], int n);
void SapXepHoTenTangDan(Sinhvien a[], int n);
void SapXepHoTenGiamDan(Sinhvien a[], int n);
// Giao dien chon sap xep tang hoac giam
void Updown(char* a);
// Cap nhat
void CapNhatSinhVien(Sinhvien a[], int n, char MSSVCanCapNhat[]);
// Doc du lieu
void DocFile(Sinhvien a[]);
// Ghi du lieu
void GhiFile(Sinhvien a[], int n);
#endif


