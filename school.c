#include <stdio.h>
#include <stdlib.h>
#define NAME_MAX_CHAR 30

//numero de datos guardados
int num_data = 0;

//estructura de profesores
struct sTeacher {
       //id es identidad como una llave primaria y year la edad del profesor
       int id,year;
       //nombre del profesor
       char name[30];
}*p;
//queria darle la oportunidad de que agarrara gran cantidad de datos sin limites
//pero lo que hago es consumir memoria y no se que hacer alli...

int strlen(char c[])
{
    int i;
    for(i=0; c[i] != '\0'; i++)
    i=i;
    return i;
}

//imprime la bienvenida
void print_welcome()
{
    printf("bienvenidos al organizador de la escolar\n");
}

//lee el nombre, el nombre mas pequeño que conozco es ana de 3 caracteres por eso es el limite 3
int read_name(char *c)
{
    int i;
    while(1)
        {
            printf("\nNombre del profesor: ");
            scanf("%30s",&(*c));
            getchar();
            i = strlen(c);
            if(i < 3)
                 printf("\nEl nombre ingresado tiene menos de 3 tres letras\npor favor ingrese un nombre mas largo:\n");
            else
                return 1;
        }
}

//lee la edad, el profesor debe ser mayor de 20 años y menor de 60
//para no estar jubilado...
int read_year(int *n)
{
    while(1)
    {
            printf("\nEdad del profesor: ");
            int read_count = scanf("%d",&(*n));
            getchar();
            if(read_count == 1 && (*n) > 20 && (*n) < 60)
                return 0;
            else
                printf("\nEl profesor no puede ser menor de 20 años ni mayor de 60 años...\ningrese una edad correspondiente\n");
    }
}

//funcion encargada de crear un nuevo dato del profesor
void create_new_teacher(char *c,int *a)
{
     int i, n = num_data;
     p[n].id = n + 1;
     p[n].year = *a;
     for(i=0; c[i] != '\0';i++)
              p[n].name[i] = c[i];
     num_data++;
     printf("\n\nSe agrego un nuevo profesor con exito\n\n");
}

//este funcion se encarga de mostrar una tabla con los datos de los profesores guardados
void show_table()
{
    int i;
    printf("__________________________\n");
    printf("| N |  Nombres  |   Edad |\n");
    printf("__________________________\n");
    for(i = 0 ; i < num_data; i++)
        {
            printf("| %d | %s |  %d  |\n",p[i].id,p[i].name,p[i].year);
            printf("___________________________________\n");
        }
        if(num_data == 0)
        {
            printf("      Sin Datos Aun\n");
            printf("__________________________\n");
        }
    printf("\n");
}

//funcion que organiza como evaluar para crear los datos del profesor
void create_teacher()
{
     char temp_name[NAME_MAX_CHAR + 1];

     int temp_year=0;

     read_name(temp_name);

     read_year(&temp_year);

     create_new_teacher(temp_name,&temp_year);
}

//funcion encargada de imprimir las opciones
void print_options()
{
    printf("1)Crear datos de un nuevo profesor.\n");
    printf("2)Muestra los profesores.\n");
    printf("3)Salir del programa.\n");
}

//funcion encargada de leer las entradas a las opciones
int read_option()
{
    p = (struct sTeacher*) malloc(sizeof(unsigned int));
    while(1)
        {
            print_options();
            int option;
            printf("ingrese su opcion: ");
            scanf("%d",&option);
            getchar();
            switch(option)
            {
                          case 1: create_teacher(); break;
                          case 2: show_table(); break;
                          case 3: return 0; break;
                          default: printf("\nla opcion escogida no es valida\n\n");break;
            }
        }
}

//funcion principal
int main()
{
    print_welcome();

    read_option();
}
