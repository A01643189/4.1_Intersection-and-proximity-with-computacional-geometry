#include <iostream>
#include <vector>

using namespace std;

// We create a struct to represent a point in the plane
struct Punto {
    int x, y;
};

// Function to calculate the cross product of two vectors
int producto_cruzado(Punto A, Punto B, Punto C) {
    return (B.x - A.x) * (C.y - A.y) - (B.y - A.y) * (C.x - A.x);
}

// Function to verify if a point P is in the segment AB
bool en_segmento(Punto A, Punto B, Punto P) { // Complexity: O(1), the function is only checking conditions of max and min.
    return min(A.x, B.x) <= P.x && P.x <= max(A.x, B.x) &&
           min(A.y, B.y) <= P.y && P.y <= max(A.y, B.y);
}

// Function to verify if two segments intersect
bool segmentos_intersectan(Punto A, Punto B, Punto C, Punto D) { // Complexity: O(1), the function is only making calls to other constant time functions and making validations.
    int d1 = producto_cruzado(A, B, C);
    int d2 = producto_cruzado(A, B, D);
    int d3 = producto_cruzado(C, D, A);
    int d4 = producto_cruzado(C, D, B);

    // Verify the intersection of the segments
    if ((d1 > 0 && d2 < 0 || d1 < 0 && d2 > 0) &&
        (d3 > 0 && d4 < 0 || d3 < 0 && d4 > 0)) {
        return true; // The segments intersect
    }

    // Especial cases for colinearity
    if (d1 == 0 && en_segmento(A, B, C)) return true;
    if (d2 == 0 && en_segmento(A, B, D)) return true;
    if (d3 == 0 && en_segmento(C, D, A)) return true;
    if (d4 == 0 && en_segmento(C, D, B)) return true;

    return false;
}

int main() {
    int n; // Number of points
    cin >> n; 
    vector<bool> resultados;

    for (int i = 0; i < n; i += 4) {
        Punto A, B, C, D;
        cin >> A.x >> A.y >> B.x >> B.y >> C.x >> C.y >> D.x >> D.y;

        bool intersectan = segmentos_intersectan(A, B, C, D);
        resultados.push_back(intersectan);
    }

    // Print the results
    for (bool resultado : resultados) {
        cout << (resultado ? "True" : "False") << endl;
    }

    return 0;
}
