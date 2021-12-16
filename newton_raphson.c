#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MODULE(x) ((x)>=0?(x):-(x)) //Calcular o módulo

double  function     (double x); 
double  derivative   (double x);
void    initialize   (double* precision, double* x0, int* maxIter, double** itrer);
int     npMethod     (double* iter, double precision, int maxIter);
double* initArray    (int size, double x0);
double  getPrecision (int decimalss);
void    viewReport   (double* iter, int numberIter, int maxIter);

int main(){
    double  precision;      // Número de casas decimais de precisão da raiz
    double  x0;             // Ponto Inicial
    double* iteration;      // Vetor de Iterações
    int     maxIter;        // Limite de iterações
    int numberIteration;    // Número de iterações realizadas

    initialize(&precision, &x0, &maxIter, &iteration);
    numberIteration = npMethod(iteration, precision, maxIter);
    if(numberIteration == -1){ return -1;}

    viewReport(iteration, numberIteration, maxIter);

    return 0;
}

//Funções que serão aplicadas 
/* Para aplicar o método de Newton-Rhapson em outras funções f(x), basta editar essas duas funções, lembre-se de colocar f(x) na função 'function'
    e f'(x) na função 'derivative'.*/

double function(double x){   // f(x)
    return (exp(x)) + (pow(( (27/4) + x), 5)) + 5;
}
double derivative(double x){ // f'(x)
    return exp(x) + 5*pow((x + (27/4) ),4); 
}
// Fim das funções que serão aplicadas 


// Funções responsáveis por coletar dados inicias e iniciar as variáveis

void initialize(double* precision, double* x0, int* maxIter, double** itrer){
    int decimals;

    printf("\n\nAplicacao do método de Newton-Rhapson para estimar o valor da raiz de uma funcao f(x).\n\n");
    printf("\tInforme o numero de casa decimais de precisao: ");
    scanf("%d", &decimals);
    printf("\tInforme o numero maximo de iteracoes: ");
    scanf("%d", maxIter);
    printf("\tInforme o ponto inicial(x0): ");
    scanf("%lf", x0);
    
    *precision = getPrecision(decimals);
    *itrer = initArray(*maxIter, *x0);

}
double getPrecision(int decimals){
    double precision;
    char* str;
    
    str = (char*) calloc(decimals + 3, sizeof(char));
    
    str[0] = '0';
    str[1] = '.';

    for(int i = 2; i <= decimals + 2; i++){
        if(i < decimals +2 ) { str[i] = '0'; }
        else                 { str[i] = '9'; }
    }
    precision = atof(str);
    free(str);

    return precision;
}
double* initArray(int size, double x0){
    double* array = (double *) calloc(size, sizeof(double)); 
    array[0] = x0;
    
    return array;
}
// Fim das funções responsáveis por coletar dados inicias e iniciar as variáveis.

// Função que aplica o método de Newthon-Rhapson
int npMethod(double* iter, double precision, int maxIter){
    int control = 0;

    while( MODULE( function(iter[control]) )  > precision   ){
        if(control > maxIter){
            printf("\n\n[ERRO]- O numero de iteracoes ultrapassou o limite sugerido.");
            printf("\n Verifique suas funcao f(x) e sua f'(x) e tente novamente.\n\n");
            return -1;
        }
        iter[control + 1] = iter[control] - function(iter[control]) / derivative(iter[control]);
        control++;
    }

    return control ;
}
// Fim da função que aplica o método de Newthon-Rhapson

void viewReport(double* iter, int numberIter, int maxIter){
    printf("\n\nResultados obtidos:");
    printf("\n\tIteracoes realizadas: %d/%d", numberIter, maxIter);
    printf("\n\tValor estimado da raiz: %lf", iter[numberIter]);
    printf("\n\nIteracoes: ");
    for(int i = 0; i <= numberIter; i++ ){
        printf("\nx%d = %lf -> f(%lf) = %lf ", i, iter[i], iter[i], function(iter[i]));
    }
    printf("\n\nObservacao*  Por padrao sao exibidos apensa 6 casas apos a virgula, caso deseje ver valores mais precisos altere o codigo para printar double com mais casas decimais\n\n");
}

