#ifndef JUGAR_H_
#define JUGAR_H_
#include "Estructuras.h"

//Cabecera: void Menu_Jugar(Jugador *j);
//Precondicion: recibe el vector de estrcutura con los datos de los jugadores
//Postcondicion: imprime el menu de Jugar y realiza la acción necesaria segun la opcion del usuario
void Menu_Jugar(Jugador *);

//Cabecera:void Libera_Memoria(char ***m,int dim);
//Precondicion: recibe una matriz dinamica reservada y su dimension
//Postcondicion: libera su memoria asignada
void Libera_Memoria(char ***,int );

//Cabecera:void Reserva_Memoria(char ***m,int dim);
//Precondicion:recibe una matriz dinamica sin reservar y su dimension
//Postcondicion:reserva memoria para la matriz
void Reserva_Memoria(char ***,int );

//Cabecera:void inicializar_matriz(char **,int );
//Precondicion: recibe una matriz cuadrada dinamica sin inicializar y su dimensión
//Postcondicion:inicializa las matrices a sus valores nulos antes de colocar los barcos
void inicializar_matriz(char **,int );

//Cabecera:void imprimir_matriz(char **m,int dim);
//Precondicion: recibe una matriz de caracteres inicializada y su dimensión
//Postcondicion: la imprime por pantalla
void imprimir_matriz(char **,int );

//Cabecera: void Reiniciar_Partida(Jugador *j,int dim);
//Precondicion: recibe el vector de estructuras con los datos de ambos jugadores y la dimension de los tableros
//Postcondicion: elimina el nº de disparos, si es ganador o no y resetea los tableros de cada jugador
void Reiniciar_Partida(Jugador *,int );

#endif