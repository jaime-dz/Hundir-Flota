#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "jugar.h"
#include "Estructuras.h"
/*#include "cargar.h"
#include "configuracion.h"
#include "guardar.h"*/
void Menu_Jugar(Jugador *);
void inicializar_matriz(char **,int );
void Libera_Memoria(char ***,int );
void Reserva_Memoria(char ***,int );
void imprimir_matriz(char **,int );
void Resumen(Jugador *);
void Jugar_Partida(Jugador *,int );
void Reiniciar_Partida(Jugador *,int );
int main(){
    int i;
    Jugador j[N_JUG];
    for(i=0;i<N_JUG;i++){
        Reserva_Memoria(&(j[i].Flota),10);
        Reserva_Memoria(&(j[i].Oponente),10);
    }
    for(i=0;i<N_JUG;i++){
        inicializar_matriz(j[i].Flota,10);
        inicializar_matriz(j[i].Oponente,10);
    }
    Menu_Jugar(j);

    for(i=0;i<N_JUG;i++){
        Libera_Memoria(&(j[i].Flota),10);
        Libera_Memoria(&(j[i].Oponente),10);
    }
    
    system("cls");
    return 0;
}
//Cabecera: void Menu_Jugar(Jugador *j);
//Precondicion: recibe el vector de estrcutura con los datos de los jugadores
//Postcondicion: imprime el menu de Jugar y realiza la acción necesaria segun la opcion del usuario
void Menu_Jugar(Jugador *j){
    int opc_menu;
    do{
        printf("-----Jugar partida-----\n\n");
        printf("1.Jugar partida\n");
        printf("2.Reiniciar partida\n");
        printf("3.Resumen\n");
        printf("4.Volver\n");
        printf("->");
        scanf("%d",&opc_menu);
        fflush(stdin);
        switch(opc_menu){
            case 1:
                Jugar_Partida(j,10);
                break;
            case 2:
                Reiniciar_Partida(j,10);
                break;
            case 3:
                Resumen(j);
                break;
            case 4:
                break;
            default:
                system("cls");
                printf("Opcion no valida\n\n");
                break;
        }
    }while(opc_menu!=4);
}
//Cabecera:
//Precondicion: recibe el vector de estructuras con los datos de cada jugador y sus tableros
//Postcondicion: muestra por pantalla el resumen de la partida al acabar esta
void Resumen(Jugador *j){
    int i,m,cont,fila,col;
    printf("           |          Valor de las casillas      |         Barcos        |\n");
    printf("Jugador    |Disparos|Vacias|Agua|Tocadas|Hundidas|Hundidos|Restan|Ganador|\n");
    /*printf("-----------|--------|------|----|-------|--------|--------|------|-------|\n");
    printf("%s   |      %d|    %d|  %d|     %d|      %d|      %d|    %d|     %d|\n",j[1].Nomb_jugador,j[1].Num_disp,,,,,,j[1].Ganador);
    printf("%s   |      %d|    %d|  %d|     %d|      %d|      %d|    %d|     %d|\n",j[2].Nomb_jugador,j[2].Num_disp,,,,,,j[2].Ganador);*/
    printf("\n\n");
    for(i=0;i<N_JUG;i++){
        printf("Jugador %d:     FLOTA                               OPONENTE\n",i+1);
        for(m=0;m<2;m++){
            imprimir_matriz(j[i].Flota,10);
            printf("                ");
            imprimir_matriz(j[i].Oponente,10);
        }
        printf("\n\n");
    }
    system("pause");
    system("cls");
}
//Cabecera: void Reiniciar_Partida(Jugador *j,int dim);
//Precondicion: recibe el vector de estructuras con los datos de ambos jugadores y la dimension de los tableros
//Postcondicion: elimina el nº de disparos, si es ganador o no y resetea los tableros de cada jugador
void Reiniciar_Partida(Jugador *j,int dim){
    int i,p,u;
    for(i=0;i<N_JUG;i++){
        j[i].Num_disp=0;
        j[i].Ganador=0;
        for(p=0;p<dim;p++){
            for(u=0;u<dim;u++){
                j[i].Flota[p][u]='-';
                j[i].Oponente[p][u]='-';
            }
        }
    }
}
//Cabecera:
//Precondicion:
//Postcondicion:
void Jugar_Partida(Jugador *j,int dim){
    int i,k,cont_p=1;
    char op_partida;

    printf("Desea generar los tableros manualmente o de forma aleatoria? (m/a)\n");
    printf("->");
    scanf(" %c",&op_partida);
    switch(op_partida){
        case 'm':
        case 'M':
            printf("Ha seleccionado generar los tableros manualmente\n\n");
            for(i=0;i<N_JUG;i++){
                inicializar_matriz(j[i].Flota,dim);
                inicializar_matriz(j[i].Oponente,dim);
            }
            for(i=0;i<N_JUG; i++){
                printf("Jugador %d - Tablero de Flota\n", i+1);
                imprimir_matriz(j[i].Flota, dim);
                printf("\n");
            
                printf("Jugador %d - Tablero de Oponente\n", i+1);
                imprimir_matriz(j[i].Oponente, dim);
                printf("\n\n");
            }
            break;
        case 'a':
        case 'A':
            break;
        default:
            printf("No es una opcion valida\n\n");
            break;
    }
   
}
//Cabecera:void imprimir_matriz(char **m,int dim);
//Precondicion: recibe una matriz de caracteres inicializada y su dimensión
//Postcondicion: la imprime por pantalla
void imprimir_matriz(char **m,int dim){
    int i,j;
    for(i=0;i<dim;i++){
        for(j=0;j<dim;j++){
            printf("%c",m[i][j]);
        }
        printf("\n");
    }
}
//Cabecera:void Libera_Memoria(char ***m,int dim);
//Precondicion: recibe una matriz dinamica reservada y su dimension
//Postcondicion: libera su memoria asignada
void Libera_Memoria(char ***m,int dim){
    int i;
    for(i=0;i<dim;i++){
        free((*m)[i]);
    }
    free(*m);
    *m=NULL;
}
//Cabecera:void Reserva_Memoria(char ***m,int dim);
//Precondicion:recibe una matriz dinamica sin reservar y su dimension
//Postcondicion:reserva memoria para la matriz
void Reserva_Memoria(char ***m,int dim){
    int i;
    *m=(char**)malloc(dim*sizeof(char*));
    if(*m==NULL){
        printf("Error, no se pudo asignar memoria para las filas\n");
        exit(1);
    }
    for(i=0;i<dim;i++){
        (*m)[i]=(char*)malloc(dim*sizeof(char));
        if((*m)[i]==NULL){
            printf("Error, no se ha podido asignar memoria\n");
            exit(1);
        }
    }
}
//Cabecera:void inicializar_matriz(char **,int );
//Precondicion: recibe una matriz cuadrada dinamica sin inicializar y su dimensión
//Postcondicion:inicializa las matrices a sus valores nulos antes de colocar los barcos
void inicializar_matriz(char **m,int dim){
    int i,j;
    for(i=0;i<dim;i++){
        for(j=0;j<dim;j++){
            m[i][j]='-';
        }
    }
}