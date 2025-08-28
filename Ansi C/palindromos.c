#include <stdio.h>


//Função que compara as frases e retorna 0 para diferente, 1 pra igual e 2 pra fim.
int comparafrase(char frase1[1000], char frase2[1000]){
  char A,B, x = '\0';
  char fim[3] = {"FIM"};
  int retorno = 0,letraA = 0,letraB = 0;
  int fimnum = 0;
  //Aqui eu conto quantas letras tem
    for (int i = 0; i < 1000; i++){
    A = frase1[i];
    B = frase2[i];
    if(A != x){
        letraA++;
    }
    if(B != x){
        letraB++;
    }
}   //Esse pedaço verifica se é o final
    if (letraA == 3){
        for (int i = 0; i<3;i++){
            if (frase1[i] == fim[i] )
            fimnum++;
        }
        if (fimnum == 3)
        return 2;
    }
    /*if (letraB == 0){
        return 3;
    }*/
//Aqui eu vejo se é igual
    if (letraA == letraB){
        for (int i = 0; i<letraA;i++){
        A = frase1[i];
        B = frase2[i];
        if (A == B){
            retorno++;
        }
        }
        if (retorno == letraA){
            return 1;
        }
        else
        return 0;
    }
    else {
        return 0;
    }
   
} 

//função que inverte as frases
char inverter(char* vetor, char frase[], int i, int j) {
    if (i >0){

        if (frase[i] == '\0'){
            }
        else {
            *(vetor + j) = frase[i];
            j++;
        }
        
            return inverter(vetor,frase,i-1,j);
    }
        if (i == 0){
        *(vetor + j) = frase[i];
         return 0;
    }
}


int main() {
    int controle = 1;
    while (controle == 1) {
    char contraria[1000] = {0};
    char frase[1000] = {0};
    int x = 0;
        //scanf("%s", frase);
        scanf(" %[^\n]", frase); 
        if (comparafrase(frase,contraria) == 2) 
        controle = 0;
        
        inverter(contraria,frase,999,0);
        //printf("frase editada: %s \n",contraria);

        int numero = comparafrase(frase,contraria);
        if (numero == 0){
            printf("NAO\n");
        }
        if (numero == 1){
            printf("SIM\n");
        }

    }
    return 0;
} 