# Verificador de Números Primos com Pthreads

![Status](https://img.shields.io/badge/status-conclu%C3%ADdo-green)

## Descrição do Projeto

Este projeto consiste em um programa em C que calcula de forma eficiente todos os números primos até um limite superior `N` definido pelo usuário. Seu principal recurso é a otimização de desempenho através do uso de paralelismo, permitindo que o usuário especifique um número `T` de threads para dividir a carga de trabalho. Isso é alcançado utilizando a biblioteca `pthread`, onde o intervalo de números a serem verificados é segmentado e distribuído entre as threads, acelerando o processo de cálculo em sistemas com múltiplos núcleos de processamento.

## Funcionalidades

-   **Cálculo de Primos**: Identifica todos os números primos de 0 até `N`.
-   **Processamento Paralelo**: Utiliza a biblioteca Pthreads para criar múltiplas threads e dividir a verificação.
-   **Entrada Dinâmica**: O usuário define em tempo de execução o limite para o cálculo (`N`) e o número de threads (`T`).

## Tecnologias Utilizadas

-   **Linguagem**: C
-   **Bibliotecas**: `pthread.h` (Pthreads) para multithreading.

## Pré-requisitos

Para compilar e executar este projeto, você precisará de:
-   Um compilador C, como o GCC.
-   Um sistema operacional baseado em UNIX (Linux, macOS) com suporte a Pthreads.

## Como Compilar e Executar

1.  **Clone ou salve o código** em um arquivo.

2.  **Abra o terminal** e navegue até a pasta onde o arquivo foi salvo.

3.  **Compile o programa** usando o seguinte comando. A flag `-lpthread` é essencial para vincular a biblioteca de threads.
    ```bash
    gcc -o verificador_primos main.c -lpthread
    ```

4.  **Execute o programa compilado**:
    ```bash
    ./verificador_primos
    ```

5.  **Forneça os dados de entrada**:
    -   O programa irá aguardar a primeira entrada: o número máximo para a verificação (`N`).
    -   Em seguida, irá aguardar a segunda entrada: o número de threads que você deseja usar (`T`).
    -   Pressione `Enter` após cada número.

## Exemplo de Uso

Ao executar o programa, você pode, por exemplo, pedir para verificar os primos até 30 usando 4 threads.

**Entrada:**
```
30
4
```

**Saída:**
```
 2  3  5  7  11  13  17  19  23  29
```

## Autor

-   Felipe Leonardo Kerwald Santana
  
