#include "tdas/list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tipoPaciente {
  char nombre[61];
  int edad;
  char sintomas[150];
  int hora_ingreso;
  int minuto_ingreso;
} tipoPaciente;

//-----------------------------------------------------------------------------------
void limpiarPantalla() { system("clear"); }

void presioneTeclaParaContinuar() {
  puts("Presione una tecla para continuar..."); //**PUTS**funciona como un
                                                // printf, usualmente acompaña
                                                // un gets
  getchar(); // Consume el '\n' del buffer de entrada (puts genera
             // automaticamente un \n)
  getchar(); // Espera a que el usuario presione una tecla
}

// Menú principal
void mostrarMenuPrincipal() {
  limpiarPantalla();
  puts("========================================");
  puts("     Sistema de Gestión Hospitalaria");
  puts("========================================");

  puts("1) Registrar paciente");
  puts("2) Asignar prioridad a paciente");
  puts("3) Mostrar lista de espera");
  puts("4) Atender al siguiente paciente");
  puts("5) Mostrar pacientes por prioridad");
  puts("8) Salir");
}
//-----------------------------------------------------------------
int lower_than(void *data1, void *data2) {
  tipoPaciente *paciente1 = (tipoPaciente *)data1;
  tipoPaciente *paciente2 = (tipoPaciente *)data2;

  if (paciente1->hora_ingreso < paciente2->hora_ingreso) {
    return 1;
  } else if (paciente1->hora_ingreso == paciente2->hora_ingreso &&
             paciente1->minuto_ingreso < paciente2->minuto_ingreso) {
    return 1;
  }
  return 0;
}
//-----------------------------------------------------------------------------------
tipoPaciente *buscar_eliminar_paciente(List *lista, char *nombre) {
  tipoPaciente *paciente = NULL;
  for (paciente = list_first(lista); paciente != NULL;
       paciente = list_next(lista)) {
    if (strcmp(paciente->nombre, nombre) == 0) {
      list_popCurrent(lista);
      return paciente;
    }
  }
  return NULL;
}
//---------------------------------------------------------------------------------------

void registrar_paciente(List *listaPrioridad1) {
  printf("Registrar nuevo paciente\n");

  tipoPaciente *nuevoPaciente = malloc(sizeof(tipoPaciente));
  if (nuevoPaciente == NULL) {
    printf("Error al asignar memoria para el paciente.\n");
    return;
  }

  printf("\n||Ingrese nombre del paciente||\n->");
  scanf("%60[^\n]s", nuevoPaciente->nombre);
  getchar();

  int resultado;
  do {
    printf("\n||Ingrese la edad del paciente en años||\n->");
    resultado = scanf("%d", &nuevoPaciente->edad);
    while (getchar() != '\n')
      ; // Limpia el búfer de entrada.
    if (resultado != 1) {
      printf("**ENTRADA NO VALIDA. INGRESE UN NUMERO**\n");
    }
  } while (resultado != 1);

  printf("\n||inserte sintomas del paciente||\n->");
  scanf("%150[^\n]s", nuevoPaciente->sintomas);
  getchar();

  int horasValidas, minutosValidos;
  do {
    printf(
        "\n||Ingrese horario de ingreso del paciente en formato hr:min||\n->");
    horasValidas = scanf("%d", &nuevoPaciente->hora_ingreso);
    while (getchar() != ':')
      ; // Espera por el carácter separador ':'.
    minutosValidos = scanf("%d", &nuevoPaciente->minuto_ingreso);
    while (getchar() != '\n')
      ; // Limpia el búfer de entrada.

    if (horasValidas != 1 || minutosValidos != 1 ||
        nuevoPaciente->hora_ingreso < 0 || nuevoPaciente->hora_ingreso > 23 ||
        nuevoPaciente->minuto_ingreso < 0 ||
        nuevoPaciente->minuto_ingreso > 59) {
      printf("**HORA NO VALIDA. INGRESE LA HORA Y MINUTOS EN EL FORMATO "
             "CORRECTO (hh:mm) Y ASEGURATE QUE SEA UNA HORA VALIDA.**\n");
      horasValidas = minutosValidos =
          0; // Reinicia las variables para el próximo intento.
    }
  } while (horasValidas != 1 || minutosValidos != 1);

  printf("\n||LA PRIORIDAD DEL PACIENTE SE HA ASIGNADO AUTOMATICAMENTE COMO "
         "BAJA(1)||\n");

  list_sortedInsert(listaPrioridad1, nuevoPaciente, lower_than);

  printf("\nPACIENTE REGISTRADO CON EXITO.\n");
}
//-----------------------------------------------------------------------------------------
void asignar_prioridad_pacientes(List *listaPrioridad1, List *listaPrioridad2,
                                 List *listaPrioridad3) {

  tipoPaciente *paciente = NULL;
  List *listaActual = NULL;
  char nombreBuscar[61];
  int actualPrioridad;
  int nuevaPrioridad;

  printf("||Ingrese el nombre del paciente al que desea asignar una nueva "
         "prioridad||\n");
  scanf("%60[^\n]s", nombreBuscar);
  getchar();

  printf("\n||Ingrese la PRIORIDAD ACTUAL del "
         "paciente\nAlta[3]\nMedia[2]\nBaja[1]||\n->");
  while (1) {
    scanf("%d", &actualPrioridad);

    if (actualPrioridad != 1 && actualPrioridad != 2 && actualPrioridad != 3)
      printf("\n");

    else {
      getchar();
      break;
    }
  }

  printf("\n||Ingrese la nueva prioridad del "
         "paciente\nAlta[3]\nMedia[2]\nBaja[1]||\n");
  while (1) {
    scanf("%d", &nuevaPrioridad);

    if (nuevaPrioridad != 1 && nuevaPrioridad != 2 && nuevaPrioridad != 3)
      printf("**PRIORIDAD NO VALIDA**\n");

    else {
      getchar();
      break;
    }
  }

  switch (actualPrioridad) {
  case 1:
    if (nuevaPrioridad == 1) {
      printf("**El paciente ya tiene prioridad baja**\n");
      return;
    } else
      paciente = buscar_eliminar_paciente(listaPrioridad1, nombreBuscar);
    break;
  case 2:
    if (nuevaPrioridad == 2) {
      printf("**El paciente ya tiene prioridad media**\n");
      return;
    } else
      paciente = buscar_eliminar_paciente(listaPrioridad2, nombreBuscar);
    break;
  case 3:
    if (nuevaPrioridad == 3) {
      printf("**El paciente ya tiene prioridad alta**\n");
      return;
    }

    else
      paciente = buscar_eliminar_paciente(listaPrioridad3, nombreBuscar);
    break;
  }

  if (paciente == NULL) {
    printf("**PACIENTE NO ENCONTRADO**");
    return;
  }

  switch (nuevaPrioridad) {
  case 1:
    list_sortedInsert(listaPrioridad1, paciente, lower_than);
    break;
  case 2:
    list_sortedInsert(listaPrioridad2, paciente, lower_than);
    break;
  case 3:
    list_sortedInsert(listaPrioridad3, paciente, lower_than);
    break;
  }
}
//------------------------------------------------------------------------------------------
void mostrar_pacientes_de_lista(List *lista) {
  int contador = 1;
  tipoPaciente *paciente = list_first(lista);
  if (paciente == NULL)
    printf("\n**NO HAY PACIENTES EN LA LISTA**\n");
  while (paciente != NULL) {
    printf("\n%d)Nombre: %s, Edad: %d\n\nSíntomas: %s\nHora de "
           "ingreso: %02d:%02d\n",
           contador, paciente->nombre, paciente->edad, paciente->sintomas,
           paciente->hora_ingreso, paciente->minuto_ingreso);
    paciente = list_next(lista);
    contador++;
  }
  printf("\n");
}

void mostrar_lista_pacientes(List *listaPrioridad1, List *listaPrioridad2,
                             List *listaPrioridad3) {
  printf("\nPACIENTES EN ESPERA: \n\n");
  printf("||Pacientes de prioridad ALTA||\n");
  mostrar_pacientes_de_lista(listaPrioridad3);

  printf("||Pacientes de prioridad MEDIA||\n");
  mostrar_pacientes_de_lista(listaPrioridad2);

  printf("||Pacientes de prioridad BAJA||\n");
  mostrar_pacientes_de_lista(listaPrioridad1);
}
//------------------------------------------------------------------------------------------

void atender_siguiente_paciente(List *listaPrioridad) {
  tipoPaciente *paciente = list_popFront(listaPrioridad);
  printf("Nombre: %s, Edad: %d\n\nSíntomas: %s\nHora de "
         "ingreso: %02d:%02d\n",
         paciente->nombre, paciente->edad, paciente->sintomas,
         paciente->hora_ingreso, paciente->minuto_ingreso);
}
//-------------------------------------------------------------------------------------------
void mostrar_por_prioridad(List *listaPrioridad1, List *listaPrioridad2,
                           List *listaPrioridad3) {
  printf("Ingrese la prioridad a mostrar\n\n(3)ALTA\n(2)MEDIA\n(1)BAJA\n\n");
  int opcion;
  scanf("%d", &opcion);
  getchar();

  do {
    if (opcion != 1 && opcion != 2 && opcion != 3) {
      printf("Opcion no valida\n");
      scanf("%d", &opcion);
      while (getchar() != '\n')
        ;
    }
  } while (opcion != 1 && opcion != 2 && opcion != 3);

  switch (opcion) {
  case 1:
    mostrar_pacientes_de_lista(listaPrioridad1);
    break;
  case 2:
    mostrar_pacientes_de_lista(listaPrioridad2);
    break;
  case 3:
    mostrar_pacientes_de_lista(listaPrioridad3);
    break;
  }
}
//-------------------------------------------------------------------------------------------
int main() {
  char opcion;
  List *listaPrioridad1 = list_create();
  List *listaPrioridad2 = list_create();
  List *listaPrioridad3 = list_create();

  do {
    mostrarMenuPrincipal();
    printf("Ingrese su opción: \n-> ");
    scanf(" %c", &opcion);

    getchar();

    switch (opcion) {
    case '1':
      registrar_paciente(listaPrioridad1);
      break;
    case '2':
      asignar_prioridad_pacientes(listaPrioridad1, listaPrioridad2,
                                  listaPrioridad3);
      break;
    case '3':
      mostrar_lista_pacientes(listaPrioridad1, listaPrioridad2,
                              listaPrioridad3);
      break;

    case '4':
      if (list_first(listaPrioridad3) != NULL)
        atender_siguiente_paciente(listaPrioridad3);
      else if (list_first(listaPrioridad3) == NULL &&
               list_first(listaPrioridad2) != NULL)
        atender_siguiente_paciente(listaPrioridad2);
      else if (list_first(listaPrioridad3) == NULL &&
               list_first(listaPrioridad2) == NULL &&
               list_first(listaPrioridad1) != NULL)
        atender_siguiente_paciente(listaPrioridad1);
      else
        printf("NO HAY PACIENTES EN ESPERA\n");

      break;

    case '5':
      mostrar_por_prioridad(listaPrioridad1, listaPrioridad2, listaPrioridad3);
      break;
    case '6':
      puts("Saliendo del sistema de gestión hospitalaria...");
      break;
    default:
      puts("Opción no válida. Por favor, intente de nuevo.");
    }
    presioneTeclaParaContinuar();

  } while (opcion != '6');

  list_clean(listaPrioridad1);
  list_clean(listaPrioridad2);
  list_clean(listaPrioridad3);

  return 0;
}