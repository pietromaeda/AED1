#include <stdio.h>

int main() {
    int horaInicial, minutoInicial, horaFinal, minutoFinal;
    int horasDiferenca, minutosDiferenca, resultado;

    while (scanf("%d %d %d %d", &horaInicial, &minutoInicial, &horaFinal, &minutoFinal), 
           (horaInicial != 0) || (minutoInicial != 0) || (horaFinal != 0) || (minutoFinal != 0)) {
        if (minutoFinal > minutoInicial && horaInicial == horaFinal) {
            resultado = minutoFinal - minutoInicial;
        } else {
            if (minutoInicial > minutoFinal && horaInicial == horaFinal) {
                resultado = 1440 - (minutoInicial - minutoFinal);
            } else {
                if (horaInicial > horaFinal) {
                    resultado = (horaInicial - horaFinal) * 60;
                    resultado = 1440 - resultado;
                    if (minutoInicial > minutoFinal) {
                        resultado -= (minutoInicial - minutoFinal);
                    } else {
                        resultado += (minutoFinal - minutoInicial);
                    }
                } else {
                    resultado = (horaFinal - horaInicial) * 60;
                    if (minutoInicial > minutoFinal) {
                        resultado -= (minutoInicial - minutoFinal);
                    } else {
                        resultado += (minutoFinal - minutoInicial);
                    }
                }
            }
        }
        printf("%d\n", resultado);
    }

    return 0;
}
