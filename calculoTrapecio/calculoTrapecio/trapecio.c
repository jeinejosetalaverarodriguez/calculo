
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double funcion(double xi) //calcula el valor de f(x)
{

	//return (sin(pow(xi, 2)));
	//return (3*xi);
	return ((pow(xi,3))/(1+pow(xi,0.5)));
}

double trapecio(double X0, double Xn, int N)//metodo de trapecio compuesto
{
	double h, i, suma, F, xi;

	h = (Xn - X0) / N;
	i = 0;
	suma = funcion(X0) + funcion(Xn);//parte no iterativa de la formula de trapecio compuesto(parte1)

	for (i = 1;i < N;i++)//iteracion de la formula de trapecio compuesto(parte2)
	{
		xi = X0 + (i*h);
		F = 2 * funcion(xi);
		suma = suma + F;
	}
	if (N != 100000)//para no usarlo en VR(solo se muestra cuando calcula VA)
	{
		printf("Los valores son:\n");
		printf("X0 = %.3lf\n", X0);
		printf("Xn = %.3lf\n", Xn);
		printf("h = %.3lf\n", h);
		printf("\n////////////////////////////////////////////////////////////////////////////////\n");
		printf("\n");
		//printf("la suma es: %.3lf\n", suma);
	}
	return (suma * h * 0.5);
}

int main(int argc, char **argv) {

	double X0, Xn, va, vr,ERROR;//
	int N;

	printf("Metodo de intregacion compuesto del trapecio\n");
	printf("\n");
	//printf("La funcion a integrar es SENO(X^2)\n");
	printf("\n");
	printf("\n////////////////////////////////////////////////////////////////////////////////\n");
	printf("\n");
	printf("Ingrese el limite inferior de la integral(X0): \n");
	scanf_s("%lf", &X0);//limite inferior d la integracion
	
	printf("Ingrese el limite superior de la integral(Xn): \n");
	scanf_s("%lf", &Xn);//limite superior d la integracion
	
	printf("Ingrese el valor de N: ");
	scanf_s("%d", &N);//numero de iteraciones
	printf("\n////////////////////////////////////////////////////////////////////////////////\n");
	printf("\n");
	va = trapecio(X0,Xn,N);
	vr = trapecio(X0, Xn, 100000);

	printf("Valor aproximado mediante el metodo del trapecio compuesto(VA) : %.11lf\n", va );
	printf("Valor real de la integral(VR) : %.11lf\n", vr);
	printf("\n");
	ERROR = fabs((vr - va) / vr);
	printf("error: %.3lf\n", ERROR);


	system("PAUSE");
	return 0;
}