#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student
{
    int id;
    char name[50];
    char gt[10];
    int age;
    double Math;
    double Physics;
    double Chemistry;
    double GPA;
};

typedef struct student SV;

void modau()
{
    printf("\t\t\t\t    CHUONG TRINH QUAN LI SINH VIEN \t\t\t\t\n\n");
    printf("\t\t\t ***********************-MENU-************************* \t\t\t\n");
    printf("\t\t\t **  1. Them sinh vien.\t\t\t\t     **\n");
    printf("\t\t\t **  2. Cap nhat thong tin sinh vien bang ID.\t     **\n");
    printf("\t\t\t **  3. Xoa sinh vien boi ID.\t\t\t     **\n");
    printf("\t\t\t **  4. Tim kiem sinh vien theo ten.\t\t     **\n");
    printf("\t\t\t **  5. Sap xep sinh vien theo diem trung binh (GPA).**\n");
    printf("\t\t\t **  6. Sap xep sinh vien theo ten.\t\t     **\n");
    printf("\t\t\t **  7. Hien thi danh sach sinh vien.\t\t     **\n");
    printf("\t\t\t **  0. Thoat.\t\t\t\t\t     **\n");
    printf("\t\t\t ****************************************************** \t\t\t\n");
}

char *Ten(char a[])
{
    char *b = (char *)malloc(strlen(a) + 1);
    if (b == NULL)
    {
        printf("Khong the cap phat bo nho!");
        exit(1);
    }
    char *ten = strtok(a, " ");
    while (ten != NULL)
    {
        strcpy(b, ten);
        ten = strtok(NULL, " ");
    }
    return b;
}

void Enter(SV *ptr) // Nhập thông tin sinh viên
{
    scanf("%d", &(ptr)->id);
    getchar();
    fgets((ptr)->name, sizeof(ptr)->name, stdin);
    (ptr)->name[strlen((ptr)->name) - 1] = '\0';
    scanf("%s", (ptr)->gt);
    scanf("%d", &(ptr)->age);
    scanf("%lf", &(ptr)->Math);
    scanf("%lf", &(ptr)->Physics);
    scanf("%lfd", &(ptr)->Chemistry);
    ptr->GPA = ptr->Math + ptr->Physics + ptr->Chemistry / 3;
}

void add(SV *ptr, int *n) // Them Sinh vien
{
    int x;
    int n2 = *n;
    printf("Moi ban nhap so sinh vien muon them vao: ");
    scanf("%d", &x);
    *n += x;                                    // so luong ma cong them phan muon them sinh vien
    SV *ptr1 = realloc(ptr, sizeof(SV) * (*n)); // cap phat them bo nho khi muon them sinh vien
    if (ptr1 != NULL)
    {
        ptr = ptr1;
    }
    else
    {
        printf("Khong the them sinh vien ");
    }
    for (int i = n2; i < *n; ++i)
    {
        Enter(ptr + i);
    }
}

void Out(SV *x) // in thông tin 1 sinh viên
{
    printf("%d \t%s \t%s \t%d \t%.2lf \t\t%.2lf \t\t%.2lf \t\t%.2lf \t", x->id, x->name, x->gt, x->age, x->Math, x->Physics, x->Chemistry, (double)(x->Math + x->Physics + x->Chemistry) / 3);

    if (x->GPA >= 8)
        printf("Gioi");
    else if (x->GPA >= 6.5 && x->GPA < 8)
        printf("Kha");
    else if (x->GPA >= 5 && x->GPA < 6.5)
        printf("Trung binh");
    else
        printf("Yeu");
    printf("\n");
}

void in(SV *ptr, int n) // in thông tin toàn bộ sinh viên
{
    printf("ID      Name \t\tGt \tTuoi \tDiem_Toan \tDiem_Li \tDiem_Hoa \tGPA \tHoc_Luc\n");
    for (int i = 0; i < n; ++i)
    {
        Out(ptr + i);
    }
}

void Xoa(SV *y, int *n) // Xoá 1 sinh viên theo yêu cầu
{
    int ID;
    printf("Sinh vien ban muon xoa co id la: ");
    scanf("%d", &ID);
    for (int i = 0; i < *n; ++i)
    {
        if ((y + i)->id == ID)
            memmove(y + i, y + i + 1, (*n - i - 1) * sizeof(SV));
        SV *ptr1 = (SV *)realloc(y, (*n - 1) * sizeof(SV));
        y = ptr1;
        *n = *n - 1;
        break;
    }
}

void update(SV *y) // Cập nhật thông tin sinh viên
{
    int x;
    int id;
    printf("Sinh vien ban muon update thong tin co id la: ");
    scanf("%d", &id);
    printf("Ban muon thay doi thong tin gi\n");
    printf("1.Name\n");
    printf("2.Gioi tinh\n");
    printf("3.Age\n");
    printf("4.Math\n");
    printf("5.Physics\n");
    printf("6.Chemistry\n");
    printf("Moi ban nhap tuy chon:");
    scanf("%d", &x);
    if (x == 1)
    {
        char NewName[50];
        printf("Moi ban nhap ten moi: ");
        fgets(NewName, sizeof(NewName), stdin);
        NewName[strlen(NewName) - 1] = '\0';
        strcpy((y + id-1)->name, NewName);
    }
    if (x == 2)
    {
        char NewGt[10];
        printf("Moi ban nhap gioi tinh moi cho sinh vien: ");
        scanf("%s", NewGt);
        strcpy((y + id-1)->gt, NewGt);
    }
    if (x == 3)
    {
        int NewAge;
        printf("Moi ban nhap tuoi moi cho sinh vien: ");
        scanf("%d", &NewAge);
        (y + id-1)->age = NewAge;
    }
    if (x == 4)
    {
        double NewMath;
        printf("Nhap diem moi cho mon toan cua sinh vien: ");
        scanf("%lf", &NewMath);
        (y + id-1)->Math = NewMath;
    }
    if (x == 5)
    {
        double NewPhysics;
        printf("Nhap diem moi cho mon Vat Li cua sinh vien: ");
        scanf("%lf", &NewPhysics);
        (y + id-1)->Physics = NewPhysics;
    }
    if (x == 6)
    {
        double NewChemistry;
        printf("Nhap diem moi cho mon Hoa cua sinh vien: ");
        scanf("%lf", &NewChemistry);
        (y + id-1)->Chemistry = NewChemistry;
    }
}

void FindName(SV *y, int n) // Tìm kiếm sinh viên theo tên
{
    char a[50];
    getchar();
    printf("Nhap ten sinh vien ban muon tim: ");
    fgets(a, 50, stdin);
    a[strlen(a) - 1] = '\0';
    for (int i = 0; i < n; ++i)
    {
        if (strcmp((y + i)->name, a) == 0)
        {
            printf("ID      Name \t\tGt \tTuoi \tDiem_Toan \tDiem_Li \tDiem_Hoa \tGPA \tHoc_Luc\n");
            Out(y + i);
            return;
        }
    }
    printf("Khong co sinh vien nao phu hop voi thong tin ban tim kiem\n");
}

void SapxepID(SV *y, int n)
{
    SV tmp;
    for (int i = 0; i < n; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            if ((y + i)->GPA < (y + j)->GPA)
            {
                tmp = *(y + i);
                *(y + i) = *(y + j);
                *(y + j) = tmp;
            }
        }
    }
}

void Sapxepname(SV *y, int n)
{
    SV tmp;
    for (int i = 0; i < n; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            char z[50];
            char d[50];
            strcpy(z, (y + i)->name);
            strcpy(d, (y + j)->name);
            // printf("%s %s\n",z,d);
            // printf("z:%s d:%s\n",Ten(z),Ten(d));
            if (strcmp(Ten(z), Ten(d)) > 0)
            {
                // printf("Co vao day\n");
                tmp = *(y + i);
                *(y + i) = *(y + j);
                *(y + j) = tmp;
            }
        }
    }
}

int main()
{
    modau();
    int n = 0, x;
    int n1 = 1;
    SV *ptr = (SV *)malloc(1 * sizeof(SV));
    printf("Moi ban nhap tuy chon: ");
    scanf("%d", &n1);
    while (n1 != 0)
    {
        if (n1 == 1)
        {
            add(ptr, &n);
            printf("\n");
        }
        if (n1 == 2)
        {
            update(ptr);
            printf("\n");
        }
        if (n1 == 3)
        {
            Xoa(ptr, &n);
            printf("\n");
        }
        if (n1 == 4)
        {
            FindName(ptr, n);
            printf("\n");
        }
        if (n1 == 5)
        {
            SapxepID(ptr, n);
            printf("\n");
        }
        if (n1 == 6)
        {
            Sapxepname(ptr, n);
            printf("\n");
        }
        if (n1 == 7)
        {
            in(ptr, n);
            printf("\n");
        }
        printf("Neu ban khong muon lam gi nua thi nhan so 0 neu muon tiep tuc thuc hien cac chuc nang khac thi nhan so 1:");
        scanf("%d", &n1);
        printf("\n");
        if (n1 == 1)
        {
            printf("Moi ban nhap tuy chon: ");
            scanf("%d", &n1);
        }
        else break;
    }
    free(ptr);
    return 0;
}