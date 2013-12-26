

#include "crono.h"
#include <Arduino.h>

	crono::crono(){
		
		end=-1;
		numMedidas=0;
		maxMedidas=10;

		medidas= new int[10];
		int i; 
		 for ( i= 0; i < 10 ; i++){
       		medidas[i]=-1;
		}
	}


	crono::crono (int tam){

		end=-1;
		numMedidas=0;
		maxMedidas=tam;

		medidas= new int[tam];
		int i; 
		 for ( i= 0; i < tam ; i++){
       		medidas[i]=-1;
	}
}

	

	void crono::Start(){ init=millis(); medidas[0]=init; numMedidas=1;}

	void crono::MedidaParcial(){
		
		if (numMedidas<maxMedidas){ 
			medidas[numMedidas]= millis() - medidas[numMedidas-1];
			numMedidas++;	
		}

	}

	int crono::calculaMedia(){
		int sum=0;
		for (int i=0;i<numMedidas;i++){ sum+=medidas[i]; }
		return (sum/numMedidas);
	}

	void crono::Stop(){
		end=millis();
		MedidaParcial();
	}


	int crono::GetnumMedidas(){ return numMedidas; }

	int crono::GetTiempoTotal(){
		
		return (millis()-init);
	}


	int crono::GetUltimaMedida(){
		return medidas[numMedidas-1];
	}

	int crono::GetMediaMedidas(){
		return  calculaMedia();
	}

	void crono::clear(){
		init=0;
		end=-1;
		numMedidas=0;
		for (int i=0;i<maxMedidas;i++){medidas[i]=-1;}

	}





