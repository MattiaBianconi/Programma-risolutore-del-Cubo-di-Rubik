#include <stdio.h>
int cube[6][3][3] = {
    // faccia 0: SOPRA (Giallo)
    {
        {0, 0, 0},
        {0, 0, 0},
        {0, 0, 0}
    },
    // faccia 1: SOTTO (Bianco)
    {
        {1, 1, 1},
        {1, 1, 1},
        {1, 1, 1}
    },
    // faccia 2: DAVANTI (Blu)
    {
        {2, 2, 2},
        {2, 2, 2},
        {2, 2, 2}
    },
    // faccia 3: DIETRO (Verde)
    {
        {3, 3, 3},
        {3, 3, 3},
        {3, 3, 3}
    },
    // faccia 4: SINISTRA (Arancione)
    {
        {4, 4, 4},
        {4, 4, 4},
        {4, 4, 4}
    },
    // faccia 5: DESTRA (Rosso)
    {
        {5, 5, 5},
        {5, 5, 5},
        {5, 5, 5}
    }
};				                      
void insert_cube(){
    const char* nomi_facce[6] = {
        "SUPERIORE (Giallo - 0)",
        "INFERIORE (Bianco - 1)",
        "DAVANTI    (Blu - 2)",
        "DIETRO     (Verde - 3)",
        "SINISTRA   (Arancione - 4)",
        "DESTRA     (Rosso - 5)"
    };
    int f, r, c;
    printf("=== INSERIMENTO COLORI DEL CUBO ===\n");
    printf("Usa i numeri da 0 a 5 per i colori:\n");
    printf("0=Giallo, 1=Bianco, 2=Blu, 3=Verde, 4=Arancione, 5=Rosso\n\n");
    for (f=0;f<6;f++){
        printf("--------------------------------------------------\n");
        printf("Stai inserendo i colori per la faccia: %s\n", nomi_facce[f]);
        printf("Inserisci i quadratini riga per riga (da sinistra a destra, dall'alto in basso):\n");
        printf("--------------------------------------------------\n");
        for (r=0;r<3;r++){
            for (c=0;c<3;c++){
                int colore_inserito = -1;
                while (colore_inserito < 0 || colore_inserito > 5){
                    printf("Quadratino [Riga %d][Colonna %d]: ", r+1, c+1);
                    if (scanf("%d", &colore_inserito) != 1) {
                        while (getchar() != '\n'); 
                        colore_inserito = -1;
                    }
                    if (colore_inserito < 0 || colore_inserito > 5){
                        printf("[ERRORE] Numero non valido! Inserisci un valore compreso tra 0 e 5.\n");
                    }
                }
                cube[f][r][c]=colore_inserito;
            }
        }
        printf("\nFaccia %d completata!\n\n", f);
    }
    printf("==================================================\n");
    printf("CUBO ACQUISITO CON SUCCESSO!\n");
    printf("==================================================\n\n");
}                 
void mossa_F(){  //MOSSA DAVANTI ORARIO (FRONT)---------------------------------------------------------------
 int i, j;
 int temp_face[3][3];
 int temp_cornice[3];
 // ROTAZIONE DELLA FACCIA
 for(i=0;i<3;i++){
	 for(j=0;j<3;j++){
		temp_face[j][2-i]=cube[2][i][j];
	}
 }
 for(i=0;i<3;i++){
	 for(j=0;j<3;j++){
	     cube[2][i][j]=temp_face[i][j];
     }
 }	
    // ROTAZIONE DELLE CORNICI LATERALI
 for(i=0;i<3;i++){
 	temp_cornice[i]=cube[0][2][i];
 }
 for(i=0;i<3;i++){
 	cube[0][2][i]=cube[4][2-i][2];
 }
 for(i=0;i<3;i++){
 	cube[4][2-i][2]=cube[1][0][i];
 }
 for(i=0;i<3;i++){
 	cube[1][0][i]=cube[5][2-i][0];
 }
 for(i=0;i<3;i++){
 	cube[5][i][0]=temp_cornice[i];
 }	
  printf("F ");
}
void mossa_F_S(){  //MOSSA ORARIO senza stampa per F'(FRONT)-----------------------------------------------------------
 int i, j;
 int temp_face[3][3];
 int temp_cornice[3];
 // ROTAZIONE DELLA FACCIA
 for(i=0;i<3;i++){
	 for(j=0;j<3;j++){
		temp_face[j][2-i]=cube[2][i][j];
	}
 }
 for(i=0;i<3;i++){
	 for(j=0;j<3;j++){
	     cube[2][i][j]=temp_face[i][j];
     }
 }	
    // ROTAZIONE DELLE CORNICI LATERALI
 for(i=0;i<3;i++){
 	temp_cornice[i]=cube[0][2][i];
 }
 for(i=0;i<3;i++){
 	cube[0][2][i]=cube[4][2-i][2];
 }
 for(i=0;i<3;i++){
 	cube[4][2-i][2]=cube[1][0][i];
 }
 for(i=0;i<3;i++){
 	cube[1][0][i]=cube[5][2-i][0];
 }
 for(i=0;i<3;i++){
 	cube[5][i][0]=temp_cornice[i];
 }	
}
void mossa_F_primo(){ //MOSSA D'AVANTI ANTIORARIO (F')---------------------------------------------------------
	 mossa_F_S();
	 mossa_F_S();
	 mossa_F_S();
	 printf("F' ");
}
void mossa_B(){ // MOSSA DIETRO ORARIO (BACK)--------------------------------------------------------------------------
	int i,j;
	int temp_face[3][3];
	int temp_cornice[3];
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			temp_face[j][2-i]=cube[3][i][j];
		}
	}
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			cube[3][i][j]=temp_face[i][j];
		}
	}	
	for(i=0;i<3;i++){
		temp_cornice[i]=cube[0][0][2-i];
	}
	for(i=0;i<3;i++){
	    cube[0][0][2-i]=cube[5][2-i][2];	
	}
	for(i=0;i<3;i++){
	    cube[5][2-i][2]=cube[1][2][i];	
	}	
	for(i=0;i<3;i++){
	    cube[1][2][i]=cube[4][i][0];	
	}		
	for(i=0;i<3;i++){
	    cube[4][i][0]=temp_cornice[i];	
	}	
	printf("B ");
}
void mossa_B_S(){ // mossa orario senza stampa(da mettere in B') (BACK)------------------------------------------------
	int i,j;
	int temp_face[3][3];
	int temp_cornice[3];
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			temp_face[j][2-i]=cube[3][i][j];
		}
	}
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			cube[3][i][j]=temp_face[i][j];
		}
	}	
	for(i=0;i<3;i++){
		temp_cornice[i]=cube[0][0][2-i];
	}
	for(i=0;i<3;i++){
	    cube[0][0][2-i]=cube[5][2-i][2];	
	}
	for(i=0;i<3;i++){
	    cube[5][2-i][2]=cube[1][2][i];	
	}	
	for(i=0;i<3;i++){
	    cube[1][2][i]=cube[4][i][0];	
	}		
	for(i=0;i<3;i++){
	    cube[4][i][0]=temp_cornice[i];	
	}	
}
void mossa_B_primo(){ //MOSSA DIETRO ANTIORARIO (B')------------------------------------------------------------------
	mossa_B_S();
	mossa_B_S();
	mossa_B_S();
	printf("B' ");
}
void mossa_R(){ //MOSSA DESTRA ORARIO (RIGHT)-------------------------------------------------------------------------
	int i,j;
	int temp_face[3][3];
	int temp_cornice[3];
	// ROTAZIONE FACCIA ROSSA
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			temp_face[j][2-i]=cube[5][i][j];
		}
	}
	for(i=0;i<3;i++){
	    for(j=0;j<3;j++){
		    cube[5][i][j]=temp_face[i][j];
	    }
    }
    // ROTAZIONE CORNICE 
    for(i=0;i<3;i++){
    	temp_cornice[i]=cube[0][i][2];
	}
    for(i=0;i<3;i++){
    	cube[0][i][2]=cube[2][i][2];
	}	
    for(i=0;i<3;i++){
    	cube[2][i][2]=cube[1][i][2];
	}	
    for(i=0;i<3;i++){
    	cube[1][i][2]=cube[3][2-i][0];
	}	
    for(i=0;i<3;i++){
    	cube[3][2-i][0]=temp_cornice[i];
	}
	printf("R ");	
}
void mossa_R_S(){
	int i,j;
	int temp_face[3][3];
	int temp_cornice[3];
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			temp_face[j][2-i]=cube[5][i][j];
		}
	}
	for(i=0;i<3;i++){
	    for(j=0;j<3;j++){
		    cube[5][i][j]=temp_face[i][j];
	    }
    }
    for(i=0;i<3;i++){
    	temp_cornice[i]=cube[0][i][2];
	}
    for(i=0;i<3;i++){
    	cube[0][i][2]=cube[2][i][2];
	}	
    for(i=0;i<3;i++){
    	cube[2][i][2]=cube[1][i][2];
	}	
    for(i=0;i<3;i++){
    	cube[1][i][2]=cube[3][2-i][0];
	}	
    for(i=0;i<3;i++){
    	cube[3][2-i][0]=temp_cornice[i];
	}
}
void mossa_R_primo(){ //MOSSA DESTRA ANTIORARIO (R')------------------------------------------------------------------
	 mossa_R_S();
	 mossa_R_S();
	 mossa_R_S();
	 printf("R' ");
}
void mossa_L(){ //MOSSA SINISTRA ORARIO (LEFT)------------------------------------------------------------------------
	int i, j;
	int temp_face[3][3];
	int temp_cornice[3];
	// ROTAZIONE FACCIA DI SINISTRA
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			temp_face[j][2-i]=cube[4][i][j];
		}
	}
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
		   cube[4][i][j]=temp_face[i][j];	
		}
	}
	// ROTAZIONE CORNICE
	for(i=0;i<3;i++){
		temp_cornice[i]=cube[0][i][0];
	}
	for(i=0;i<3;i++){
		cube[0][i][0]=cube[3][2-i][2];
	}	
	for(i=0;i<3;i++){
		cube[3][i][2]=cube[1][2-i][0];
	}	
	for(i=0;i<3;i++){
		cube[1][i][0]=cube[2][i][0];
	}	
	for(i=0;i<3;i++){
		cube[2][i][0]=temp_cornice[i];
	}
	printf("L ");
}
void mossa_L_S(){
	int i, j;
	int temp_face[3][3];
	int temp_cornice[3];
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			temp_face[j][2-i]=cube[4][i][j];
		}
	}
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
		   cube[4][i][j]=temp_face[i][j];	
		}
	}
	for(i=0;i<3;i++){
		temp_cornice[i]=cube[0][i][0];
	}
	for(i=0;i<3;i++){
		cube[0][i][0]=cube[3][2-i][2];
	}	
	for(i=0;i<3;i++){
		cube[3][i][2]=cube[1][2-i][0];
	}	
	for(i=0;i<3;i++){
		cube[1][i][0]=cube[2][i][0];
	}	
	for(i=0;i<3;i++){
		cube[2][i][0]=temp_cornice[i];
	}
}
void mossa_L_primo(){ // MOSSA SINISTRA ANTIORARIO (L')---------------------------------------------------------------
	 mossa_L_S();
	 mossa_L_S();
	 mossa_L_S();
	 printf("L' ");
}
void mossa_U(){ // MOSSA SU ORARIO (UP)-------------------------------------------------------------------------------
	int i,j;
	int temp_face[3][3];
	int temp_cornice[3];
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			temp_face[j][2-i]=cube[0][i][j];
		}
	}
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			cube[0][i][j]=temp_face[i][j];
		}
	}
	for(i=0;i<3;i++){
		temp_cornice[i]=cube[2][0][i];
	}	
	for(i=0;i<3;i++){
		cube[2][0][i]=cube[5][0][i];
	}	
	for(i=0;i<3;i++){
		cube[5][0][i]=cube[3][0][i];
	}	
	for(i=0;i<3;i++){
		cube[3][0][i]=cube[4][0][i];
	}	
	for(i=0;i<3;i++){
		cube[4][0][i]=temp_cornice[i];
	}	
	printf("U ");
}
void mossa_U_S(){ 
	int i,j;
	int temp_face[3][3];
	int temp_cornice[3];
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			temp_face[j][2-i]=cube[0][i][j];
		}
	}
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			cube[0][i][j]=temp_face[i][j];
		}
	}
	for(i=0;i<3;i++){
		temp_cornice[i]=cube[2][0][i];
	}	
	for(i=0;i<3;i++){
		cube[2][0][i]=cube[5][0][i];
	}	
	for(i=0;i<3;i++){
		cube[5][0][i]=cube[3][0][i];
	}	
	for(i=0;i<3;i++){
		cube[3][0][i]=cube[4][0][i];
	}	
	for(i=0;i<3;i++){
		cube[4][0][i]=temp_cornice[i];
	}	
}
void mossa_U_primo(){
	mossa_U_S();
	mossa_U_S();
	mossa_U_S();
	printf("U' ");
}
void mossa_D(){ // MOSSA DOWN ORARIO (D)------------------------------------------------------------------------------
	int i,j;
	int temp_face[3][3];
	int temp_cornice[3];
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			temp_face[j][2-i]=cube[1][i][j];
		}
	}
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			cube[1][i][j]=temp_face[i][j];
		}
	}
	for(i=0;i<3;i++){
		temp_cornice[i]=cube[2][2][i];
	}		
	for(i=0;i<3;i++){
		cube[2][2][i]=cube[4][2][i];
	}
	for(i=0;i<3;i++){
		cube[4][2][i]=cube[3][2][i];
	}	
	for(i=0;i<3;i++){
		cube[3][2][i]=cube[5][2][i];
	}	
	for(i=0;i<3;i++){
		cube[5][2][i]=temp_cornice[i];
	}		
	printf("D ");	
}
void mossa_D_S(){
	int i,j;
	int temp_face[3][3];
	int temp_cornice[3];
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			temp_face[j][2-i]=cube[1][i][j];
		}
	}
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			cube[1][i][j]=temp_face[i][j];
		}
	}
	for(i=0;i<3;i++){
		temp_cornice[i]=cube[2][2][i];
	}		
	for(i=0;i<3;i++){
		cube[2][2][i]=cube[4][2][i];
	}
	for(i=0;i<3;i++){
		cube[4][2][i]=cube[3][2][i];
	}	
	for(i=0;i<3;i++){
		cube[3][2][i]=cube[5][2][i];
	}	
	for(i=0;i<3;i++){
		cube[5][2][i]=temp_cornice[i];
	}		
}
void mossa_D_primo(){ // MOSSA GIU' ANTIORARIO (D')-------------------------------------------------------------------
	mossa_D_S();
	mossa_D_S();
	mossa_D_S();
	printf("D' ");
}
void sm_blue(){ // MOSSA SEXYMOVE (sulla faccia blu) (primo algoritmo) (R U R' U')_____________________________________
	mossa_R();
	mossa_U();
	mossa_R_primo();
	mossa_U_primo();
}
void sm_red(){ // MOSSA SEXYMOVE (sulla faccia rossa) (primo algoritmo)
	mossa_B();
	mossa_U();
	mossa_B_primo();
	mossa_U_primo();
}
void sm_green(){ // MOSSA SEXYMOVE (sulla faccia verde) (primo algoritmo)
	mossa_L();
	mossa_U();
	mossa_L_primo();
	mossa_U_primo();
}
void sm_orange(){ // MOSSA SEXYMOVE (sulla faccia arancione) (primo algoritmo)
	mossa_F();
	mossa_U();
	mossa_F_primo();
	mossa_U_primo();
}

void antism_blue(){ // MOSSA ANTISEXYMOVE (sulla faccia blu)(L' U' L U)_____________________________________
	mossa_L_primo();
	mossa_U_primo();
	mossa_L();
	mossa_U();
}
void antism_red(){ // MOSSA ANTISEXYMOVE (sulla faccia rossa)
	mossa_F_primo();
	mossa_U_primo();
	mossa_F();		
	mossa_U();
}
void antism_green(){ // MOSSA ANTISEXYMOVE (sulla faccia verde)
	mossa_R_primo();
	mossa_U_primo();
	mossa_R();
	mossa_U();
}
void antism_orange(){ // MOSSA ANTISEXYMOVE (sulla faccia arancione)
	mossa_B_primo();
	mossa_U_primo();
	mossa_B();
	mossa_U();
}
void sune_blue(){ // algoritmo sune (sulla faccia blu) _____________________________________________________________
	mossa_R();
	mossa_U();
	mossa_R_primo();
	mossa_U();
	mossa_R();
	mossa_U_primo();
	mossa_U_primo();
	mossa_R_primo();
	mossa_U();	
}
void sune_red(){ // algoritmo sune (sulla faccia rossa) 
	mossa_B();
	mossa_U();
	mossa_B_primo();           
	mossa_U();
	mossa_B();
	mossa_U_primo();
	mossa_U_primo();
	mossa_B_primo();
	mossa_U();
}
void sune_green(){ // algoritmo sune (sulla faccia verde) 
	mossa_L();
	mossa_U();
	mossa_L_primo();
	mossa_U();
	mossa_L();
	mossa_U_primo();
	mossa_U_primo();
	mossa_L_primo();
	mossa_U();
}
void sune_orange(){ // algoritmo sune (sulla faccia arancione) 
	mossa_F();
	mossa_U();
	mossa_F_primo();
	mossa_U();
	mossa_F();
	mossa_U_primo();
	mossa_U_primo();
	mossa_F_primo();
	mossa_U();	
}
void niklas_blue(){ // algoritmo niklas (faccia blu)________________________________________________________________________
	mossa_R();
	mossa_U_primo();	
	mossa_L_primo();
	mossa_U();	
	mossa_R_primo();	
	mossa_U_primo();
	mossa_L();		
	mossa_U();		
}
void niklas_red(){ // algoritmo niklas (faccia rossa)
	mossa_B();
	mossa_U_primo();	
	mossa_F_primo();
	mossa_U();	
	mossa_B_primo();	
	mossa_U_primo();
	mossa_F();		
	mossa_U();		
}
void niklas_green(){ // algoritmo niklas (faccia verde)
	mossa_L();
	mossa_U_primo();	
	mossa_R_primo();
	mossa_U();	
	mossa_L_primo();	
	mossa_U_primo();
	mossa_R();		
	mossa_U();		
}
void niklas_orange(){ // algoritmo niklas (faccia arancione)
	mossa_F();
	mossa_U_primo();	
	mossa_B_primo();
	mossa_U();	
	mossa_F_primo();	
	mossa_U_primo();
	mossa_B();		
	mossa_U();		
}
void upsidedown_sm_blue(){ // sexy move con il cubo capovolto (ultimo step di risoluzione)(FACCIA BLU)______________________
	mossa_L();
	mossa_D();
	mossa_L_primo();
	mossa_D_primo();
}
void upsidedown_sm_red(){ // sexy move con il cubo capovolto (FACCIA ROSSA)
	mossa_F();
	mossa_D();
	mossa_F_primo();
	mossa_D_primo();
}
void upsidedown_sm_green(){ // sexy move con il cubo capovolto (FACCIA VERDE)
	mossa_R();
	mossa_D();
	mossa_R_primo();
	mossa_D_primo();
}
void upsidedown_sm_orange(){ // sexy move con il cubo capovolto (FACCIA ARANCIONE)
	mossa_B();
	mossa_D();
	mossa_B_primo();
	mossa_D_primo();
}
void unlock_edge_br(){ // algoritmo per sbloccare un spigolo centrale nel posto giusto ma al contrario  
     mossa_R();
     mossa_R();
	 mossa_U();
	 mossa_U();
	 mossa_F();
	 mossa_R();
	 mossa_R();
	 mossa_F_primo();
	 mossa_U();
	 mossa_U();
	 mossa_R_primo();
	 mossa_U();
	 mossa_R_primo();     
}
void unlock_edge_rg(){
	 mossa_B();
	 mossa_B();
	 mossa_U();
	 mossa_U();
	 mossa_R();
	 mossa_B();
	 mossa_B();
	 mossa_R_primo();
	 mossa_U();
	 mossa_U();
	 mossa_B_primo();
	 mossa_U();
	 mossa_B_primo();
}
void unlock_edge_go(){
	 mossa_L();
	 mossa_L();
	 mossa_U();
	 mossa_U();
	 mossa_B();
	 mossa_L();
	 mossa_L();
	 mossa_B_primo();
	 mossa_U();
	 mossa_U();
	 mossa_L_primo();
	 mossa_U();
	 mossa_L_primo();
}     
void unlock_edge_ob(){
	 mossa_F();
	 mossa_F();
	 mossa_U();
	 mossa_U();
	 mossa_L();
	 mossa_F();
	 mossa_F();
	 mossa_L_primo();
	 mossa_U();
	 mossa_U();
	 mossa_F_primo();
	 mossa_U();
	 mossa_F_primo();
	
}
void solve_w_blue(){ // RISOLUZIONE SPIGOLO BIANCO-BLU
    if(cube[2][2][1]==2 && cube[1][0][1]==1){ //spigoli di sotto
		return;
	}
	if(cube[2][2][1]==1 && cube[1][0][1]==2){
		     mossa_F_primo();
		     mossa_R_primo();
		     mossa_D_primo(); 
	}else if(cube[4][2][1]==1 && cube[1][1][0]==2){
		     mossa_L_primo();
		     mossa_F_primo();
	}else if(cube[4][2][1]==2 && cube[1][1][0]==1){
		     mossa_D();
	}else if(cube[3][2][1]==2 && cube[1][2][1]==1){
		     mossa_D();
		     mossa_D();
	}else if(cube[3][2][1]==1 && cube[1][2][1]==2){
		     mossa_B();
		     mossa_R();
		     mossa_D_primo();
    }else if(cube[5][2][1]==2 && cube[1][1][2]==1){
		     mossa_D_primo();
    }else if(cube[5][2][1]==1 && cube[1][1][2]==2){
		     mossa_R();
		     mossa_F();
	}else if(cube[2][1][0]==1 && cube[4][1][2]==2){ //spigoli nel mezzo
		     mossa_L();
		     mossa_D();
	}else if(cube[2][1][0]==2 && cube[4][1][2]==1){
		     mossa_F_primo();
    }else if(cube [2][1][2]==2 && cube[5][1][0]==1){
    	     mossa_F();
	}else if(cube [2][1][2]==1 && cube[5][1][0]==2){
     	     mossa_R_primo();
        	 mossa_D_primo();
    }else if(cube[5][1][2]==2 && cube[3][1][0]==1){
             mossa_R();
             mossa_D_primo();
    }else if(cube[5][1][2]==1 && cube[3][1][0]==2){
    	     mossa_B_primo();
    	     mossa_D();
    	     mossa_D();
	}else if(cube[3][1][2]==1 && cube[4][1][0]==2){
		     mossa_L_primo();
		     mossa_D();
	}else if(cube[3][1][2]==2 && cube[4][1][0]==1){
		     mossa_B();
    	     mossa_D();
    	     mossa_D();		     
    }else if(cube[2][0][1]==2 && cube[0][2][1]==1){ // spigoli di sopra
        	 mossa_F();
        	 mossa_F();
	}else if(cube[2][0][1]==1 && cube[0][2][1]==2){
        	 mossa_F();
        	 mossa_R_primo();
        	 mossa_D_primo();
	}else if(cube[4][0][1]==1 && cube[0][1][0]==2){
		     mossa_L();
		     mossa_F_primo();
	}else if(cube[4][0][1]==2 && cube[0][1][0]==1){
		     mossa_L();
		     mossa_L();
		     mossa_D();
	}else if(cube[3][0][1]==2 && cube[0][0][1]==1){
		     mossa_B();
		     mossa_B();
		     mossa_D();
		     mossa_D();
	}else if(cube[3][0][1]==1 && cube[0][0][1]==2){
		     mossa_B();
		     mossa_L_primo();
		     mossa_D();
	}else if(cube[5][0][1]==2 && cube[0][1][2]==1){
		     mossa_R();
		     mossa_R();
		     mossa_D_primo();
    }else if(cube[5][0][1]==1 && cube[0][1][2]==2){
		     mossa_R_primo();
		     mossa_F();
    } 
}
void solve_w_red(){ // RISOLUZIONE SPIGOLO BIANCO-ROSSO
    if(cube[5][2][1]==5 && cube[1][1][2]==1){ // spigoli di sotto
		return;
	}else if(cube[5][2][1]==1 && cube[1][1][2]==5){
		mossa_R();
		mossa_D_primo();
		mossa_F();
		mossa_D();
	}else if(cube[3][2][1]==5 && cube[1][2][1]==1){
		mossa_B();
		mossa_D();
		mossa_B_primo();
		mossa_D_primo();
	}else if(cube[3][2][1]==1 && cube[1][2][1]==5){
		mossa_B();
		mossa_R();
	}else if(cube[4][2][1]==5 && cube[1][1][0]==1){
		mossa_L();
		mossa_L();
		mossa_U();
		mossa_U();
		mossa_R();
		mossa_R();
	}else if(cube[4][2][1]==1 && cube[1][1][0]==5){
		mossa_L_primo();
		mossa_D_primo();
		mossa_F_primo();
		mossa_D();
	}else if(cube[2][1][2]==1 && cube[5][1][0]==5){ //spigoli nel mezzo
		mossa_R_primo();
	}else if(cube[2][1][2]==5 && cube[5][1][0]==1){
		mossa_D_primo();
		mossa_F();
		mossa_D();
	}else if(cube[5][1][2]==5 && cube[3][1][0]==1){ 
		mossa_R();
	}else if(cube[5][1][2]==1 && cube[3][1][0]==5){ 
		mossa_D();
		mossa_B_primo();
		mossa_D_primo();
	}else if(cube[3][1][2]==5 && cube[4][1][0]==1){
		mossa_D();
		mossa_B();
		mossa_D_primo();
	}else if(cube[3][1][2]==1 && cube[4][1][0]==5){ 
		mossa_D();
		mossa_D();
		mossa_L_primo();
		mossa_D();
		mossa_D();
	}else if(cube[4][1][2]==1 && cube[2][1][0]==5){
		mossa_D_primo();
		mossa_F_primo();
		mossa_D();
	}else if(cube[4][1][2]==5 && cube[2][1][0]==1){
		mossa_D();
		mossa_D();
		mossa_L();
		mossa_D();
		mossa_D();
	}else if(cube[2][0][1]==5 && cube[0][2][1]==1){  // spigoli di sopra
		mossa_U_primo();
		mossa_R();
		mossa_R();
	}else if(cube[2][0][1]==1 && cube[0][2][1]==5){
		mossa_D_primo();
		mossa_F();
		mossa_D();
		mossa_R_primo();		
	}else if(cube[5][0][1]==5 && cube[0][1][2]==1){
		mossa_R();
		mossa_R();	
	}else if(cube[5][0][1]==1 && cube[0][1][2]==5){
		mossa_R_primo();
		mossa_D_primo();
		mossa_F();
		mossa_D();  	
	}else if(cube[3][0][1]==5 && cube[0][0][1]==1){
		mossa_U();
		mossa_R();
		mossa_R();
	}else if(cube[3][0][1]==1 && cube[0][0][1]==5){
		mossa_B_primo();
		mossa_R();
	}else if(cube[4][0][1]==5 && cube[0][1][0]==1){
		mossa_U();
		mossa_U();
		mossa_R();
		mossa_R();
	}else if(cube[4][0][1]==1 && cube[0][1][0]==5){
		mossa_L();
		mossa_D_primo();
		mossa_F_primo();
		mossa_D();
    }
}
void solve_w_green(){ // RISOLUZIONE SPIGOLO BIANCO-VERDE
    if(cube[3][2][1]==3 && cube[1][2][1]==1){ // spigoli di sotto
		return;
	}else if(cube[3][2][1]==1 && cube[1][2][1]==3){
		mossa_B();
		mossa_D_primo();
		mossa_R();
		mossa_D();
	}else if(cube[4][2][1]==3 && cube[1][1][0]==1){
		mossa_L_primo();
		mossa_D();
		mossa_L();
		mossa_D_primo();
	}else if(cube[4][2][1]==1 && cube[1][1][0]==3){
		mossa_L();
		mossa_B();
	}else if(cube[2][1][2]==3 && cube[5][1][0]==1){ // spigoli nel mezzo
		mossa_D();
		mossa_D();
		mossa_F();
		mossa_D();
		mossa_D();
	}else if(cube[2][1][2]==1 && cube[5][1][0]==3){
		mossa_D_primo();
		mossa_R_primo();
		mossa_D();
	}else if(cube[5][1][2]==3 && cube[3][1][0]==1){
		mossa_D_primo();
		mossa_R();
		mossa_D();
	}else if(cube[5][1][2]==1 && cube[3][1][0]==3){
		mossa_B_primo();
	}else if(cube[3][1][2]==3 && cube[4][1][0]==1){
		mossa_B();
	}else if(cube[3][1][2]==1 && cube[4][1][0]==3){
		mossa_D();
		mossa_L_primo();
		mossa_D_primo();
	}else if(cube[4][1][2]==3 && cube[2][1][0]==1){
		mossa_D();
		mossa_L();
		mossa_D_primo();
	}else if(cube[4][1][2]==1 && cube[2][1][0]==3){
		mossa_D();
		mossa_D();
		mossa_F_primo();
		mossa_D();
		mossa_D();
	}else if(cube[2][0][1]==3 && cube[0][2][1]==1){ // spigoli di sopra
		mossa_U();
		mossa_U();
		mossa_B();
		mossa_B();
	}else if(cube[2][0][1]==1 && cube[0][2][1]==3){
		mossa_U();
		mossa_U();
		mossa_B();
		mossa_D();
		mossa_L_primo();
		mossa_D_primo();
	}else if(cube[5][0][1]==3 && cube[0][1][2]==1){
		mossa_U_primo();
		mossa_B();
		mossa_B();
	}else if(cube[5][0][1]==1 && cube[0][1][2]==3){
		mossa_D_primo();
		mossa_R();
		mossa_D();
		mossa_B_primo();
	}else if(cube[3][0][1]==3 && cube[0][0][1]==1){
		mossa_B();
		mossa_B();
	}else if(cube[3][0][1]==1 && cube[0][0][1]==3){
		mossa_B();
		mossa_D();
		mossa_L_primo();
		mossa_D_primo();
	}else if(cube[4][0][1]==3 && cube[0][1][0]==1){
        mossa_U();
		mossa_B();
		mossa_B();
	}else if(cube[4][0][1]==1 && cube[0][1][0]==3){
        mossa_L_primo();
		mossa_B();
	}
}
void solve_w_orange(){ // RISOLUZIONE SPIGOLO BIANCO-ARANCIONE
    if(cube[4][2][1]==4 && cube[1][1][0]==1){ // spigoli di sotto
		return;
	}else if(cube[4][2][1]==1 && cube[1][1][0]==4){
		mossa_L_primo();
		mossa_D();
		mossa_F_primo();
		mossa_D_primo();
	}else if(cube[2][1][2]==4 && cube[5][1][0]==1){  //spigoli nel mezzo
		mossa_D();
		mossa_F();
		mossa_D_primo();
	}else if(cube[2][1][2]==1 && cube[5][1][0]==4){ 
		mossa_D();
		mossa_D();
		mossa_R_primo();
		mossa_D();
		mossa_D();
	}else if(cube[5][1][2]==4 && cube[3][1][0]==1){ 
		mossa_D();
		mossa_D();
		mossa_R();
		mossa_D();
		mossa_D();	
	}else if(cube[5][1][2]==1 && cube[3][1][0]==4){
		mossa_D_primo();
		mossa_B_primo();
		mossa_D();	
	}else if(cube[3][1][2]==4 && cube[4][1][0]==1){
		mossa_D_primo();
		mossa_B();
		mossa_D();	
	}else if(cube[3][1][2]==1 && cube[4][1][0]==4){
		mossa_L_primo();
	}else if(cube[4][1][2]==4 && cube[2][1][0]==1){
		mossa_L();
	}else if(cube[4][1][2]==1 && cube[2][1][0]==4){
		mossa_D();
		mossa_F_primo();
		mossa_D_primo();
	}else if(cube[2][0][1]==4 && cube[0][2][1]==1){  // spigoli di sopra
		mossa_U();
		mossa_L();
		mossa_L();
	}else if(cube[2][0][1]==1 && cube[0][2][1]==4){
		mossa_U();
		mossa_L();
		mossa_D();
		mossa_F_primo();
		mossa_D_primo();
	}else if(cube[5][0][1]==4 && cube[0][1][2]==1){
		mossa_U();
		mossa_U();
		mossa_L();
		mossa_L();
	}else if(cube[5][0][1]==1 && cube[0][1][2]==4){
		mossa_U();
		mossa_U();
		mossa_L();
		mossa_D();
		mossa_F_primo();
		mossa_D_primo();
	}else if(cube[3][0][1]==4 && cube[0][0][1]==1){
		mossa_U_primo();
		mossa_L();
		mossa_L();
	}else if(cube[3][0][1]==1 && cube[0][0][1]==4){
		mossa_U_primo();
		mossa_L();
		mossa_D();
		mossa_F_primo();
		mossa_D_primo();
	}else if(cube[4][0][1]==4 && cube[0][1][0]==1){
		mossa_L();
		mossa_L();
	}else if(cube[4][0][1]==1 && cube[0][1][0]==4){
		mossa_L();
		mossa_D();
		mossa_F_primo();
		mossa_D_primo();
	}
}
void solve_white_cross(){
	solve_w_blue();
	solve_w_red();
	solve_w_green();
	solve_w_orange();
}
void solve_corner_brw(){ // risolvi angolo brw(blue, red and white) 
     if(cube[2][2][2]==2 && cube[5][2][0]==5 && cube[1][0][2]==1){ // CASI ANGOLO SOTTO
     	return;
	 }else if(cube[2][2][2]==1 && cube[5][2][0]==2 && cube[1][0][2]==5){
     	antism_red();
     	antism_red();
	 }else if(cube[2][2][2]==5 && cube[5][2][0]==1 && cube[1][0][2]==2){
     	sm_blue();
     	sm_blue();
	 }else if(cube[5][2][2]==2 && cube[3][2][0]==5 && cube[1][2][2]==1){
     	sm_red();
     	mossa_U();
     	antism_red();
	 }else if(cube[5][2][2]==1 && cube[3][2][0]==2 && cube[1][2][2]==5){
     	antism_green();
     	mossa_U();
     	antism_red();
	 }else if(cube[5][2][2]==5 && cube[3][2][0]==1 && cube[1][2][2]==2){
     	sm_red();
     	mossa_U();
     	sm_blue();
	 }else if(cube[3][2][2]==2 && cube[4][2][0]==5 && cube[1][2][0]==1){
     	sm_green();
     	mossa_U();
     	mossa_U();     	
     	sm_red();
	 }else if(cube[3][2][2]==5 && cube[4][2][0]==1 && cube[1][2][0]==2){
     	sm_green();
     	mossa_U();
     	mossa_U();     	
     	sm_blue();
     }else if(cube[3][2][2]==1 && cube[4][2][0]==2 && cube[1][2][0]==5){
     	antism_orange();
     	mossa_U();
     	mossa_U();     	
     	antism_red();
	 }else if(cube[4][2][2]==2 && cube[2][2][0]==5 && cube[1][0][0]==1){
     	antism_blue();
     	mossa_U_primo();    	
     	sm_blue();
	 }else if(cube[4][2][2]==1 && cube[2][2][0]==2 && cube[1][0][0]==5){
     	antism_blue();
     	mossa_U_primo();    	
     	antism_red();
	 }else if(cube[4][2][2]==5 && cube[2][2][0]==1 && cube[1][0][0]==2){
     	sm_orange();
     	mossa_U_primo();    	
     	sm_blue();
	 }else if(cube[2][0][2]==2 && cube[0][2][2]==5 && cube[5][0][0]==1){ // CASI ANGOLO SOPRA
	    sm_blue();	
	 }else if(cube[2][0][2]==1 && cube[0][2][2]==2 && cube[5][0][0]==5){
	    antism_red();	
	 }else if(cube[2][0][2]==5 && cube[0][2][2]==1 && cube[5][0][0]==2){
	    sm_blue();	
	    sm_blue();
	    sm_blue();
	 }else if(cube[5][0][2]==2 && cube[0][0][2]==5 && cube[3][0][0]==1){
	 	mossa_U();
	    sm_blue();	
	 }else if(cube[5][0][2]==1 && cube[0][0][2]==2 && cube[3][0][0]==5){
	 	mossa_U();
	    antism_red();	
	 }else if(cube[5][0][2]==2 && cube[0][0][2]==5 && cube[3][0][0]==1){
	 	mossa_U();
	    sm_blue();	
	    sm_blue();
	    sm_blue();	
	 }else if(cube[3][0][2]==2 && cube[0][0][0]==5 && cube[4][0][0]==1){
	 	mossa_U();
	 	mossa_U();
	    sm_blue();	
	 }else if(cube[3][0][2]==1 && cube[0][0][0]==2 && cube[4][0][0]==5){
	 	mossa_U();
	 	mossa_U();
	    antism_red();	
	 }else if(cube[3][0][2]==5 && cube[0][0][0]==1 && cube[4][0][0]==2){
	 	mossa_U();
	 	mossa_U();
	    sm_blue();	
	    sm_blue();
	    sm_blue();
	 }else if(cube[4][0][2]==2 && cube[0][2][0]==5 && cube[2][0][0]==1){
	 	mossa_U_primo();
	    sm_blue();	
	 }else if(cube[4][0][2]==1 && cube[0][2][0]==2 && cube[2][0][0]==5){
	 	mossa_U_primo();
	    antism_red();	
	 }else if(cube[4][0][2]==5 && cube[0][2][0]==1 && cube[2][0][0]==2){
	 	mossa_U_primo();
	    sm_blue();	
	    sm_blue();
	    sm_blue();	
	 }
}
void solve_corner_rgw(){ // risolvi angolo rgw(red, green and white)
     if(cube[5][2][2]==5 && cube[3][2][0]==3 && cube[1][2][2]==1){ //CASI ANGOLO SOTTO
     	return;
	 }else if(cube[5][2][2]==1 && cube[3][2][0]==5 && cube[1][2][2]==3){
     	antism_green();
     	antism_green();
	 }else if(cube[5][2][2]==3 && cube[3][2][0]==1 && cube[1][2][2]==5){
     	sm_red();
     	sm_red();
	 }else if(cube[3][2][2]==5 && cube[4][2][0]==3 && cube[1][2][0]==1){
	 	sm_green();
	 	mossa_U();
	 	antism_green();
	 }else if(cube[3][2][2]==1 && cube[4][2][0]==5 && cube[1][2][0]==3){
	 	antism_orange();
	 	mossa_U();
	 	antism_green();
	 }else if(cube[3][2][2]==3 && cube[4][2][0]==1 && cube[1][2][0]==5){
        sm_green();
	 	mossa_U();
	 	sm_red();
	 }else if(cube[4][2][2]==5 && cube[2][2][0]==3 && cube[1][0][0]==1){
	 	antism_blue();
	 	mossa_U();
	 	mossa_U();
	 	sm_red();
	 }else if(cube[4][2][2]==1 && cube[2][2][0]==5 && cube[1][0][0]==3){
	 	antism_blue();
	 	mossa_U();
	 	mossa_U();
	 	antism_green();
	 }else if(cube[4][2][2]==3 && cube[2][2][0]==1 && cube[1][0][0]==5){
	 	sm_orange();
	 	mossa_U();
	 	mossa_U();
	 	sm_red();
	 }else if(cube[2][0][2]==5 && cube[0][2][2]==3 && cube[5][0][0]==1){ // CASI ANGOLO SOPRA
	    mossa_U_primo();
	    sm_red();
	 }else if(cube[2][0][2]==1 && cube[0][2][2]==5 && cube[5][0][0]==3){
	    mossa_U_primo();
	    antism_green();
	 }else if(cube[2][0][2]==3 && cube[0][2][2]==1 && cube[5][0][0]==5){
	    mossa_U_primo();
	    sm_red();
	    sm_red();
	    sm_red();
	 }else if(cube[5][0][2]==5 && cube[0][0][2]==3 && cube[3][0][0]==1){
	    sm_red();
	 }else if(cube[5][0][2]==1 && cube[0][0][2]==5 && cube[3][0][0]==3){
	    antism_green();
	 }else if(cube[5][0][2]==3 && cube[0][0][2]==1 && cube[3][0][0]==5){
	    sm_red();
	    sm_red();
	    sm_red();
	 }else if(cube[3][0][2]==5 && cube[0][0][0]==3 && cube[4][0][0]==1){
	 	mossa_U();
	    sm_red();
	 }else if(cube[3][0][2]==1 && cube[0][0][0]==5 && cube[4][0][0]==3){
	 	mossa_U();
	    antism_green();
	 }else if(cube[3][0][2]==3 && cube[0][0][0]==1 && cube[4][0][0]==5){
	 	mossa_U();
	    sm_red();
	    sm_red();
	    sm_red();
	 }else if(cube[4][0][2]==5 && cube[0][2][0]==3 && cube[2][0][0]==1){
	 	mossa_U();
	 	mossa_U();
	    sm_red();
	 }else if(cube[4][0][2]==1 && cube[0][2][0]==5 && cube[2][0][0]==3){
	 	mossa_U();
	 	mossa_U();
	    antism_green();
	 }else if(cube[4][0][2]==3 && cube[0][2][0]==1 && cube[2][0][0]==5){
	 	mossa_U();
	 	mossa_U();
	    sm_red();
	    sm_red();
	    sm_red();
	 }
}
void solve_corner_gow(){ // risolvi angolo gow(green, orange and white)
     if(cube[3][2][2]==3 && cube[4][2][0]==4 && cube[1][2][0]==1){ //CASI ANGOLO SOTTO
     	return;
	 }else if(cube[3][2][2]==1 && cube[4][2][0]==3 && cube[1][2][0]==4){
     	antism_orange();
     	antism_orange();
	 }else if(cube[3][2][2]==4 && cube[4][2][0]==1 && cube[1][2][0]==3){
     	sm_green();
     	sm_green();
	 }else if(cube[4][2][2]==3 && cube[2][2][0]==4 && cube[1][0][0]==1){
     	sm_orange();
     	mossa_U();
     	antism_orange();
	 }else if(cube[4][2][2]==1 && cube[2][2][0]==3 && cube[1][0][0]==4){
     	antism_blue();
     	mossa_U();
     	antism_orange();
	 }else if(cube[4][2][2]==4 && cube[2][2][0]==1 && cube[1][0][0]==3){
     	sm_orange();
     	mossa_U();
     	sm_green();
	 }else if(cube[2][0][2]==3 && cube[0][2][2]==4 && cube[5][0][0]==1){ // CASI ANGOLO SOPRA
     	mossa_U();
     	mossa_U();
     	sm_green();
	 }else if(cube[2][0][2]==1 && cube[0][2][2]==3 && cube[5][0][0]==4){
     	mossa_U();
     	mossa_U();
     	antism_orange();
	 }else if(cube[2][0][2]==4 && cube[0][2][2]==1 && cube[5][0][0]==3){
     	mossa_U();
     	mossa_U();
     	sm_green();
     	sm_green();
     	sm_green();
	 }else if(cube[5][0][2]==3 && cube[0][0][2]==4 && cube[3][0][0]==1){
     	mossa_U_primo();
     	sm_green();
	 }else if(cube[5][0][2]==4 && cube[0][0][2]==1 && cube[3][0][0]==3){
     	mossa_U_primo();
     	sm_green();
     	sm_green();
     	sm_green();
	 }else if(cube[5][0][2]==1 && cube[0][0][2]==3 && cube[3][0][0]==4){
     	mossa_U_primo();
     	antism_orange();
	 }else if(cube[3][0][2]==3 && cube[0][0][0]==4 && cube[4][0][0]==1){
     	sm_green();
	 }else if(cube[3][0][2]==4 && cube[0][0][0]==1 && cube[4][0][0]==3){
     	sm_green();
     	sm_green();
     	sm_green();
	 }else if(cube[3][0][2]==1 && cube[0][0][0]==3 && cube[4][0][0]==4){
     	antism_orange();
	 }else if(cube[4][0][2]==3 && cube[0][2][0]==4 && cube[2][0][0]==1){
	 	mossa_U();
     	sm_green();
	 }else if(cube[4][0][2]==4 && cube[0][2][0]==1 && cube[2][0][0]==3){
	 	mossa_U();
     	sm_green();
     	sm_green();
     	sm_green();
	 }else if(cube[4][0][2]==1 && cube[0][2][0]==3 && cube[2][0][0]==4){
	 	mossa_U();
     	antism_orange();
	 }
}
void solve_corner_obw(){ // risolvi angolo obw(orange, blue and white)
     if(cube[4][2][2]==4 && cube[2][2][0]==2 && cube[1][0][0]==1){ // CASI ANGOLO SOTTO
        return;
	 }else if(cube[4][2][2]==2 && cube[2][2][0]==1 && cube[1][0][0]==4){
	 	sm_orange();
	 	sm_orange();
	 }else if(cube[4][2][2]==1 && cube[2][2][0]==4 && cube[1][0][0]==2){
	 	antism_blue();
	 	antism_blue();
	 }else if(cube[2][0][2]==4 && cube[0][2][2]==2 && cube[5][0][0]==1){ // CASI ANGOLO SOPRA
	    mossa_U();
	    sm_orange();
	 }else if(cube[2][0][2]==2 && cube[0][2][2]==1 && cube[5][0][0]==4){
	    mossa_U();
	    sm_orange();
	    sm_orange();
	    sm_orange();
	 }else if(cube[2][0][2]==1 && cube[0][2][2]==4 && cube[5][0][0]==2){
	    mossa_U();
	    antism_blue();
	 }else if(cube[5][0][2]==4 && cube[0][0][2]==2 && cube[3][0][0]==1){
	    mossa_U();
	    mossa_U();
	    sm_orange();
	 }else if(cube[5][0][2]==2 && cube[0][0][2]==1 && cube[3][0][0]==4){
	    mossa_U();
	    mossa_U();
	    sm_orange();
	    sm_orange();
	    sm_orange();
	 }else if(cube[5][0][2]==1 && cube[0][0][2]==4 && cube[3][0][0]==2){
	    mossa_U();
	    mossa_U();
	    antism_blue();
	 }else if(cube[3][0][2]==4 && cube[0][0][0]==2 && cube[4][0][0]==1){
	    mossa_U_primo();
	    sm_orange();
	 }else if(cube[3][0][2]==2 && cube[0][0][0]==1 && cube[4][0][0]==4){
	    mossa_U_primo();
	    sm_orange();
	    sm_orange();
	    sm_orange();
	 }else if(cube[3][0][2]==1 && cube[0][0][0]==4 && cube[4][0][0]==2){
	    mossa_U_primo();
	    antism_blue();
	 }else if(cube[4][0][2]==4 && cube[0][2][0]==2 && cube[2][0][0]==1){
	    sm_orange();
	 }else if(cube[4][0][2]==2 && cube[0][2][0]==1 && cube[2][0][0]==4){
	    sm_orange();
	    sm_orange();
	    sm_orange();
	 }else if(cube[4][0][2]==1 && cube[0][2][0]==4 && cube[2][0][0]==2){
	    antism_blue();
	 }
}
void solve_white_corners(){
	solve_corner_brw();
	solve_corner_rgw();
	solve_corner_gow();
	solve_corner_obw();
}
void solve_b_r(){ // risolvi spigolo blu-rosso
}
void solve_r_g(){ // risolvi spigolo rosso-verde
}
void solve_g_o(){ // risolvi spigolo verde-arancio
}
void solve_o_b(){ // risolvi spigolo arancio-blu
}
void solve_middle_edges(){
	solve_b_r();
    solve_r_g();
    solve_g_o();
    solve_o_b();
}
int main(){
	char cubo[6][3][3];
	printf("================================================================\n\n");
	printf(">>BENVENUTO NEL MIO PROGRAMMA RISOLUTORE DEL CUBO DI RUBIK!!!<<\n\n");
	printf("================================================================\n\n");
	insert_cube();
	printf("-----RISOLUZIONE CUBO:-----\n");
	solve_white_cross();
	solve_white_corners();
	return 0;
}
