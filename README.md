En este *repl* puedes encontrar varios ejemplos que te pueden ayudar con las tareas de estructura.

## Código de Ejemplo (main)
Para ejecutar el main primero debemos compilar (en la carpeta raíz)
````
gcc tdas/*.c main.c -Wno-unused-result -o main
````

Y luego ejecutar:
````
./main
````

## Como ejecutar el programa

A la hora de compilar el programa se le solicitara al ususario ingresar una de las siguientes opciones, las cuales deben ser ingresadas en formato numerico:

1) Registrar paciente: Encargado del registro adecuado de los pacientes, que solicitará el nombre, edad, síntomas y hora de ingreso del paciente. Asignará al paciente de forma automática a una prioridad BAJA.
2) Asignar prioridad a paciente: Se le solicita al usuario ingresar el nombre del paciente, luego la prioridad actual y a la que se desea reasignar.
3) Mostrar lista de espera: Mostrará a los pacientes, desde la prioridad alta a la baja.
4) Atender al siguiente paciente: mostrará el paciente de mayor prioridad y lo eliminará, pues se considerará atendido.
5) Mostrar pacientes por prioridad: muestra la lista de prioridad que se le solicitó.
8) Salir: sale del programa.

## Posibles errores

A pesar de que en algunos casos, si no se siguen correctamente las instrucciones, el programa será capaz de solicitar al usuario volver a ingresar un imput. Existen algunos que probablemente no haya previsto. Por esto, no seguir de forma adecuada los pasos puede llevar a errores.
Por otro lado, ingresar dos pacientes del mismo nombre, hora y prioridad, puede llevar a confusiones a la hora de cambiar sus prioridades, pues no hay una forma real de mover a un paciente específico, pues el programa moverá al que encuentre primero. El error radica en que, si los pacientes tienen síntomas distintos, puede conllevar errores fatales.


## Ejemplo de uso

Paso 1: 
Al abrir el menú de usuario por primera vez se debe seleccionar *(1)* para poder añadir un nuevo paciente.

imputs:
````
(en el menú principal)
1 ↵
Gabriel Pérez ↵
19 ↵
Dolor de costillas flotantes ↵
````

Gabriel será guardado en la lista de prioridad baja, y se le informará al respecto.

Paso 2:
Si se desea mover a Gabriel a una lista de prioridad más alta, se debe seguir un procedimiento como este. 
````
(en el menú principal)
2 ↵
Gabriel Pérez↵
1↵
3↵
````
El 2 representa la acción que se desea. Sigue el nombre a buscar y la lista de prioridad actual del paciente. Finalmente, se escribe la lista de prioridad a la que se ha de mover al paciente. Recordar que las prioridades son *(1)Baja*, *(2)Media* y *(3)Alta*.

Paso 3:
Si se desea ver a todos los pacientes en espera, se debe seguir una sucesión de imputs sencilla.
````
(en el menú)
3↵
````
Esto nos mostrará todas las listas de mayor a menor prioridad y sus pacientes. En nuestro ejemplo, la lista *(3)Alta* sería la única con un paciente, siendo este Gabriel.

Paso 4:
Imaginemos que luego de ingresar a Gabriel, decidimos añadir a otro paciente, Verónica Martínez. No ha sido movida, así que su prioridad es baja. Si nuestro interés es atender a los pacientes en orden, necesitamos seguir la siguiente sucesión de impuestos.
````
(en el menú)
4↵
````
Esta sencilla respuesta nos desplegará inmediatamente el paciente más prioritario y que además haya llegado con más antelación. En nuestro caso, sería Gabriel. Si volvemos a preguntar por la siguiente paciente, Verónica aparecerá. Luego de presionar la *opción 4*, los pacientes se darán por atendidos y se eliminarán de sus respectivas listas.

Paso 5:
si se desea ver solo una porción de los pacientes en espera, segmentando por prioridades, el procedimiento es sencillo.
````
(en el menú)
5↵
3↵ 
````
se debe seleccionar la opción 5, seguida de la lista de prioridad que se espera ver *(1)Baja, (2)Media y (3)Alta*. Una vez seleccionado, se mostrará la lista con sus pacientes. Al ya haber atendido a Gabriel, la lista se mostrará vacía.
