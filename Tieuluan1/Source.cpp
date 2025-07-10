#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include "Header1.h"
#define MAX 200


// 1. KHAI BAO KIEU DU LIEU

// +-----DINH NGHIA CAC HAM CHUC NANG-----+
// Ham nhap chuoi 
void nhapChuoi(char str[], int size) {
    fgets(str, size, stdin);        // Dam bao nhap vao toan bo nhung gi nguoi dung nhap
    str[strcspn(str, "\n")] = '\0'; // Xóa '\n'
}

// 2. HAM NHAP THONG TIN
void nhap(Sinhvien a[], int n) {
    for (int i = 0; i < n; i++) {
        printf("Nhap thong tin cho sinh vien so %d\n", i + 1);

        printf("Ma so sinh vien: ");
        fflush(stdin); //Xoa ky tu con sot lai trong bo nho dem truoc khi nhap chuoi 
        nhapChuoi(a[i].mssv, sizeof(a[i].mssv));

        printf("Ho va ten: ");
        nhapChuoi(a[i].hoten, sizeof(a[i].hoten));

        printf("So dien thoai: ");
        nhapChuoi(a[i].sdt, sizeof(a[i].sdt));

        printf("Gioi tinh: ");
        nhapChuoi(a[i].gioitinh, sizeof(a[i].gioitinh));

        printf("Ngay sinh: ");
        nhapChuoi(a[i].ngaysinh, sizeof(a[i].ngaysinh));

        printf("Ma lop: ");
        nhapChuoi(a[i].malop, sizeof(a[i].malop));

        printf("Diem trung binh: ");
        scanf("%f", &a[i].diemtrungbinh);
        while (getchar() != '\n'); // Xoa ki tu con xot trong bo dem nhap , 	                            
        // Ngan ham doc luon cac ky tu rac hay \n cho lan lap tiep theo
    }
}

// 3. IN DANH SACH
void xuat(Sinhvien a[], int n) {
    printf("\n%-4s | %-10s | %-20s | %-12s | %-8s | %-12s | %-8s | %-6s\n",
        "STT", "MSSV", "Ho ten", "SDT", "Gioi tinh", "Ngay sinh", "Ma lop", "DTB");
    printf("---------------------------------------------------------------------------------------------------\n");
    for (int i = 0; i < n; i++) {
        printf("%-4d | %-10s | %-20s | %-12s | %-8s | %-12s | %-8s | %-6.2f\n",
            i + 1,
            a[i].mssv,
            a[i].hoten,
            a[i].sdt,
            a[i].gioitinh,
            a[i].ngaysinh,
            a[i].malop,
            a[i].diemtrungbinh);
    }
    printf("---------------------------------------------------------------------------------------------------\n");
}

// 4. HAM TIM KIEM ( LINEAR SEARCH )
// 
int TimKiemSinhVien(Sinhvien a[], int n, char Thongtincantim[]) {
    for (int i = 0; i < n; i++) {
        if (strcmp(a[i].mssv, Thongtincantim) == 0 ||
            strcmp(a[i].hoten, Thongtincantim) == 0 ||
            strcmp(a[i].malop, Thongtincantim) == 0 ||
            strcmp(a[i].sdt, Thongtincantim) == 0)
        {
            return i;
        }
    }
    return -1;
}

// 5. THEM SINH VIEN
// Kiem tra so luong sinh vien -> Nhap thong tin sinh vien can them -> Tang bien dem n (*n) hay So Thu Tu
void ThemSinhVien(Sinhvien a[], int* n) {
    if (*n >= MAX) {  // Kiem tra So luong sinh vien so voi gioi han MAX
        printf("Danh sach da day, khong the them sinh vien!\n");
        return;
    }

    printf("\n--- Nhap thong tin sinh vien moi ---\n");
    printf("-- Sinh vien so: %d\n", *n + 1);

    printf("Ma so sinh vien: ");
    fflush(stdin);
    nhapChuoi(a[*n].mssv, sizeof(a[*n].mssv));

    printf("Ho va ten: ");
    nhapChuoi(a[*n].hoten, sizeof(a[*n].hoten));

    printf("So dien thoai: ");
    nhapChuoi(a[*n].sdt, sizeof(a[*n].sdt));

    printf("Gioi tinh: ");
    nhapChuoi(a[*n].gioitinh, sizeof(a[*n].gioitinh));

    printf("Ngay sinh: ");
    nhapChuoi(a[*n].ngaysinh, sizeof(a[*n].ngaysinh));

    printf("Ma lop: ");
    nhapChuoi(a[*n].malop, sizeof(a[*n].malop));

    printf("Diem trung binh: ");
    scanf("%f", &a[*n].diemtrungbinh);
    while (getchar() != '\n'); // Xoa ki tu con xot trong bo dem nhap , 
    // Ngan ham doc luon cac ky tu rac hay \n cho lan lap tiep theo

    (*n)++;

    printf("+----Da them thanh cong sinh vien----+\n");
}

// 6. XOA SINH VIEN
void XoaSinhVien(Sinhvien a[], int* n, char MSSVCanXoa[]) {
    int i = TimKiemSinhVien(a, *n, MSSVCanXoa);
    if (i == -1) {
        printf("Khong tim thay sinh vien co MSSV [%s] de xoa\n", MSSVCanXoa);
        return;
    }
    for (int j = i; j < *n - 1; j++) {
        a[j] = a[j + 1];                 // Ghi de sinh vien vi tri j xoa bang sinh vien vi tri j + 1
    }
    (*n)--;
    printf("+---Da xoa sinh vien thanh cong---+\n");
}

// 7. CAP NHAT THONG TIN SINH VIEN
void CapNhatSinhVien(Sinhvien a[], int n, char MSSVCanCapNhat[]) {
    int i = TimKiemSinhVien(a, n, MSSVCanCapNhat);
    if (i == -1) {
        printf("Khong tim thay sinh vien co MSSV [%s] de cap nhat\n", MSSVCanCapNhat);
        return;
    }
    else {
        printf("\n--- Thong tin hien tai ---\n");
        printf("\n%-4s | %-10s | %-20s | %-12s | %-8s | %-12s | %-8s | %-6s\n",
            "STT", "MSSV", "Ho ten", "SDT", "Gioi tinh", "Ngay sinh", "Ma lop", "DTB");
        printf("---------------------------------------------------------------------------------------------------\n");
        printf("%-4d | %-10s | %-20s | %-12s | %-8s | %-12s | %-8s | %-6.2f\n",
            i + 1,
            a[i].mssv,
            a[i].hoten,
            a[i].sdt,
            a[i].gioitinh,
            a[i].ngaysinh,
            a[i].malop,
            a[i].diemtrungbinh);
        printf("---------------------------------------------------------------------------------------------------\n");

        printf("\n--- Nhap thong tin moi ---\n");

        printf("Ma so sinh vien: ");
        fflush(stdin);
        nhapChuoi(a[i].mssv, sizeof(a[i].mssv));

        printf("Ho va ten: ");
        nhapChuoi(a[i].hoten, sizeof(a[i].hoten));

        printf("So dien thoai: ");
        nhapChuoi(a[i].sdt, sizeof(a[i].sdt));

        printf("Gioi tinh: ");
        nhapChuoi(a[i].gioitinh, sizeof(a[i].gioitinh));

        printf("Ngay sinh: ");
        nhapChuoi(a[i].ngaysinh, sizeof(a[i].ngaysinh));

        printf("Ma lop: ");
        nhapChuoi(a[i].malop, sizeof(a[i].malop));

        printf("Diem trung binh: ");
        scanf("%f", &a[i].diemtrungbinh);
        getchar();

        printf("+----Da cap nhat thanh cong thong tin sinh vien----+\n");
    }
}
// 8. HAM SAP XEP DANH SACH THEO 2 TIEU CHI: TANG/GIAM THEO DIEM VA THEO TEN TU A DEN Z
// + Ham hoan doi
void Swap(Sinhvien* a, Sinhvien* b)
{
    Sinhvien temp = *a;
    *a = *b;
    *b = temp;
}
// a. Su dung thuat toan sap xep Interchange Sort cho Ham sap xep MSSV TANG DAN va GIAM DAN
void SapXepMSSVTangDan(Sinhvien a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[i].mssv > a[j].mssv)
            {
                Swap(&a[i], &a[j]);
            }
        }
    }
}
//
void SapXepMSSVGiamDan(Sinhvien a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[i].mssv < a[j].mssv)
            {
                Swap(&a[i], &a[j]);
            }
        }
    }
}
// b.Su dung thuat toan sap xep Bubble Sort cho sap xep Diem trung binh TANG DAN va GIAM DAN
void SapXepDTBTangDan(Sinhvien a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = n - 1; j > i; j--)
        {
            if (a[j].diemtrungbinh < a[j - 1].diemtrungbinh)
            {
                Swap(&a[j], &a[j - 1]);
            }
        }
    }
}
//
void SapXepDTBGiamDan(Sinhvien a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = n - 1; j > i; j--)
        {
            if (a[j].diemtrungbinh > a[j - 1].diemtrungbinh)
            {
                Swap(&a[j], &a[j - 1]);
            }
        }
    }
}
// c. Su dung thuat toan Insertion Sort cho sap xep So dien thoai TANG DAN va GIAM DAN 
void SapXepSDTTangDan(Sinhvien a[], int n)
{
    int pos;
    for (int i = 0; i < n; i++)
    {
        pos = i;
        while (pos > 0 && strcmp(a[pos].sdt, a[pos - 1].sdt) < 0)    //a[pos] < a[pos-1]
        {
            Swap(&a[pos], &a[pos - 1]);
            pos--;
        }
    }
}
//
void SapXepSDTGiamDan(Sinhvien a[], int n)
{
    int pos;
    for (int i = 0; i < n; i++)
    {
        pos = i;
        while (pos > 0 && strcmp(a[pos].sdt, a[pos - 1].sdt) > 0)    //a[pos] < a[pos-1]
        {
            Swap(&a[pos], &a[pos - 1]);
            pos--;
        }
    }
}
// d. Su dung thuat toan Selection Sort cho sap xep Ho Ten TANG DAN va GIAM DAN tu A den Z ( Z ve A )
void SapXepHoTenTangDan(Sinhvien a[], int n)
{
    int min;
    for (int i = 0; i < n - 1; i++)
    {
        min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (strcmp(a[j].hoten, a[min].hoten) < 0)         // a[j] < a[min]
            {
                min = j;
            }
        }

        if (min != i)
        {
            Swap(&a[min], &a[i]);
        }
    }
}
// 
void SapXepHoTenGiamDan(Sinhvien a[], int n)
{
    int max;
    for (int i = 0; i < n - 1; i++)
    {
        max = i;
        for (int j = i + 1; j < n; j++)
        {
            if (strcmp(a[j].hoten, a[max].hoten) > 0)         // a[j] > a[max]
            {
                max = j;
            }
        }

        if (max != i)
        {
            Swap(&a[max], &a[i]);
        }
    }
}


//. GHI DU LIEU RA TEP
void GhiFile(Sinhvien a[], int n)
{
    FILE* f = fopen("sinhvien.txt", "w");  // w = write : Mo file de ghi gu lieu 
    if (f == NULL)
    {
        printf("Khong the mo tep de ghi\n");
        return;
    }
    for (int i = 0; i < n; i++) {
        fprintf(f, "%s|%s|%s|%s|%s|%s|%.2f\n",
            a[i].mssv,
            a[i].hoten,
            a[i].sdt,
            a[i].gioitinh,
            a[i].ngaysinh,
            a[i].malop,
            a[i].diemtrungbinh);
    }

    fclose(f);
    printf("Da ghi %d sinh vien vao tep sinhvien.txt !\n", n);
}
//. DOC DU LIEU RA TEP 
void DocFile(Sinhvien a[])
{
    FILE* f = fopen("sinhvien.txt", "r");
    if (f == NULL) {
        printf("Khong the mo tep de doc\n");
        return;
    }

    int i = 0;
    while (fscanf(f, "%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%f\n",
        a[i].mssv,
        a[i].hoten,
        a[i].sdt,
        a[i].gioitinh,
        a[i].ngaysinh,
        a[i].malop,
        &a[i].diemtrungbinh) == 7) {
        i++;
    }

    fclose(f);
    printf("Da doc %d sinh vien tu tep sinhvien.txt !\n", i); // tra ve so luong sinh vien thuc te doc duoc
}
//. Ham lua chon sap xep TANG DAN hay GIAM DAN
void Updown(char* a)
{
    printf("Ban muon sap xep:\n");
    printf("[U].Tang dan\n");
    printf("[D].Giam dan\n");
    fflush(stdin);  //Xoa bo nho dem truoc khi nhap chuoi
    printf("[U-D]:");
    scanf("%c", a);
}
