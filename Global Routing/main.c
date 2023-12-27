#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

struct file {
    int grid_x, grid_y;
    int capacity;
    int net_num;
    int *id_lines;
};

typedef struct {
	float d;
    int now_x, now_y;
    int from_x, from_y;
	int visit;
} V;

int** mallocMatrix(int row, int col) {
	int **A;
	int i, j;

	A = malloc(row*sizeof(int*));

	for (i = 0; i < row; ++i) {
		A[i] = malloc(col*sizeof(int));
	}

    for (i = 0; i < row; ++i) {
		for (j = 0; j < col; ++j) {
            A[i][j] = 1;
        }
    }

	return A;
}

V **Initialize_Single_Source(int row, int col, int sx, int sy) {
	V **A;
	int i, j;

	A = malloc(row*sizeof(V*));
    for (i = 0; i < row; ++i) {
		A[i] = malloc(col*sizeof(V));
	}
    for (i = 0; i < row; ++i) {
		for (j = 0; j < col; ++j) {
            V vec = {99999, j, i, -1, -1 ,0};
            A[i][j] = vec;
        }
    }

    A[sy][sx].d = 0;
    A[sy][sx].visit = 1;

	return A;
}

struct file readFile(char const *fileName) {
	FILE *fp = fopen(fileName, "r");
    char str[10];
    int grid_x, grid_y, capacity, net_num, n;
	int *id_lines;


    // grid
    fscanf(fp, "%s", str);
    fgetc(fp);
    fscanf(fp, "%d", &grid_x);
    fgetc(fp);
    fscanf(fp, "%d", &grid_y);

    // capacity
    fscanf(fp, "%s", str);
    fgetc(fp);
    fscanf(fp, "%d", &capacity);

    // num net
    fscanf(fp, "%s", str);
    fscanf(fp, "%s", str);
    fgetc(fp);
    fscanf(fp, "%d", &net_num);

	id_lines = malloc((net_num*5+1) * sizeof(int));
	for (n=0; fgetc(fp) != EOF; ++n) {
		fscanf(fp, "%d", &id_lines[n]);
	}
 
	id_lines[net_num*5] = -1;
	fclose(fp);

	struct file f = {grid_x, grid_y, capacity, net_num, id_lines};
	return f;
}

V extract_min_idx(V *queue, int idx) {
    int i, min_idx=0;
    for(i=1; i < idx; ++i) {
        if (queue[min_idx].d > queue[i].d) {
            min_idx = i;
        }
    }
    V min_u = queue[min_idx];
    for(i=min_idx+1; i<idx; ++i) {
        queue[i-1] = queue[i];
    }
    return min_u;
}

V relax(V u, V v, int **w_matrix, int flg) {
    int ux = u.now_x, uy = u.now_y, vx = v.now_x, vy = v.now_y, w;

    if (flg == 0) {
        w = w_matrix[uy][ux];
    } else {
        w = w_matrix[vy][vx];
    }

    if (u.d+w < v.d) {
        v.from_x = ux;
        v.from_y = uy;
        v.d = u.d+w;
        v.visit = 1;
    }

    return v;
}

void Dijkstra(V **grid_matrix, int **x_matrix, int **y_matrix, int sx, int sy, struct file f) {
    V queue[f.grid_x*f.grid_y], current_v, current_u;
    int row = f.grid_y;
    int col = f.grid_x;
    int idx = 0, now_x, now_y;
    queue[0] = grid_matrix[sy][sx];
    idx++;
    while(idx != 0) {
        current_u = extract_min_idx(queue, idx);
        idx--;
        now_x = current_u.now_x;
        now_y = current_u.now_y;
        // up
        if (now_y-1 >= 0) {
            current_v = grid_matrix[now_y-1][now_x];
            if (current_v.visit == 0) {
                current_v = relax(current_u, current_v, y_matrix, 1);
                queue[idx] = current_v;
                grid_matrix[now_y-1][now_x] = current_v;
                idx++;
            } else if (current_v.visit == 1) {
                current_v = relax(current_u, current_v, y_matrix, 1);
                grid_matrix[now_y-1][now_x] = current_v;
            }
        }

        // down
        if (now_y+1 < row) {
            current_v = grid_matrix[now_y+1][now_x];
            if (current_v.visit == 0) {
                current_v = relax(current_u, current_v, y_matrix, 0);
                grid_matrix[now_y+1][now_x] = current_v;
                queue[idx] = grid_matrix[now_y+1][now_x];
                idx++;
            } else if (current_v.visit == 1) {
                current_v = relax(current_u, current_v, y_matrix, 0);
                grid_matrix[now_y+1][now_x] = current_v;
            }
        }
        // left
        if (now_x-1 >= 0) {
            current_v = grid_matrix[now_y][now_x-1];
            if (current_v.visit == 0) {
                current_v = relax(current_u, current_v, x_matrix, 1);
                grid_matrix[now_y][now_x-1] = current_v;
                queue[idx] = grid_matrix[now_y][now_x-1];
                idx++;
            } else if (current_v.visit == 1) {
                current_v = relax(current_u, current_v, x_matrix, 1);
                grid_matrix[now_y][now_x-1] = current_v;
            }
        }
        // right
        if (now_x+1 < col) {
            current_v = grid_matrix[now_y][now_x+1];
            if (current_v.visit == 0) {
                current_v = relax(current_u, current_v, x_matrix, 0);
                grid_matrix[now_y][now_x+1] = current_v;
                queue[idx] = grid_matrix[now_y][now_x+1];
                idx++;
            } else if (current_v.visit == 1) {
                current_v = relax(current_u, current_v, x_matrix, 0);
                grid_matrix[now_y][now_x+1] = current_v;
            }
        }
        grid_matrix[now_y][now_x].visit = 2;
    }
}

void modifyEdge(int **x_matrix, int **y_matrix, int now_x, int now_y, int from_x, int from_y) {
    if (now_x == from_x) {
        if (now_y > from_y) {
            y_matrix[from_y][from_x]++;
        } else {
            y_matrix[now_y][from_x]++;
        }
    } else {
        if (now_x > from_x) {
            x_matrix[from_y][from_x]++;
        } else {
            x_matrix[from_y][now_x]++;
        }
    }
}

void tracePath(V **grid_matrix, int **x_matrix, int **y_matrix, int line_num, int sx, int sy, int fx, int fy, FILE *fp) {
    int i, step = 0, answer_idx = 0, answer[1000000];
    int from_x, from_y, now_x = fx, now_y = fy;
    while (now_x != sx || now_y != sy) {
        from_x = grid_matrix[now_y][now_x].from_x;
        from_y = grid_matrix[now_y][now_x].from_y;
        answer[answer_idx++] = now_y;
        answer[answer_idx++] = now_x;
        answer[answer_idx++] = from_y;
        answer[answer_idx++] = from_x;
        answer[answer_idx++] = -1;
        step++;
        modifyEdge(x_matrix, y_matrix, now_x, now_y, from_x, from_y);
        now_x = from_x, now_y = from_y;
    }
    answer[answer_idx++] = step;
    answer[answer_idx++] = line_num;
    for (i = answer_idx-1; i >= 0; i--) {
        if (answer[i] == -1) {
            fprintf(fp, "\n");
        } else {fprintf(fp, "%d ", answer[i]);
        }
    }
    fprintf(fp, "\n");
}

int main(int argc, char const *argv[]) {
    struct file f = readFile(argv[1]);
    FILE *fp = fopen(argv[2], "w");
    int **x_matrix, **y_matrix;
    int i;
    int line_num, sx, sy, fx, fy;
    int overflow = 0, net_num = 0;
	x_matrix = mallocMatrix(f.grid_y, f.grid_x-1);
    y_matrix = mallocMatrix(f.grid_y-1, f.grid_x);
    V **grid_matrix;
    for (i=0; i < f.net_num; i++) {
        line_num = f.id_lines[i*5+0], sx = f.id_lines[i*5+1], sy = f.id_lines[i*5+2], fx = f.id_lines[i*5+3], fy = f.id_lines[i*5+4];
        grid_matrix = Initialize_Single_Source(f.grid_x, f.grid_y, sx, sy);
        Dijkstra(grid_matrix, x_matrix, y_matrix, sx, sy, f);
        tracePath(grid_matrix, x_matrix, y_matrix, line_num, sx, sy, fx, fy, fp);
        net_num++;
        free(grid_matrix);
    }

    for (int j=0; j<f.grid_y; j++){
        for (int i=0; i<f.grid_x-1; i++){
            if (x_matrix[j][i] > overflow) {
                overflow = x_matrix[j][i];
            }
        }
    }
    for (int j=0; j<f.grid_y-1; j++){
        for (int i=0; i<f.grid_x; i++){
            if (y_matrix[j][i] > overflow) {
                overflow = y_matrix[j][i];
            }
        }
    }
    
    fclose(fp);

	return 0;
}
