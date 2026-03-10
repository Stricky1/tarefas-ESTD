#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int lista(int *ptdes);

typedef struct Contatos{

    char nome[129];
    char numero[33];
}contatos;

int main() {

    contatos agenda[100];
    int cont=0, des=0, r=0, lines=0, li=0, *ptdes=&des;
    
    *ptdes = des;
    

    FILE  *pot_ar;

  

    pot_ar = fopen("../agenda.csv","a");

     if (pot_ar == NULL) {
                              printf("Erro ao abrir ou ao criar o arquivo! \n");
                              return 0;
                            }

    
      fclose(pot_ar);

      li = lista( ptdes);

      printf( "O numero de linhas: %d", li);
     
      pot_ar = fopen("../agenda.csv","a");

      lines = 101 - li; 

      printf("\nDeseja adicionar um novo contato? \n");
      scanf("%d", &des);
     
      while( (des == 1) && (cont <= lines) ){
       
        printf("\nNome \n");
        scanf(" %[^\n]", agenda[cont].nome);

        printf("\nNumero \n");
        scanf(" %[^\n]", agenda[cont].numero);

          r = fprintf(pot_ar," \n Contato   Nome: %s  Numero: %s ", agenda[cont].nome,agenda[cont].numero);

            if (r<0) {
              printf("Erro!");
              return 0;
          }

        cont++;
        printf("\nDeseja adicionar um novo contato? \n");
        scanf("%d", &des);

    }
     
        fclose(pot_ar);

        printf("Deseja ver a lista de contatos? \n");
        scanf("%d", &des);
   
         if(des!=0){

            *ptdes= des;
             lista( ptdes);
         }

   


    return 0;
}



int lista(int *ptdes){


    int li=0, des = *ptdes;
    char buffer[129];
    
     
    FILE *pt_ar;

    pt_ar = fopen("../agenda.csv","r");

        if (pt_ar == NULL) {
                              printf("Erro ao abrir o arquivo! \n");
                              return 0;
                            }
            else{
             printf("O arquivo foi aberto com sucesso \n");
            }


    while( (fgets(buffer,sizeof(buffer),pt_ar)) != (NULL)){
  
      if( des==1){

          printf(" %s", buffer);
      }

    li++;
    
    }

      fclose(pt_ar);

  return(li);

}