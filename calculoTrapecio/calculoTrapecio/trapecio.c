
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double funcion(double xi) {

	return (sin(pow(xi, 2)));
}

double trapecio(double a, double b, int N){
	double h, i, suma, F, xi, t;

	h = (b - a) / N;
	i = 0;
	suma = 0;

	for (i = 0;i <= N;i++) {
		if (i == 0) {
			xi = a;
			F = funcion(xi);
			suma = suma + F;
		}
		else {
			if (i == N) {
				xi = b;
				F = funcion(xi);
				suma = suma + F;
			}
			else {
				xi = a + (i*h);
				F = 2 * funcion(xi);
				suma = suma + F;
			}
		}

	}
	if (N != 1000) {
		printf("Los valores son:\n");
		printf("a = %.3lf\n", a);
		printf("b = %.3lf\n", b);
		printf("h = %.3lf\n", h);
		printf("\n////////////////////////////////////////////////////////////////////////////////\n");
		printf("\n");
		//printf("la suma es: %.3lf\n", suma);
	}
	return suma * (h / 2);
}

int main(int argc, char **argv) {

	double h, a, b, i, suma, F, xi, va, vr,ERROR;
	int N;

	printf("Metodo de intregacion compuesto del trapecio\n");
	printf("La funcion a integrar es SENO(X^2)\n");
	
	printf("Ingrese el limite inferior de la integral(A): \n");
	scanf_s("%lf", &a);//limite inferior d la integracion
	
	printf("Ingrese el limite superior de la integral(B): \n");
	scanf_s("%lf", &b);//limite superior d la integracion
	
	printf("Ingrese el valor de N: ");
	scanf_s("%d", &N);//numero de iteraciones
	printf("\n////////////////////////////////////////////////////////////////////////////////\n");
	printf("\n");
	va = trapecio(a,b,N);
	vr = trapecio(a, b, 1000);

	printf("Valor aproximado mediante el metodo del trapecio compuesto(VA) : %.3lf\n", va );
	printf("Valor real de la integral(VR) : %.3lf\n", vr);
	printf("\n");
	ERROR = (vr - va) / vr;
	printf("error: %.3lf\n", ERROR);


	system("PAUSE");
	return 0;
}