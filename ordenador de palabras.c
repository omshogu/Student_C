 /*programa que ordena un texto en orden de letras a numeros por orden alfabetico*/

#include "stdio.h"

int positions[100];
char alpha[100];

//funcion que crea las posiciones de los caracteres de las palabras;
int create_position(char c)
{
    char M[27]="ABCDEFGHIJKLMNOPQRSTUVWXYZ",m[27]="abcdefghijklmnopqrstuvwxyz",n[10]="0123456789";
    int i=0;
    if(c>='A' && c<='Z')
    {
              for(i=0;i<27;i++)
              {
                                     if(c==M[i])
                                     {
                                                return (i+1);
                                     }
              }
    }
    if(c>='a' && c<='z')
    {
              for(i=0;i<27;i++)
              {
                                     if(c==m[i])
                                     {
                                                return (i+28);
                                     }
              }
    }
    if(c>='0' && c<='9')
    {
              for(i=0;i<10;i++)
              {
                               if(c==n[i])
                               {
                                          return (i+55);
                               }
              }
    }
}

/* ordena los caracteres de la palabra dada por el usuario 
de acuerdo un orden alfa numerico */
void order_by_alpha(char c[],int pt[])
{
     // hay 100 espacios temporales para poder ordenar la palabra
     char temp_c[100];
     int temp[100],a,b=0,i;
     
     /* El limite es 64 porque caractes 27 en mayuscaulas + 27 en minusculas + 10 en numericos dan
     dan como resultado el limite de las posiciones */
     for(i=0; i < 64; i++)
     {
              for(a=0; c[a] != '\0'; a++)
              {
                       if(pt[a] == i)
                       {
                                temp[b] = i;
                                temp_c[b] = c[a];
                                b++;
                       }
              }
     }
     /* Es un ciclo que descarga desde las variables temporales 
     a variables formales para imprimirlas */
     for(i=0; i < b;i++)
     {
              alpha[i] = temp_c[i];
              positions[i] = temp[i];
     }
}

//funcion que imprime la orden de la posiciones
void print_position_order()
{
     int e;
     printf("\nlas positiones segun su orden alfabetico y numerico es: \n\n");
     for(e=0;alpha[e]!='\0';e++)
     {
                     printf(" \"%c (%d)\" ",alpha[e],positions[e]);
                     /*esta expresion permite darle un valor nulo
                     a los espacios de las variables '\0'*/
                     alpha[e] = '\0';
                     positions[e] = '\0';
     }
     getchar();
     
}

int main()
{
    while(1)
    {
            char text[100];
            int i=0,e=0;
            printf("ingrese una cadena de caracteres:  \n\n");
            scanf("%s",&text);
            getchar();
            for(i=0; text[i]!='\0' ; i++)
            {
                          positions[i] = create_position(text[i]);
            }
            
            order_by_alpha(text,positions);
            
            print_position_order();
    }
}
