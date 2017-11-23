#include <stdio.h>
#include <stdlib.h>
#include <math.h>//libreria para operaciones matematicas

double funcion(double xi) //calcula el valor de f(x)
{
	//return (cos(cos(xi)));
	return (1 / (1 + xi));
	//return (xi*cos(pow(xi, 2)+1));
	//return (sin(pow(xi, 2)));
	//return (3*xi);
	//return ((pow(xi, 3)) / (1 + pow(xi, 0.5)));
}

double simpsonSimple(double X0, double Xn, double N){

	
	double xi,f,h;
	f = 0;
	h = (Xn - X0) / 2;
	xi = X0 + (h);
	f = (((Xn - X0) / 6)*(funcion(X0)+ (4 * funcion(xi)) + funcion(Xn) ));
	//printf("la suma es = %.3lf\n", f);
	return f;
}


double simpsonCompuestoS() {
	int N, i;
	double X0, Xn, X0a, Xna, suma, sumaPar, sumaImpar, f, xi, h;
	//printf(" *********METODO SIMPSON 1/3************\n");

	/*
	printf("Ingrese el Limite Inferior de la Integral definida: ");
	scanf_s("%lf", &X0);
	printf("Ingrese el Limite Superior de la Integral definida: ");
	scanf_s("%lf", &Xn);
	printf("Ingrese un Numero par de Iteraciones : \n");
	scanf_s("%d", &N);
	*/
	X0 = 0;
	Xn = 1;
	N = 3;

	h = (Xn - X0) / N;
	suma = 0;
	f = 0;
	i = 0;
	X0a = h;
	Xna = 2 * h;

	

	for (i = 0;i < N;i++)//iteracion de la formula de trapecio compuesto(parte2)
	{
		xi = Xna + (i*h);

		f = simpsonSimple(X0a, Xna, N);
		
		suma = suma + f;
			
			X0a = Xna;
			Xna = Xna + h;
			printf("el intervalo I%d = %.3lf\n",i, suma);
		}
	printf("los valores son los siguientes : \n");

	printf("a= %.3lf\n", X0);
	printf("b= %.3lf\n", Xn);
	printf("h= %.3lf\n", h);

	printf("la integral es = %.3lf\n", suma);


	return 0;
}



double simpsonCompuesto() {
	int N, i;
	double X0, Xn, X0a, Xna, suma, sumaPar, sumaImpar, f, xi, h;
	//printf(" *********METODO SIMPSON 1/3************\n");

	/*
	printf("Ingrese el Limite Inferior de la Integral definida: ");
	scanf_s("%lf", &X0);
	printf("Ingrese el Limite Superior de la Integral definida: ");
	scanf_s("%lf", &Xn);
	printf("Ingrese un Numero par de Iteraciones : \n");
	scanf_s("%d", &N);
	*/
	X0 = 0;
	Xn = 1;
	N = 6;

	h = (Xn - X0) / N;
	suma = 0;
	sumaPar = 0;
	sumaImpar = 0;
	i = 0;
	X0a = h;
	Xna = 2*h;
	
	suma = funcion(X0) + funcion(Xn);

	for (i = 1;i < N;i++)//iteracion de la formula de trapecio compuesto(parte2)
	{
		xi = Xna + (i*h);
		
			
			if (i % 2 == 0)
			{
				//sumaPar = sumaPar + simpsonSimple(X0a, Xna, N);
				sumaPar = sumaPar + funcion(xi);
				X0a = Xna;
				Xna = Xna + h;
				printf("la suma es par= %.3lf\n", sumaPar);

			}
			else
			{
				//sumaImpar = sumaImpar + simpsonSimple(X0a, Xna, N);
				sumaImpar = sumaImpar + funcion(xi);
				X0a = Xna;
				Xna = Xna + h;
				printf("la suma es impar = %.3lf\n", sumaImpar);

			}
		
	}
	printf("la suma es impar = %.3lf\n", sumaImpar);
		suma = suma + (4*sumaImpar) + (2*sumaPar);
		printf("la suma = %.3lf\n", suma);
		suma = h*suma*(1/3);


	

	printf("los valores son los siguientes : \n");

printf("a= %.3lf\n", X0);
printf("b= %.3lf\n", Xn);
printf("h= %.3lf\n", h);

printf("la integral es = %.3lf\n", suma);


return 0;
}

int main(int argc, char **argv){
	//simpsonCompuesto();
	simpsonCompuestoS();
	


system("PAUSE");
return 0;
}