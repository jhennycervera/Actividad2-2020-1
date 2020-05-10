/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Jhenny Cervera Vargas(20182841)
 *
 * Created on 7 de mayo de 2020, 17:03
 */

#include <stdio.h>
#include <stdlib.h>
#include "FuncAux.h"
#define MAX_LIN 80
/*
/*
 * 
 */
int main(int argc, char** argv) {
    
     int segi, segf;
    printf("INFORME DE PRECIPITACIONES DE LA REGION\n");
    printf("Rango de horas: 00:00:00 a 06:59:59\n");
    ImprimLin(MAX_LIN, '=');
    printf(" Fecha   Cantidad    Tiempo total   Total Llovido  Promedio++\n");
    segi=0;
    segf=6*3600 + 59*60 + 59;
    
    ImprimirRep(segi,segf);
    
    printf("INFORME DE PRECIPITACIONES DE LA REGION\n");
    printf("Rango de horas: 07:00:00 a 17:59:59\n");
    ImprimLin(MAX_LIN, '=');
    printf(" Fecha   Cantidad    Tiempo total   Total Llovido  Promedio++\n");
    segi=7*3600;
    segf=17*3600 + 59*60 + 60;
    
    ImprimirRep(segi,segf);
    
    printf("INFORME DE PRECIPITACIONES DE LA REGION\n");
    printf("Rango de horas: 18:00:00 a 24:00:00\n");
    ImprimLin(MAX_LIN, '=');
    printf(" Fecha   Cantidad    Tiempo total   Total Llovido  Promedio++\n");
    segi=6*3600;
    segf=24*3600;
    
    ImprimirRep(segi,segf);
    
    
    
    
    
    
    
    return (EXIT_SUCCESS);
}

