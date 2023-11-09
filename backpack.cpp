#include <ostream>
#include <algorithm>
// 	N-->vector de monedas  /filas / tamaño del array
//	V-->tipo de moneda 
//	M--> Cantidad a devolver que va del 0 al M 

int* backpack(int N, int M, int* v, int* p) {
    int** matrix = new int* [N + 1];//creo la matriz que es un array de punteros  a arrays
    for (int i = 0; i <= N; i++) {
        matrix[i] = new int[M + 1];
        for (int j = 0; j <= M; j++) {//recorro la matriz las columnas
            if (i == 0) {
                //si estoy en la primera fila
                matrix[i][j] = 0;
            }
            else if (j == 0) {
                //si estoy en la primera columna
                matrix[i][j] = 0;
            }
            else if (i == 1 && p[0] > j) {
                //en el caso que el valor sea myor que lo que tengo de capacidad
                matrix[i][j] = 0;
            }
            else if (i == 1) {
                //si el peso del objeto es menor o igual le asigno ese valora la mtriz
                matrix[i][j] = v[0];
            }
            else if (p[i] > j) {
                //no uso ese objeto ,asique le resto uno al tipo  ya que su peso es mayor que la capacidad
                matrix[i][j] = matrix[i - 1][j];
            }
            else {
                //debo escojer entre que es mejor usarlo o no
                matrix[i][j] = std::max(matrix[i - 1][j], v[i - 1] + matrix[i - 1][j - p[i - 1]]);
            }
        }
    }

    //funscion para dar el resultado Directamente
    int j = M;//pesos
    int i = N;//valores/tipos
    //vector solucion x
    int* x = new int[N];

    while (i > 0 && j > 0) {//mientras que  no estemos en la fila 0 o la columna 0 pq estan llenas de 0s
        if (i == 1 && matrix[i][j] == v[0]) {
            //si estamos en la fila 1 peroel valor de la matriz es el mismo que el del valor de el objeto
            //esto quiere decir que usamos el objeto
            x[i] = 1;
        }
        else if (matrix[i][j] == (v[i - 1] + matrix[i - 1][j - p[i - 1]])) {
            //de otra manera ,si el valor de la matriz es igual a el valor del objeto anterior mas lo que habia en la matriz en el objeto anteior menos el peso del objeto anterior
            //esto significa que se uso elobjeto de ese tipo
            x[i] = 1;
            // le restas a la capacidad el peso de ese tipo de objeto
            j -= p[i - 1];
        }
        i--;//deoues cambias de tipo de objeto
    }
    return x;

}
int main() {
    int v[3] = { 38, 40, 24 };
    int p[3] = { 9, 6, 5 };
    int* valor = backpack(3, 15, v, p);
    printf("V: ");
    for (int i = 0; i <= 2; i++) {
        printf("%d, ", valor[i]);
    }
    printf("\n");
}










};




































