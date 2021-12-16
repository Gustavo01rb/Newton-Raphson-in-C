# Método Newton-Raphson na Linguagem C

## Explicação
O método de Newton-Raphson foi desenvolvido por Isaac Newton e Joseph Raphson e publicado no livro: _"De analysi per aequationes numero terminorum infinitas"_ no ano de 1669. O objetivo desse método é estimar a raiz de uma equação f(x), ou seja, o ponto no qual f(x) = 0.

### Passo a passo da aplicação do método Newton-Raphson:

1. Escolher uma aproximação inicial para a raiz. (x0)
1. Calcular a equação da reta tangente (por meio da derivada) no ponto x0. 
1. Calcular a interseção da reta tangente com o eixo das abcissas.
1. Repetir os passos 1 2 e 3 com valores de x1, x2 ... xn.

Em notação matemática o método Newton-Raphson pode ser aplicado da seguinte forma:

$$ x_{n+1} = x_n - \frac{f(x_n)}{f'(x_n)}, n \in \mathbb{N}  $$

## Instalação, compilação e execução

* ### Instalçao: (necessário git instalado)  
    
    Para baixar o diretório do arquivo digite o seguinte comando no terminal:
    ~~~
    git clone https://github.com/Gustavo01rb/Newton-Raphson-in-C.git
    ~~~

* ### Compilação:
    
    Abra o diretório no qual o arquivo foi baixado:
    ~~~
    cd Newton-Raphson-in-C
    ~~~
    Compile com o seguinte comando:
    ~~~
    gcc newton_raphson.c -o metodoNP -lm
    ~~~

* ### Execução

    Após compilar o arquivo será gerado um executável, utilize o seguinte comando:
    ~~~
    ./metodoNP
    ~~~
* ## Comando para baixar, executar e compilar:

    ~~~
    git clone https://github.com/Gustavo01rb/Newton-Raphson-in-C.git && cd Newton-Raphson-in-C  && gcc newton_raphson.c -o metodoNP -lm && ./metodoNP
    ~~~

## Observações
O programa está setado para a função:

$$ f(x) = e^x + (\frac{27}{4} + x)^5 +5 $$

Valor incial sugerido: x0 = -6.75

Para alterar a função no código basta modificar o seguinte trecho:

~~~C
double function(double x){   // f(x)
    return (exp(x)) + (pow(( (27/4) + x), 5)) + 5;
}
double derivative(double x){ // f'(x)
    return exp(x) + 5*pow((x + (27/4) ),4); 
}
~~~
    
  
