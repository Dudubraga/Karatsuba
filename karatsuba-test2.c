#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define MAX 1024
#define MAX_POW 10

void printS(char *str){
    int i = 0;
    while(str[i] == '0'){ i++; }
    if(i == strlen(str)){ 
        printf("0\n");
        return;
    }
    for(i; i < strlen(str); i++){
        printf("%c", str[i]);
    } printf("\n");
}

void verify_size(char *str){
    int size = strlen(str);
    if(size == 1) return;
    if(size > pow(2, MAX_POW)){
        printf("Numero muito grande\n");
        return;
    }
    int zeros = 1;
    for(int i = 1; i < MAX_POW; i++){
        if(size > pow(2, i) && size <= pow(2, i+1)){
            zeros = i + 1;
            break;
        }
    }
    zeros = pow(2, zeros) - size;
    char num[MAX];
    memset(num, '\0', sizeof(num));
    memset(num, '0', zeros);
    strcat(num, str);
    strcpy(str, num);
}

void same_size(char *num, int size){
    char str[size];
    memset(str, '\0', size);
    memset(str, '0', size - strlen(num));
    strcat(str, num);
    strcpy(num, str);
}

void sum(char *num1, char *num2, char *result){
    char r[MAX];
    memset(r, '\0', sizeof(r));
    int carry = 0, size = strlen(num1);
    for(int i = size-1; i >= 0; i--){
        int sum = (num1[i] - '0') + (num2[i] - '0');
        r[i] = ((sum + carry) % 10) + '0';
        carry = (sum + carry) / 10;
    }
    if(carry == 1){
        result[0] = '1';
        strcat(result, r);
    }else{
        strcpy(result, r);
    }
}

void multiply(){
    /* TO DO */
}

int main(){
    char N1[MAX], N2[MAX], result[MAX];
    memset(N1, '\0', sizeof(N1));
    memset(N2, '\0', sizeof(N2));
    memset(result, '\0', sizeof(result));
    /* ENTRADA */
    printf("Insira o primeiro numero: "); scanf("%s", N1);
    printf("Insira o segundo numero: "); scanf("%s", N2);
    /* CORRIGIR O TAMANHO PARA POW(2) */ 
    verify_size(N1);
    verify_size(N2);
    /* IGUALAR OS TAMANHOS */
    int size1 = strlen(N1);
    int size2 = strlen(N2);

    if(size1 > size2){
        same_size(N2, size1);
    }
    else if(size2 > size1){
        same_size(N1, size2);
    }
    /* MULTIPLICAR NUMEROS POR SUBSTRINGS (size * 10^1/2) */
    

    /* SOMAR NUMEROS */
    sum(N1, N2, result);

    /* SAIDA */
    printS(result);

    return 0;
}
