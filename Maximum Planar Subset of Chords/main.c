#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int buffsize = 10000;

struct C {
	int *inputs;
	int vectries;
};

struct C readFile(char const *fileName) {
	FILE *fp = fopen(fileName, "r");
    int *inputs;
	int n;

	inputs = malloc(buffsize * sizeof(int));
 
    if (NULL == fp) {
        printf("the file can't be opened or is not in direction\n");
    }

    n = 0;
	fgetc(fp);
	fscanf(fp, "%d", &n);
	for (n=0; fgetc(fp) != EOF; ++n) {
		fscanf(fp, "%d", &inputs[n]);
	}
 
    n--;
	inputs[n] = -1;
	fclose(fp);

	struct C c = {inputs, n};

	return c;
}

int** mallocMatrix(int row, int col) {
	int **A;
	int i;

	A = malloc(row*sizeof(int*));

	for (i = 0; i < row; ++i) {
		A[i] = calloc(col, sizeof(int));
	}

	return A;
}

int findK(int *inputs, int j) {
	int i;
	int k;

	for (i = 0; inputs[i] != j; i++) continue;
	if (i%2 == 0)
		k = inputs[i+1];
	else
		k = inputs[i-1];

	return k;
}

void computeMIS(int *inputs, int vectries, int **mis_matrix, int **case_matrix) {
	int i,j,k;
	int layer;
	
	for (layer = 1; layer < vectries; ++layer) {
		for (i = 0,	j = i + layer; j != vectries; ++i, ++j) {
			k = findK(inputs, j);
			// case1: k is not in i ~ j
			if(k < i || k > j) mis_matrix[i][j] = mis_matrix[i][j-1];
			// case2: k is in i ~ j
			else if (k > i && k < j) {
				mis_matrix[i][j] = mis_matrix[i][k-1] + mis_matrix[k+1][j-1] + 1;
				if (mis_matrix[i][j-1] >= mis_matrix[i][j]) mis_matrix[i][j] = mis_matrix[i][j-1];
				else case_matrix[i][j] = 2;
			}
			// case3: k = i
			else {
				mis_matrix[i][j] = mis_matrix[i+1][j-1] +1;
				case_matrix[i][j] = 3;
			}
		}
	}
}

int chord_logit = 0;
void findChord(int i, int j, int *inputs, int **case_matrix, int** chords) {
	if (j-1 > 1) {
		// in case 2: chord [k, j] = (+1) and record in chords matrix, then recurrence  [i, k-1] and [k+1, j-1]
		if (case_matrix[i][j] == 2) {
			int k = findK(inputs, j);
			chords[chord_logit][0] = k;
			chords[chord_logit][1] = j;
			chord_logit++;
			findChord(i, k-1, inputs, case_matrix, chords);
			findChord(k+1, j-1, inputs, case_matrix, chords);
		}
		// in case 3: chord [i, j] = (+1) and record in chords matrix, then recurrence  [i+1, j-1]
		else if(case_matrix[i][j] == 3) {
			chords[chord_logit][0] = i;
			chords[chord_logit][1] = j;
			chord_logit++;
			findChord(i+1, j-1, inputs, case_matrix, chords);
		} 
		// in case 1: recurrence  [i, j-1]
		else {
			findChord(i, j-1, inputs, case_matrix, chords);
		}
	}
}

int main() {
	int **mis_matrix, **case_matrix, **chords;

    char file[] = "../5000.in";
	struct C c = readFile(file);

	// create a mis matrix to store mis[i, j] and a case matrix to store the use case of mis[i, j]
	mis_matrix = mallocMatrix(c.vectries, c.vectries);
	case_matrix = mallocMatrix(c.vectries, c.vectries);
	// calculate each mis[i, j] and store use case of mis[i, j]
	computeMIS(c.inputs, c.vectries, mis_matrix, case_matrix);
	// create a chords matrix to store which chords include in Maximum Planar Subset of mis[0, 2n]
	chords = mallocMatrix(mis_matrix[0][c.vectries-1], 2);
	// find chords in Maximum Planar Subset of mis[0, 2n]
	findChord(0, c.vectries-1, c.inputs, case_matrix, chords);
	
	// int i=0, j=0;
	// for (i=0; i<c.vectries; ++i){
	// 	for (j=0; j<c.vectries; ++j){
	// 		printf("%d, ", case_matrix[i][j]);
	// 	}
	// 	printf("\n");
	// }
	// printf("\n");
	// for (i=0; i<c.vectries; ++i){
	// 	for (j=0; j<c.vectries; ++j){
	// 		printf("%d, ", mis_matrix[i][j]);
	// 	}
	// 	printf("\n");
	// }
	// printf("\n");
	// for (i=mis_matrix[0][c.vectries-1]-1; i>=0; --i){
	// 	for (j=0; j<2; ++j){
	// 		printf("%d, ", chords[i][j]);
	// 	}
	// 	printf("\n");
	// }

	int i;
	FILE *fp = fopen("../5000.out", "w");
	fprintf(fp, "%d", mis_matrix[0][c.vectries-1]);
	for (i=mis_matrix[0][c.vectries-1]-1; i>=0; --i){
		fprintf(fp, "\n");
        fprintf(fp, "%d %d", chords[i][0], chords[i][1]);
	}
    fclose(fp);
	return 0;
}