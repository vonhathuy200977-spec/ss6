#include <stdio.h>
#include <string.h>

#define MAX 100

int main() {
    char maPhieu[MAX][20];
    char maSach[MAX][20];

    int soNgayMuon[MAX];
    int soLuong = 0;
    int luaChon;

    do {
        printf("\n");
        printf("==============================================================\n");
        printf("       HE THONG QUAN LY MUON TRA SACH (LOGISTICS)\n");
        printf("==============================================================\n");
        printf("1. Them moi phieu muon sach (Create)\n");
        printf("2. Hien thi danh sach phieu muon & Tien phat (Read)\n");
        printf("3. Cap nhat so ngay muon sach (Update)\n");
        printf("4. Xac nhan tra sach / Xoa phieu muon (Delete)\n");
        printf("5. Thoat chuong trinh\n");
        printf("==============================================================\n");
        printf("Lua chon cua ban (1-5): ");
        scanf("%d", &luaChon);

        while (getchar() != '\n');

        switch (luaChon) {

            // ================================================
            // 1. THEM PHIEU MUON
            // ================================================
            case 1: {
                if (soLuong >= MAX) {
                    printf("Bo nho danh sach da day, khong the them moi!\n");
                    break;
                }

                printf("\n--- THEM MOI PHIEU MUON ---\n");

                char maPhieuMoi[20];
                int trungMa = 0;

                printf("Nhap ma phieu: ");
                scanf("%19s", maPhieuMoi);

                while (getchar() != '\n');

                // Kiem tra ma phieu trung
                for (int i = 0; i < soLuong; i++) {
                    if (strcmp(maPhieu[i], maPhieuMoi) == 0) {
                        trungMa = 1;
                        break;
                    }
                }

                if (trungMa == 1) {
                    printf("Ma phieu da ton tai trong he thong!\n");
                    break;
                }

                // Luu ma phieu
                strcpy(maPhieu[soLuong], maPhieuMoi);

                // Nhap ma sach
                printf("Nhap ma sach: ");
                scanf("%19s", maSach[soLuong]);

                while (getchar() != '\n');

                // Nhap so ngay muon
                do {
                    printf("Nhap so ngay muon: ");
                    scanf("%d", &soNgayMuon[soLuong]);

                    while (getchar() != '\n');

                    if (soNgayMuon[soLuong] <= 0) {
                        printf("So ngay muon phai > 0. Vui long nhap lai!\n");
                    }

                } while (soNgayMuon[soLuong] <= 0);

                soLuong++;

                printf("Them moi phieu muon thanh cong!\n");

                break;
            }


            // ================================================
            // 2. HIEN THI DANH SACH
            // ================================================
            case 2: {

                if (soLuong == 0) {
                    printf("Danh sach phieu muon hien dang rong!\n");
                    break;
                }

                printf("\n");
                printf("==========================================================================\n");
                printf("                    DANH SACH PHIEU MUON\n");
                printf("==========================================================================\n");

                printf("%-5s | %-10s | %-12s | %-12s | %-15s | %-15s\n",
                       "STT",
                       "Ma Phieu",
                       "Ma Sach",
                       "So Ngay",
                       "Trang Thai",
                       "Tien Phat");

                printf("--------------------------------------------------------------------------\n");

                for (int i = 0; i < soLuong; i++) {

                    int ngayQuaHan;
                    int tienPhat;

                    if (soNgayMuon[i] > 14) {
                        ngayQuaHan = soNgayMuon[i] - 14;
                        tienPhat = ngayQuaHan * 5000;

                        printf("%-5d | %-10s | %-12s | %-12d | %-15s | %-15d\n",
                               i + 1,
                               maPhieu[i],
                               maSach[i],
                               soNgayMuon[i],
                               "QUA HAN",
                               tienPhat);
                    } else {
                        tienPhat = 0;

                        printf("%-5d | %-10s | %-12s | %-12d | %-15s | %-15d\n",
                               i + 1,
                               maPhieu[i],
                               maSach[i],
                               soNgayMuon[i],
                               "DUNG HAN",
                               tienPhat);
                    }
                }

                printf("==========================================================================\n");

                break;
            }


            // ================================================
            // 3. CAP NHAT SO NGAY MUON
            // ================================================
            case 3: {

                if (soLuong == 0) {
                    printf("Danh sach phieu muon hien dang rong!\n");
                    break;
                }

                char maNhap[20];
                int pos = -1;
                int soNgayMoi;

                printf("\n--- CAP NHAT SO NGAY MUON ---\n");

                printf("Nhap ma phieu can cap nhat: ");
                scanf("%19s", maNhap);

                while (getchar() != '\n');

                // Tim ma phieu
                for (int i = 0; i < soLuong; i++) {
                    if (strcmp(maPhieu[i], maNhap) == 0) {
                        pos = i;
                        break;
                    }
                }

                // Khong tim thay
                if (pos == -1) {

                    printf("Khong tim thay ma phieu trong he thong!\n");

                } else {

                    printf("So ngay muon hien tai cua phieu %s la: %d\n",
                           maPhieu[pos],
                           soNgayMuon[pos]);

                    do {
                        printf("Nhap so ngay muon moi: ");
                        scanf("%d", &soNgayMoi);

                        while (getchar() != '\n');

                        if (soNgayMoi <= 0) {
                            printf("So ngay muon phai > 0. Vui long nhap lai!\n");
                        }

                    } while (soNgayMoi <= 0);

                    soNgayMuon[pos] = soNgayMoi;

                    printf("Cap nhat so ngay muon thanh cong!\n");
                }

                break;
            }


            // ================================================
            // 4. XOA PHIEU MUON
            // ================================================
            case 4: {

                if (soLuong == 0) {
                    printf("Danh sach phieu muon hien dang rong!\n");
                    break;
                }

                char maNhap[20];
                int pos = -1;

                printf("\n--- XAC NHAN TRA SACH / XOA PHIEU ---\n");

                printf("Nhap ma phieu xac nhan tra/xoa: ");
                scanf("%19s", maNhap);

                while (getchar() != '\n');

                // Tim vi tri can xoa
                for (int i = 0; i < soLuong; i++) {
                    if (strcmp(maPhieu[i], maNhap) == 0) {
                        pos = i;
                        break;
                    }
                }

                // Khong tim thay
                if (pos == -1) {

                    printf("Khong tim thay ma phieu can xoa!\n");

                } else {

                    // Don mang sang trai
                    for (int i = pos; i < soLuong - 1; i++) {

                        strcpy(maPhieu[i], maPhieu[i + 1]);

                        strcpy(maSach[i], maSach[i + 1]);

                        soNgayMuon[i] = soNgayMuon[i + 1];
                    }

                    // Giam so luong
                    soLuong--;

                    printf("Xac nhan tra sach va xoa phieu muon thanh cong!\n");
                }

                break;
            }


            // ================================================
            // 5. THOAT
            // ================================================
            case 5:

                printf("\nCam on ban da su dung LIBRARY_WMS LOGISTICS!\n");
                printf("Thoat chuong trinh thanh cong.\n");

                break;


            // ================================================
            // NHAP SAI
            // ================================================
            default:

                printf("Lua chon khong hop le, vui long chon lai!\n");
        }

    } while (luaChon != 5);

    return 0;
}