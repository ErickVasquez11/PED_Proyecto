# Operaciones Bancarias
## Integrantes
* Edwin Manuel Gonzáles Flores  00013420
* Erick Rickelmy Vásquez Alfaro 00065520
* Felipe Alejandro Araujo Gutiérrez 00155220
* Joel Mauricio Barrera Zepeda 00014220
## Descripción
Operaciones Bancarias tiene como objetivo ser la herramienta con la cual los bancos puedan registrar nuevos usuarios y llevar seguimiento de usuarios ya activos y debido a ello necesitan un software que tiene los siguientes requerimientos:

* Realizar registros de usuarios nuevos tanto como usuarios nuevos de suguros de vida.
* Mostrar el registro de usuarios ingresados tanto como la actualización de datos ingresados por el empleado.
* Mostrar el registro de usuarios de seguros de vida ingresados por el empleado.
* Mostrar el estado de cuenta bancaria de usuario normal, teniendo en cuenta que puede hacer retiro e ingreso de su saldo.
* Mostrar el estado de cuenta bancaria de asegurado, teniendo en cuenta el despuesto del seguro, saldo con el que cuenta.
* Realizar retiro de remesas de cualquier usuario.

## Estructuras utilizadas en el proyecto
Nuestro proyecto cuenta con varias estructuras entre las cuales tenemos:
- 2 registros (struct) utilizados para el registro de clientes, una utilizada para almacenar la informacion del cliente cuenta bancaria y otra utilizada para almacenar datos del cliente de seguro de vida.
- 2 listas donde se guardarán los registros de cada una de las cuentas con la que cuenta el software.
- 1 cola donde se llevara cada cliente sobre el retiro de remesas.
