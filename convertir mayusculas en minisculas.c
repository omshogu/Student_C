/* programa do convertir las mayusculas en minusculas */
#include <stdio.h>

//nM numero de mayusculas y nm numero de minisculas
int nM,nm;

//esta funcion ara el proceso que convertir cada caracter
char process(char c)
{
     //si las letras son mayusculas las convierte en minusculas
     if(c>='A' &&  c<='Z')
     {
               nM++;
               return (c+('a'-'A'));
     }
     //de lo contrario conviertela en mayusculas
     else
     {
         nm++;
         return (c+('A'-'a'));
     }
}

/* esta funcion se encarga de saber si el mayor numero de 
letras es mayusculas o minisculas he imprimir un mensaje
correspondiente a la cantidad de letras de acuerdo a su
especificacion de ser mayusculas o minusculas*/
int print_name(char name[])
{
    if( nM > nm )
    {
        printf("su nombre en minusculas es : \"%s\"",name);
    }
    if( nm > nM)
    {
        printf("su nombre en mayusculas es : \"%s\"",name);
    }
    if(nm == nM)
    {
          printf("su nombre en tiene igual de mayusculas y minusculas es : \"%s\"",name);
    }
}

//funcion principal
int main()
{
    //un arreglo de caracteris si un limite determinado porque
    //no se que tan largo puede ser lo que inroduzca nuestro usuaio
    char name[]="";
    int i;
    printf("ingrese su nombre todo en miniscula o mayusculas: ");
    
    //escanea en forma de una linea de caracteres el nombre ingresado
    scanf("%s",&name);
    getchar();
    
    //este ciclo nos ayudara a determinar si cada caracter esta en mayusculas o minisculas
    for(i=0;name[i]!='\0';i++)
    {
                     name[i]=process(name[i]);
    }
    
    print_name(name);
    getchar();
}
