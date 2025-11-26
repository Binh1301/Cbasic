#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char classment(float diem){
    if( diem >= 9 && diem <= 10) return 'A';
    else if( diem >= 8 && diem < 9 ) return 'B';
    else if( diem >= 6.5 && diem < 8 ) return 'C';
    else if( diem >= 0 && diem < 6.5 ) return 'D';

}
typedef struct{
    char id[6];
    char name[31];
    float grade;
    char classment;

}students;
void xeploai(students student[], int n){
    for(int i = 0; i < n; i++){
            for(int j = i; j < n; j++){
        if (student[j].grade > student[i].grade ){
            students temp = student[i];
            student[i] = student[j];
            student[j] = temp;
        }
    }}
}
int main(){
    int n;
    scanf("%d", &n);
    students student[n];
    for(int i = 0; i < n; i++){
        scanf(" %[^,], %[^,], %f", &student[i].id, &student[i].name, &student[i].grade);
        student[i].classment = classment(student[i].grade);
        getchar();
        for(int j = 0; j < 31; j++){
            if (student[i].name[j] == '.') {
                printf("Khong hop le");
                return 0;
            }
        }
    }
    xeploai(student, n);
    printf("%-10s%-30s%-10s%-10s\n", "ID", "Ho va Ten", "Diem", "Hang");
    for (int i = 0; i < n; i++) {
        printf("%-10s%-30s%-10.1f%-10c\n",student[i].id, student[i].name, student[i].grade, student[i].classment);
    }
    return 0;
}

