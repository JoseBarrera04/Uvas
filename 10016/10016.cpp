#include <iostream>
#include <vector>

using namespace std;

// En el anillo en el que estas se invierte verticalmente el anillo. Ejemplo: matrix[0][0] <-> matrix[n-1][0]
void flipUpsideDown(vector<vector<int>>& matrix, int ring);

// En el anillo en el que estas se invierte horizontalmente el anillo. Ejemplo: matrix[0][0] <-> matrix[0][n-1]
void flipLeftRight(vector<vector<int>>& matrix, int ring);

// En el anillo en el que estas se trasnpone la matriz tomando como referencia la diagonal principal para intercabiar los datos opuestos a esa diagonal. Ejemplo: matrix[0][1] <-> matrix[1][0]
void flipMainDiagonal(vector<vector<int>>& matrix, int ring);

// En en anillo en el que estas se transpone la matriz tomando como referencia la diagonal secundaria para intercabiar los datos opuestos a esa diagonal. Ejemplo: matrix[0][0] <-> matrix[n-1][n-1]
void flipInverseDiagonal(vector<vector<int>>& matrix, int ring);

int main() {
    int M; // Número de casos
    cin >> M;

    while (M--) {
        int N; // Tamaño de la matriz
        cin >> N;

        vector<vector<int>> squarelotron(N, vector<int>(N));

        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                cin >> squarelotron[i][j]; // Llenamos la matriz
            }
        }

        int numRings = (N + 1) / 2;

        for (int ring = 0; ring < numRings; ++ring) {
            int T; // Número de transformaciones
            cin >> T;

            for (int t = 0; t < T; ++t) {
                int C; // Tipo de transformación
                cin >> C;

                switch (C) {
                    case 1: flipUpsideDown(squarelotron, ring); break;
                    case 2: flipLeftRight(squarelotron, ring); break;
                    case 3: flipMainDiagonal(squarelotron, ring); break;
                    case 4: flipInverseDiagonal(squarelotron, ring); break;
                    default:
                        cout << "Error" << endl;
                }

                for (int i = 0; i < N; ++i) {
                    for (int j = 0; j < N; ++j) {
                        if (j > 0) cout << " ";
                        cout << squarelotron[i][j];
                    }
                    cout << endl;
                }
            }
        }

        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (j > 0) cout << " ";
                cout << squarelotron[i][j];
            }
            cout << endl;
        }
    }

    return 0;
}

void flipUpsideDown(vector<vector<int>>& matrix, int ring) {
    int tamMatriz = matrix.size();
    vector<vector<int>>copiaMatriz = matrix;

    for(int i = ring; i < tamMatriz - ring; i++) {
        // Columna Izquierda
        matrix[i][ring] = copiaMatriz[tamMatriz - i - 1][ring];
        matrix[tamMatriz - i - 1][ring] = copiaMatriz[i][ring];

        // Columna Derecha
        matrix[i][tamMatriz - ring - 1] = copiaMatriz[tamMatriz - i - 1][tamMatriz - ring - 1];
        matrix[tamMatriz - i - 1][tamMatriz - ring - 1] = copiaMatriz[i][tamMatriz - ring - 1];
    }
}

void flipLeftRight(vector<vector<int>>& matrix, int ring) {
    int tamMatriz = matrix.size();
    vector<vector<int>> copiaMatriz = matrix;

    for (int j = ring; j < tamMatriz - ring; ++j) {
        // Fila superior
        matrix[ring][j] = copiaMatriz[ring][tamMatriz - 1 - j];
        matrix[ring][tamMatriz - 1 - j] = copiaMatriz[ring][j];

        // Fila inferior
        matrix[tamMatriz - 1 - ring][j] = copiaMatriz[tamMatriz - 1 - ring][tamMatriz - 1 - j];
        matrix[tamMatriz - 1 - ring][tamMatriz - 1 - j] = copiaMatriz[tamMatriz - 1 - ring][j];
    }
}

void flipMainDiagonal(vector<vector<int>>& matrix, int ring) {
    int tamMatriz = matrix.size();
    vector<vector<int>> copiaMatriz = matrix;

    for(int x = ring; x < tamMatriz - ring; x++) {
        matrix[ring][x] = copiaMatriz[x][ring];
        matrix[x][ring] = copiaMatriz[ring][x];
    }
}

void flipInverseDiagonal(vector<vector<int>>& matrix, int ring) {
}