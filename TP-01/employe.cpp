#include <stdio.h>  
#include <stdlib.h>
#include <limits.h>
#include <string.h>

struct Employee {
    int employeeId;
    char namaLengkap[30];
    char tempatLahir[30];
    char tanggalLahir[30];
    char jabatan[50];
    struct Employee *next;
};

struct Employee * HEAD;

int numLen();
int checkEmployeeID();
int getCount();
void menu();  
void addEmployee();
void showEmployee();
void deleteById();
void deleteAllData();
void quick_sort();
struct Employee *last_node();
struct Employee *parition();

int main() {
    system("cls");

    printf("**************************************\n");
    printf("Employee Program | Singly Linked List\n\n");
    menu();
    return 0;    
}

void menu() {  
    int option;

    printf("Main Menu\n");
    printf("Tekan [1] untuk Input Data Employee\n");
    printf("Tekan [2] untuk Melihat Data Employee\n");
    printf("Tekan [3] untuk Menghapus Data Employee by ID\n");
    printf("Tekan [4] untuk Menghapus All Data Employee\n");
    printf("Tekan [5] untuk Keluar dari program\n");

    if (scanf("%d",&option) == 1)
    {
        switch (option) {
            case 1: {
                system("cls");
                if (getCount() > 5) {
                    printf("Database Employee Penuh\n");
                } else {
                    addEmployee();
                    system("PAUSE");
                    menu();
                }
                break;
            }
            case 2: {
                system("cls");
                quick_sort(HEAD, last_node(HEAD));
                showEmployee();
                break;
            }
            case 3: {
                system("cls");
                deleteById();
                break;
            }
            case 4: {
                system("cls");
                deleteAllData();
                break;
            }
            case 5: {
                system("cls");
                printf("Terima Kasih\n");
                exit(0);
                break;
            }
            default: {
                if (option != 1 || option != 2 || option != 3 || option != 4 || option != 5) {
                    system("cls");
                    printf ("Invalid option!\n");
                    system("PAUSE");
                    menu();
                }
                break;
            }
        }
    }
}  

void addEmployee() {  
    int employeeId;  
    char namaLengkap[30];
    char tempatLahir[30];
    char tanggalLahir[30];
    char jabatan[50];
    struct Employee *point,*tmp;  
    point = (struct Employee*)malloc(sizeof(struct Employee));    

    if(point == NULL) {  
        printf("\nInvalid!!");   
    } else {  
        printf("Input Data Employee\n");

        do {
            printf("Employee ID: (positive 5-digit angka & Unique)\n");  
            scanf("%d",&employeeId);  
        } while (numLen(employeeId) > 5 || checkEmployeeID(employeeId));
        point->employeeId = employeeId;

        do {
            printf("Nama Lengkap: (Maks. 30 Characters)\n");  
            scanf("%s",&namaLengkap);  
        } while (strlen(namaLengkap) > 30);
        strcpy(point->namaLengkap, namaLengkap);

        do {
            printf("Tempat Lahir: (Maks. 30 Characters)\n");  
            scanf("%s",&tempatLahir);  
        } while (strlen(tempatLahir) > 30);
        strcpy(point->tempatLahir, tempatLahir);

        do {
            printf("Tanggal Lahir: (Maks. 30 Characters)\n");  
            scanf("%s",&tanggalLahir);  
        } while (strlen(tanggalLahir) > 30);
        strcpy(point->tanggalLahir, tanggalLahir);

        do {
            printf("Jabatan: (Maks. 50 Characters)\n");  
            scanf("%s",&jabatan);  
        } while (strlen(jabatan) > 50);
        strcpy(point->jabatan, jabatan);
        
        if(HEAD == NULL) {  
            point->next = NULL;  
            HEAD = point;  
            printf ("\nSukses Menambah Data Employee!\n");
        } else {  
            tmp = HEAD;  
            while (tmp->next != NULL)  
            {  
                tmp = tmp->next;  
            }  
            tmp->next = point;  
            point->next = NULL;  
            printf ("\nSukses Menambah Data Employee!\n");
        }  
    }

    system("PAUSE");
    system("cls");
    menu();
}

void showEmployee()
{
    struct Employee *point;  
    point = HEAD; 
    if(point == NULL)  
    {  
        printf("Tidak ada data Employee untuk ditampilkan!\n");  
    }  
    else  
    {  
        printf("\nList Data Employee!\n");   
        while (point!=NULL)  
        {  
            printf("\n-----------------------------------------\n");  
            printf("Employee ID: %d\n",point->employeeId);  
            printf("Nama Lengkap: %s\n",point->namaLengkap);  
            printf("Tempat Lahir: %s\n",point->tempatLahir);  
            printf("Tanggal Lahir: %s\n",point->tanggalLahir);  
            printf("Jabatan: %s\n",point->jabatan);  
            point = point -> next;
        }  
    }  
    
    system("PAUSE");
    system("cls");
    menu();
}

void deleteById() {
    int employeeId;
    struct Employee *temp = HEAD, *prev;

    do {
        printf("Employee ID: (positive 5-digit angka & Unique)\n");  
        scanf("%d",&employeeId);  
    } while (!checkEmployeeID(employeeId));

    if (temp != NULL && temp->employeeId == employeeId) {
        HEAD = temp->next;
        free(temp);
        return;
    }

    while (temp != NULL && temp->employeeId != employeeId) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
        return;

    prev->next = temp->next;

    free(temp);

    printf ("\nSukses Menghapus Data Employee Dengan ID: %d!\n", employeeId);
    
    system("PAUSE");
    system("cls");
    menu();
}

void deleteAllData() {
    struct Employee *point;  
    point = HEAD; 
    struct Employee* next;
    
    while (point != NULL) 
    {
        next = point->next;
        free(point);
        point = next;
    }

    HEAD = NULL;

    printf ("\nSukses Menghapus All Data Employee!\n");
    
    system("PAUSE");
    system("cls");
    menu();
}

int numLen(unsigned long num){
    if(num < 10) 
        return 1;
    return 1 + numLen(num/10);
}

int checkEmployeeID(int id){
    struct Employee *point;  
    point = HEAD;   

    while (point!=NULL) {  
        if(point->employeeId == id){  
            return 1;
        }   
        point = point -> next;  
    }

    return 0; 
}

int getCount()
{
    struct Employee *point;  
    point = HEAD;   
    int count = 0;

    while (point != NULL)
    {
        count++;
        point = point->next;
    }
    return count;
}

struct Employee *last_node(struct Employee *head)
{
    struct Employee *temp = head;
    while (temp != NULL && temp->next != NULL)
    {
        temp = temp->next;
    }
    return temp;
}

struct Employee *parition(struct Employee *first, struct Employee *last)
{
    struct Employee *pivot = first;
    struct Employee *front = first;
    int temp = 0;
    while (front != NULL && front != last)
    {
        if (front->employeeId < last->employeeId)
        {
            pivot = first;
            temp = first->employeeId;
            first->employeeId = front->employeeId;
            front->employeeId = temp;
            first = first->next;
        }
        front = front->next;
    }
    temp = first->employeeId;
    first->employeeId = last->employeeId;
    last->employeeId = temp;
    return pivot;
}

void quick_sort(struct Employee *first, struct Employee *last)
{
    if (first == last)
    {
        return;
    }
    struct Employee *pivot = parition(first, last);
    if (pivot != NULL && pivot->next != NULL)
    {
        quick_sort(pivot->next, last);
    }
    if (pivot != NULL && first != pivot)
    {
        quick_sort(first, pivot);
    }
}