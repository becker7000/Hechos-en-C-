#include <graphics.h>
#include <conio.h>
#include <stdlib.h> // Para la conversión de cadenas a enteros

#define MAX 10

char resultado[20];
char inputA[MAX] = "";
char inputB[MAX] = "";
char operador = 0;
float a = 0, b = 0;
float final = 0;

void pantalla(int x, int y, char *n="     "){
    settextstyle(3, 0, 2);
    outtextxy(x + 10, y + 5, n);
    rectangle(x, y, x + 200, y + 80);
}

void botonNum(int x, int y, char *n) {
    settextstyle(3, 0, 2);
    outtextxy(x + 10, y + 5, n);
    rectangle(x, y, x + 40, y + 40);
    if (mousex() > x && mousex() < (x + 40) && mousey() > y && mousey() < (y + 40) && ismouseclick(WM_LBUTTONDOWN)) {
        clearmouseclick(WM_LBUTTONDOWN);
        if (strlen(inputA) == 0 || operador == 0) {
            if (strlen(inputA) < MAX - 1) {
                strcat(inputA, n);
                settextstyle(3, 0, 2);
                outtextxy(20, 10, inputA);
            }
        } else {
            if (strlen(inputB) < MAX - 1) {
                strcat(inputB, n);
                settextstyle(3, 0, 2);
                outtextxy(20, 55, inputB);
            }
        }
    }
    delay(100);
}

void botonOper(int x, int y, char op, char *n) {
    settextstyle(3, 0, 2);
    outtextxy(x + 10, y + 5, n);
    rectangle(x, y, x + 40, y + 40);
    if (mousex() > x && mousex() < (x + 40) && mousey() > y && mousey() < (y + 40) && ismouseclick(WM_LBUTTONDOWN)) {
        clearmouseclick(WM_LBUTTONDOWN);
        operador = op;
        settextstyle(3, 0, 2);
        outtextxy(20, 35, n); // 35 <- 
    }
    delay(100);
}

void resetear() {
    inputA[0] = '\0';
    inputB[0] = '\0';
    operador = 0;
    final = 0;
    outtextxy(20, 10, "                        "); // Input A
    outtextxy(50, 10, "                        "); // Result
    outtextxy(20, 35, "                        "); // boton oper
    outtextxy(20, 55, "                        "); // Input B
}

void calcular() {
	
    a = atof(inputA);
    b = atof(inputB);

    switch (operador) {
        case '+':
            final = a + b;
            break;
        case '-':
            final = a - b;
            break;
        case '*':
            final = a * b;
            break;
        case '/':
            final = a / b;
            break;
        default:
            final = 0;
            break;
    }

    gcvt(final, 10, resultado); // Convierte el resultado a cadena para fijarlo en la pantalla
    settextstyle(3, 0, 2);
    outtextxy(80, 10, "=");
	outtextxy(100, 10, resultado);
}

void resolver(int x, int y, char *n=" ") {
    settextstyle(3, 0, 2);
    outtextxy(x + 10, y + 5, n);
    rectangle(x, y, x + 40, y + 40);
    if (mousex() > x && mousex() < (x + 130) && mousey() > y && mousey() < (y + 40) && ismouseclick(WM_LBUTTONDOWN)) {
        clearmouseclick(WM_LBUTTONDOWN);
        calcular();
    }
    delay(100);
}

int main() {
	
    initwindow(400, 400, "Calculadora", 300, 200);
    cleardevice();
    setcolor(WHITE);

    while (true) {
    	
        botonNum(15, 105, "1");
        botonNum(60, 105, "2");
        botonNum(105, 105, "3");
        botonOper(150, 105, '+', "+");

        botonNum(15, 150, "4");
        botonNum(60, 150, "5");
        botonNum(105, 150, "6");
        botonOper(150, 150, '-', "-");

        botonNum(15, 195, "7");
        botonNum(60, 195, "8");
        botonNum(105, 195, "9");
        botonOper(150, 195, '*', "*");
        
        botonOper(15, 240, '/', "/");
		botonNum(60,240,"0");
		
        settextstyle(3, 0, 2);
        outtextxy(115, 245, "C");
        rectangle(105, 240, 145, 280);
        
        if (mousex() > 105 && mousex() < 145 && mousey() > 240 && mousey() < 280 && ismouseclick(WM_LBUTTONDOWN)) {
            clearmouseclick(WM_LBUTTONDOWN);
            resetear();
        }

        resolver(150, 240, "=");
        botonNum(60,285,".");
        pantalla(5, 5, "");
    }

    getch();
    return 0;
}

