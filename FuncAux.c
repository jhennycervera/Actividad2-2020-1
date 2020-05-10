/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <stdio.h>
#include <stdlib.h>
#include "FuncAux.h"
#define MAX_LIN 80

void ImprimirRep(int rangi, int rangf){
    FILE* archPrec;
    archPrec=fopen("Precipitaciones.txt", "r");
    if(archPrec==NULL){
        printf("No se pudo abrir el archivo precipitaciones.txt\n");
        exit(1);
    }
    
    int dd, mm, aa, ciu, hhi,mini, segi, hhf, minf, segf;
    int segI, segF, durSeg, flag=0;
    double cantLluv, vol,totLlov=0, tiempMin, TotalLlovPer=0;
    int contLluvFecha=0, fechaAnt,fecha, tiempoTotseg=0, contLluvTot=0;
    int aai, mmi, ddi, anho, mes, dia, hh, min, seg, ddf, aaf, mmf, cantDias=0;
    while(1){
        fscanf(archPrec, "%d/%d/%d %d %d:%d:%d %d:%d:%d %lf", &dd, &mm, &aa,
                            &ciu, &hhi,&mini, &segi, &hhf, &minf, &segf,&vol);

        segI=hhi*3600 + mini*60 + segi;
        segF=hhf*3600+minf*60 +segf;
        fecha=dd+ mm*100 + aa*10000;
        if( PertRango(segI,segF,rangi,rangf)){
            cantLluv=CalcularCantLlovida(segI,segF,rangi,rangf, vol, &durSeg);
            
            if(flag==0){
                fechaAnt=fecha;
                aai=aa;
                mmi=mm;
                ddi=dd;
            }
            if(fechaAnt!=fecha){
                //imprimir
            separarFech(fechaAnt, &anho, &mes, &dia);
            separarTiemp(tiempoTotseg,&hh, &min,&seg);
            tiempMin=tiempoTotseg/60.0;
            contLluvTot+=contLluvFecha;    
            cantDias++;
            TotalLlovPer+=totLlov;
            printf("%02d/%02d/%d  %8d  %8d:%02d:%02d  %8.2lf  %8.2lf\n",dia,mes,anho,
                            contLluvFecha,hh, min, seg, totLlov,totLlov/tiempMin );
            
            tiempoTotseg=totLlov=contLluvFecha=0;
            }
            
            ProcesarDatosFecha(durSeg,cantLluv,&contLluvFecha,&tiempoTotseg,&totLlov);
            
            fechaAnt=fecha;
            flag++;
        }
        
        if(feof(archPrec)){
            ddf=dd;
            mmf=mm;
            aaf=aa;
            separarFech(fecha, &anho, &mes, &dia);
            separarTiemp(tiempoTotseg,&hh, &min,&seg);
            tiempMin=tiempoTotseg/(double)60;
            cantDias++;
            contLluvTot+=contLluvFecha;   
            TotalLlovPer+=totLlov;
            printf("%02d/%02d/%d  %8d  %8d:%02d:%02d  %8.2lf  %8.2lf\n",dia,mes,anho,
                contLluvFecha,hh, min, seg, totLlov,totLlov/tiempMin );
            
            break;
        }
    }
    ImprimLin(MAX_LIN, '-');
    printf("Resumen:\n");
    printf("Fecha inicial: %02d/%02d/%d       Fecha Final: %02d/%02d/%d",ddi, mmi, aai, ddf, mmf, aaf);
    printf("Cantidaad total de registros: %d    Cantidad de dias: %d\n",contLluvTot,cantDias );
    printf("Total llovido en el periodo: %.2lf\n",TotalLlovPer);
    ImprimLin(MAX_LIN, '=');
    
    fclose(archPrec);
}

    
int PertRango(int evenI,int evenF,int rangoI,int rangoF){
    
    if(evenI>rangoF || evenF<rangoI ) return 0;
    else return 1;

}

double CalcularCantLlovida(int segI,int segF,int rangI,int rangF, double cantLluv,
                            int* durSeg){
    
    int exced;
    double proporcion;
    int maximo, minimo;
    maximo=max(rangI-segI, 0);
    minimo=minim(rangF-segF,0);
    exced= ((maximo<0) ? maximo*(-1): maximo )+ ((minimo<0) ? minimo*(-1): minimo );
    proporcion=((segF-segI)-exced)/(double)(segF-segI);
    *durSeg=(segF-segI)-exced;
    return proporcion*cantLluv;
}

int max(int a, int b){
    if(a>b) return a;
    else return b;
}

int minim(int a, int b){
    if(a<b) return a;
    else return b;
}

void ImprimLin(int cant, char c){
    for(int i=0; i<cant; i++){
        printf("%c",c);
    }
    printf("\n");
}

void ProcesarDatosFecha(int durSeg,double cantLluv, int *contLluvFecha,
                        int *tiempoTotseg,double *totLlov){
    (*tiempoTotseg)+=durSeg;
    (*totLlov)+=cantLluv;
    (*contLluvFecha)++;
}

void  separarFech(int fechaAnt,int*anho, int*mes, int*dia){
   (*anho)=fechaAnt/10000;
   fechaAnt%=10000;
   (*mes)=fechaAnt/100;
   (*dia)=fechaAnt%100;
}

void separarTiemp(int tiempoTotseg,int*hh, int*min, int*seg){
 (*hh)=tiempoTotseg/3600;
 tiempoTotseg%=3600;
 (*min)=tiempoTotseg/60;
 (*seg)=tiempoTotseg%60;
}