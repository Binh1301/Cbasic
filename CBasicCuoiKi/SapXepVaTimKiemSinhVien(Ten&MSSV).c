#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 64

int cmpStr(const void* a, const void* b) 
{
    return strcmp((char*)a, (char*)b);
}

typedef struct in4
{
    char ten[MAX];
    char mssv[MAX];
}in4;

in4 ds[1000];
int n = 0;

int cmpMSSV(const void* a, const void* b) 
{
    in4* x = (in4*)a;
    in4* y = (in4*)b;
    return strcmp(x->mssv, y->mssv);
}


void nhapchuoi()
{
    char line[256];
    while (1)
    {
        fgets(line, sizeof(line), stdin);
        line[strcspn(line, "\n")] = '\0';
        if (strcmp(line, "end.") == 0) break;
        char* sv = strtok(line, ";");
        while (sv != NULL) 
        {
            char* comma = strchr(sv, ',');
            if (comma != NULL) 
            {
                *comma = '\0';
                strcpy(ds[n].ten, sv);
                strcpy(ds[n].mssv, comma + 1);
                n++;
            }
            sv = strtok(NULL, ";");
        }
    }
}

char* layTen(char* hoten) 
{
    char* lastSpace = strrchr(hoten, ' ');
    if (lastSpace == NULL)
        return hoten;        
    return lastSpace + 1;    
}


void timTen() 
{
    char key[MAX];

    while (1) 
    {
        fgets(key, sizeof(key), stdin);
        key[strcspn(key, "\n")] = '\0';

        if (strcmp(key, "end.") == 0) break;

        int found = 0;
        for (int i = 0; i < n; i++) 
        {
            char* ten = layTen(ds[i].ten);
            if (strcmp(ten, key) == 0) 
            {
                printf("%s\n", ds[i].mssv);
                found = 1;
            }
        }
        if (!found)
            printf("Khong thay\n");
    }
}



int main() 
{
    nhapchuoi();
    timTen();
    qsort(ds, n, sizeof(in4), cmpMSSV);
    for (int i = 0; i < n; i++) 
    {
        printf("%s", ds[i].mssv);
        if (i < n - 1) printf(",");
    }
    return 0;
}

