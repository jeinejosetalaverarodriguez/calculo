
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char **argv) {

	double h, a, b, i, suma, F, xi, t;
	int N;

	printf("Metodo de intregacion compuesto del trapecio\n");
	printf("La funcion a integrar es SENO(X^2)\n");
	
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
		if (i == 0) {
			xi = a;
			F = ((sin(pow(xi, 2))));
			suma = suma + F;
		}
		else {
			if (i == N) {
				xi = b;
				F = ((sin(pow(xi, 2))));
				suma = suma + F;
			}
			else {
				xi = a + (i*h);
				F = ((2 * sin(pow(xi, 2))));
				suma = suma + F;
			}
		}
		
	}
	t = suma * (h/2);
	
	printf("Los valores son:\n");
	printf("a = %.4lf\n" ,a );
	printf("b = %.4lf\n", b );
	printf("h = %.4lf\n", h );
	printf("la suma es: %.4lf\n", suma );


	printf("LA INTEGRAL ES : %.4lf\n", t );

	system("PAUSE");
	return 0;
}