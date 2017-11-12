#include <stdio.h>
#include <stdlib.h>
#include <math.h>//libreria para operaciones matematicas

double funcion(double x) {//Funcion.
					 
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


int diferentessigno(double valora, double valorb) {//Funcion para saber el signo de dos punto en la funcion
									
	if ((funcion(valora)>0 && funcion(valorb)<0) || (funcion(valora)<0 && funcion(valorb)>0)) {

		return 1;//Retorna 1 en caso de ser positivo.									

	}
	else {

		return 0;//Retorna 0 en caso de ser negativo.
	}

}

double exi(double a, double b) {//ecuacion para calcular el valor xi.
							  
	return (a + b) / 2;
}

double error(double antxi, double actxi) {//Funcion para calcular la cota de error.
									  
	return fabs(actxi - antxi);//fabs calcula el valor absoluto
}

void biseccion(double a, double b, double cuotaerror, int numerointervalo) {//Algoritmo biseccion.
														   
	int i = 0;
	double aux = 0, xi = 0, er = 0;//er:Dominio del error 
								  
	do {

		printf("\n I%d xi%d = %.4lf\t", i + 1, i + 1, xi = exi(a, b));
		printf("fxi  = %.4lf\t", funcion(xi));

		if (i>0) {
			printf("er%d = %.3lf", i + 1, er = error(aux, xi));
			if (er<cuotaerror) break;
		}

		if (diferentessigno(a, xi)) { b = xi; }
		else { a = xi; }

		aux = xi;
		i++;

	} while (i<numerointervalo);

}



int main(int argc, char **argv)
{
	biseccion(1.3, 2, 0.03, 5);//biseecion(Valor a,Valor b,Cuota de Error,Numero de Iteraciones).
	printf("\n");
	printf("Hello world!\n");
	system("PAUSE");
	return 0;
}
