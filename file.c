#include <stdio.h>
#include <string.h>

void Read(FILE *fp1, FILE *fp2, FILE *fp3)
{
    int x;

    printf("Neu muon hien thi tat ca moi nhap so 1. Hien thi phan trang moi nhap so 2: ");
    scanf("%d", &x);
    if (x == 1)
    {
        char arr[1000];
        char *token;
        while (fgets(arr, 1000, fp1) != NULL)
        {
            token = strtok(arr, ";");
            while (token != NULL)
            {
                fprintf(fp2, "%s ", token);
                token = strtok(NULL, ";");
            }
        }
    }
    if (x == 2)
    {
        do
        {
            int y;
            char a[1000];
            int dem = 0;
            printf("Moi ban nhap so trang muon xem: ");
            scanf("%d", &y);
            fprintf(fp2, "Page %d\n", y);
            while (fgets(a, 1000, fp3) != NULL)
            {
                dem++;
                if (dem - 1 >= (y - 1) * 20 + 1 && dem <= y * 20 + 1)
                {
                    fprintf(fp2, "%s", a);
                }
            }
            rewind(fp3);
            printf("Ban co muo xem trang nao nua khong.Co nhap 1, khong nhap 0: ");
            scanf("%d", &x);
        } while (x != 0);
    }
}

void Search(FILE *fp1, FILE *fp2)
{
    int x;
    printf("\t\t\t ***********************-MENU-************************* \t\t\t\n");
    printf("\t\t\t **  1. Tim kiem theo so bao danh.\t\t\t\t     **\n");
    printf("\t\t\t **  2. Tim kiem theo ma so sinh vien.\t     **\n");
    printf("\t\t\t **  3. Tim kiem theo ten.\t\t\t     **\n");
    printf("\t\t\t **  4. Tim kiem theo lop.\t\t     **\n");
    printf("\t\t\t **  5. Tim kiem theo ngay sinh.**\n");
    printf("\t\t\t **  0. Thoat.\t\t\t\t\t     **\n");
    printf("\t\t\t ****************************************************** \t\t\t\n");

    printf("Moi ban nhap tuy chon: ");
    scanf("%d", &x);
    getchar();

    if (x == 1)
    {
        char SBD[20];
        char arr[1000];
        char kq[1000];
        int t = 0; // biến để xem đã tìm thấy sinh viên theo yêu cầu hay chưa nếu tìm thấy gán t=1
        
        printf("Nhap so bao danh cua sinh vien ban can tim: ");
        scanf("%s", SBD);
        
        char *token;
        while (fgets(arr, 1000, fp1) != NULL)
        {
            strcpy(kq, arr); // Mang kq luu arr sau moi lan fgets vi sau khi su dung ham strok thi arr se bi thay doi
            token = strtok(arr, ";");
            while (token != NULL)
            {
                if (strcmp(SBD, token) == 0)
                {
                    fprintf(fp2, "%s", kq);
                    //return;
                }
                else
                {
                    token = strtok(NULL, ";");
                }
            }
            if (t)
                break; // lúc này đã tìm thấy sinh viên theo yêu cầu thoát khỏi vòng lặp
        }
    }

    if (x == 2)
    {
        char MSSV[20];
        char arr[1000];
        char kq[1000];
        int t = 0;// biến để xem đã tìm thấy sinh viên theo yêu cầu hay chưa nếu tìm thấy gán t=1

        printf("Nhap MSSV cua sinh vien ban can tim: ");
        scanf("%s", MSSV);

        char *token;
        while (fgets(arr, 1000, fp1) != NULL)
        {
            strcpy(kq, arr); // Mang kq luu arr sau moi lan fgets vi sau khi su dung ham strok thi arr se bi thay doi
            token = strtok(arr, ";");
            while (token != NULL)
            {
                if (strcmp(MSSV, token) == 0)
                {
                    fprintf(fp2, "%s", kq);
                    //return;
                }
                else
                {
                    token = strtok(NULL, ";");
                }
            }
            if (t)
                break; //lúc này đã tìm thấy sinh viên theo yêu cầu thoát khỏi vòng lặp
        }
    }

    if (x == 3)
    {
        char Name[50];
        char arr[1000];
        char kq[1000];

        printf("Nhap ho ten cua sinh vien ban can tim: ");

        fgets(Name, 50, stdin);
        Name[strlen(Name) - 1] = '\0';

        char *token;
        while (fgets(arr, 1000, fp1) != NULL)
        {
            strcpy(kq, arr); // Mang kq luu arr sau moi lan fgets vi sau khi su dung ham strok thi arr se bi thay doi
            token = strtok(arr, ";");
            while (token != NULL)
            {
                if (strcmp(Name, token) == 0)
                {
                    fprintf(fp2, "%s\n", kq);
                    //return;
                }
                else
                {
                    token = strtok(NULL, ";");
                }
            }
        }
    }
    
    if (x == 4)
    {
        char Class[50];
        char arr[1000];
        char kq[1000];

        printf("Nhap lop cua sinh vien ban can tim: ");
        scanf("%s",Class);

        char *token;
        while (fgets(arr, 1000, fp1) != NULL)
        {
            strcpy(kq, arr); // Mang kq luu arr sau moi lan fgets vi sau khi su dung ham strok thi arr se bi thay doi
            token = strtok(arr, ";");
            while (token != NULL)
            {
                if (strcmp(Class, token) == 0)
                {
                    fprintf(fp2, "%s\n", kq);
                    //return;
                }
                else
                {
                    token = strtok(NULL, ";");
                }
            }
        }
    }
}

int main()
{
    FILE *fp1;
    FILE *fp2;
    FILE *fp3;
    char arr[1000];

    fp1 = fopen("danh_sach_thi_tieng_anh_hoc_ky.csv", "r");
    fp2 = fopen("kq.out", "w");
    fp3 = fopen("kq1.out", "w+");

    int cnt;
    char *token;
    while (fgets(arr, 1000, fp1) != NULL) // tạo ra 1 file mới để lưu thông tin khi đã bỏ dấu ;
    {
        token = strtok(arr, ";");
        while (token != NULL)
        {
            fprintf(fp3, "%s ", token);
            token = strtok(NULL, ";");
        }
        cnt++;
    }
    rewind(fp1); // đưa con trỏ về đầu file
    rewind(fp3); // đưa con trỏ về đầu file

    // Read(fp1, fp2, fp3);
    Search(fp1, fp2);

    fclose(fp1);
    fclose(fp2);
    fclose(fp3);
    return 0;
}