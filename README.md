# Lista de Exercícios - Programação Paralela com OpenMP

Este repositório contém a resolução da lista de exercícios da disciplina de Programação Paralela, focada na utilização da biblioteca OpenMP para a paralelização de algoritmos em C++.

**Aluno:** Sofia Vaz da Costa Xavier 
**Professor:** Rodrigo Gonçalves

---

## Estrutura do Repositório

O projeto está organizado em cinco arquivos, cada um correspondendo a uma questão da lista:

* `exercicio1.cpp`: Demonstração de um "Hello World" paralelo, onde cada thread se identifica.
* `exercicio2.cpp`: Comparação entre a soma sequencial e paralela de um vetor, destacando o uso da cláusula `reduction`.
* `exercicio3.cpp`: Comparação de desempenho (sequencial vs. paralelo) para uma expressão vetorial, utilizando `schedule(static)`.
* `exercicio4.cpp`: Medição de tempo de execução total e individual por thread.
* `exercicio5.cpp`: Análise comparativa dos escalonadores `schedule(static)` e `schedule(dynamic)` com diferentes números de threads.

---

## Pré-requisitos

Para compilar e executar os códigos deste projeto, é necessário ter:

* Um compilador C++ com suporte a OpenMP (recomenda-se o **GCC/G++**).

---

## Como Compilar e Executar

Todos os códigos devem ser compilados com a flag `-fopenmp` para habilitar as funcionalidades do OpenMP. Abaixo estão os comandos específicos para cada exercício.

### Exercício 1: "Hello World" Paralelo

**1. Compilar o código:**
```sh
g++ -fopenmp exercicio1.cpp -o exercicio1
```
**2. Executar o programa:** 
```sh
./exercicio1
```

Repetindo o mesmo processo para todos os outros exercícios. 
- Os códigos-fonte foram comentados para detalhar o funcionamento das funções, métodos e diretivas OpenMP, conforme solicitado nas instruções da atividade.
