# Biblioteca NeoPixel --- ESP32-S3 (versão enxuta)

## Escopo

Biblioteca dedicada exclusivamente ao **único NeoPixel integrado à placa
ESP32-S3**. Não fazem parte do escopo fitas, anéis, matrizes, conjuntos
de LEDs, segmentos ou controle de múltiplos pixels, nem comunicação
(Serial, Wi-Fi, Bluetooth), que pertence ao programa do usuário.

**Modelo central:** todo efeito, transição e curva é uma função do
tempo que produz uma cor e/ou um brilho. Combinar comportamentos
significa combinar um gerador de cor com um modulador de brilho.

------------------------------------------------------------------------

## 1. Controle básico de cores

| Funcionalidade | Descrição |
|---|---|
| Estrutura de cores | Tipo próprio para armazenar e manipular cores (resolução interna maior que 8 bits). |
| Controle RGB | Definir valores individuais de vermelho, verde e azul. |
| Controle HSV | Definir cores por matiz, saturação e valor. |
| Controle hexadecimal | Definir cores utilizando códigos hexadecimais. |
| Cores predefinidas | Disponibilizar cores por nomes e constantes. |
| Brilho | Controlar a intensidade luminosa do NeoPixel. |
| Ganho por canal | Ajustar separadamente a intensidade dos canais RGB, também usado para calibrar o branco. |
| Mistura de cores | Combinar duas ou mais cores. |
| Correção de gama | Ajustar a resposta luminosa percebida pelo olho. |
| Pino e ordem dos canais | Configurar o GPIO do LED e a ordem das cores (GRB, RGB), com padrão sensato. |

## 2. Transições

| Funcionalidade | Descrição |
|---|---|
| Fade-in / Fade-out | Aumentar ou diminuir gradualmente o brilho de uma cor. |
| Fade entre cores | Transição gradual entre duas cores, interpolando em RGB ou HSV. |
| Duração configurável | Determinar o tempo total de uma transição. |
| Curvas de easing | Linear, ease-in, ease-out e ease-in-out. |
| Curva personalizada | Definir matematicamente a velocidade da transição. |
| Piscar configurável | Alternar entre ligado e desligado, com tempos ligado/desligado independentes. |
| Transição cíclica | Percorrer uma sequência de cores continuamente. |

## 3. Efeitos visuais predefinidos

### 3.1. Efeitos de cor

| Efeito | Descrição |
|---|---|
| Rainbow | Percorrer continuamente o espectro de cores (ciclo HSV). |
| Color Cycle | Alternar continuamente entre uma sequência de cores. |
| Cor aleatória | Selecionar novas cores aleatoriamente em intervalos configuráveis. |

### 3.2. Efeitos de intensidade

| Efeito | Descrição |
|---|---|
| Breathing | Variar suavemente o brilho em ciclos. |
| Heartbeat | Simular batimentos cardíacos com pulsos de brilho. |
| Flicker | Produzir oscilações irregulares de intensidade. |
| Candle | Simular a luminosidade variável de uma vela. |
| Strobe | Produzir flashes rápidos e repetitivos. |
| Flash | Produzir um ou mais flashes (individual, duplo ou em intervalos aleatórios, por parâmetro). |
| Lightning | Simular relâmpagos por meio de flashes de intensidade variável. |
| Twinkle | Produzir brilhos repentinos e breves, com duração e intensidade configuráveis. |

### 3.3. Parâmetros gerais dos efeitos

| Funcionalidade | Descrição |
|---|---|
| Cor configurável | Definir a cor utilizada pelo efeito. |
| Brilho configurável | Definir a intensidade máxima do efeito. |
| Velocidade configurável | Ajustar a velocidade de execução. |
| Duração configurável | Determinar por quanto tempo o efeito será executado. |
| Repetição | Repetir o efeito uma quantidade definida de vezes ou indefinidamente. |
| Aleatoriedade configurável | Ajustar a variação e os intervalos de efeitos aleatórios. |
| Combinação de efeitos | Combinar um gerador de cor com um modulador de brilho. |

## 4. Controle temporal e animações não bloqueantes

**Prioridade arquitetural:** as animações devem funcionar sem bloquear o
restante do programa.

| Funcionalidade | Descrição |
|---|---|
| Motor não bloqueante | Executar animações sem utilizar `delay()`. |
| Função `update()` | Centralizar a atualização das animações e transições conforme o tempo decorrido. |
| Intervalo mínimo de atualização | Definir a frequência máxima de atualização. |
| Tempo relativo por animação | Cada animação mede o tempo a partir do seu próprio início, permitindo pausar e retomar corretamente. |
| Pausar e continuar | Interromper temporariamente um efeito e retomá-lo. |
| Reiniciar animação | Voltar ao início de um efeito. |
| Interromper animação | Encerrar imediatamente um efeito. |
| Execução simultânea | Combinar comportamentos compatíveis, como uma transição de cor com uma pulsação de brilho. |
| Prioridade de animações | Determinar qual animação prevalece quando houver conflito. |

## 5. Controle de brilho e aparência

| Funcionalidade | Descrição |
|---|---|
| Brilho global | Ajustar a intensidade luminosa do pixel. |
| Brilho mínimo | Definir um limite inferior de intensidade. |
| Brilho máximo | Definir um limite superior de intensidade. |
| Modo noturno | Aplicar um limite reduzido de brilho. |
| Resolução interna ampliada | Manter a cor em 16 bits (ou float) e reduzir para 8 bits apenas na saída, com dithering temporal opcional para fades suaves em brilho baixo. |

## 6. Controle de estados e comportamentos

| Funcionalidade | Descrição |
|---|---|
| Estados configuráveis | Associar cor, efeito, brilho e velocidade a cada estado (desligado, inicial, funcionamento, espera, alerta, erro, conclusão, carregamento e outros definidos pelo usuário). |
| Estados predefinidos | Disponibilizar presets prontos de estado, como alerta, erro, conclusão e carregamento. |
| Duração por estado | Definir quanto tempo cada estado permanece ativo. |
| Prioridade por estado | Determinar a precedência dos estados. |
| Interrupção de efeitos | Permitir que um estado de maior prioridade interrompa outro comportamento. |
| Retomada de efeitos | Retomar o comportamento anterior após uma interrupção. |
| Máquina de estados | Gerenciar a troca de estados e suas prioridades. |

## 7. Personalização de efeitos

| Funcionalidade | Descrição |
|---|---|
| Efeitos matemáticos | Criar animações utilizando funções matemáticas do tempo. |
| Curvas personalizadas de brilho | Definir como o brilho varia ao longo do tempo. |
| Sequências de cores | Criar listas ordenadas de cores. |
| Sequenciador de animações | Executar listas de efeitos em sequência, com duração individual por etapa. |
| Efeitos personalizados por código | Permitir que o usuário desenvolva seus próprios efeitos. |
| Callbacks | Executar funções externas durante animações ou eventos (ponteiros de função com contexto, sem alocação dinâmica). |
| Funções de progresso | Utilizar o progresso de uma animação como entrada de funções personalizadas. |

## 8. Recursos adicionais

| Funcionalidade | Descrição |
|---|---|
| Paletas predefinidas | Disponibilizar conjuntos prontos de cores. |
| Presets | Salvar configurações completas de iluminação e efeitos. |
| Debug | Exibir informações internas para depuração. |
| Persistência (opcional) | Salvar presets na memória não volátil, como módulo separado ou exemplo. |

## 9. Arquitetura e organização interna

A implementação deve manter a interface pública simples e separar
responsabilidades internamente, sem criar abstrações desnecessárias para
hardware que não faz parte do escopo.

| Módulo | Responsabilidade |
|---|---|
| NeoPixel | Interface principal de inicialização e controle do pixel. |
| Color | Operações, estruturas e conversões de cores. |
| Effects | Implementação dos efeitos predefinidos. |
| Animation | Transições, curvas e animações temporais. |
| State | Gerenciamento de estados e prioridades. |
| Driver | Comunicação física com o NeoPixel integrado à placa. |
| Configuration | Parâmetros e configurações gerais da biblioteca. |
| Debug | Diagnóstico e informações de execução. |

### Requisitos internos

-   Separar a lógica dos efeitos da comunicação física com o LED, de
    modo que possa ser testada fora da placa.
-   Manter a API pública simples e consistente.
-   Evitar bloqueios durante animações.
-   Evitar alocações dinâmicas (sem `std::function`).
-   Permitir configurar os parâmetros dos efeitos.
-   Documentar parâmetros, retornos e limitações das funções.
-   Disponibilizar exemplos individuais para cada grupo de
    funcionalidades.

------------------------------------------------------------------------

## 10. Checklist de desenvolvimento

### Etapa 1 --- Núcleo

-   [ ] Driver do NeoPixel integrado (pino e ordem de canais configuráveis).
-   [ ] Estrutura própria de cores.
-   [ ] Controle RGB, HSV e hexadecimal.
-   [ ] Brilho, ganho por canal e correção de gama.
-   [ ] Motor não bloqueante e função `update()`.

### Etapa 2 --- Animação

-   [ ] Transições e fades com curvas de easing.
-   [ ] Efeitos de brilho: blink, breathing, heartbeat, flash, strobe e candle.
-   [ ] Efeitos de cor: rainbow, color cycle e cor aleatória.
-   [ ] Pausar, continuar, reiniciar e interromper.
-   [ ] Execução simultânea de cor e brilho.

### Etapa 3 --- Estados e personalização

-   [ ] Máquina de estados com prioridades, interrupção e retomada.
-   [ ] Estados predefinidos.
-   [ ] Callbacks e efeitos personalizados por código.
-   [ ] Sequenciador de animações e sequências de cores.
-   [ ] Paletas e presets.
-   [ ] Debug e persistência opcional.

### Etapa 4 --- Finalização

-   [ ] Testes no ESP32-S3.
-   [ ] Testes de desempenho e memória.
-   [ ] Testes de execução simultânea, transições e efeitos.
-   [ ] Documentação completa e exemplos.
-   [ ] Revisão da API pública.

------------------------------------------------------------------------

## 11. Diretrizes do projeto

1.  A biblioteca será dedicada a um único NeoPixel integrado ao
    ESP32-S3.
2.  Não serão implementados recursos para fitas, matrizes, anéis ou
    múltiplos LEDs, nem comunicação por Serial, Wi-Fi ou Bluetooth.
3.  Efeitos devem ser adequados a um único ponto luminoso.
4.  Todas as animações devem ser não bloqueantes sempre que possível.
5.  As funcionalidades devem ser altamente parametrizáveis.
6.  A lógica de animação deve ser independente do driver de hardware.
7.  O uso de memória deve ser previsível e adequado aos recursos do
    ESP32-S3.
8.  A biblioteca deve permitir adicionar novos efeitos sem modificar o
    funcionamento dos existentes.
9.  A API deve priorizar simplicidade para quem utiliza a biblioteca e
    flexibilidade para quem deseja personalizá-la.

**Princípio central:** tudo que puder ser parametrizado deve ser
parametrizável; tudo que puder ser executado sem bloquear o programa
deve ser não bloqueante.
