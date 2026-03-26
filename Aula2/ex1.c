#include "fila.h"
#include <time.h>

int main(){
	
	srand(time(NULL));
	int i = 0, numZeros = 0,numGerado;

	int sizePositivos = 100;
	int sizeNegativos = 100;

	Queue *qP = create(sizePositivos);
	Queue *qN = create(sizeNegativos);
	
	while (!(full(qP) && full(qN))){
		
		numGerado = (rand()%101) - 50;

		if (numGerado > 0 && !full(qP)){
			enqueue (numGerado, qP);
		}else if (numGerado < 0 && !full(qN)){
			enqueue (numGerado, qN);
		}else {
			numZeros++;
		}

		i++;
	}

	print (qP);
	print (qN);
	printf ("%d\n", numZeros);

	destroy (qP);
	destroy (qN);
	return 0;
}
