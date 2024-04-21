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


