
#define __CRONO_H__




class crono {

private:
	int init;
	int end;
	int *medidas;  
	int numMedidas;
	int maxMedidas;

	int calculaMedia();

public:

	crono(); //Contructor por defecto;
	crono(int tam);
	~crono(){  delete medidas;  }

	void Start();
	void MedidaParcial();
	void Stop();
	int GetnumMedidas();

	int GetTiempoTotal();
	int GetUltimaMedida();
	int GetMediaMedidas();
	void clear();

};

