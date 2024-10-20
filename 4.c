#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

//Deklrasi Fungsi
void menuAwal();
float input();
bool validasiInt(char *string, int *integer1);
bool validasiFloat(char *string, float *float1);
void output(float nilai);
void rentangNilai(float nilai);
void menuAkhir();
void menuBerhenti();
void hapusBaris(int baris);

//Implementasi Fungsi
int main(){
    menuAwal();
    float nilai = input();
    output(nilai);
    menuAkhir();
    return 0;
}

void menuAwal() {
    system("cls");
        printf("-----------------------------------------------------------------\n");
        printf("||                 PROGRAM PENENTUAN NILAI MAHASISWA           || \n");
        printf("-----------------------------------------------------------------\n");
        printf("||                     ALGORITMA DAN PEMROGRAMAN               || \n");
        printf("||                              KELAS C                        || \n");
        printf("||                                                             || \n");
        printf("|| ANAK AGUNG NARENDERA SANCAYA                   (2405551038) || \n");
        printf("|| DEWA MADE PANDU DIOTAMA                        (2405551098) || \n");
        printf("----------------------------------------------------------------- ");

        printf("\n\nTekan tombol apapun untuk melanjutkan...");

    char buffer[100];
    fgets(buffer, 100, stdin);
}

float input() {
    float nilai;
    bool parsedCorrect;

    system("cls");
        printf("------------------------------------------------------------------\n");
        printf("||                         MASUKAN NILAI                        ||\n");
        printf("------------------------------------------------------------------\n\n");

    do {
        printf("Masukan nilai : ");
        char buffer[100];
        fgets(buffer, 100, stdin);

        parsedCorrect = validasiFloat(buffer, &nilai);
        if (!parsedCorrect || (nilai <= 0 || nilai > 100)) {
            hapusBaris(1);
                printf("Nilai harus di antara 0 dan 100!\n");
            sleep(1);
            hapusBaris(1);
        }
    } while (!parsedCorrect || (nilai <= 0 || nilai > 100));

    return nilai;
    }

bool validasiFloat(char *string, float *float1){
    int i = 0;
    int floatChar = 0;
    bool hasDecimal = false;

    while (isspace(string[i])) i++;

    int length = strlen(string);

    if (length == i) return false;

    char floatBuffer[100];

    if (string[i] == '-') {
        floatBuffer[floatChar++] = '-';
        i++;

        if (!isdigit(string[i]) && string[i] != '.') return false;
    }

    while (i < length && !isspace(string[i]) && string[i] != '\0') {
        if (isdigit(string[i]) || ((string[i] == '.' || string[i] == ',') && !hasDecimal)) {
            if (string[i] == '.' || string[i] == ',') hasDecimal = true;
            floatBuffer[floatChar++] = string[i++];
        } else {
            return false;
        }
    }

    floatBuffer[floatChar] = '\0';

    while (isspace(string[i])) i++;

    if (string[i] != '\0' && string[i] != '\n') return false;

    *float1 = atof(floatBuffer);

    return true;
}

bool validasiInt(char *string, int *integer1){
    int i = 0;
    int integerChar = 0;

    while (isspace(string[i])) i++;

    int length = strlen(string);
  
    if (length == i) return false; 

    char integerBuffer[100];

    if(string[i] == '-'){
        integerBuffer[integerChar] = '-';
        integerChar++;
        i++;

        if(!isdigit(string[i])) return false;
    }

    while (i < length && !isspace(string[i]) && string[i] != '\0'){
        if (!isdigit(string[i])) return false;

        integerBuffer[integerChar] = string[i]; 
        integerChar++;
        i++;
    }

    integerBuffer[integerChar] = '\0'; 

    while (isspace(string[i])) i++;

    if (string[i] != '\0' && string[i] != '\n') return false;

    *integer1 = atoi(integerBuffer); 

    return true;
}

void output(float nilai){
    system("cls");
        printf("-----------------------------------------------------------------\n");
        printf("||                         NILAI MAHASISWA                     || \n");
        printf("-----------------------------------------------------------------\n\n");

        printf("Nilai       : %.2f\n", nilai);
    rentangNilai(nilai);
}

void rentangNilai(float nilai){
    if(85 <= nilai && nilai<= 100){
        printf("Nilai huruf : A\n");
    } else if (70 <= nilai && nilai < 85){ 
        printf("Nilai huruf : B\n");
    } else if (55 <= nilai && nilai < 70){
        printf("Nilai huruf : C\n");
    } else if (40 <= nilai && nilai < 55){
        printf("Nilai huruf : D\n");
    } else if(nilai < 40){
        printf("Nilai huruf : E\n");
    }
}

void menuAkhir() {
    int akhir;
    bool parsedCorrect;
    do {
        printf("\nMasukan 0 untuk keluar atau 1 untuk mengulang... ");
        char buffer[100];
        fgets(buffer, 100, stdin);
        parsedCorrect = validasiInt(buffer, &akhir);
        if (!parsedCorrect || (akhir != 0 && akhir != 1)) {
            hapusBaris(1);
            printf("MASUKAN OPSI YANG BENAR!");
            sleep(1);
            hapusBaris(1);
        } else if (akhir == 0) {
            menuBerhenti();
        } else {
            main();
        }
    } while (true);
}

void menuBerhenti() {
    system("cls");
        printf("------------------------------------------------------------------\n");
        printf("||         TERIMA KASIH SUDAH MENGGUNAKAN PROGRAM KAMI          ||\n");
        printf("------------------------------------------------------------------\n");
    exit(0);
}

void hapusBaris(int baris) {
    for (int i = 0; i < baris; i++) {
            printf("\033[F\033[K");
    }
}
