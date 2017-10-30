#include <stdio.h>
#include <stdlib.h>
/**
* Funcion encargada de convertir un entero en un caracter
@param int num
@return int
*/
char convert_int_char(int num)
{
     char s[] = "";
     if(num <= 9)
     {
         return (char)(num+48);
     }
}

int main()
{
    int e[8]={0,10,100,1000,10000,100000,1000000,10000000};//la bases a dividir
    int i, num_scanf,n=0,x,y;//numero a escanear
    char charter_num[] = "";//espacio para los caracteres numericos
    while(n != 1)
    {
            n = scanf("%d",&num_scanf);
            getchar();
            if(n != 1)
            {
                printf("Ingrese un numero entero por favor...\n");
            }
    }
    while(num_scanf > e[i])
    i++;
    if(i == 0)
         charter_num[i] = convert_int_char(num_scanf);

    printf("Este es el numero en caracter '%s' \n",charter_num);
    getchar();
    
    
}
