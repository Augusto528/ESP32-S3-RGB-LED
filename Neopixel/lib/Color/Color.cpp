#include "Color.h"

RGB HSV_RGB(HSV valor){
  
    float h = std::fmod(valor.h, 360.0f);

    if (h < 0.0f) h += 360.0f;

    float s = valor.s;
    float v = valor.v;

    if (s > 1.0f) s = 1.0f;
    if (s < 0.0f) s = 0.0f;

    if (v > 1.0f) v = 1.0f;
    if (v < 0.0f) v = 0.0f;

    float c = v * s;

    float x = c * (1.0f - std::fabs(std::fmod(h/60.0f, 2.0f) - 1.0f));

    float m = v - c;

    float r, g, b;


    if (h < 60.0f) {
        r = c;
        g = x;
        b = 0;
    } else if (h < 120.0f) {
        r = x;
        g = c;
        b = 0;
    } else if (h < 180.0f) {
        r = 0;
        g = c;
        b = x;
    } else if (h < 240.0f) {
        r = 0;
        g = x;
        b = c;
    } else if (h < 300.0f) {
        r = x;
        g = 0;
        b = c;
    } else {
        r = c;
        g = 0;
        b = x;
    }

    RGB resultado;

    resultado.r = std::lround((r + m) * 255.0f);
    resultado.g = std::lround((g + m) * 255.0f);
    resultado.b = std::lround((b + m) * 255.0f);

    return resultado;
}

HSV RGB_HSV(RGB valor){
    float r = valor.r/255.0f;
    float g = valor.g/255.0f;
    float b = valor.b/255.0f;

    float h, v, s = 0.0f;

    float M = std::max(r, g, b);
    float m = std::min(r, g, b);

    float delta = M - m;


    if (M == 0) s = 0;
    else s = delta/M;

    if (delta == 0) h = 0;
    else if(M == r) h = 60.0f * (std::fmod((g-b)/delta, 6.0f));
    else if(M == g) h = 60.0f * (((b-r)/delta)+2.0f);
    else if(M == b) h = 60.0f * (((r-g)/delta)+4.0f);

    if (h < 0.0f) h += 360.0f;

    v = M;

    HSV resultado = {h, s, v};

return resultado;
};

RGB HEX_RGB(HEX valor){

    RGB resultado;

    resultado.r = (valor >> 16) & 0xFF;
    resultado.g = (valor >> 8) & 0xFF;
    resultado.b = valor & 0xFF;

    return resultado;
}

HEX RGB_HEX(RGB valor){

    HEX resultado = (static_cast<uint32_t>(valor.r) << 16) | (static_cast<uint32_t>(valor.g) << 8)  | (static_cast<uint32_t>(valor.b));

    return resultado;
}

HSV HEX_HSV(HEX valor){
    return RGB_HSV(HEX_RGB(valor));
}

HEX HSV_HEX(HSV valor){
    return RGB_HEX(HSV_RGB(valor));
}
