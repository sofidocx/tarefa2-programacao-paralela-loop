// Exercício 5 — Escalonamento
// Use novamente o cálculo de a[i] = x[i]^2 + y[i]^2 + z[i]^2, mas:
// a) Execute com schedule(static) e schedule(dynamic, 1000).
// b) Compare os tempos em diferentes quantidades de threads (2, 4, 8).
// c) Explique em quais situações static e dynamic são mais adequados.

#include <iostream>
#include <vector>
#include <cmath>
#include <omp.h>

//encapsula o cálculo e medição de tempo 
// - num_threads: número de threads a serem usadas.
// - schedule_type: string que descreve o tipo de escalonamento para impressão.
// - tamanho: o tamanho dos vetores.
// - a, x, y, z: referências para os vetores.
void executar_e_medir(int num_threads, const std::string& schedule_type, const int tamanho,
                      std::vector<double>& a, const std::vector<double>& x,
                      const std::vector<double>& y, const std::vector<double>& z) {
    // numero de threads para a próxima função de paralelização 
    omp_set_num_threads(num_threads);
    double tempo_inicio, tempo_fim;
    
    tempo_inicio = omp_get_wtime();

    if (schedule_type == "static") {
      // iterações divididas igualmente entre as threads, antes de executar o loop
        #pragma omp parallel for schedule(static)
        for (int i = 0; i < tamanho; ++i) {
            a[i] = pow(x[i], 2) + pow(y[i], 2) + pow(z[i], 2);
        }
    } else if (schedule_type == "dynamic, 1000") {
      // escalonamento dinamico - mais um avez, dividida em blocos, a função pega o próximo disponível na fila 
        #pragma omp parallel for schedule(dynamic, 1000)
        for (int i = 0; i < tamanho; ++i) {
            a[i] = pow(x[i], 2) + pow(y[i], 2) + pow(z[i], 2);
        }
    }

    tempo_fim = omp_get_wtime();
    std::cout << "Threads: " << num_threads << ", Schedule: " << schedule_type
              << ", Tempo: " << tempo_fim - tempo_inicio << " segundos." << std::endl;
}

int main() {
    const int TAMANHO = 1000000;
    std::vector<double> a(TAMANHO);
    std::vector<double> x(TAMANHO, 1.5);
    std::vector<double> y(TAMANHO, 2.5);
    std::vector<double> z(TAMANHO, 3.5);

    // threads que queremos testar 
    std::vector<int> threads_para_testar = {2, 4, 8};

    std::cout << "comparando escalonamento Static vs. Dynamic" << std::endl;
    for (int nt : threads_para_testar) {
        // a) e b) executa com schedule(static) para a quantidade atual de threads.
        executar_e_medir(nt, "static", TAMANHO, a, x, y, z);

        // a) e b) executa com schedule(dynamic, 1000) para a quantidade atual de threads.
        executar_e_medir(nt, "dynamic, 1000", TAMANHO, a, x, y, z);
        
    }

    return 0;
}
