#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {
    char maSach[20];
    char tenSach[100];
    char tacGia[50];
    float giaTien;
    char theLoai[50];
} Sach;
Sach danhSach[100];
int soLuongSach = 0;
void nhapSach() {
    printf("Nhap so luong sach muon them: ");
    int soLuong;
    scanf("%d", &soLuong);
    getchar();
    for (int i = 0; i < soLuong; i++) {
        printf("\nNhap thong tin sach thu %d:\n", i + 1);
        printf("Ma sach: ");
        fgets(danhSach[soLuongSach].maSach, 20, stdin);
        danhSach[soLuongSach].maSach[strcspn(danhSach[soLuongSach].maSach, "\n")] = '\0';
        printf("Ten sach: ");
        fgets(danhSach[soLuongSach].tenSach, 100, stdin);
        danhSach[soLuongSach].tenSach[strcspn(danhSach[soLuongSach].tenSach, "\n")] = '\0';
        printf("Tac gia: ");
        fgets(danhSach[soLuongSach].tacGia, 50, stdin);
        danhSach[soLuongSach].tacGia[strcspn(danhSach[soLuongSach].tacGia, "\n")] = '\0';
        printf("Gia tien: ");
        scanf("%f", &danhSach[soLuongSach].giaTien);
        getchar();
        printf("The loai: ");
        fgets(danhSach[soLuongSach].theLoai, 50, stdin);
        danhSach[soLuongSach].theLoai[strcspn(danhSach[soLuongSach].theLoai, "\n")] = '\0';
        soLuongSach++;
    }
}
void hienThiSach() {
    printf("\nDanh sach sach:\n");
    for (int i = 0; i < soLuongSach; i++) {
        printf("\nSach thu %d:\n", i + 1);
        printf("Ma sach: %s\n", danhSach[i].maSach);
        printf("Ten sach: %s\n", danhSach[i].tenSach);
        printf("Tac gia: %s\n", danhSach[i].tacGia);
        printf("Gia tien: %.2f\n", danhSach[i].giaTien);
        printf("The loai: %s\n", danhSach[i].theLoai);
    }
}
void themSach() {
    if (soLuongSach >= 100) {
        printf("\nKhong the them sach, bo nho day!\n");
        return;
    }
    int viTri;
    printf("Nhap vi tri muon them sach (0 - %d): ", soLuongSach);
    scanf("%d", &viTri);
    getchar();
    if (viTri < 0 || viTri > soLuongSach) {
        printf("Vi tri khong hop le!\n");
        return;
    }
    for (int i = soLuongSach; i > viTri; i--) {
        danhSach[i] = danhSach[i - 1];
    }
    printf("Nhap thong tin sach:\n");
    printf("Ma sach: ");
    fgets(danhSach[viTri].maSach, 20, stdin);
    danhSach[viTri].maSach[strcspn(danhSach[viTri].maSach, "\n")] = '\0';
    printf("Ten sach: ");
    fgets(danhSach[viTri].tenSach, 100, stdin);
    danhSach[viTri].tenSach[strcspn(danhSach[viTri].tenSach, "\n")] = '\0';
    printf("Tac gia: ");
    fgets(danhSach[viTri].tacGia, 50, stdin);
    danhSach[viTri].tacGia[strcspn(danhSach[viTri].tacGia, "\n")] = '\0';
    printf("Gia tien: ");
    scanf("%f", &danhSach[viTri].giaTien);
    getchar();
    printf("The loai: ");
    fgets(danhSach[viTri].theLoai, 50, stdin);
    danhSach[viTri].theLoai[strcspn(danhSach[viTri].theLoai, "\n")] = '\0';
    soLuongSach++;
}
void xoaSach() {
    char maSach[20];
    printf("Nhap ma sach can xoa: ");
    fgets(maSach, 20, stdin);
    maSach[strcspn(maSach, "\n")] = '\0';
    int found = 0;
    for (int i = 0; i < soLuongSach; i++) {
        if (strcmp(danhSach[i].maSach, maSach) == 0) {
            found = 1;
            for (int j = i; j < soLuongSach - 1; j++) {
                danhSach[j] = danhSach[j + 1];
            }
            soLuongSach--;
            printf("Xoa sach thanh cong!\n");
            break;
        }
    }
    if (!found) {
        printf("Khong tim thay ma sach!\n");
    }
}
void capNhatSach() {
    char maSach[20];
    printf("Nhap ma sach can cap nhat: ");
    fgets(maSach, 20, stdin);
    maSach[strcspn(maSach, "\n")] = '\0';
    int found = 0;
    for (int i = 0; i < soLuongSach; i++) {
        if (strcmp(danhSach[i].maSach, maSach) == 0) {
            found = 1;
            printf("Nhap thong tin moi:\n");
            printf("Ten sach: ");
            fgets(danhSach[i].tenSach, 100, stdin);
            danhSach[i].tenSach[strcspn(danhSach[i].tenSach, "\n")] = '\0';
            printf("Tac gia: ");
            fgets(danhSach[i].tacGia, 50, stdin);
            danhSach[i].tacGia[strcspn(danhSach[i].tacGia, "\n")] = '\0';
            printf("Gia tien: ");
            scanf("%f", &danhSach[i].giaTien);
            getchar();
            printf("The loai: ");
            fgets(danhSach[i].theLoai, 50, stdin);
            danhSach[i].theLoai[strcspn(danhSach[i].theLoai, "\n")] = '\0';
            printf("Cap nhat thong tin sach thanh cong!\n");
            break;
        }
    }
    if (!found) {
        printf("Khong tim thay ma sach!\n");
    }
}
void sapXepSach() {
    int tangDan;
    printf("Nhap 1 de sap xep tang dan, 0 de sap xep giam dan: ");
    scanf("%d", &tangDan);
    getchar();
    for (int i = 0; i < soLuongSach - 1; i++) {
        for (int j = i + 1; j < soLuongSach; j++) {
            if ((tangDan && danhSach[i].giaTien > danhSach[j].giaTien) ||
                (!tangDan && danhSach[i].giaTien < danhSach[j].giaTien)) {
                Sach temp = danhSach[i];
                danhSach[i] = danhSach[j];
                danhSach[j] = temp;
            }
        }
    }
    printf("Sap xep sach thanh cong!\n");
}
void timKiemSach() {
    char tenSach[100];
    printf("Nhap ten sach can tim: ");
    fgets(tenSach, 100, stdin);
    tenSach[strcspn(tenSach, "\n")] = '\0';
    printf("\nKet qua tim kiem:\n");
    int found = 0;
    for (int i = 0; i < soLuongSach; i++) {
        if (strstr(danhSach[i].tenSach, tenSach) != NULL) {
            found = 1;
            printf("\nMa sach: %s\n", danhSach[i].maSach);
            printf("Ten sach: %s\n", danhSach[i].tenSach);
            printf("Tac gia: %s\n", danhSach[i].tacGia);
            printf("Gia tien: %.2f\n", danhSach[i].giaTien);
            printf("The loai: %s\n", danhSach[i].theLoai);
        }
    }
    if (!found) {
        printf("Khong tim thay sach!\n");
    }
}
int main() {
    int luaChon;
    do {
        printf("\nMENU\n");
        printf("1. Nhap so luong va thong tin sach\n");
        printf("2. Hien thi thong tin sach\n");
        printf("3. Them sach vao vi tri\n");
        printf("4. Xoa sach theo ma sach\n");
        printf("5. Cap nhat thong tin sach theo ma sach\n");
        printf("6. Sap xep sach theo gia (tang/giam)\n");
        printf("7. Tim kiem sach theo ten sach\n");
        printf("8. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &luaChon);
        getchar();
        switch (luaChon) {
            case 1:
                nhapSach();
                break;
            case 2:
                hienThiSach();
                break;
            case 3:
                themSach();
                break;
            case 4:
                xoaSach();
                break;
            case 5:
                capNhatSach();
                break;
            case 6:
                sapXepSach();
                break;
            case 7:
                timKiemSach();
                break;
            case 8:
                printf("Thoat chuong trinh. Tam biet!\n");
                break;
            default:
                printf("Lua chon khong hop le!\n");
        }
    } while (luaChon != 8);
    return 0;
}

