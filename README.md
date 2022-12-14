# Trabalho 2 - Redes de Computadores (SSC0641)

## Integrantes

- Felipe de Alcântara Tomé - 11800970 
- Francisco Reis Nogueira - 11954374
- Luiz Henrique Pereira - 11918539
- Maíra de Souza Canal - 11819403
- João Augusto Fernandes Barbosa - 11953348

## Link da apresentação

[LINK](https://drive.google.com/file/d/16XA0VJL5xvOLCUog5SFhmIp658y5rjjb/view?usp=share_link)

## Sobre o Trabalho

- **Versões do sistema operacional testadas:** Ubuntu 22.04, Fedora 36
- **Compiladores:** g++ 11 e 12
- **Descrição:**
    O presente trabalho busca simular o funcionamento da comunicação entre dois computadores por meio de protocolos. Neste, não só as informações e mensagens são transformadas em bits e enviadas, como também, em seu recebimento, há a confirmação da integridade de seus valores através dos modos estudados, sendo eles: bit de paridade par, bit de paridade impar e CRC.
    Como toda a troca de informação é realizada na mesma máquina, muito dificilmente haveria algum corrompimento dos dados. Por isso, foi-se estabelecido uma chance aleatória de erro, a fim de verificiar a eficiência dos diversos métodos de controle de erros.
    
## Como Executar

Para executar o simulador, é necessário apenas utilizar o Makefile disponível
no repositório. No diretório raiz do programa, execute o seguinte comando para
compilar o arquivo executável:

```bash
$ make all
```

Em seguida, para executar o simulador basta rodar:

```bash
$ make run
```

Há diversas formas de conferir a integridade da transmissão. Cada modelo pode ser selecionado alterando o paramêtro `HANDLING_ROUTINE`
no arquivo `src/layers/DataCheck.hpp`. Neste, o valor desta variável implica na seguinte equivalência:

0. Controle de Erros por Paridade Par
1. Controle de Erros por Paridade Ímpar 
2. Controle de Erros pelo algoritmo CRC-32

A saída da aplicação pode ser realizada simplesmente ao digitar "exit" no terminal.
