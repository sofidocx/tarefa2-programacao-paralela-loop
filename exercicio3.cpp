// Exercício 3 — Expressão Vetorial
// Implemente a expressão: a[i] = x[i]^2 + y[i]^2 + z[i]^2 para vetores de tamanho 1.000.000.
// a) Faça a versão sequencial.
// b) Paralelize com #pragma omp parallel for schedule(static).
// c) Mostre o tempo total de execução em cada versão.

#include <iostream>
#include <vector>
#include <cmath> 
#include <omp.h> 

int main() {
    const int TAMANHO = 1000000;
    std::vector<double> a(TAMANHO);
    std::vector<double> x(TAMANHO);
    std::vector<double> y(TAMANHO);
    std::vector<double> z(TAMANHO);

    for (int i = 0; i < TAMANHO; ++i) {
        x[i] = i * 1.0;
        y[i] = i * 2.0;
        z[i] = i * 3.0;
    }

// para o calculo de tempo 
    double tempo_inicio, tempo_fim;
    std::cout << "-execucao" << std::endl;
  // pegando o tempo inicial da execução 
    tempo_inicio = omp_get_wtime();

    for (int i = 0; i < TAMANHO; ++i) {
        // equacao 
        a[i] = pow(x[i], 2) + pow(y[i], 2) + pow(z[i], 2);
    }
  // tempo final do calculo 
    tempo_fim = omp_get_wtime();
    std::cout << "tempo de execucao sequencial: " << tempo_fim - tempo_inicio << " segundos." << std::endl;
  
    std::cout << "\n execucao paralela " << std::endl;
    tempo_inicio = omp_get_wtime();
  
   // levando em consideração o que pode ser resolvido sozinho, no caso, essas operações serão divididas em chunks (blocos)
   //e ficam fixo na thread 
    #pragma omp parallel for schedule(static)
    for (int i = 0; i < TAMANHO; ++i) {
        a[i] = pow(x[i], 2) + pow(y[i], 2) + pow(z[i], 2);
    }
    tempo_fim = omp_get_wtime();
  // tempo total 
    std::cout << "tempo de execucao paralela: " << tempo_fim - tempo_inicio << " segundos." << std::endl;

    return 0;
}
