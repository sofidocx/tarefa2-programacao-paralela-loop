
// Exercício 4 — Medindo tempo por thread
// Adapte o código do exercício anterior para:
// a) Medir e exibir o tempo total de execução.
// b) Medir e exibir o tempo gasto por cada thread.
// c) Mostrar quantas threads foram utilizadas no cálculo.

#include <iostream>
#include <vector>
#include <cmath>
#include <omp.h>

int main() {
    const int TAMANHO = 1000000;
    std::vector<double> a(TAMANHO);
    std::vector<double> x(TAMANHO, 1.5);
    std::vector<double> y(TAMANHO, 2.5);
    std::vector<double> z(TAMANHO, 3.5);

    //tempo total 
    double tempo_total_inicio, tempo_total_fim;

    std::cout << "execucao paralela com medicao por thread" << std::endl;

  // tempo de inicio sendo capturado antes da paralela 
    tempo_total_inicio = omp_get_wtime();
    #pragma omp parallel
    {
       
       // medindo tempo dentro da execução da funçaõ paralela 
        double tempo_thread_inicio, tempo_thread_fim;
        // cada uma das threads vai guardar o tempo de execução 
        tempo_thread_inicio = omp_get_wtime();
        int thread_id = omp_get_thread_num();

        #pragma omp for schedule(static)
        for (int i = 0; i < TAMANHO; ++i) {
            a[i] = pow(x[i], 2) + pow(y[i], 2) + pow(z[i], 2);
        }

        // cada thread individual vai capturar o tempo 
        tempo_thread_fim = omp_get_wtime();
        
       // por motivos de organização, usando o critical apenas para não bagunçar o terminal para que apenas uma thread por vez vai executar 
        #pragma omp critical
        {
            std::cout << "Thread " << thread_id << " gastou: "
                      << tempo_thread_fim - tempo_thread_inicio << " segundos." << std::endl;
        }

       //omp master garante que o proximo codigo vai ser executado apenas por ela 
        #pragma omp master
        {
            // retorna o número total de threads na equipe.
            int total_threads = omp_get_num_threads();
            std::cout << "\nTotal de threads utilizadas no calculo: " << total_threads << std::endl;
        }
    } 

    tempo_total_fim = omp_get_wtime();

    std::cout << "Tempo TOTAL de execucao: " << tempo_total_fim - tempo_total_inicio << " segundos." << std::endl;

    return 0;
}
