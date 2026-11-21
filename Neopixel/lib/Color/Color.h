#pragma once

#include "Estruturas.h"
#include <cmath>
#include <algorithm>

enum class Cores : uint8_t {
    VERMELHO,
    VERDE,
    AZUL,
    AMARELO,
    CIANO,
    MAGENTA,
    BRANCO,
    PRETO,
    LARANJA,
    ROXO
};

// RGB cor_RGB(Cores cor);

RGB HSV_RGB(HSV valor);
HSV RGB_HSV(RGB valor);

RGB HEX_RGB(HEX valor);
HEX RGB_HEX(RGB valor);

HSV HEX_HSV(HEX valor);
HEX HSV_HEX(HSV valor);



