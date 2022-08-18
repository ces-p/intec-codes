// Tabla de Amortización
/*
Enunciado: Realizar un programa C++ que genera la tabla de amortización correspondiente dado
el monto del préstamo, la tasa (anualizada) y el período establecido (meses).
La tabla debe especificar los pagos mensuales

Participantes:
Hamlet Daniel Santana Cruz 1099895
Frederick Fermín Guzman 1100364
Cesar Portillo 1100268

Fecha: 02/03/2022
*/

#include <iostream>
using namespace std;
#include <math.h>

double Cuota(double monto, double tiempo, double tasa_interes)
{
    // Calcula el periodo en meses
    tiempo = tiempo * 12;
    // Transformar a decimal la tasa de intereses
    tasa_interes = (tasa_interes * 0.01)/12;

    // Calcular el numerador de la formula de cuota
    double monto_interes = monto * tasa_interes * (pow((1 + tasa_interes), tiempo));

    // la división del resultado del numerador entre el denominador
    double cuota_resultado = monto_interes / (pow((1 + tasa_interes), tiempo) - 1);

    return cuota_resultado;
}

int main(int argc, const char *argv[])
{
    double monto, tiempo, tasa_interes, saldo;
    cout << "Bienvenidos a nuestro programa que realiza una tabla de amortización " << endl;
    cout << endl;
    cout << "Monto total de su prestamo: ";
    cin >> monto;
    cout << "Plazo (anual): ";
    cin >> tiempo;
    cout << "Tasa de Interes (%): ";
    cin >> tasa_interes;

    double cuota = Cuota(monto, tiempo, tasa_interes);

    cout << endl;
    cout << "Su cuota sera de: " << cuota << endl;
    cout << endl;
    cout << "Su tabla de amortizacion es: " << endl;
    cout << endl;

    cout << "Periodo     Renta     Interes     Amortizacion     Saldo" << endl;
    cout << endl;
    saldo = monto;

    int periodo;
    double renta, interes, amortizacion;
    cout << "   0"
         << "          0"
         << "          0"
         << "              0          " << saldo << endl;
    for (int i = 1; i <= tiempo * 12; i++)
    {

        periodo = i;
        renta = cuota;
        interes = saldo * tasa_interes * 0.01;
        amortizacion = renta - interes;

        if (saldo - amortizacion >= 1)
        {
            saldo -= amortizacion;
        }
        else
        {
            saldo = 0;
        }

        cout << "   " << periodo << "       " << renta << "      "
             << interes << "       " << amortizacion << "       " << saldo << endl;
    }
}