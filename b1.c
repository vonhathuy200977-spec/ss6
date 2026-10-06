#include <stdio.h>
#include <string.h>

#define MAX_PHIEU 50
#define MAX_MA 20
#define TIEN_PHAT_MOI_NGAY 5000

int main() {
    char maPhieu[MAX_PHIEU][MAX_MA] = {
        "PM101",
        "PM102",
        "PM103"
    };

    int ngayQuaHan[MAX_PHIEU] = {0, 3, 5};

    int soLuong = 3;
    int choice;

    do {
        printf("\n--- HE THONG QUAN LY MUON TRA SACH (LIBRARY_WMS) ---\n");
        printf("1. Xem danh sach phieu muon\n");
        printf("2. Them moi phieu muon\n");
        printf("3. Cap nhat so ngay qua han\n");
        printf("0. Thoat\n");
        printf("Chon chuc nang: ");
        scanf("%d", &choice);

        // Xoa ky tu '\n' con lai trong bo dem
        while (getchar() != '\n');

        switch (choice) {

            // =====================================
            // 1. XEM DANH SACH
            // =====================================
            case 1: {
                printf("\n--- DANH SACH PHIEU MUON SACH ---\n");
                printf("STT | Ma Phieu | So Ngay Qua Han | Tien Phat (VND)\n");
                printf("--------------------------------------------------\n");

                for (int i = 0; i < soLuong; i++) {
                    int tienPhat = ngayQuaHan[i] * TIEN_PHAT_MOI_NGAY;

                    printf("%d | %s | %d ngay | %d VND\n",
                           i + 1,
                           maPhieu[i],
                           ngayQuaHan[i],
                           tienPhat);
                }

                printf("--------------------------------------------------\n");
                printf("Tong so phieu: %d\n", soLuong);

                break;
            }

            // =====================================
            // 2. THEM MOI PHIEU
            // =====================================
            case 2: {

                if (soLuong >= MAX_PHIEU) {
                    printf("Loi: Danh sach phieu muon da day, khong the them!\n");
                    break;
                }

                printf("Nhap ma phieu muon moi: ");
                scanf("%19s", maPhieu[soLuong]);

                // Phieu moi mac dinh 0 ngay qua han
                ngayQuaHan[soLuong] = 0;

                soLuong++;

                printf("Them phieu muon thanh cong!\n");

                break;
            }

            // =====================================
            // 3. CAP NHAT SO NGAY QUA HAN
            // =====================================
            case 3: {
                char maCanTim[MAX_MA];
                int viTri = -1;
                int ngayMoi;

                printf("Nhap ma phieu muon can cap nhat: ");
                scanf("%19s", maCanTim);

                // Tim kiem tuyen tinh bang strcmp()
                for (int i = 0; i < soLuong; i++) {
                    if (strcmp(maPhieu[i], maCanTim) == 0) {
                        viTri = i;
                        break;
                    }
                }

                if (viTri == -1) {
                    printf("Khong tim thay phieu muon '%s'!\n", maCanTim);
                } else {

                    printf("Tim thay phieu muon '%s' tai vi tri index %d.\n",
                           maPhieu[viTri],
                           viTri);

                    do {
                        printf("Nhap so ngay qua han moi: ");
                        scanf("%d", &ngayMoi);

                        // Xoa '\n' sau scanf so
                        while (getchar() != '\n');

                        if (ngayMoi < 0) {
                            printf("Loi: So ngay qua han phai >= 0. Vui long nhap lai!\n");
                        }

                    } while (ngayMoi < 0);

                    ngayQuaHan[viTri] = ngayMoi;

                    printf("Cap nhat thanh cong! So ngay qua han moi cua %s la %d ngay.\n",
                           maPhieu[viTri],
                           ngayQuaHan[viTri]);
                }

                break;
            }

            // =====================================
            // 0. THOAT
            // =====================================
            case 0:
                printf("\nCam on ban da su dung he thong LIBRARY_WMS!\n");
                break;

            // =====================================
            // NHAP SAI CHUC NANG
            // =====================================
            default:
                printf("Loi: Chuc nang khong hop le! Vui long chon lai.\n");
        }

    } while (choice != 0);

    return 0;
}