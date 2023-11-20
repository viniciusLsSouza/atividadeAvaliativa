#include <stdio.h>


int validaQuantidade() {
    int quantidade;
    do {
        printf("Digite a quantidade de peças fabricadas: ");
        if (scanf("%d", &quantidade) != 1 || quantidade < 0) {
            printf("Quantidade inválida. Digite novamente.\n");
            while (getchar() != '\n'); 
        } else {
            break;
        }
    } while (1);

    return quantidade;
}


float calculaSalario(int quantidade) {
    float salario_base = 600.00;
    float adicional;

    if (quantidade <= 50) {
        adicional = 0;
    } else if (quantidade <= 80) {
        adicional = 0.50 * (quantidade - 50);
    } else {
        adicional = 0.50 * (80 - 50) + 0.75 * (quantidade - 80);
    }

    return salario_base + adicional;
}


void mostraFinal() {
    while (1) {
        int quantidade = validaQuantidade();
        float salario_final = calculaSalario(quantidade);

        printf("Salário do funcionário: R$ %.2f\n", salario_final);
        printf("---------------------------------\n");

        printf("Deseja cadastrar outro funcionário? (1 para sim, 0 para não): ");
        int continuar;
        scanf("%d", &continuar);
        if (continuar != 1) {
            break;
        }
    }
}


int main() {
    mostraFinal();

    return 0;
}