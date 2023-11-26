#include <stdio.h>
#include "FUNCIONES.H"

/*Aguirre Mares Juan Antonio -
    Programación Estructurada*/

int main() {
    struct tarea Tareas[MAX_TAREAS];
    int numTareas = 0, opc;

    do {
        system("cls");
        menu_principal();
        scanf("%d", &opc);

        switch (opc) {
            case 1:
                system("cls");
                agregarTareas(Tareas, &numTareas);
                break;
            case 2:
                system("cls");
                listarTareas(Tareas, numTareas);
                system("pause");
                break;
            case 3:
                system("cls");
                TareasPendientes(Tareas, numTareas);
                system("pause");
                break;
            case 4:
                system("cls");
                tareaCompletada(Tareas, numTareas);
                system("pause");
                break;
            case 5:
                system("cls");
                buscarTareaPorTitulo(Tareas, numTareas, 0);
                system("pause");
                break;
            case 6:
                imprime_salida();
                break;
            default:
                printf("Error opci%cn incorrecta. Int%cntelo de nuevo.\n", 162, 130);
        }

    } while (opc != 6);

    return 0;
}
