#include<iostream>
#include<string>

using namespace std;

class Fecha{
	
	private:
		int dia, mes, anio,fent;
	
	public:
		Fecha(int _dia, int _mes,int _anio);
		void mostrar();
		void sumarFechas(const Fecha &f);
		void fechaMayor(const Fecha &f);
		
};

Fecha::Fecha(int _dia, int _mes,int _anio){
	dia=_dia;
	mes=_mes;
	anio=_anio;
	fent=dia*1000000+mes*10000+anio;
}

void Fecha::mostrar(){
	cout<<"\n\t La fecha es: "<<dia;
	cout<<"/"<<mes;
	cout<<"/"<<anio;
}

void Fecha::sumarFechas(const Fecha &f){
	cout<<"\n\t "<<fent<<" + "<<f.fent<<" = "<<(fent+f.fent);
}

void Fecha::fechaMayor(const Fecha &f){
	if(fent>f.fent)
		cout<<"\n\t La fecha mayor es: "<<dia<<"/"<<mes<<"/"<<anio;
	else if(fent<f.fent)
		cout<<"\n\t La fecha mayor es: "<<f.dia<<"/"<<f.mes<<"/"<<f.anio;
	else 
		cout<<"\n\t Las fechas son iguales.";
}

int main(){
	
	//Instanciamos un objeto de la clase fecha
	Fecha f1(12,04,2022);
	f1.mostrar();
	
	//Instanciamos otro objeto de la clase fecha
	Fecha f2(10,02,2022);
	f2.mostrar();
	
	//Sumando las fechas
	f1.sumarFechas(f2);
	
	//Descubriendo cual fecha es mayor
	f1.fechaMayor(f2);
	
	
	return 0;
}
