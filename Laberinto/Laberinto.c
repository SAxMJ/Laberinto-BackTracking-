#include <stdio.h>
#include <stdlib.h>


#define N 7

void Laberinto(char (*mSol)[N], int posX, int posY, int *exito);

int main(void){

//TABLERO PROPUESTO, PUEDE MODIFICARSE COMO SE QUIERA
char tablero[N][N]={'+',' ','#','#','#',' ','#',
					'#',' ','#','#','#',' ','#',
					'#',' ','#',' ',' ',' ',' ',
					'#',' ','#',' ','#',' ','#',
					'#',' ','#','#','#',' ','#',
					' ',' ',' ',' ',' ',' ','#',
					' ','#','#',' ','#',' ',' '};

int coordInX=0;
int coordInY=0;

int exito=0;

int i,j;

Laberinto(tablero,coordInX,coordInY,&exito);

	for(i=0; i<N; i++){
		for(j=0; j<N; j++){
			printf("%c",tablero[i][j]);
		}printf("\n");
	}
}


void Laberinto(char (*mSol)[N], int posX, int posY, int *exito){


int movX[4]={1,-1,0,0};
int movY[4]={0,0,1,-1};

int posMov=0;
int u,v;

	
	while(*exito==0 && posMov<4){
	u=posX+movX[posMov];
	v=posY+movY[posMov];

		if(u>=0 && u<N && v>=0 && v<N){

			if(mSol[u][v]==' '){
				mSol[u][v]='+';
				if(u==N-1 && v==N-1){
				*exito=1;
				}else{
				 Laberinto(mSol,u,v,exito);
				 	if(*exito==0){
					mSol[u][v]=' ';
					}
				 }
			}
		}

	posMov++;
	}

}
