#include "fila.h"
#include <time.h>
#include <stdbool.h>

int main(){
	int sizeC = 10;
	int i, j = 0, numVoltas,numSort1,numSort2,numSort3;
	bool condVit = 0;

	srand(time(NULL));

	Queue *c1 = create(sizeC + 1);
	Queue *c2 = create(sizeC + 1);
	Queue *c3 = create(sizeC + 1);
	
	for(i = 0; i < sizeC; i++){
		enqueue(i, c1);
		enqueue(i, c2);
		enqueue(i, c3);
	}

	//print(c1);
	//print(c2);
	//print(c3);
	
	while(!(condVit)){

		numVoltas = (rand()%10);

		for(i = 0; i < numVoltas; i++){
			enqueue (dequeue(c1), c1);
		}
	
		numSort1 = dequeue(c1);
		numVoltas = (rand()%10);

		for(i = 0; i < numVoltas; i++){
			enqueue (dequeue(c2),c2);
		}

		numSort2 = dequeue(c2);
		numVoltas = (rand()%10);

		for(i = 0; i < numVoltas; i++){
			enqueue (dequeue(c3),c3);
		}

		numSort3 = dequeue(c3);

		printf("Sorteio: %d %d %d\n", numSort1, numSort2, numSort3);

		if(numSort1 == numSort2 && numSort1 == numSort3){
			printf("GANHOU\n");
			condVit = 1;
		}else{
			enqueue(numSort1, c1);
			enqueue(numSort2, c2);
			enqueue(numSort3, c3);
		}
		


	}
	




	return 0;
}
