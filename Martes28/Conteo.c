#include<stdio.h>

int main(){
	
	int i;
	
	for(i=1;i<=5;i++){
		
		switch(i){
			case 1:
				printf("\n\t Soy el uno...");
				Sleep(3000);
				break;
			case 2:
				printf("\n\t Soy el dos...");
				Sleep(3000);
				break;
			case 3:
			    printf("\n\t Soy el tres...");
			    Sleep(3000);
				break;	
			case 4: 
			    printf("\n\t Soy el cuatro...");
			    Sleep(3000);
				break;
			case 5: 
			    printf("\n\t Soy el cinco...");
				Sleep(3000);
				break;	
		}
		
	}
	
}
