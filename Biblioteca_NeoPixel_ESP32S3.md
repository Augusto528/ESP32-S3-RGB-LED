# Biblioteca NeoPixel --- ESP32-S3

## Escopo

Biblioteca dedicada exclusivamente ao **único NeoPixel integrado à placa
ESP32-S3**. Não fazem parte do escopo fitas, anéis, matrizes, conjuntos
de LEDs, segmentos ou controle de múltiplos pixels.

O objetivo é oferecer controle completo da cor e do brilho, animações,
efeitos visuais, transições, estados e personalização, com execução não
bloqueante e uma API simples.

------------------------------------------------------------------------

## 1. Controle básico de cores

| Funcionalidade | Descrição |
|---|---|
| Controle RGB | Definir valores individuais de vermelho, verde e azul. |
| Controle HSV | Definir cores por matiz, saturação e valor. |
| Controle HSL | Definir cores por matiz, saturação e luminosidade. |
| Controle hexadecimal | Definir cores utilizando códigos hexadecimais. |
| Cores predefinidas | Disponibilizar cores por nomes e constantes. |
| Controle de branco | Definir branco e diferentes tonalidades de branco. |
| Brilho | Controlar a intensidade luminosa do NeoPixel. |
| Intensidade por canal | Ajustar separadamente a intensidade dos canais RGB. |
| Inversão de cores | Inverter os valores dos canais de uma cor. |
| Mistura de cores | Combinar duas ou mais cores. |
| Correção de gama | Ajustar a resposta luminosa percebida pelo olho. |
| Balanço de branco | Corrigir diferenças na tonalidade do branco. |
| Estrutura de cores | Criar um tipo próprio para armazenar e manipular cores. |

## 2. Transições e mudanças de cores

| Funcionalidade | Descrição |
|---|---|
| Fade-in | Aumentar gradualmente o brilho de uma cor. |
| Fade-out | Diminuir gradualmente o brilho até apagar. |
| Fade entre cores | Fazer uma transição gradual entre duas cores. |
| Transição RGB | Interpolar cores utilizando o espaço RGB. |
| Transição HSV | Interpolar cores utilizando o espaço HSV. |
| Transição HSL | Interpolar cores utilizando o espaço HSL. |
| Duração configurável | Determinar o tempo total de uma transição. |
| Transição linear | Alterar a cor em velocidade constante. |
| Transição exponencial | Aplicar uma curva exponencial à mudança. |
| Ease-in | Começar lentamente e acelerar. |
| Ease-out | Começar rapidamente e desacelerar. |
| Ease-in-out | Começar e terminar lentamente. |
| Curva personalizada | Permitir definir matematicamente a velocidade da transição. |
| Pulso de brilho | Aumentar e diminuir o brilho periodicamente. |
| Respiração (breathing) | Simular uma iluminação que aumenta e diminui suavemente. |
| Piscar configurável | Alternar entre ligado e desligado. |
| Tempo ligado/desligado | Configurar separadamente os períodos de iluminação e apagamento. |
| Alternância de cores | Alternar entre duas ou mais cores. |
| Transição cíclica | Percorrer uma sequência de cores continuamente. |

## 3. Efeitos visuais predefinidos

Como existe apenas um pixel, os efeitos devem atuar sobre sua cor e
intensidade ao longo do tempo. Efeitos que dependem de deslocamento,
posição, cauda ou sequência espacial de LEDs não fazem parte do escopo.

### 3.1. Efeitos de cor

| Efeito | Descrição |
|---|---|
| Rainbow / ciclo HSV | Percorrer continuamente o espectro de cores em um único pixel. |
| Color Cycle | Alternar continuamente entre uma sequência de cores. |
| Alternância de cores | Alternar entre duas ou mais cores definidas. |
| Cor aleatória | Selecionar novas cores aleatoriamente em intervalos configuráveis. |
| Transição cíclica | Fazer transições suaves entre várias cores. |

### 3.2. Efeitos de intensidade

| Efeito | Descrição |
|---|---|
| Breathing | Variar suavemente o brilho em ciclos. |
| Heartbeat | Simular batimentos cardíacos com pulsos de brilho. |
| Flicker | Produzir oscilações irregulares de intensidade. |
| Candle | Simular a luminosidade variável de uma vela. |
| Strobe | Produzir flashes rápidos e repetitivos. |
| Flash | Produzir um flash individual. |
| Double Flash | Produzir dois flashes consecutivos. |
| Random Flash | Produzir flashes em intervalos aleatórios. |
| Lightning | Simular relâmpagos por meio de flashes de intensidade variável. |
| Twinkle | Produzir variações repentinas e breves de brilho. |
| Sparkle | Criar brilhos repentinos com duração e intensidade configuráveis. |

### 3.3. Parâmetros gerais dos efeitos

| Funcionalidade | Descrição |
|---|---|
| Cor configurável | Definir a cor utilizada pelo efeito. |
| Brilho configurável | Definir a intensidade máxima do efeito. |
| Velocidade configurável | Ajustar a velocidade de execução. |
| Duração configurável | Determinar por quanto tempo o efeito será executado. |
| Repetição | Repetir o efeito uma quantidade definida de vezes ou indefinidamente. |
| Aleatoriedade configurável | Ajustar a variação e os intervalos de efeitos aleatórios. |
| Combinação de efeitos | Permitir combinar comportamentos compatíveis, como variação de cor e brilho. |

## 4. Controle temporal e animações não bloqueantes

**Prioridade arquitetural:** as animações devem funcionar sem bloquear o
restante do programa.

| Funcionalidade | Descrição |
|---|---|
| Motor não bloqueante | Executar animações sem utilizar `delay()` para controlar sua duração. |
| Atualização automática | Atualizar os efeitos conforme o tempo decorrido. |
| Função `update()` | Centralizar a atualização das animações e transições. |
| Controle de FPS | Definir a frequência máxima de atualização. |
| Intervalos configuráveis | Determinar o intervalo entre atualizações. |
| Temporizadores independentes | Permitir diferentes tempos para cada comportamento. |
| Pausar animação | Interromper temporariamente um efeito. |
| Continuar animação | Retomar um efeito pausado. |
| Reiniciar animação | Voltar ao início de um efeito. |
| Interromper animação | Encerrar imediatamente um efeito. |
| Agendamento de início | Programar quando uma animação começará. |
| Agendamento de encerramento | Programar quando uma animação terminará. |
| Repetições configuráveis | Determinar quantas vezes um efeito será executado. |
| Execução simultânea | Executar comportamentos compatíveis simultaneamente, como uma transição de cor com uma pulsação de brilho. |
| Prioridade de animações | Determinar qual animação prevalece quando houver conflito. |
| Sincronização temporal | Sincronizar diferentes comportamentos por tempo. |
| Duração configurável | Definir o tempo total de execução. |

## 5. Controle avançado de brilho e aparência

| Funcionalidade | Descrição |
|---|---|
| Brilho global | Ajustar a intensidade luminosa do pixel. |
| Brilho mínimo | Definir um limite inferior de intensidade. |
| Brilho máximo | Definir um limite superior de intensidade. |
| Controle por canal | Ajustar a intensidade individual dos canais RGB. |
| Correção de gama | Compensar a resposta não linear da percepção luminosa. |
| Correção de cores | Ajustar a reprodução das cores. |
| Temperatura de cor | Ajustar a tonalidade da iluminação branca. |
| Saturação | Controlar a intensidade das cores. |
| Suavização de mudanças | Evitar alterações bruscas de iluminação. |
| Escurecimento gradual | Reduzir o brilho progressivamente. |
| Modo noturno | Aplicar um limite reduzido de brilho. |
| Modo econômico | Reduzir a intensidade para economizar energia. |
| Limitação de potência | Restringir a potência estimada do pixel. |
| Estimativa de consumo | Calcular aproximadamente a corrente e a potência a partir dos valores RGB e de parâmetros configurados. |

## 6. Controle de estados e comportamentos

| Funcionalidade | Descrição |
|---|---|
| Estado desligado | Definir o comportamento quando o pixel estiver apagado. |
| Estado inicial | Configurar a iluminação de inicialização. |
| Estado de funcionamento | Definir a iluminação de operação normal. |
| Estado de espera | Configurar a iluminação em repouso. |
| Estado de alerta | Definir uma indicação visual de aviso. |
| Estado de erro | Definir uma indicação visual de erro. |
| Estado de emergência | Configurar uma indicação de emergência. |
| Estado de carregamento | Indicar visualmente um processo de carregamento. |
| Estado de conclusão | Indicar que uma operação foi finalizada. |
| Configuração por estado | Associar cor, efeito, brilho e velocidade a cada estado. |
| Duração por estado | Definir quanto tempo cada estado permanece ativo. |
| Prioridade por estado | Determinar a precedência dos estados. |
| Transição automática | Alterar estados conforme condições definidas. |
| Interrupção de efeitos | Permitir que um estado interrompa outro comportamento. |
| Retomada de efeitos | Retomar o comportamento anterior após uma interrupção. |
| Máquina de estados | Gerenciar transições e condições dos estados. |

## 7. Personalização de efeitos

| Funcionalidade | Descrição |
|---|---|
| Efeitos matemáticos | Criar animações utilizando funções matemáticas. |
| Curvas personalizadas de brilho | Definir como o brilho varia ao longo do tempo. |
| Sequências de cores | Criar listas ordenadas de cores. |
| Sequências de animações | Criar listas de efeitos executados em sequência. |
| Tempos por etapa | Definir a duração individual de cada etapa. |
| Efeitos aleatórios configuráveis | Personalizar os parâmetros de efeitos aleatórios. |
| Tabelas de valores | Criar animações a partir de conjuntos de dados. |
| Efeitos condicionais | Alterar animações conforme variáveis externas. |
| Efeitos por sensores | Controlar efeitos com informações de sensores. |
| Combinação de efeitos | Misturar comportamentos predefinidos compatíveis. |
| Efeitos personalizados por código | Permitir que o usuário desenvolva seus próprios efeitos. |
| Callbacks | Executar funções externas durante animações ou eventos. |
| Funções de progresso | Utilizar o progresso de uma animação como entrada de funções personalizadas. |

## 8. Recursos adicionais

| Funcionalidade | Descrição |
|---|---|
| Paletas predefinidas | Disponibilizar conjuntos prontos de cores. |
| Histórico de cores | Armazenar cores utilizadas anteriormente. |
| Presets | Salvar configurações completas de iluminação e efeitos. |
| Sequenciador | Executar listas ordenadas de efeitos. |
| Camadas | Sobrepor comportamentos compatíveis, como cor e brilho. |
| Sincronização externa | Sincronizar animações com outros dispositivos. |
| Controle Serial | Receber comandos pela comunicação serial. |
| Controle Wi-Fi | Receber comandos pela rede sem fio. |
| Controle Bluetooth | Receber comandos por Bluetooth. |
| Persistência | Salvar configurações na memória não volátil, quando necessário. |
| Debug | Exibir informações internas para depuração. |
| Estatísticas | Monitorar atualizações, execuções e tempo de funcionamento. |
| Gerenciamento de energia | Aplicar limites de brilho e consumo estimado. |

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
| Scheduler | Temporizadores, agendamentos e execução de tarefas da biblioteca. |
| Driver | Comunicação física com o NeoPixel integrado à placa. |
| Configuration | Parâmetros e configurações gerais da biblioteca. |
| Debug | Diagnóstico e informações de execução. |

### Requisitos internos

-   Separar a lógica dos efeitos da comunicação física com o LED.
-   Manter a API pública simples e consistente.
-   Evitar bloqueios durante animações.
-   Controlar cuidadosamente o uso de memória.
-   Evitar alocações dinâmicas desnecessárias.
-   Permitir configurar os parâmetros dos efeitos.
-   Documentar parâmetros, retornos e limitações das funções.
-   Disponibilizar exemplos individuais para cada grupo de
    funcionalidades.

------------------------------------------------------------------------

## 10. Checklist de desenvolvimento

### Etapa 1 --- Fundação

-   [ ] Comunicação com o NeoPixel integrado.
-   [ ] Inicialização e configuração do driver.
-   [ ] Estrutura própria de cores.
-   [ ] Controle RGB, HSV e HSL.
-   [ ] Conversões de cores.
-   [ ] Controle de brilho.
-   [ ] Buffer de cor.
-   [ ] Atualização física do pixel.
-   [ ] Correção de gama e balanço de branco.

### Etapa 2 --- Animações

-   [ ] Motor não bloqueante.
-   [ ] Função `update()`.
-   [ ] Transições e fades.
-   [ ] Curvas de animação.
-   [ ] Temporizadores e controle de FPS.
-   [ ] Efeitos visuais predefinidos.
-   [ ] Pausar, continuar e interromper animações.
-   [ ] Execução simultânea de comportamentos compatíveis.

### Etapa 3 --- Personalização

-   [ ] Paletas de cores.
-   [ ] Efeitos personalizados por código.
-   [ ] Callbacks.
-   [ ] Funções matemáticas personalizadas.
-   [ ] Combinação e sobreposição de efeitos.
-   [ ] Sequenciador de animações.
-   [ ] Parâmetros personalizáveis dos efeitos.

### Etapa 4 --- Gerenciamento avançado

-   [ ] Máquina de estados.
-   [ ] Sistema de prioridades.
-   [ ] Agendamento de animações.
-   [ ] Presets e persistência.
-   [ ] Sincronização externa.
-   [ ] Controle Serial, Wi-Fi e Bluetooth.
-   [ ] Estimativa de consumo.
-   [ ] Debug e estatísticas.

### Etapa 5 --- Finalização

-   [ ] Testes de funcionamento no ESP32-S3.
-   [ ] Testes de desempenho e memória.
-   [ ] Testes de execução simultânea.
-   [ ] Testes de transições e efeitos.
-   [ ] Documentação completa.
-   [ ] Exemplos de utilização.
-   [ ] Revisão da API pública.

------------------------------------------------------------------------

## 11. Diretrizes do projeto

1.  A biblioteca será dedicada a um único NeoPixel integrado ao
    ESP32-S3.
2.  Não serão implementados recursos para fitas, matrizes, anéis ou
    múltiplos LEDs.
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
