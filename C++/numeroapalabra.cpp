/*
Enunciado: Realizar un programa C++ que lea un monto real y que convierta este monto a palabra

Participantes:
Hamlet Daniel Santana Cruz 1099895
Frederick Fermín Guzman 1100364
Elian Marte 1100103
Cesar Portillo 1100268

Fecha: 22/06/2022
*/

#include <iostream>
using namespace std;

struct Unidad
{
    string nombre;
    int cantidad;
};

struct Comparacion
{
    string palabra;
    string palabraExtra;
    int numero;
};

string palabra = "";

int main()
{
    // Structs para las unidades

    Unidad centenas;
    centenas.nombre = "";
    centenas.cantidad = 1;

    Unidad miles;
    miles.nombre = "mil ";
    miles.cantidad = 1000;

    Unidad millones;
    millones.nombre = "millones ";
    millones.cantidad = 1000000;

    // Structs Comparacion

    Comparacion novecientos;
    novecientos.palabra = "novecientos ";
    novecientos.palabraExtra = "novecientos ";
    novecientos.numero = 900;

    Comparacion ochocientos;
    ochocientos.palabra = "ochocientos ";
    ochocientos.palabraExtra = "ochocientos ";
    ochocientos.numero = 800;

    Comparacion setesientos;
    setesientos.palabra = "setecientos ";
    setesientos.palabraExtra = "setecientos ";
    setesientos.numero = 700;

    Comparacion seiscientos;
    seiscientos.palabra = "seiscientos ";
    seiscientos.palabraExtra = "seiscientos ";
    seiscientos.numero = 600;

    Comparacion quinientos;
    quinientos.palabra = "quinientos ";
    quinientos.palabraExtra = "quinientos ";
    quinientos.numero = 500;

    Comparacion cuatrocientos;
    cuatrocientos.palabra = "cuatrocientos ";
    cuatrocientos.palabraExtra = "cuatrocientos ";
    cuatrocientos.numero = 400;

    Comparacion trescientos;
    trescientos.palabra = "trescientos ";
    trescientos.palabraExtra = "trescientos ";
    trescientos.numero = 300;

    Comparacion doscientos;
    doscientos.palabra = "doscientos ";
    doscientos.palabraExtra = "doscientos ";
    doscientos.numero = 200;

    Comparacion cien;
    cien.palabra = "cien ";
    cien.palabraExtra = "ciento ";
    cien.numero = 100;

    Comparacion noventa;
    noventa.palabra = "noventa ";
    noventa.palabraExtra = "noventa y ";
    noventa.numero = 90;

    Comparacion ochenta;
    ochenta.palabra = "ochenta ";
    ochenta.palabraExtra = "ochenta y ";
    ochenta.numero = 80;

    Comparacion setenta;
    setenta.palabra = "setenta ";
    setenta.palabraExtra = "setenta y ";
    setenta.numero = 70;

    Comparacion sesenta;
    sesenta.palabra = "sesenta ";
    sesenta.palabraExtra = "sesenta y ";
    sesenta.numero = 60;

    Comparacion cincuenta;
    cincuenta.palabra = "cincuenta ";
    cincuenta.palabraExtra = "cincuenta y ";
    cincuenta.numero = 50;

    Comparacion cuarenta;
    cuarenta.palabra = "cuarenta ";
    cuarenta.palabraExtra = "cuarenta y ";
    cuarenta.numero = 40;

    Comparacion treinta;
    treinta.palabra = "treinta ";
    treinta.palabraExtra = "treinta y ";
    treinta.numero = 30;

    Comparacion veinte;
    veinte.palabra = "veinte ";
    veinte.palabraExtra = "veinte y ";
    veinte.numero = 20;

    Comparacion diecinueve;
    diecinueve.palabra = "diecinueve ";
    diecinueve.palabraExtra = "diecinueve ";
    diecinueve.numero = 19;

    Comparacion dieciocho;
    dieciocho.palabra = "dieciocho ";
    dieciocho.palabraExtra = "dieciocho";
    dieciocho.numero = 18;

    Comparacion diecisiete;
    diecisiete.palabra = "diecisiete ";
    diecisiete.palabraExtra = "diecisiete ";
    diecisiete.numero = 17;

    Comparacion dieciseis;
    dieciseis.palabra = "dieciseis ";
    dieciseis.palabraExtra = "dieciseis ";
    dieciseis.numero = 16;

    Comparacion quince;
    quince.palabra = "quince ";
    quince.palabraExtra = "";
    quince.numero = 15;

    Comparacion catorce;
    catorce.palabra = "catorce ";
    catorce.palabraExtra = "catorce ";
    catorce.numero = 14;

    Comparacion trece;
    trece.palabra = "trece ";
    trece.palabraExtra = "trece ";
    trece.numero = 13;

    Comparacion doce;
    doce.palabra = "doce ";
    doce.palabraExtra = "doce ";
    doce.numero = 12;

    Comparacion once;
    once.palabra = "once ";
    once.palabraExtra = "once ";
    once.numero = 11;

    Comparacion diez;
    diez.palabra = "diez ";
    diez.palabraExtra = "diez ";
    diez.numero = 10;

    Comparacion nueve;
    nueve.palabra = "nueve ";
    nueve.palabraExtra = "nueve ";
    nueve.numero = 9;

    Comparacion ocho;
    ocho.palabra = "ocho ";
    ocho.palabraExtra = "ocho ";
    ocho.numero = 8;

    Comparacion siete;
    siete.palabra = "siete ";
    siete.palabraExtra = "siete ";
    siete.numero = 7;

    Comparacion seis;
    seis.palabra = "seis ";
    seis.palabraExtra = "seis ";
    seis.numero = 6;

    Comparacion cinco;
    cinco.palabra = "cinco ";
    cinco.palabraExtra = "cinco ";
    cinco.numero = 5;

    Comparacion cuatro;
    cuatro.palabra = "cuatro ";
    cuatro.palabraExtra = "cuatro ";
    cuatro.numero = 4;

    Comparacion tres;
    tres.palabra = "tres ";
    tres.palabraExtra = "tres ";
    tres.numero = 3;

    Comparacion dos;
    dos.palabra = "dos";
    dos.palabraExtra = "dos ";
    dos.numero = 2;

    Comparacion uno;
    uno.palabra = "uno ";
    uno.palabraExtra = "uno ";
    uno.numero = 1;

    int num = 0, resta, unid, comp;

    Unidad uni[3] = {centenas, miles, millones};

    Comparacion com[36] = {novecientos, ochocientos, setesientos, seiscientos, quinientos, cuatrocientos, trescientos, doscientos, cien, noventa, ochenta, setenta, sesenta, cincuenta, cuarenta, treinta, veinte, diecinueve, dieciocho, diecisiete, dieciseis, quince, catorce, trece, doce, once, diez, nueve, ocho, siete, seis, cinco, cuatro, tres, dos, uno};

    while (true)
    {
        cout << "Inserte el numero que desea convertir a palabra: ";
        cin >> num;
        if (!cin.fail() && num <= 999999999 && num >= 1)
            break;
        else
        {
            cout << "Solo se aceptan numeros desde el 1 hasta el 999,999,999 \n";
            cin.clear();
            cin.ignore(10000, '\n');
            system("pause");
            system("cls");
        }
    }

    while (num > 0)
    {
        comp = 0;
        unid = 0;
        resta = num;
        while (resta / 1000 > 0)
        {
            resta /= 1000;
            unid++;
        }
        if (resta == 1 && unid == 2)
        {
            palabra += "un millon ";
            num -= 1000000;
        }
        else if (resta == 1 && unid == 1)
        {
            palabra += "mil ";
            num -= 1000;
        }
        else
        {
            num -= resta * uni[unid].cantidad;
            while (resta > 0)
            {
                if (resta >= com[comp].numero)
                {
                    if (resta == com[comp].numero)
                        palabra += com[comp].palabra;
                    else
                        palabra += com[comp].palabraExtra;

                    resta -= com[comp].numero;
                }
                if (resta == 0 && unid > 0)
                    palabra += uni[unid].nombre;
                comp++;
            }
        }
    }
    cout << palabra << "\n";
    system("pause");
}