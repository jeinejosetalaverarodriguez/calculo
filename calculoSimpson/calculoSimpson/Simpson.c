#include <stdio.h>
#include <stdlib.h>
#include <math.h>//libreria para operaciones matematicas
void main(int argc, char **argv){
	int N,i;
	double a,b,suma,f,xi,h;
printf(" *********METODO SIMPSON 1/3************\n");

printf("LA FUNCION A INTEGRAR ES F(X)= (X)/SQRT(1+X^4) \n");

printf("Ingrese el Limite Inferior de la Integral definida: ");
scanf_s("%lf", &a);
printf("Ingrese el Limite Superior de la Integral definida: ");
scanf_s("%lf", &b);
printf("Ingrese un Numero par de Iteraciones : \n");
scanf_s("%d", &N);

h=(b-a)/N;
suma=0;
i=0;
for (i = 0;i <= N;i++){
	if (i % 2 != 0) {
		f = 4 * xi / sqrt(1 + xi*xi*xi*xi);
	}
	else {
		if (i % 2 == 0) {
			f = 2 * xi / sqrt(1 + xi*xi*xi*xi);
		}else {
	if (i == 0) {
		f = xi / sqrt(1 + xi*xi*xi*xi);
	}
	else {
		if (i == N)
		{f = xi / sqrt(1 + xi*xi*xi*xi);
	}
}}
xi = a + i*h;
suma = suma + f;
	}
	printf("los valores son los siguientes : \n");
}
printf("a= %.3lf",a);
printf("b= %.3lf",b);
printf("h= %.3lf",h);
printf("la suma es = %.3lf",suma);
printf("la integral es = %.3lf",suma*h/3);

system("PAUSE");
return 0;
}