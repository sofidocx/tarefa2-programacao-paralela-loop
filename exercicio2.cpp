// Exercício 2 — Paralelizando um for simples
// a) Crie um vetor v de tamanho 100 e inicialize todos os elementos com o valor 1.
// b) Escreva um loop sequencial que soma todos os elementos.
// c) Refaça o loop com #pragma omp parallel for reduction(+:soma).
// d) Compare os resultados e explique por que a diretiva reduction é necessária.

#include <iostream>
#include <vector> // Usado para criar um vetor dinâmico `std::vector`
#include <numeric> // Usado para a função `std::accumulate` (opcional, para verificação)

int main() {

    // letra a) criando um vetor de tamanho v e depois inicializando ele com o valor 1 
    const int TAMANHO_VETOR = 100;
    // a segunda parte do argumento (1) está definindo como ele será inicializado, no caso, o valor 1 
    // resultado = um vetor com todos os elementos iguais a 1 
    std::vector<int> v(TAMANHO_VETOR, 1);
    // letra b) loop sequencial que soma todos os elementos
    std::cout << "execucao sequencial" << std::endl;
    // acumulador da soma 
    long long soma_sequencial = 0;
    //a cada loop o valor do ele,mento é adicionado, no valor da variável anterior (soma_sequencial)
    for (int i = 0; i < TAMANHO_VETOR; ++i) {
        soma_sequencial += v[i];
    }
    std::cout << "resultado da soma sequencial: " << soma_sequencial << std::endl;
    std::cout << "\usando reduction" << std::endl;
    long long soma_paralela = 0;
   //divide as iterações do loop, e divide as obrigações entre as threads 
   //para evitar uma condição de corrida, criamos uma cópia privada da soma paralela para cada uma 
   // das threads que a gente está executando e cada thread faz a sua soma, depois, o OpenMP no final 
  // pega essas threads e pega os valores dela nas cópias privadas e soma na soma_paralela 
    #pragma omp parallel for reduction(+:soma_paralela)
    for (int i = 0; i < TAMANHO_VETOR; ++i) {
        soma_paralela += v[i];
    }
    std::cout << "Resultado da soma paralela: " << soma_paralela << std::endl;
    return 0;
}
