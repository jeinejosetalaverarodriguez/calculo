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



//Funcion que queremos aproximar*/
double funcion(double x) {
	
	return (pow(x,3)-x-1);
}

//Derivada de la función a aproximar*/
double dfx(double x) {
	
	return ((3*pow(x, 2)) - 1);
}
//segunda derivada
double ddfx(double x) {

	return (6 * x);
}



/*Formula iterativa de NewtonRapson*/
double f(double xi) {

	return xi - (funcion(xi) / dfx(xi));

}
/*Error de la funcion*/
double error(double ant, double act) {

	return fabs((act - ant) / act);

}

int convergencia(double x) {
	double aux= ((funcion(x)*ddfx(x)) / pow(dfx(x), 2));
	int s;
	if (aux<1) {
		s = 1;
	printf("\n el valo de Xi=%.2lf cumple con el citerio de convergencia\n",x);
	printf("\n criterio de convergencia=%lf<1\n", aux);
	}
	else {
		s = 0;
		printf("valor de Xi=%lf no cumple con el criterio de convergencia", x);
		printf("\n criterio de convergencia=%lf >  1\n", aux);
	}
	printf("\n////////////////////////////////////////////////////////////////////////////////\n");
	printf("\n");
	return s;
}

void Newton_Rapson(double xi, double cota, int n) {/*Algoritmo de Newton-Rapson*/
	int i = 0;
	double er = cota + 1, aux = 0;
	
	if (convergencia(xi) == 1){
		do {
			if (i == 0) {
				printf("i = %d\t X%d\ = %.6lf\t	 X%d\ = %.6lf\t\n", i, i, xi, i + 1, f(xi));

			}
			else {
				printf("i = %d\t X%d\ = %.6lf\t	 X%d\ = %.6lf\t\n", i, i, xi, i + 1, f(xi), er = error(aux, f(xi)));

			}

			aux = f(xi);
			xi = f(xi);

			i++;
		} while (i<n && er>cota);
		printf("\n////////////////////////////////////////////////////////////////////////////////\n");
		printf("\n");
		printf("X%i=%.11lf\n",i, xi);
		printf("\nERROR=%.11lf",er = error(aux, f(xi)));
		printf("\n////////////////////////////////////////////////////////////////////////////////\n");
		printf("\n");
		printf("f(X%i) = %.11lf",i, funcion(xi));
		printf("\n////////////////////////////////////////////////////////////////////////////////\n");
		printf("\n");
}
}






int main(int argc, char **argv)
{
	
	Newton_Rapson(-8, 0.0000005, 10);/*Newton Rapson(punto para converger Xo,cota de error,Numero de iteraciones)*/
	printf("\n");
	system("PAUSE");
	return 0;
}