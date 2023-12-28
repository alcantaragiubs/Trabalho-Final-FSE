# Trabalho Final (2023-2)

Trabalho Final da disciplina de Fundamentos de Sistemas Embarcados - Sala de Estar Automatizada

## Alunos

| Matrícula | Aluno                                                            |
| --------- | -----------------------------------------------------------------|
| 202015984	| [Breno Henrique de Souza](https://github.com/bhsouza)            |
| 180121308 | [Giulia Alcantara](https://github.com/alcantaragiubs)            |
| 202016480 | [Hellen Fernanda M. de Faria](https://github.com/Hellen159)      |
| 190033681 | [Luiz Henrique Fernandes Zamprogno](https://github.com/luiz-hfz) |

## Visão Geral

O sistema foi construído com o uso de uma placa ESP32, que integra um conjunto de sensores de entrada e saída para a detecção e interação com o usuário. A implementação das diversas funcionalidades foi realizada por meio de códigos em linguagem C

| Microcontrolador  | Versão | Framework |  Linguagem  |
| :---------------: | ------ | --------- | ----------- |
|      Esp32        | 5.1.2  | Espressif |      C      |

### Funcionalides implementadas

Este trabalho tem por objetivo a criação de um sistema de uma sala de estar automatizada pela simulação de um tablet. O sistema será desenvolvido incluindo as funcionalidades:

- **Operações Básicas:**
  - Ligar e Desligar uma Televisão
  - Abertura e Fechamento de Persiana
    
- **Controle do Ambiente:**
  - Ar Condicionado:
    - Ativação e Desativação de Ar Condicionado
    - Aumento e Diminuição da temperatura
  - Monitoramento de Ambiente:
    - Captura da temperatura
    - Captura de umidade do ambiente

- **Modos de Operação da Lâmpada:**
  - Mode de ajuste de luz:
     - Luz natural: lâmpada apagada
     - Luz de descanso: lâmpada com baixa intensidade
     - Luz de atividade: lâmpada com intensidade média
     - Luz ambiente: lâmpada com alta intensidade

- **Segurança Residencial:**
  - Alarme de Incêndio:
     - Detecção de chamas
     - Ativiação de alarme(buzzer) 
  - Alerme de invasão:
     - Modo de ativo e inativo
     - Dectação de intrusos
     - Adicionamento de alarme

### Interface - [Dashboard](http://thingsboard.lappis.rocks:443/dashboard/0ddfaf90-9511-11ee-bdb2-7b07ee36c1c6?publicId=d1a50d70-949f-11ee-bdb2-7b07ee36c1c6):

![image](https://github.com/FSE-2023-2/trabalho-final-2023-2-trabalho-final-fse/assets/54143767/19bd6f7e-ddd2-4818-a950-35c1f6a7ad30)


### 🔂 Executando o Projeto

#### Clone o repositório

```bash 
$ git clone https://github.com/alcantaragiubs/Trabalho-Final-FSE.git
```

Observação: Caso não possua o git instalado será nessario a instalação. Sigua o [Tutorial](https://git-scm.com/book/pt-br/v2/Começando-Instalando-o-Git).

#### Instale a extenção da Esp no VSCode

![image](https://github.com/FSE-2023-2/trabalho-final-2023-2-trabalho-final-fse/assets/54143767/8e7bb0cb-0f76-4a08-b375-53d9abfe4e10)

#### Siga o tutorial de instalação da ESP no seu computador

[Windows](https://docs.espressif.com/projects/esp-idf/en/latest/esp32/get-started/windows-setup.html)
[Linux e MacOs](https://docs.espressif.com/projects/esp-idf/en/latest/esp32/get-started/linux-macos-setup.html)

#### Verifique se a placa está limpa para rodar o projeto

```bash 
$ idf.py fullclean
```

#### Construa o projeto (build)

```bash 
$ idf.py build
```

#### Compile e rode a placa

```bash
$ idf.py flash monitor
```

Ou execute os seguintes comandos na extensão do VSCode:
- FullClean:
  
![image](https://github.com/FSE-2023-2/trabalho-final-2023-2-trabalho-final-fse/assets/54143767/1f34eba2-3a4e-41a8-b7d7-3c93c6c1b92c)

- Build / Flash / Monitor:

![image](https://github.com/FSE-2023-2/trabalho-final-2023-2-trabalho-final-fse/assets/54143767/cf60c3c6-b36b-40c0-8b31-971867682675)

Obs: Caso esteja utilizando Windows, entre no Gerenciador de Dispotivos para descobrir qual porta (COM) está conectada sua placa. Após isso, selecione a porta correta no VSCode clicando em:

![image](https://github.com/FSE-2023-2/trabalho-final-2023-2-trabalho-final-fse/assets/54143767/36e24c0e-6ea4-4d66-96fa-fe24f21f622b)

![image](https://github.com/FSE-2023-2/trabalho-final-2023-2-trabalho-final-fse/assets/54143767/d3047e76-50c5-4b8b-bb44-7512f15dfebd)

Selecionando a porta indicada.

Obs2: Caso esteja utilizando Windows, na hora que for dar o flash, selecione a opção UART em:

![image](https://github.com/FSE-2023-2/trabalho-final-2023-2-trabalho-final-fse/assets/54143767/aaf0e726-2ee0-488f-bbab-f3b6f58d7856)


## ✔️ Utilização do projeto
Acesse o [dashboard](http://thingsboard.lappis.rocks:443/dashboard/0ddfaf90-9511-11ee-bdb2-7b07ee36c1c6?publicId=d1a50d70-949f-11ee-bdb2-7b07ee36c1c6) após rodar a placa e veja o projeto executando 