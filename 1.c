#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <math.h>

//Deklarasi Fungsi
void menuAwal();
void input();
void inisiasiArray();
bool validasiInt(char *string, long long int *integer1);
void integerSplitter(long long int nilai);
void rahasia(int *arr, int length);
void output();
void menuAkhir();
void menuBerhenti();
void hapusBaris(int baris);

//deklarasi Variabel Global
int total;

//Implementasi Fungsi
int main(){
    menuAwal();
    input();
    output();
    menuAkhir();
    return 0;
}

void menuAwal() {
    system("cls");
        printf("-----------------------------------------------------------------\n");
        printf("||                    PROGRAM TOTAL GENAP-GANJIL               || \n");
        printf("-----------------------------------------------------------------\n");
        printf("||                    ALGORITMA DAN PEMROGRAMAN                || \n");
        printf("||                              KELAS C                        || \n");
        printf("||                                                             || \n");
        printf("|| ANAK AGUNG NARENDERA SANCAYA                   (2405551038) || \n");
        printf("|| DEWA MADE PANDU DIOTAMA                        (2405551098) || \n");
        printf("----------------------------------------------------------------- ");

        printf("\n\nTekan tombol apapun untuk melanjutkan...");

    char buffer[100];
    fgets(buffer, 100, stdin);
}

void input() {
    long long int nilai;
    bool parsedCorrect;

    system("cls");
        printf("------------------------------------------------------------------\n");
        printf("||                         MASUKAN ARRAY                        ||\n");
        printf("------------------------------------------------------------------\n\n");

    do {
        printf("Masukan array : ");
        char buffer[100];
        fgets(buffer, 100, stdin);

        parsedCorrect = validasiInt(buffer, &nilai);
        if (!parsedCorrect || nilai < 0) {
            hapusBaris(1);
                printf("Masukan input yang benar!\n");
            sleep(1);
            hapusBaris(1);
        }
    } while (!parsedCorrect || nilai < 0);

    integerSplitter(nilai);
    }

bool validasiInt(char *string, long long int *integer1){
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

    *integer1 = atoll(integerBuffer); 

    return true;
}

void integerSplitter(long long int nilai){
    int arr[20];  
    int length = (int)log10(nilai) + 1; 

    for (int i = length - 1; i >= 0; i--) {
        arr[i] = nilai % 10; 
        nilai /= 10;
    }

    rahasia(arr, length);  
}

void rahasia(int *arr, int length){
    for (int i = 0; i <= length - 1; i++){
        if (arr[i] % 2 == 0) {
            total = total + arr[i];
        } else {
            total = total - arr[i];
        }
    }
}

void output(){
    system("cls");
        printf("------------------------------------------------------------------\n");
        printf("||                        TOTAL GENAP-GANJIL                    ||\n");
        printf("------------------------------------------------------------------\n\n");

    printf("Total genap-ganjil adalah : %d \n", total ); 
}

void menuAkhir(){
    long long int akhir;
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

void menuBerhenti(){
    system("cls");
        printf("------------------------------------------------------------------\n");
        printf("||         TERIMA KASIH SUDAH MENGGUNAKAN PROGRAM KAMI          ||\n");
        printf("------------------------------------------------------------------\n");
    exit(0);
}

void hapusBaris(int baris){
    for (int i = 0; i < baris; i++) {
            printf("\033[F\033[K");
    }
}
