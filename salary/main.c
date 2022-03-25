#include<stdio.h>
float CalculoNeto(float sueldo, float descuento);
float CalculoDescuento(float sueldo);
int main() {
    float sal = 0, sueldo = 0, desc;
    do {
        //Datos Entrada,
        if (sal <= 0) //lanzara error de excepcion si es menor igual a '0'
            printf("Error..Ingrese una cantidad calculable\n");
        printf("Ingrese salario bruto: ");
        while (scanf("%f", &sal) != 1) //valida que los datos ingresados sean números solamente
        {
            printf("::ERROR:: Ingrese su salario nuevamente: ");
            while (getchar() != '\n'); //Elimina caracteres no numericos para que no se repita el error
        }
    } while (sal <= 0); //no finalizará hasta que la entrada sea mayor a '0'
    //Datos Salida
    desc = CalculoDescuento(sal);
    sueldo = CalculoNeto(sal, desc);
    printf("\nEl descuento es: B/.%.2f\n", desc);
    printf("El salario neto es: B/.%.2f\n", sueldo);

}

//Funcion para calcular descuento
float CalculoDescuento(float sueldo)
{
    float descuento;
    if (sueldo >= 0 && sueldo <= 1500)
    {
        descuento = (sueldo*0.15f);   //operacion del descuento de 15%
    }
    else if (sueldo > 1500 && sueldo <= 3000)
    {
        descuento = (sueldo*0.25f);   //operacion del descuento de 15% más el 10% adicional: 25%
    }
    else if (sueldo > 3000)
    {
        descuento = (sueldo*0.31f);   //operacion del descuento de 25% mas 6% adicional: 31%
    }
    return descuento;//la funcion devuelve solo el descuento realizado
}
//Funcion para calcular salario neto
float CalculoNeto(float sueldo, float descuento) //recibe datos de la previa funcion ->
{
    float suelneto = sueldo-descuento;
    return suelneto; // <- para realizar el calculo del salario neto
}
