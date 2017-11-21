
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char **argv) {

	double h, a, b, i, suma, F, xi, t;
	int N;

	printf("Metodo de intregacion compuesto del trapecio\n");
	printf("La funcion a integrar es SENO(X)/(1+X^4)^0.5\n");
	
	printf("Ingrese el limite inferior de la integral---A: \n");
	scanf_s("%lf", &a);//limite inferior d la integracion
	
	printf("Ingrese el limite superior de la integral---B: \n");
	scanf_s("%lf", &b);//limite superior d la integracion
	
	printf("Ingrese N: ");
	scanf_s("%d", &N);//numero de iteraciones

	h = (b - a) / N;
	i = 0;
	suma = 0;

	for (i = 0;i <= N;i++) {
		xi = a + i*h;
		F = (xi*( sin (pow(xi,2))));

		suma = suma + F;
		t = suma * h;
	}
	printf("Los valores son:\n");
	printf("a = %.3lf\n" ,a );
	printf("b = %.3lf\n", b );
	printf("h = %.3lf\n", h );
	printf("la suma es: %.3lf\n", suma );


	printf("LA INTEGRAL ES : %.3lf\n", t );

	system("PAUSE");
	return 0;
}