#include <stdio.h>
#include <math.h>


struct Complex {
    double real;
    double imag;
}; // Користувацька структура для комплексного числа


struct Complex tan_complex(struct Complex z) {
    struct Complex result; // Функція для обчислення тангенсу комплексного числа

    
    double a = z.real;
    double b = z.imag; // Присвоєння комплексному числу z його дійсної та уявної частини

    
    double numerator_real = sin(a) * cosh(b);
    double numerator_imag = cos(a) * sinh(b);
    double denominator_real = cos(a) * cosh(b);
    double denominator_imag = -sin(a) * sinh(b); // Обчислимо значення тангенсу за наданою формолою для комплексного числа z

    
    result.real = (numerator_real + numerator_imag) / (denominator_real + denominator_imag);
    result.imag = (numerator_imag - numerator_real) / (denominator_real + denominator_imag); // Формуємо результат для комплексної та уявної частини

    return result;
}

int main() {
    
    struct Complex z; //Ініціалізація структури комплексного числа z
    printf("Enter the real part of the complex number: ");
    scanf("%lf", &z.real);
    printf("Enter the imaginary part of the complex number: ");
    scanf("%lf", &z.imag);  // Введемо дійсну та уявну частини комплексного числа

    
    struct Complex result = tan_complex(z); // Ініціалізація тангенса комплексного числа

    
    printf("tg(z)= tg(%.2f + %.2fi) = %.6f + %.6fi\n", z.real, z.imag, result.real, result.imag); // Вивід результату

    return 0;
}
