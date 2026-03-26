#include "fila.h"


int main(){
	int i = 0,pos = 0, numPessoas = 5, j = 1;

       Queue *qJ = create(numPessoas + 1);

	for( i = 1; i < numPessoas + 1; i++){
		enqueue(i, qJ);
	}

	print(qJ);

	while(j < numPessoas){
		pos = (pos + 2) % (numPessoas - j + 1);

		for( i = 0; i < pos; i++){
			enqueue (dequeue(qJ),qJ);
		}

		dequeue(qJ);

		for(i = 0; i < (numPessoas - pos - j); i++){
			enqueue (dequeue(qJ),qJ);
		}

		print(qJ);

		j++;

	}

	dequeue(qJ);

	print(qJ);
	
	

	return 0;
}
