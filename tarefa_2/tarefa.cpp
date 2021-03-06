/*
 * Com o intúito de relembrar os conceitos sobre algoritmos de ordenação O(n log n)
 * (Quicksort e Mergesort) e O(dn) (Radixsort) vistos em sala de aula
 * implemente três funções recursivas de ordenação, uma para cada tipo de algoritmo.
 *
 * Execute testes utilizando as três funções implementadas.
 * Os testes deverão ser divididos em três cenários.
 * No primeiro, as funções deverão ordenar arranjos de números aleatórios com 100, 300, 500, 800 e 1000 elementos.
 * No segundo, elas deverão lidar com arranjos de números ordenados de forma crescente
 * (usar as mesmas quantidades de números).
 * No último, as funções deverão lidar com  arranjos de números ordenados de forma decrescente
 * (usar as mesmas quantidades de números). 
 * 
 */

#include <iostream>
#include <fstream> // para a manipulação de arquivos
#include <cstdlib> // para uso da função hand()
#include <sys/time.h> // para cálculo do tempo de execução
#include "../includes/gera_array.h" // funções de geração de array

/*
 * Funções dos algoritmos de ordenação
 */
    /*
     * Quick Sort
     */
        #include "../AlgoritmosOrdenacao/quickSort.cpp"
    /*
     * Merge Sort
     */
        #include "../AlgoritmosOrdenacao/mergeSort_recursivo.cpp"

    /*
     * Radix Sort
     */
        #include "../AlgoritmosOrdenacao/radixSort_recursivo.cpp"


// teste dos algoritmos
    #include "teste_ordenacao.h"

int main() {
    // alocação das variáveis
        int *i = new int;
        int *j = new int;

        // variáveis de tempo
            double *time1 = new double; // variável de tempo para o algoritmo selectionSort
            double *time2 = new double; // variável de tempo para o algoritmo bubbleSort
            double *time3 = new double; // variável de tempo para o algoritmo insertionSort

        // Criação do vetor com os tamanho
            int *tamanhos = new int[5];
                tamanhos[0] = 100; tamanhos[1] = 300; tamanhos[2] = 500; tamanhos[3] = 800; tamanhos[4] = 1000;

    std::ofstream Escrita; // instância o objeto para manipulaão de arquivos
    Escrita.open("output.csv"); // Inicialização do arquivo que será gravada a saída dos dados

    for(*i = 1; *i <= 3; (*i)++){
        Escrita << "Cenário " << *i << ".\n";
        for(*j = 0; *j < 5; (*j)++){
            testeAlgoritmo(*i, time1, time2, time3, tamanhos[*j]);
            Escrita << "Tamanho do vetor:" << tamanhos[*j] << "\n";
            Escrita << "Tempo decorrido quickSort: " << *time1 << "\n";
            Escrita << "Tempo decorrido mergeSort: " << *time2 << "\n";
            Escrita << "Tempo decorrido radixSort: " << *time3 << "\n\n";
        }
    }

    Escrita.close();

    // desalocação das variáveis
        delete i;
        delete j;
        delete time1;
        delete time2;
        delete time3;
        delete tamanhos;

    return 0;
}
