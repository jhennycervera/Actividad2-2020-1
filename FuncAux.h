/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FuncAux.h
 * Author: Admin
 *
 * Created on 7 de mayo de 2020, 20:22
 */

#ifndef FUNCAUX_H
void ImprimirRep(int , int );
int PertRango(int ,int ,int ,int );
double CalcularCantLlovida(int ,int ,int ,int , double ,
                            int* );
int max(int a, int b);
int minim(int a, int b);
void ImprimLin(int , char);
void ProcesarDatosFecha(int ,double , int *,
                        int *,double *);
void  separarFech(int ,int*, int*, int*);
void separarTiemp(int ,int*, int*, int*);


#endif /* FUNCAUX_H */

