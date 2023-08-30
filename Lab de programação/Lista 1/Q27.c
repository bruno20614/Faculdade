#include <stdio.h>
#include <math.h>
int main()
{   
    float num1, num2 ,num3;
    float Mg, exp;

    printf("Digite os tres numeros: ");
    scanf("%f %f %f", &num1, &num2, &num3);

    printf("O valor da media aitmetica foi de: %.2f\n", num1+num2+num3/3);

    exp = 1.0 /3;
    Mg = pow(num1 * num2 * num3, exp);
    printf("O valor da media aritmetca foi de %.2f\n", Mg);
    
    return 0;
}
