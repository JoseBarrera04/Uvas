#include <iostream>
#include <vector>

using namespace std;

void flipUpsideDown(vector<vector<int>>& matrix, int ring) {
}

void flipLeftRight(vector<vector<int>>& matrix, int ring) {
}

void flipMainDiagonal(vector<vector<int>>& matrix, int ring) {
}

void flipInverseDiagonal(vector<vector<int>>& matrix, int ring) {
}

int main() {
    int M;
    cin >> M;

    while (M--) {
        int N;
        cin >> N;

        vector<vector<int>> squarelotron(N, vector<int>(N));

        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                cin >> squarelotron[i][j];
            }
        }

        int numRings = (N + 1) / 2;

        for (int ring = 0; ring < numRings; ++ring) {
            int T;
            cin >> T;

            for (int t = 0; t < T; ++t) {
                int C;
                cin >> C;

                switch (C) {
                    case 1: flipUpsideDown(squarelotron, ring); break;
                    case 2: flipLeftRight(squarelotron, ring); break;
                    case 3: flipMainDiagonal(squarelotron, ring); break;
                    case 4: flipInverseDiagonal(squarelotron, ring); break;
                    default:
                        cout << "Error" << endl;
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
