//tarea
#include <iostream>
using namespace std;

int elevado(int exponente){
    int resultado = 1;
    for(int i = 0; i < exponente; i++) resultado=resultado*10;
    return resultado;
}

int main(){
    int LARGO=28, ALTO=35;
    int valor=0, canValores, valorAc, final, sobranteL=LARGO, sobranteA=ALTO, unidad=1, pag=1;
    cin >> final;
    while(valor!=final){
        canValores = 9*elevado(unidad-1)*unidad;
        valorAc = valor+(canValores/unidad);

        if(valorAc>final){
            canValores -= (valorAc-final)*unidad;
            valorAc = final;
        }
        if(true){
            if(sobranteL>=canValores){
                sobranteL-=canValores;
            }
            else{
                int sobranteValor = canValores;
                sobranteL-=sobranteL%unidad;
                sobranteValor-=sobranteL;
                sobranteL=LARGO;
                if(sobranteA>1) sobranteA--;
                else{
                    sobranteA=ALTO;
                    pag++;
                }
                int lRestantes = sobranteValor/(sobranteL-(sobranteL%unidad));
                sobranteValor = sobranteValor%(sobranteL-(sobranteL%unidad));
                sobranteL -= sobranteValor;
                if(lRestantes < sobranteA) sobranteA-=lRestantes;
                else{
                    lRestantes -= sobranteA;
                    sobranteA = ALTO;
                    pag++;
                    pag += (int) lRestantes/sobranteA;
                    sobranteA -= lRestantes%sobranteA;
                }

            }
        }
        valor=valorAc;
        unidad++;
    }
    cout << pag << endl;
    return 0;
}