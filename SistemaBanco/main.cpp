#include <graphics.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <sstream> // Para usar std::stringstream

#define MAX 10

// Clase para los botones
class Boton {
private:
    int x1, y1, x2, y2;
    char texto[50];
    int colorFondo;
    int colorTexto;

public:
    Boton(int x1, int y1, int x2, int y2, const char* texto, int colorFondo = LIGHTCYAN, int colorTexto = WHITE) {
        this->x1 = x1;
        this->y1 = y1;
        this->x2 = x2;
        this->y2 = y2;
        strcpy(this->texto, texto);
        this->colorFondo = colorFondo;
        this->colorTexto = colorTexto;
    }

    void dibujar() {
        setfillstyle(SOLID_FILL, colorFondo);
        bar(x1, y1, x2, y2);
        setcolor(colorTexto);
        rectangle(x1, y1, x2, y2);

        settextstyle(3, 0, 2);
        int textWidth = textwidth(texto);
        int textHeight = textheight(texto);
        outtextxy((x1 + x2 - textWidth) / 2, (y1 + y2 - textHeight) / 2, texto);
    }

    bool fueClickeado(int mx, int my) {
        return mx >= x1 && mx <= x2 && my >= y1 && my <= y2;
    }

    const char* getTexto() {
        return texto;
    }
};

// Clase para el sistema bancario
class Banco {
private:
    float saldo;
    Boton* botones[5];

public:
    Banco() {
        saldo = 1000.0;
        botones[0] = new Boton(50, 50, 200, 90, "Depositar", LIGHTGREEN);
        botones[1] = new Boton(250, 50, 400, 90, "Retirar", LIGHTRED);
        botones[2] = new Boton(50, 120, 200, 160, "Consultar", LIGHTBLUE);
        botones[3] = new Boton(250, 120, 400, 160, "Transferir", LIGHTMAGENTA);
        botones[4] = new Boton(150, 200, 300, 240, "Salir", LIGHTGRAY);
    }

    void mostrarSaldo() {
        char msg[50];
        snprintf(msg, sizeof(msg), "Saldo actual: $%.2f", saldo);
        setcolor(WHITE);
        setfillstyle(SOLID_FILL, WHITE);
        bar(50, 260, 400, 300);  // Ajuste en la posición para no cortar
        settextstyle(3, 0, 2);
        outtextxy(70, 270, msg);
    }

    void mostrar() {
        for (int i = 0; i < 5; ++i) {
            botones[i]->dibujar();
        }
        mostrarSaldo();
    }

    bool manejarClick(int mx, int my) {
        for (int i = 0; i < 5; ++i) {
            if (botones[i]->fueClickeado(mx, my)) {
                const char* accion = botones[i]->getTexto();

                if (strcmp(accion, "Depositar") == 0) {
                    saldo += 100;
                } else if (strcmp(accion, "Retirar") == 0) {
                    if (saldo >= 100) saldo -= 100;
                } else if (strcmp(accion, "Consultar") == 0) {
                    // No cambia nada, solo muestra el saldo
                } else if (strcmp(accion, "Transferir") == 0) {
                    if (saldo >= 50) saldo -= 50;
                } else if (strcmp(accion, "Salir") == 0) {
                    return false; // Finalizar programa
                }
                mostrarSaldo(); // Actualiza la pantalla con el saldo
            }
        }
        return true;
    }
};

// Clase para la interfaz gráfica
class Interfaz {
private:
    Banco banco;

public:
    void iniciar() {
        initwindow(600, 400, "Sistema Bancario", 300, 200); // Ajustado a 432x288 píxeles
        cleardevice();

        while (true) {
            banco.mostrar();

            if (ismouseclick(WM_LBUTTONDOWN)) {
                int mx, my;
                getmouseclick(WM_LBUTTONDOWN, mx, my);
                if (!banco.manejarClick(mx, my)) break;
            }
            delay(100);
        }

        closegraph();
    }
};

int main() {
    Interfaz interfaz;
    interfaz.iniciar();
    return 0;
}

