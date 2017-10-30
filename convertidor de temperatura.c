#include "stdio.h"

/*
  Name: Mota Converter
  Copyright: Cosoft
  Author: Erik Mota
  Date: 15/06/17 04:29
  Description: Aplicacion engargada en convertir la unidades de temperatura
  en °C,°F y K; Mejoramiento y actualizacion del codigo gracias a Simon Ortiz
  el Mejor Coaching.
*/

//flotante que capturara el valor de la temperatura
float get_temp()
{
      float num,i=0;
      //si existe carcteres flotantes no repetias este proceso
      while(i!=1)
      {
              printf("ingrese el valor de la temperatura a convertir: ");
	      // la varible "i" nos confirmara si existe un valor flotante arrogandonos un 1 como si y 0 como no
              i = scanf("%f",&num);
              getchar();
              if(i!=1)
              {
                  printf("\nEl valor ingresado no es posible convertir\n");
              }
      }
      return num;
}

//funcion convertora a °F
float fahrenheit(float num)
{
      num = ((num*9)/5)+32;
      printf("la temperatura es  %0.2f °F",num);
}


/*funcion para convertir a grados celsius con
tres terminos que determina si la convercion es de
°F a °C o de K °C y las vaiablre print nos
dara si hay que imprimir el resultado o si
tan solo quiere saber el valor numerico de la conversion*/
float celsius(int type,int print,float num)
{
      if(type == 1)
      {
          num = ((num-32)/9)*5;
      }
      else
      {
          num = num-273.15;
      }
      if(print == 1)
      {
               printf("la temperatura es  %0.2f °C",num);
      }
      else
      {
          return num;
      }
}

//funcion para convertir a K
float kelvin(float num)
{
      num = num+273.15;
      printf("la temperatura es  %0.2f K",num);
}

//funcion que imprime un error si hay algun caracter o numero no esperado
void print_option_error()
{
     printf("Esta opcion no esta regitrada por favor vuelva a intentarlo...");
     getchar();
}

//funcion que imprimer la opciones de convercion a los usuarios
void print_option()
{
     int option;
     float temp;
     while(1)
     {
             printf("\n1)Celsius a Fahrenheit\n");
             printf("2)Celsius a Kelvin\n");
             printf("3)Fahrenheit a Celsius\n");
             printf("4)Fahrenheit a Kelvin\n");
             printf("5)Kelvin a Celsius\n");
             printf("6)Kelvin a Fahrenheit\n");
             printf("7)Salir\n");
             printf("Seleccione una de las opciones: ");
             scanf("%d",&option);
             getchar();
             if(option>0 && option<7)
             {
                         temp = get_temp();
             }
             switch(option)
             {
                           case 1:
                                fahrenheit(temp);
                           break;
                           case 2:
                                kelvin(temp);
                           break;
                           case 3:
                                celsius(1,1,temp);
                           break;
                           case 4:
                                temp = celsius(1,0,temp);
                                kelvin(temp);
                           break;
                           case 5:
                                celsius(2,1,temp);
                           break;
                           case 6:
                                temp = celsius(2,0,temp);
                                fahrenheit(temp);
                           break;
                           case 7:
                                return;
                           break;
                           default:
                                   print_option_error();
                           break;

             }
     }
}

//funcion para imprimir una bienvenida al programa
void print_welcome()
{
     printf("Bienvendido al convertidor de temperatura NanBan\n\n");
}

//funcion que se encargara de imprimir un mensaje final antes de salir
void print_exit()
{
     printf("Gracias por usar nuestro producto");
     getchar();
}

//esta es la funcion principal o de menu
int main()
{
    print_welcome();

    print_option();

    print_exit();
}
