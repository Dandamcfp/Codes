#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main()
{

    int c = 0;
    char l1, l2, l3, l4, l5, t1, t2, t3, t4, t5, E = 'X';
    printf("Digite sua palavra de 5 letras usando apenas minusculas \n");
    scanf("%c%c%c%c%c",&l1,&l2,&l3,&l4,&l5);
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n Adivinhe a palavra de 5 letras, vc tem 5 chances. \n");
    while (c <5)
      {
         scanf(" %c%c%c%c%c",&t1,&t2,&t3,&t4,&t5);
        c++;
         if (t1 == l1)
         {
             printf("%c",t1);
         }
         else
         {
             printf("%c",E);
         }
         if (t2 == l2)
         {
             printf("%c",t2);
         }
         else
         {
             printf("%c",E);
         }
         if (t3 == l3)
         {
             printf("%c",t3);
         }
         else
         {
             printf("%c",E);
         }
         if (t4 == l4)
         {
             printf("%c",t4);
         }
         else
         {
             printf("%c",E);
         }
         if (t5 == l5)
         {
             printf("%c \n",t5);
         }
         else
         {
             printf("%c \n",E);
         }
         if (t1 == l1 && t2 == l2 && t3 == l3 && t4 == l4 && t5 == l5)
         {
             printf("OPA Voce ganhou!");
             c = c+5;
         }
      }
      printf("\n Fim de jogo!");

    return 0;
}
