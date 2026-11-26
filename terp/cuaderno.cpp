//GEOMETRÍA 
//fórmula para calcular la orientación entre segmentos - ojo, puede parecer confuso en el comienzo, pero a la larga voy a terminar por entenderlo: producto en cruz es igual a: ((x1 - x0)*(y2-y0)) - ((x2-x0)*(y1-y0))
//para valores: 
//Con P0 = (0,0) y P1 = (4,0), mirás hacia el este:
//P2 = (2,3)
//P2 = (2,−3)
//P2 = (8,0)

//escribamos la fórmula y reemplacemos: 
//((4-0)*(3-0))-((2-0)*(0-0))-> 4*3 - 0 = 12 -> valor positivo: giro a la izda o antihorario 

//con P2 = (2, -3); entonces, px=((x1-x0)*(y2-y0)) - ((x2-x0)*(y1-y0)) -> (4-0*-3-0)-(2-0*0-0)-> 4*-3 - 2*0 -> -12 -> negativo: giro a la derecha o en sentido horario 

//con P2=(8,0)-> pc=((x1-x0)*(y2-y0))-((x2-x0)*(y1-y0))->4-0*0-0 - 8-0*0-0-> 0 - 0 = 0 -> valor nulo; el segmento es colineal

//ALGORITMO DE PRODUCTO EN CRUZ 
long long cruz(P a, P b, P c) // a=P1, b=P2, c=P3
{
    return ((b.x - a.x)*(c.y - b.y))-((c.x-a.x)*(b.y-a.y));
}
// ==== BÚSQUEDA BINARIA ROJO/VERDE (cátedra) =====
//Regla: P(l) es falso y P(R) es verdadero en todo momento.
//L=-1 y R=n son casillas imaginarias que nunca se leen.
//Corta cuando L y R son vecinas. Al terminar: R = primer verdadero, L=R-1.
//Sin salida por igualdad: con repetidos, R queda en la primera aparición. 
//Presente <=> R < n && a[R]==x
#include <bits/stdc++.h>

#define FIN ios::sync_with_stdio(0); cout.tie(0); cin.tie(0)

using namespace std; 

int primero_que_cumple(const vector<long long>& a, long long x){
    int n = a.size();
    int L = -1, R = n; 
    //R=primer verdadero L=último falso
    //lower_bound: primer>=x; higher_bound:primer>x 
    while(R-L > 1){
        int mid = L + (R-L / 2);//sin overflow: ver el artículo de Bloch 
        if(x <= a[mid]) R = mid; //CAMBIA SEGÚN ENUNCIADO - criterio de selección
        else L = mid; 
    }
    return R;
} 

int main(){
    FIN;
    vector<long long> a = {1, 3, 4, 7, 7, 10, 12, 15, 17, 22};
    for(long long x : {10, 8, 30, 0, 7, 1}){
        int R = primero_que_cumple(a, x);
        cout << x << ": L = " << R - 1 <<  ", R = " << R << '\n';
    } 
}


//GEOMETRÍA - FUNCIONES BÁSICAS
//DECLARACIÓN DE PUNTOS 
struct P{
    long long x, y;
}

//PRODUCTO CRUZADO 
//VERSIÓN DE LA TEORÍA 
double producto_en_cruz(point a, point b, point c){
    return((a[x]*b[y]-a[y]*b[x] + a[y]*c[x] - a[x]*c[y] + b[x]*c[y] - c[x]*b[y]));
}

//VERSIÓN PARA LA PRÁCTICA
long long cross (P a, P b, P c){
    return(b.x - a.x)*(c.y - a.y) - (c.x - a.x)*(b.y - a.y);
}

//POINT IN BOX 
//¿p está dentro de la caja de b1 y b2? (el punto a comprobar se recibe al final por parámetro)
bool point_in_box(P b1, P b2, P p){
    return((p.x >= min(b1.x, b2.x))&& (p.x <= max(b1.x, b2.x)) && (p.y >= min(b1.y, b2.y)) && (p.y <= max(b1.y, b2.y)));
}

//versión sin tanto paréntesis
bool point_in_box(P b1, P b2, P p){
    return p.x >= min(b1.x, b2.x) && p.x <= max(b1.x, b2.x) && p.y >= min(b1.y, b2.y) && p.y <= max(b1.y, b2.y);
}