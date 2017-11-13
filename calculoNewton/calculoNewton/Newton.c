#include <stdio.h>
#include <stdlib.h>
#include <math.h>//libreria para operaciones matematicas

/*
*double funcion(double x) {//Funcion.....
*
	*return 	sqrt(x);
	*
	 *Ejemplos de Funciones
	*(log(x-1) + cos(x-1))			funcion con la que practicamos antes del examen q saque cero :v jajajajajaja
	* sqrt(x);						sqrt(Raiz Cuadrada)
	*
	* 2+cos(exp(x)-2)-(exp(x));		exp(Exponente base 10)
	*
	* pow(x,2);						pow(Elevar numero a X potencia) pow(base,potencia)
	*
	* log(x); 						log(Logaritmo Neperiano)
	*
*}
*/



/*Funcion que queremos aproximar*/
double funcion(double x) {
	
	return (pow(x,3)-x-1);
}

/*Derivada de la función a aproximar*/
double dfx(double x) {
	
	return ((3*pow(x, 2)) - 1);
}
/*Formula iterativa de NewtonRapson*/
double f(double xi) {

	return xi - (funcion(xi) / dfx(xi));

}
/*Error de la funcion*/
double error(double ant, double act) {

	return fabs((act - ant) / act);

}


void Newton_Rapson(double xi, double cota, int n) {/*Algoritmo de Newton-Rapson*/
	int i = 0;
	double er = cota + 1, aux = 0;

	do {
		if (i == 0) {
			printf("i = %d\t X%d\ = %.6lf\t	 X%d\ = %.6lf\t\n", i, i , xi, i+1, f(xi));

		}
		else {
			printf("i = %d\t X%d\ = %.6lf\t	 X%d\ = %.6lf\t\n", i,  i, xi, i + 1, f(xi), er = error(aux, f(xi)));
			
		}

		aux = f(xi);
		xi = f(xi);

		i++;
	} while (i<n && er>cota);

	printf("funcion = %.11lf", funcion(xi));/*Falta arreglar la comprobacion */

}






int main(int argc, char **argv)
{
	
	Newton_Rapson(-8, 0.0000005, 10);/*Newton Rapson(punto para converger Xo,cota de error,Numero de iteraciones)*/
	printf("\n");
	printf("Hello world!\n");
	system("PAUSE");
	return 0;
}