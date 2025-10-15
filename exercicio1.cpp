// Exercício 1 — “Hello World” Paralelo
// a) Crie uma região paralela com #pragma omp parallel.
// b) Cada thread deve imprimir uma mensagem indicando seu número (omp_get_thread_num()) e o total de threads (omp_get_num_threads()).
// c) Configure o programa para rodar com 4 threads.

#include <iostream>
#include <omp.h>

int main() {

   //inicia uma região paralela, tudo o que vier dentro do bloco {} vai ser executado em múltiplas threads (4 threads). 
  omp_set_num_threads(4);
    #pragma omp parallel
    {
       //uma variável que vai guardar o identificador único para nossas threads 
        int thread_id;
        // o número total de threads
        int total_threads
       //retorna o id da thread em execução, id : 0, 1, 2, 3
        thread_id = omp_get_thread_num();
       //retorna o numero de threads ativa no time 
        total_threads = omp_get_num_threads();

        std::cout << "Ola! Sou a thread " << thread_id << " de um total de " << total_threads << " threads." << std::endl;
    }
    return 0; 
}
