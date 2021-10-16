#include <stdio.h>

float fn_add(float a, float b) {return a + b;}
float fn_sub(float a, float b) {return a - b;}
float fn_mul(float a, float b) {return a * b;}
float fn_div(float a, float b) {return (b ? a / b : 0.0);}
float fn_err(float a, float b) {printf("nenene\n");}

int main(int argc, char const *argv[])
{
    float x = 0.0, y = 0.0;
    char op;
    int r;
    float (*fn_comp[]) (float, float) = {fn_mul, fn_add, fn_err, fn_sub, fn_err,fn_div}; //ukazatel na fci ktera vraci float a prijima 2 floaty

    do{
        r = scanf("%f%c%f", &x, &op, &y);

        printf("%f %c %f = %f\n", x, op, y, fn_comp[op >= '*' && op <= '/' ? op - '*' : '.' - '*'](x,y));
    } while(r == 3);

    return 0;
}