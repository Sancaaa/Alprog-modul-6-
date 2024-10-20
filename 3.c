#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

//Deklarasi Fungsi
void menuAwal();
void input();
void inisiasiArray();
bool validasiInt(char *string, int *integer1);
bool validasiFloat(char *string, float *float1);
void output();
void menuAkhir();
void menuBerhenti();
void hapusBaris(int baris);

//Deklarasi Variabrl Global
int N;
int *array;

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
        printf("||                 PROGRAM RATA-RATA NILAI MAHASISWA           || \n");
        printf("-----------------------------------------------------------------\n");
        printf("||                    ALGORITMA DAN PEMROGRAMA N               || \n");
        printf("||                              KELAS C                        || \n");
        printf("||                                                             || \n");
        printf("|| ANAK AGUNG NARENDERA SANCAYA                   (2405551038) || \n");
        printf("|| DEWA MADE PANDU DIOTAMA                        (2405551098) || \n");
        printf("----------------------------------------------------------------- ");

        printf("\n\nTekan tombol apapun untuk melanjutkan...");

    char buffer[100];
    fgets(buffer, 100, stdin);
}

void input(){
    bool parsedCorrect;

    system("cls");
        printf("------------------------------------------------------------------\n");
        printf("||                    MASUKAN JUMLAH MAHASISWA                  ||\n");
        printf("------------------------------------------------------------------\n\n");

    do {
        printf("Masukan jumlah mahasiswa : ");
        char buffer[100];
        fgets(buffer, 100, stdin);

        parsedCorrect = validasiInt(buffer, &N);
        if (!parsedCorrect || N <= 0 ) {
            hapusBaris(1);
                printf("Nilai harus lebih dari 0!\n");
            sleep(1);
            hapusBaris(1);
        }
    } while (!parsedCorrect || N <= 0);

    inisiasiArray();

    system("cls");
            printf("------------------------------------------------------------------\n");
            printf("||                     MASUKAN NILAI MAHASISWA                  ||\n");
            printf("------------------------------------------------------------------\n\n");

    for(int i = 0; i < N; i++){
            do {
            printf("Masukan nilai mahasiswa ke-%d : ", i+1);
            char buffer[100];
            fgets(buffer, 100, stdin);

            parsedCorrect = validasiInt(buffer, &array[i]);
            if (!parsedCorrect || array[i] < 0) {
                hapusBaris(1);
                printf("Nilai minimal adalah 0!\n");
                sleep(1);
                hapusBaris(1);
            }
        } while (!parsedCorrect || array[i] < 0);

    }
}

void inisiasiArray(){
    array = (int *)malloc(N * sizeof(int));
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

void output(){
    float sum = 0;
    float rataRata;
    for( int i = 0; i < N; i++){
        sum = sum + array[i];
    }

    rataRata = sum / N;

    system("cls");
        printf("------------------------------------------------------------------\n");
        printf("||                    RATA-RATA NILAI MAHASISWA                 ||\n");
        printf("------------------------------------------------------------------\n\n");

    printf("Rata-rata : %.2f", rataRata ); 
}

void menuAkhir(){
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
