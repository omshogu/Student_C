
#include "stdio.h"
int main()
{
    char text[100];
    int i,c,n=0;
    printf("ingrese un text y ubicaremos si existen numeros: ");
    scanf("%s",&text);
    getchar();
    printf("\nlos numeros hallados en el textos fueron: \"");
    for(i=0;text[i]!='\0';i++)
    {
                              if(text[i]>='0' && text[i]<='9')
                              {
                                              n++;
                                              printf("%c",text[i]);
                              }
                              else
                              {
                                  c++;
                              }
    }
    printf("\" (%d)",n);
    if(c>0)
    {
        printf("\n\nEl numero de letras en el texto es de: %d",c);
    }
    printf("\n\nGracias por usar nuestro programa");
    getchar();
}
