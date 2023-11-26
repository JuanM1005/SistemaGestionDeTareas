#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#define MAX_TAREAS 50
#include <string.h>
#include <time.h>
#include <stdlib.h>

struct tarea {
    char Titulo[100];
    int completado;
    struct tm fecha_entrega;
};

void menu_principal() {
    printf("%cBienvenido al Sistema de Gesti%cn de Tareas!\n", 173, 162);
    printf("\t----------------------------------------\n");
    printf("\t1. Agregar una nueva tarea.\n");
    printf("\t2. Listar todas las tareas.\n");
    printf("\t3. Listar todas las tareas pendientes.\n");
    printf("\t4. Marcar una tarea como completada.\n");
    printf("\t5. Buscar una tarea por t%ctulo.\n", 161);
    printf("\t6. Salir.\n");
    printf("\t----------------------------------------\n");

    printf("Seleccione su opci%cn: ", 162);
}


void agregarTareas(struct tarea *Tasks, int *conTasks) {
    if (*conTasks < MAX_TAREAS) {
        while (getchar() != '\n');  // Limpiar el buffer de entrada

        printf("Ingrese el t%ctulo de la tarea: ", 161);
        fgets(Tasks[*conTasks].Titulo, sizeof(Tasks[*conTasks].Titulo), stdin);
        Tasks[*conTasks].Titulo[strcspn(Tasks[*conTasks].Titulo, "\n")] = '\0';

        printf("Ingrese la fecha de entrega (formato dd mm aaaa): ");
        scanf("%d %d %d", &Tasks[*conTasks].fecha_entrega.tm_mday, &Tasks[*conTasks].fecha_entrega.tm_mon, &Tasks[*conTasks].fecha_entrega.tm_year);

        Tasks[*conTasks].completado = 0;
        (*conTasks)++;
    } else {
        printf("No se pueden agregar m%cs tareas. L%cmite alcanzado.\n", 160, 161);
    }
}

void listarTareas(struct tarea *LisTasks, int conTasks) {
    if (conTasks == 0) {
        printf("No hay tareas para mostrar.\n");
        return;
    }

    printf("TAREAS:\n");
    for (int i = 0; i < conTasks; i++) {
        printf("%d. %s\n", i + 1, LisTasks[i].Titulo);
        }
}

void TareasPendientes(struct tarea *PendingTasks, int conTasks) {
    if (conTasks == 0) {
        printf("No hay tareas pendientes.\n");
        return;
    }

    printf("Tareas Pendientes:\n");
    for (int i = 0; i < conTasks; i++) {
        if (PendingTasks[i].completado == 0) {
            printf("\t%d. %s \nFecha de vencimiento: %02d/%02d/%04d\n", i + 1,
                   PendingTasks[i].Titulo, PendingTasks[i].fecha_entrega.tm_mday,
                   PendingTasks[i].fecha_entrega.tm_mon, PendingTasks[i].fecha_entrega.tm_year);
        }
    }
}

void tareaCompletada(struct tarea *TasksCompleted, int conTasks) {
    if (conTasks == 0) {
        printf("No hay tareas pendientes para marcar como completadas.\n");
        return;  // Indicar que no hay tareas para completar
    }

    TareasPendientes(TasksCompleted, conTasks);

    int Salir = 0;
    int selectTask;

    while (!Salir) {
        printf("Ingresa la tarea que deseas marcar como completada (0/Salir): ");
        scanf("%d", &selectTask);

        if (selectTask >= 1 && selectTask <= conTasks) {
            int index = selectTask - 1;

            if (TasksCompleted[index].completado == 0) {
                TasksCompleted[index].completado = 1;
                printf("\n%d. %s - TAREA COMPLETADA.\n", selectTask, TasksCompleted[index].Titulo);
            } else {
                printf("\nLa tarea %s ya ha sido marcada como completada. DIGITE 0 PARA SALIR\n", TasksCompleted[index].Titulo);
            }
        } else if (selectTask == 0) {
            printf("Saliendo de la operaci%cn.\n", 162);
            Salir = 1;
        } else {
            printf("Selecci%cn no v%clida. Int%cntelo de nuevo.\n", 162, 160, 130);
        }
    }
    // No se incluye "return 1;" al final de la función void.
}

int buscarTareaPorTitulo(struct tarea *titleTasks, int conTasks, int indice) {
    while (getchar() != '\n');

    // Verificar si se alcanzó el final de la lista
    if (indice >= conTasks) {
        printf("La tarea no fue encontrada.\n");
        return 0;  // Indicar que la tarea no fue encontrada
    }

    // Solicitar al usuario que ingrese el título de la tarea
    printf("Ingrese el titulo de la tarea que desea buscar: ");
    char tituloBusqueda[100];
    fgets(tituloBusqueda, sizeof(tituloBusqueda), stdin);
    tituloBusqueda[strcspn(tituloBusqueda, "\n")] = '\0';  // Elimina el carácter de nueva línea.

    // Comparar el título actual con el título de búsqueda
    if (strcmp(titleTasks[indice].Titulo, tituloBusqueda) == 0) {
        // Tarea encontrada, mostrar información
        printf("\n\033[1mTarea encontrada:\033[0m\n");
        printf("T%ctulo: %s\n", 161, titleTasks[indice].Titulo);
        printf("Estado: %s\n", (titleTasks[indice].completado == 1) ? "Completada" : "Pendiente");
        return 1;  // Indicar que la tarea fue encontrada
    }

    // Llamada recursiva con el siguiente índice
    return buscarTareaPorTitulo(titleTasks, conTasks, indice + 1);
}

//Funcion reciclada de un codigo del semestre anterior
void imprime_salida() {
    time_t t = time(NULL);
    struct tm *fecha = localtime(&t);

    char *meses[] = {"enero", "febrero", "marzo", "abril", "mayo", "junio", "julio", "agosto", "septiembre", "octubre", "noviembre", "diciembre"};

    printf("Gracias por utilizar el programa :D\n");
    printf("\t ------------------------ \n");
    printf("\t      Proyecto final \n");
    printf("\tProgramaci%cn Estructurada\n", 162);
    printf("\t ------------------------ \n");
    printf("%02d de %s %04d\n", fecha->tm_mday, meses[fecha->tm_mon], fecha->tm_year + 1900);
}
#endif // FUNCIONES_H_INCLUDED
