#include <stdio.h>
#include <stdlib.h>
#include <mem.h>
#include <conio.h>
#include <stdbool.h>

typedef struct sinhvien {
    char ten[50];
    char sdt[20];
    char msv[20];
} sinhvien;
sinhvien mangsinhvien[10];

void menu() {
    printf("1.Them moi sinh vien\n");
    printf("2.Hien thi danh sach sinh vien\n");
    printf("3.Luu danh sach sinh vien ra file\n");
    printf("4.Doc danh sach sinh vien tu file\n");
    printf("5.Thoat chuong trinh");
}

void nhapsinhvien() {
    printf("Nhap vao thong tin sinh vien\n");
    for (int i = 0; i < 1; ++i) {
        printf("Nhap vao ten cua sv:");
        fgets(mangsinhvien[i].ten, sizeof(mangsinhvien[i].ten) * sizeof(char), stdin);
        if (!strchr(mangsinhvien[i].ten, '\n')) {
            while (fgetc(stdin) != '\n');
        }
        mangsinhvien[i].ten[strlen(mangsinhvien[i].ten) - 1] = ' ';
        printf("Nhap vao sdt cua sv: ");
        fgets(mangsinhvien[i].sdt, sizeof(mangsinhvien[i].sdt) * sizeof(char), stdin);
        if (!strchr(mangsinhvien[i].sdt, '\n')) {
            while (fgetc(stdin) != '\n');
        }
        mangsinhvien[i].sdt[strlen(mangsinhvien[i].sdt) - 1] = ' ';
        printf("Nhap vao msv cua sv: ");
        fgets(mangsinhvien[i].msv, sizeof(mangsinhvien[i].msv) * sizeof(char), stdin);
        if (!strchr(mangsinhvien[i].msv, '\n')) {
            while (fgetc(stdin) != '\n');
        } else if(strlen(mangsinhvien[i].msv) < 5)
        {
            printf("Vui long nhap lai.Ma sinh vien khong du 5 ki tu\n");
            nhapsinhvien();
        }
        mangsinhvien[i].msv[strlen(mangsinhvien[i].msv) - 1] = ' ';
    }
}

void hienthidanhsachsv() {
    printf("Name: %s", mangsinhvien[0].ten);
    printf("Phone: %s", mangsinhvien[0].sdt);
    printf("MSV: %s", mangsinhvien[0].msv);
}

void luudanhsachsv() {
    FILE *fp;
    fp = fopen("../danhsachsinhvien.txt", "a+");
    for (int j = 0; j < 1; ++j) {
        fprintf(fp, "-%-9s|  %-15s|  %5s\n", mangsinhvien[j].ten, mangsinhvien[j].sdt, mangsinhvien[j].msv);
    }
    fclose(fp);
}

void xuatsinhvien() {
    FILE *fp;
    char Myfile[255];
    fp = fopen("../danhsachsinhvien.txt", "a+");
    while (fgets(Myfile, 225, fp) != NULL) {
        printf("%s", Myfile);
    }
    fclose(fp);
}

void hienthi() {
    int a;
    menu();
    scanf("%d", &a);
    getchar();
    switch (a) {
        case 1:
            nhapsinhvien();
            hienthi();
            break;
        case 2:
            hienthidanhsachsv();
            hienthi();
            break;
        case 3:
            luudanhsachsv();
            hienthi();
            break;
        case 4:
            xuatsinhvien();
            hienthi();
        default:
            break;
    }
}

int main() {
    FILE *fp;
    fp = fopen("../danhsachsinhvien.txt", "w+");
    fprintf(fp, "-Name     |     Phone       |     Msv\n");
    fclose(fp);
    hienthi();
}
