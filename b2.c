#include <stdio.h>
#include <string.h>

#define MAX 100

int main() {
    char maPhieu[MAX][15];
    char tenSach[MAX][50];

    int soNgayMuon[MAX];
    int tienPhat[MAX];

    int soLuong = 0;
    int luaChon;

    do {
        printf("\n");
        printf("==============================================================\n");
        printf("       HE THONG QUAN LY MUON TRA SACH (LIBRARY_WMS)\n");
        printf("==============================================================\n");
        printf("1. Them luot muon sach moi\n");
        printf("2. Hien thi danh sach muon sach\n");
        printf("3. Cap nhat so ngay muon theo Ma phieu\n");
        printf("4. Xoa luot muon sach theo Ma phieu\n");
        printf("5. Thong ke danh sach phieu muon bi phat\n");
        printf("6. Thoat chuong trinh\n");
        printf("==============================================================\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &luaChon);

        while (getchar() != '\n');

        switch (luaChon) {

            // ==================================================
            // CHUC NANG 1: THEM PHIEU MUON
            // ==================================================
            case 1: {
                if (soLuong >= MAX) {
                    printf("He thong day, khong the them phieu muon moi!\n");
                    break;
                }

                printf("\n=== THEM LUOT MUON SACH MOI ===\n");

                // Nhap ma phieu va kiem tra trung
                int trungMa;

                do {
                    trungMa = 0;

                    printf("Nhap ma phieu muon: ");
                    scanf("%14s", maPhieu[soLuong]);

                    while (getchar() != '\n');

                    // Tim ma trung
                    for (int i = 0; i < soLuong; i++) {
                        if (strcmp(maPhieu[i], maPhieu[soLuong]) == 0) {
                            trungMa = 1;
                            break;
                        }
                    }

                    if (trungMa == 1) {
                        printf("Ma phieu da ton tai! Vui long nhap ma khac.\n");
                    }

                } while (trungMa == 1);


                // Nhap ten sach
                printf("Nhap ten sach: ");
                fgets(tenSach[soLuong], 50, stdin);

                // Xoa ky tu '\n'
                if (strlen(tenSach[soLuong]) > 0 &&
                    tenSach[soLuong][strlen(tenSach[soLuong]) - 1] == '\n') {

                    tenSach[soLuong][strlen(tenSach[soLuong]) - 1] = '\0';
                }


                // Nhap so ngay muon
                do {
                    printf("Nhap so ngay muon thuc te: ");
                    scanf("%d", &soNgayMuon[soLuong]);

                    while (getchar() != '\n');

                    if (soNgayMuon[soLuong] <= 0) {
                        printf("So ngay muon phai > 0. Vui long nhap lai!\n");
                    }

                } while (soNgayMuon[soLuong] <= 0);


                // Tinh tien phat
                tienPhat[soLuong] =
                    (soNgayMuon[soLuong] > 14)
                    ? (soNgayMuon[soLuong] - 14) * 5000
                    : 0;

                printf("-> Tien phat tu dong tinh: %d VND\n",
                       tienPhat[soLuong]);

                soLuong++;

                printf("-> Them luot muon sach thanh cong!\n");

                break;
            }


            // ==================================================
            // CHUC NANG 2: HIEN THI DANH SACH
            // ==================================================
            case 2: {

                if (soLuong == 0) {
                    printf("\nDanh sach muon sach hien dang rong!\n");
                    break;
                }

                int tongTienPhat = 0;

                printf("\n");
                printf("==========================================================================\n");
                printf("                     DANH SACH MUON SACH\n");
                printf("==========================================================================\n");

                printf("%-5s | %-10s | %-30s | %-10s | %-15s\n",
                       "STT",
                       "Ma Phieu",
                       "Ten Sach",
                       "So Ngay",
                       "Tien Phat (VND)");

                printf("--------------------------------------------------------------------------\n");

                for (int i = 0; i < soLuong; i++) {

                    printf("%-5d | %-10s | %-30s | %-10d | %-15d\n",
                           i + 1,
                           maPhieu[i],
                           tenSach[i],
                           soNgayMuon[i],
                           tienPhat[i]);

                    tongTienPhat += tienPhat[i];
                }

                printf("--------------------------------------------------------------------------\n");

                printf("Tong tien phat toan he thong: %d VND\n",
                       tongTienPhat);

                break;
            }


            // ==================================================
            // CHUC NANG 3: CAP NHAT
            // ==================================================
            case 3: {

                if (soLuong == 0) {
                    printf("\nDanh sach muon sach hien dang rong!\n");
                    break;
                }

                char maNhap[15];
                int index = -1;
                int ngayMoi;

                printf("\n=== CAP NHAT SO NGAY MUON ===\n");

                printf("Nhap ma phieu muon can cap nhat: ");
                scanf("%14s", maNhap);

                while (getchar() != '\n');


                // Tim vi tri phieu muon
                for (int i = 0; i < soLuong; i++) {

                    if (strcmp(maPhieu[i], maNhap) == 0) {
                        index = i;
                        break;
                    }
                }


                // Khong tim thay
                if (index == -1) {

                    printf("Khong tim thay phieu muon co ma: %s\n",
                           maNhap);

                } else {

                    printf("Tim thay phieu muon cua sach: %s\n",
                           tenSach[index]);

                    printf("So ngay hien tai: %d\n",
                           soNgayMuon[index]);


                    // Nhap so ngay moi
                    do {
                        printf("Nhap so ngay muon thuc te moi: ");
                        scanf("%d", &ngayMoi);

                        while (getchar() != '\n');

                        if (ngayMoi <= 0) {
                            printf("So ngay muon phai > 0. Vui long nhap lai!\n");
                        }

                    } while (ngayMoi <= 0);


                    // Cap nhat so ngay
                    soNgayMuon[index] = ngayMoi;


                    // Tinh lai tien phat
                    tienPhat[index] =
                        (soNgayMuon[index] > 14)
                        ? (soNgayMuon[index] - 14) * 5000
                        : 0;


                    printf("-> Tien phat moi: %d VND\n",
                           tienPhat[index]);

                    printf("-> Cap nhat so ngay muon thanh cong!\n");
                }

                break;
            }


            // ==================================================
            // CHUC NANG 4: XOA
            // ==================================================
            case 4: {

                if (soLuong == 0) {
                    printf("\nDanh sach muon sach hien dang rong!\n");
                    break;
                }

                char maNhap[15];
                int index = -1;

                printf("\n=== XOA LUOT MUON SACH ===\n");

                printf("Nhap ma phieu muon can xoa: ");
                scanf("%14s", maNhap);

                while (getchar() != '\n');


                // Tim vi tri
                for (int i = 0; i < soLuong; i++) {

                    if (strcmp(maPhieu[i], maNhap) == 0) {
                        index = i;
                        break;
                    }
                }


                // Khong tim thay
                if (index == -1) {

                    printf("Khong tim thay phieu muon co ma: %s\n",
                           maNhap);

                } else {

                    // Don mang
                    for (int i = index; i < soLuong - 1; i++) {

                        strcpy(maPhieu[i], maPhieu[i + 1]);

                        strcpy(tenSach[i], tenSach[i + 1]);

                        soNgayMuon[i] = soNgayMuon[i + 1];

                        tienPhat[i] = tienPhat[i + 1];
                    }


                    // Giam so luong
                    soLuong--;

                    printf("Xoa phieu muon thanh cong!\n");
                }

                break;
            }


            // ==================================================
            // CHUC NANG 5: THONG KE PHIEU BI PHAT
            // ==================================================
            case 5: {

                if (soLuong == 0) {
                    printf("\nDanh sach muon sach hien dang rong!\n");
                    break;
                }

                int coPhieuPhat = 0;

                printf("\n");
                printf("==============================================================\n");
                printf("             DANH SACH PHIEU MUON BI PHAT\n");
                printf("==============================================================\n");

                printf("%-5s | %-10s | %-30s | %-10s | %-15s\n",
                       "STT",
                       "Ma Phieu",
                       "Ten Sach",
                       "So Ngay",
                       "Tien Phat");

                printf("--------------------------------------------------------------\n");


                for (int i = 0; i < soLuong; i++) {

                    if (soNgayMuon[i] > 14) {

                        printf("%-5d | %-10s | %-30s | %-10d | %-15d\n",
                               i + 1,
                               maPhieu[i],
                               tenSach[i],
                               soNgayMuon[i],
                               tienPhat[i]);

                        coPhieuPhat = 1;
                    }
                }


                if (coPhieuPhat == 0) {
                    printf("Khong co luot muon nao bi qua han phat!\n");
                }

                break;
            }


            // ==================================================
            // CHUC NANG 6: THOAT
            // ==================================================
            case 6:

                printf("\nCam on ban da su dung LIBRARY_WMS!\n");
                printf("Ket thuc chuong trinh.\n");

                break;


            // ==================================================
            // NHAP SAI
            // ==================================================
            default:

                printf("Lua chon khong hop le. Vui long thu lai!\n");
        }

    } while (luaChon != 6);


    return 0;
}