// Tieuluan1.cpp : This file contains the 'main' function. Program execution begins and ends there.
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Header1.h"

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
// MAIN
int main() {
	int n;
	char username[30];
	printf("\n+----------- HE CO SO DU LIEU QUAN LY SINH VIEN -----------+\n");

	printf("Nhap ten cua ban: ");          // Nhap ten nguoi dung
	nhapChuoi(username, sizeof(username));
	printf("Chao mung %s !\n", username);
	do
	{
		printf("Nhap so sinh vien [Toi da 200]: ");
		scanf("%d", &n);
	} while (n <= 0);
	getchar();

	Sinhvien a[MAX];

	// Su dung ham chuc nang
	int i;
	do
	{
		printf("\n[+].Danh sach chuc nang:\n");
		printf("[0].Nhap thong tin sinh vien\n");
		printf("[1].Them sinh vien\n");
		printf("[2].Hien thi danh sach sinh vien\n");
		printf("[3].Tim kiem sinh vien\n");
		printf("[4].Xoa sinh vien\n");
		printf("[5].Cap nhat thong tin sinh vien\n");
		printf("[6].Sap xep danh sach sinh vien\n");
		printf("[7].Ghi du lieu ra tep\n");
		printf("[8].Doc du lieu tu tep\n");
		printf("[9].Thoat\n");
		printf("\n");
		printf("Chon chuc nang [1-9]: ");
		scanf("%d", &i);
		getchar(); // Xóa bo nho dem sau khi scanf
		switch (i)
		{
		case 0: nhap(a, n);
			xuat(a, n); break;
		case 1: ThemSinhVien(a, &n); break;           // Them sinh vien
		case 2: xuat(a, n); break;                   // Hien thi danh sach sinh vien
		case 3:                                    // Tim kiem sinh vien
		{
			char thongtintimkiem[50];
			printf("Nhap thong tin cua sinh vien can tim: ");
			nhapChuoi(thongtintimkiem, sizeof(thongtintimkiem));
			int i = TimKiemSinhVien(a, n, thongtintimkiem);
			if (i == 0)
			{
				printf("Khong tim thay sinh vien nao co thong tin tren:");
			}
			else
			{
				printf("----------------------------------DA TIM THAY SINH VIEN !-------------------------------------------\n");
				printf("\n%-4s | %-10s | %-20s | %-12s | %-8s | %-12s | %-8s | %-6s\n",
					"STT", "MSSV", "Ho ten", "SDT", "Gioi tinh", "Ngay sinh", "Ma lop", "DTB");
				printf("----------------------------------------------------------------------------------------------------\n");
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
			printf("----------------------------------------------------------------------------------------------------\n");
		}break;
		case 4:                                   // Xoa sinh vien
		{
			char MSSVCanXoa[10];
			printf("Nhap MSSV cua sinh vien can xoa:");
			fflush(stdin);  //Xoa bo nho dem truoc khi nhap chuoi
			nhapChuoi(MSSVCanXoa, sizeof(MSSVCanXoa));
			XoaSinhVien(a, &n, MSSVCanXoa);
		}
		break;
		case 5:                                   // Cap nhat thong tin sinh vien
		{
			char MSSVCapNhat[10];
			printf("Nhap MSSV cua sinh vien can cap nhat:");
			fflush(stdin);  //Xoa bo nho dem truoc khi nhap chuoi
			nhapChuoi(MSSVCapNhat, sizeof(MSSVCapNhat));
			CapNhatSinhVien(a, n, MSSVCapNhat);
		}
		break;
		case 6:                                   // Sap xep danh sach sinh vien
		{
			char upordown;
			char choice;                           // Chon sap xep theo DTB tang dan hay giam dan
			printf("\n---Chon muc can sap xep---\n");
			printf("[a].Sap xep theo diem trung binh \n");
			printf("[b].Sap xep theo ho va ten [A <-> Z]\n");
			printf("[c].Sap xep theo so dien thoai\n");
			printf("[d].Sap xep theo ma so sinh vien\n");
			printf("[a-c]:");
			scanf("%c", &choice);
			switch (choice)
			{
			case 'a':                         // Sap xep theo diem trung binh
			{
				Updown(&upordown);        // Chon sap xep tang dan hay giam dan ?
				switch (upordown)
				{
				case 'U': // Tang dan
					SapXepDTBTangDan(a, n);
					printf("\n------------------Danh sach sinh vien sap xep theo diem trung binh tang dan-----------------------\n");
					xuat(a, n); break;
				case 'D': // Giam dan
					printf("\n------------------Danh sach sinh vien sap xep theo diem trung binh giam dan-----------------------\n");
					SapXepDTBGiamDan(a, n);
					xuat(a, n); break;
				default: printf("Lua chon khong hop le!");
				}
			}
			break;

			case 'b':                         // Sap xep theo Ho va ten
			{
				Updown(&upordown);
				switch (upordown)
				{
				case 'U':
					SapXepHoTenTangDan(a, n);
					printf("\n---------------------Danh sach sinh vien sap xep theo Ho va ten tang dan----------------------------\n");
					xuat(a, n); break;
				case 'D':
					printf("\n---------------------Danh sach sinh vien sap xep theo Ho va ten giam dan----------------------------\n");
					SapXepHoTenGiamDan(a, n);
					xuat(a, n); break;
				default: printf("Lua chon khong hop le!");
				}

			}
			break;

			case 'c':                          // Sap xep theo So dien thoai
			{
				Updown(&upordown);
				switch (upordown)
				{
				case 'U':
					SapXepSDTTangDan(a, n);
					printf("\n-------------------Danh sach sinh vien sap xep theo So dien thoai tang dan----------------------------\n");
					xuat(a, n); break;
				case 'D':
					printf("\n-------------------Danh sach sinh vien sap xep theo So dien thoai giam dan----------------------------\n");
					SapXepSDTGiamDan(a, n);
					xuat(a, n); break;
				default: printf("Lua chon khong hop le!");
				}
			}
			case 'd':                            // Sap xep theo Ma so sinh vien
			{
				Updown(&upordown);
				switch (upordown)
				{
				case 'U':
					SapXepMSSVTangDan(a, n);
					printf("\n-------------------Danh sach sinh vien sap xep theo Ma so sinh vien tang dan----------------------------\n");
					xuat(a, n); break;
				case 'D':
					printf("\n-------------------Danh sach sinh vien sap xep theo Ma so sinh vien giam dan----------------------------\n");
					SapXepMSSVGiamDan(a, n);
					xuat(a, n); break;
				default: printf("Lua chon khong hop le!");
				}
			}
			break;

			default:
				printf("Lua chon khong hop le !\n");
			}
		}
		break;
		case 7:  GhiFile(a, n); break;              // Ghi du lieu ra tep
		case 8:  DocFile(a); break;                // Doc du lieu tu tep
		case 9:  break;
		default: printf("Lua chon khong hop le !\n");
		}
	} while (i != 9);
	printf("=== Ket thuc chuong trinh quan ly sinh vien ===\n");
	return 0;
}

