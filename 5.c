#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

//Deklrasi Fungsi
void menuAwal();
int menuMode();
float input();
bool validasiInt(char *string, int *integer1);
bool validasiFloat(char *string, float *float1);
void output(int mode, float suhu);
float celciusKeFahrenheit(float suhu);
float fahrenheitKeCelcius(float suhu);
void menuAkhir();
void menuBerhenti();
void hapusBaris(int baris);

//Implementasi Fungsi
int main(){
    menuAwal();
    int mode = menuMode();
    float suhu = input();
    output(mode, suhu);
    menuAkhir();
    return 0;
}

void menuAwal() {
    system("cls");
        printf("-----------------------------------------------------------------\n");
        printf("||                PROGRAM KONVERSI CELCIUS-FAHRENHEIT          || \n");
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

int menuMode(){
    system("cls");
        printf("------------------------------------------------------------------\n");
        printf("||                       PILIH MODE KONVERSI                    ||\n");
        printf("------------------------------------------------------------------\n");
        printf("|| Celcius ke Fahrenheit                                 (1)    || \n");
        printf("|| Fahrenheit ke Celcius                                 (2)    || \n");
        printf("||                                                              || \n");
        printf("||                                                              || \n");
        printf("|| Keluar dari Program                                   (0)    || \n");
        printf("------------------------------------------------------------------\n");

    int integer1;
    bool parsedCorrect;

    do {
        printf("\nPilih mode konversi (1 & 2) atau keluar (0)... ");
        char buffer[100];
        fgets(buffer, 100, stdin); 

        parsedCorrect = validasiInt(buffer, &integer1); 
 
        if (!parsedCorrect || (integer1 < 0 || integer1 > 2)) {
            hapusBaris(1);
            printf("MASUKAN OPSI YANG BENAR!");
            sleep(1);
            hapusBaris(1);

        } else if(integer1 == 0){
            menuBerhenti();

        }else{
            return integer1;
        }
    } while (true); 
}

float input() {
    float suhu;
    bool parsedCorrect;

    system("cls");
        printf("------------------------------------------------------------------\n");
        printf("||                          MASUKAN SUHU                        ||\n");
        printf("------------------------------------------------------------------\n\n");

    do {
        printf("Masukan suhu : ");
        char buffer[100];
        fgets(buffer, 100, stdin);

        parsedCorrect = validasiFloat(buffer, &suhu);
        if (!parsedCorrect) {
            hapusBaris(1);
                printf("Masukan input yang benar!\n");
            sleep(1);
            hapusBaris(1);
        }
    } while (!parsedCorrect);

    return suhu;
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

void output(int mode, float suhu){
    system("cls");
    switch(mode){
        case 1:
            printf("------------------------------------------------------------------\n");
            printf("||                    CELCIUS KE FAHRENHEIT                     ||\n");
            printf("------------------------------------------------------------------\n");
        celciusKeFahrenheit(suhu);
            printf("Suhu dalam Fahrenheit : %.2f derajat F \n", celciusKeFahrenheit(suhu));
        break;

        case 2:
            printf("------------------------------------------------------------------\n");
            printf("||                    FAHRENHEIT KE CELCIUS                     ||\n");
            printf("------------------------------------------------------------------\n");
        fahrenheitKeCelcius(suhu);
            printf("Suhu dalam Celcius : %.2f derajat C \n", fahrenheitKeCelcius(suhu));
        break;
    }
}

float celciusKeFahrenheit(float suhu){
    return (9.0 / 5.0 * suhu) + 32.0;
}

float fahrenheitKeCelcius(float suhu){
    return (5.0 / 9.0) * (suhu - 32.0);
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
