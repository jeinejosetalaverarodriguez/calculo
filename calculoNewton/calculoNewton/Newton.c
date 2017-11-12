#include <stdio.h>
#include <stdlib.h>
#include <math.h>//libreria para operaciones matematicas

double funcion(double x) {//Funcion.....

	return 	sqrt(x);

	/* Ejemplos de Funciones
	*(log(x-1) + cos(x-1))			funcion con la que practicamos antes del examen q saque cero :v jajajajajaja
	* sqrt(x);						sqrt(Raiz Cuadrada)
	*
	* 2+cos(exp(x)-2)-(exp(x));		exp(Exponente base 10)
	*
	* pow(x,2);						pow(Elevar numero a X potencia) pow(base,potencia)
	*
	* log(x); 						log(Logaritmo Neperiano)
	*/
}





int main(int argc, char **argv)
{
	biseccion(1.3, 2, 0.03, 5);//biseecion(Valor a,Valor b,Cuota de Error,Numero de Iteraciones).
	printf("\n");
	printf("Hello world!\n");
	system("PAUSE");
	return 0;
}