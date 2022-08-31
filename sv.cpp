#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
struct SinhVien{ 
    char ten[20]; 
    char gt[5]; 
    int tuoi; 
    float dT, dL, dH,dTB; 
    };
    typedef SinhVien SV;
    
    void screen() {
	            system("cls");
             printf("******************************************\n");
             printf("**    CHUONG TRINH QUAN LY SINH VIEN    **\n");
             printf("**      1. In danh sach sinh vien       **\n");
             printf("**      2. Sap xep sinh vien theo dTB   **\n");
             printf("**      3. Xep loai sinh vien           **\n");
             printf("**      4. Xuat DS sinh vien ra file	**\n");
             printf("**      5. Thoat                        **\n");
             printf("**       Nhap lua chon cua ban ?        **\n");
             printf("******************************************\n");
}
void nhap(SV a[],SV b[], int n) {
	printf("\n____________________________________\n");
	for(int i = 0; i < n; i++) {
		printf("---Sinh vien thu %d---\n",i+1);
		printf("\nNhap ten: "); fflush(stdin); gets(a[i].ten);
		strcpy(b[i].ten,a[i].ten);
		printf("\nNhap gioi tinh: "); gets(a[i].gt);
	    printf("\nNhap tuoi: "); scanf("%d", &a[i].tuoi);
	    printf("\nNhap diem 3 mon: "); scanf("%f%f%f", &a[i].dT, &a[i].dL, &a[i].dH);
		a[i].dTB = (a[i].dH + a[i].dL + a[i].dT)/3;
		b[i].dTB = a[i].dTB;
	}
	printf("\n____________________________________\n");
}
void mode1(SV a[], int n) {
	printf("\n____________________________________\n");
	for(int i = 0; i < n; i++) {
		printf("---Sinh vien thu %d---\n",i+1);
		printf("Ho ten SV: %s\n", a[i].ten);
	    printf("Gioi tinh: %s\n", a[i].gt);
		printf("Tuoi: %d\n",a[i].tuoi);
		printf("Diem Toan: %.1f\nDiem Ly: %.1f\nDiem Hoa: %.1f\n",a[i].dT,a[i].dL,a[i].dH);
	}
	printf("____________________________________\n");
}
void mode2(SV b[], int n) {
	for(int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if(b[i].dTB < b[j].dTB) {
				int temp = b[i].dTB;
				b[i].dTB = b[j].dTB;
				b[j].dTB = temp;
			}
		}
	}
    printf("\n____________________________________\n");
	for(int i = 0; i < n; i++) {
		printf("\nTop %d: %s: %.1f diem",i+1,b[i].ten,b[i].dTB);
	}
	printf("\n____________________________________\n");
}
void mode3(SV a[], int n) {
	printf("\n____________________________________\n");
    for(int i = 0;i < n;i++){
        if (a[i].dTB >= 8) {
			printf("\n%s la hoc sinh gioi",a[i].ten);
		} else if (a[i].dTB >= 6.5) {
			printf("\n%s la hoc sinh tien tien",a[i].ten);
		} else if (a[i].dTB >= 5) {
			printf("\n%s la hoc sinh trung binh",a[i].ten);
		} else {
			printf("\n%s la hoc sinh yeu",a[i].ten);
		}
    }
    printf("\n____________________________________\n");
}
void mode4(SV a[], int n, char fileName[]) {
	FILE *fp;
	fp = fopen (fileName,"w");
	fprintf(fp, "%s\t %s\t %s\t %s\t %s\t %s\t %s\n", "Ho Ten","GT", "Tuoi", "DT", "DL", "DH", "DTB");	if (fp == NULL) {
		printf("fail!");
	}
	for(int i = 0; i < n; i++) {
		fprintf(fp, "%s\t %s\t %d\t %.1f\t %.1f\t %.1f\t %.1f\n", a[i].ten,a[i].gt, a[i].tuoi, a[i].dT, a[i].dL, a[i].dH, a[i].dTB);
	}
	fclose(fp);
	printf("DS Sinh vien da duoc luu trong DSSV.txt !\n");
}
/*
	FILE * fp;
    fp = fopen (fileName,"w");
    fprintf(fp, "%20s %5s %5s %10s %10s %10s %10s\n", "Ho Ten","GT", "Tuoi", "DT", "DL", "DH", "DTB");
    for(int i = 0;i < n;i++){
        fprintf(fp, "%20s %5s %5d %10f %10f %10f %10f\n", a[i].ten,a[i].gt, a[i].tuoi, a[i].dT, a[i].dL, a[i].dH, a[i].dTB);
    }
    fclose (fp);
*/
void mode5() {
	char s[4];
	printf("Are you sure ?\nYes/No ? ");
	fflush(stdin); gets(s);
	if (strcmp(s,"yes") == 0) {
		printf("Ban da thoat chuong trinh!");
		exit(0);
	}
}
int main() {
	int n;
	printf("Nhap so luong sinh vien: "); scanf("%d",&n);
	int key;
	SV a[n],b[n];
	nhap(a,b,n);
	char fileName[] = "DSSV.txt";
	while(1) {
		screen();
		scanf("%d",&key);
		switch(key) {
			case 0:
                printf("\nBan da chon nhap DS sinh vien!");
                nhap(a,b, n);
                printf("\nBan da nhap thanh cong!");
                printf("\nBam phim bat ky de tiep tuc!");
                getch();

                break;
			case 1:
				printf("**      1. In danh sach sinh vien       **\n");
				mode1(a,n);
				printf("Enter any key to continue...");
				getch();
				break;
			case 2:
				printf("**      2. Sap xep sinh vien theo dTB   **\n");
				mode2(b,n);
				printf("Enter any key to continue...");
				getch();
				break;
			case 3:
				printf("**      3. Xep loai sinh vien           **\n");
				mode3(a,n);
				printf("Enter any key to continue...");
				getch();
				break;
			case 4:
				printf("**      4. Xuat DS sinh vien ra file	**\n");
				mode4(a,n,fileName);
				printf("Enter any key to continue...");
				getch();
				break;
			case 5:
				printf("**      5. Thoat                        **\n");
				mode5();
				printf("Enter any key to continue...");
				getch();
				break;
			default:
				printf("Khong co chuc nang nay!\n");
				printf("Enter any key to continue...");
				getch();
				break;
		}
	}


}
