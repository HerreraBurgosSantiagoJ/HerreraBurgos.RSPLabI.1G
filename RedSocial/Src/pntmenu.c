#include <stdio.h>
#include <stdlib.h>

int print_mainMenu()
{
    int options[10]={1,2,3,4,5,6,7,8,9,10}, trys = 5,choice=0,scnvlue;
    do{
        progHeader("Recursos Humanos: Administracion");
        subHeader("Menu principal");
        printf(" 1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n");
        printf(" 2. Cargar los datos de los empleados desde el archivo data.bin (modo binario).\n");
        printf(" 3. Alta de empleado\n");
        printf(" 4. Modificar datos de empleado\n");
        printf(" 5. Baja de empleado\n");
        printf(" 6. Listar empleados\n");
        printf(" 7. Ordenar empleados\n");
        printf(" 8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n");
        printf(" 9. Guardar los datos de los empleados en el archivo data.bin (modo binario).\n");
        printf("10. Salir\n");
        if(trys!=5)
        {
            printf("ERROR! Lo ingresado no es una opcion valida\n");
            printf("En caso de no obterner una respuesta valida en los intentos restantes\n");
            printf("El programa guardara los cambios realizados en las 2 formas disponibles y se cerrará\n");
            printf("Intentos restantes: %d\n",trys);
        }
        trys--;
        printf("(#)Opcion: ");
        scnvlue=scanf("%d",&choice);
        fflush(stdin);
    }while(validarInt(choice,options,10)&&trys>0&&scnvlue!=1);
    if(scnvlue!=1&&validarInt(choice,options,10))
    {
        choice=-1;
    }
    return choice;
}

int print_sortMenu()
{
    int options[9]={1,2,3,4,5,6,7,8,9}, trys = 5,choice=0,scnvlue;
    do{
        progHeader("Recursos Humanos: Administracion");
        subHeader("Menu de Ordenamiento");
        printf("\n 1. Ordenar Empleados por ID Ascendente.\n");
        printf(" 2. Ordenar Empleados por nombre Ascendente.\n");
        printf(" 3. Ordenar Empleados por Horas de Trabajo Ascendente.\n");
        printf(" 4. Ordenar Empleados por Sueldo Ascendente.\n");
        printf(" 5. Ordenar Empleados por ID Desendente.\n");
        printf(" 6. Ordenar Empleados por nombre Desendente.\n");
        printf(" 7. Ordenar Empleados por Horas de Trabajo Desendente.\n");
        printf(" 8. Ordenar Empleados por Sueldo Desendente.\n");
        printf(" 9. Volver al menu principal\n");
        if(trys!=5)
        {
            printf("ERROR! Lo ingresado no es una opcion valida\n");
            printf("En caso de no obterner una respuesta valida en los intentos restantes\n");
            printf("El programa regresara al menu principal\n");
            printf("Intentos restantes: %d\n",trys);
        }
        trys--;
        printf("(#)Opcion: ");
        scnvlue=scanf("%d",&choice);
        fflush(stdin);
    }while(validarInt(choice,options,9)&&trys>0&&scnvlue!=1);
    if(scnvlue!=1||validarInt(choice,options,9))
    {
        choice=-1;
    }
    return choice;
}

int print_modifyMenu(Employee* him)
{
    int options[5]={1,2,3,4,5}, trys = 5,choice=0,scnvlue;
    do{
        progHeader("Recursos Humanos: Administracion");
        subHeader("Modificar Empleado");
        printf("\n  ID           Nombre             Hrs Trabajo  Sueldo\n");
        printf("------------------------------------------------------\n");
        employee_show(him);
        printf(" 1. Modificar Nombre del Empleado.\n");
        printf(" 2. Agregar Horas Trabajadas.\n");
        printf(" 3. Aumentar/Reducir sueldo.\n");
        printf(" 4. Elegir otro empleado para modificar.\n");
        printf(" 5. Volver al menu principal\n");
        if(trys!=5)
        {
            printf("ERROR! Lo ingresado no es una opcion valida\n");
            printf("En caso de no obterner una respuesta valida en los intentos restantes\n");
            printf("El programa regresara al menu principal\n");
            printf("Intentos restantes: %d\n",trys);
        }
        trys--;
        printf("(#)Opcion: ");
        scnvlue=scanf("%d",&choice);
        fflush(stdin);
    }while(validarInt(choice,options,5)&&trys>0&&scnvlue!=1);
    if(scnvlue!=1||validarInt(choice,options,5))
    {
        choice=-1;
    }
    return choice;
}
