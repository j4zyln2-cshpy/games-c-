#include <iostream>
#include <windows.h>
#include <conio.h>
#include <vector>
#include <locale>

using namespace std;

void ocultarCursor() {
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO info;
	info.dwSize = 100;
	info.bVisible = FALSE;
	SetConsoleCursorInfo(consoleHandle, &info);
}

void gotoxy(int x, int y){
	HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X = x;
	dwPos.Y = y;
	SetConsoleCursorPosition(hcon, dwPos);
}

int main() {
	setlocale(LC_ALL, "");
	system("title DINO RUNNER - Lo hice por pura flojera, chupenlo >:3");
	system("cls");
	ocultarCursor();
	
	const int ANCHO_PISTA = 50;
	const int PISO_Y = 12;
	
	int dinoY = PISO_Y;
	bool saltando = false;
	int tiempoSalto = 0;
	
	int cactusX = ANCHO_PISTA - 2;
	int puntaje = 0;
	int velocidad = 50;
	
	bool juegoActivo = true;
	
	gotoxy(10, 5);
	cout << "-------------------------------------" << endl;  //kill me
	gotoxy(10, 6);
	cout << "El Dinosaurio de Google por 8282928928298298292929892829 vez" << endl; 
	gotoxy(10, 7);
	cout << "-------------------------------------" << endl; //KILL MEEEEEEEEE
	gotoxy(10, 9);
	cout << "Presiona [ ESPACIO ] para Saltar" << endl;
	gotoxy(10, 10);
	cout << "Presiona [X] para Salir" << endl;
	gotoxy(10, 12);
	cout << "Presiona cualquier tecla para empezar" << endl ;
	getch();
	system("cls");
	
	gotoxy(0, PISO_Y + 1);
	for (int i= 0; i < ANCHO_PISTA; i++) cout << "=";
	
	while (juegoActivo){
		if (kbhit()) {
			char tecla = getch();
			if (tecla == ' ' && !saltando){
				saltando = true;
				tiempoSalto = 0;
			} else if (tecla == 'x' || tecla == 'X'){
				juegoActivo = false;
			}
		}
		
		if (saltando){
			tiempoSalto++;
			if (tiempoSalto <= 3){
				dinoY--;
			} else if (tiempoSalto <= 6){
				dinoY++;
			} else {
				dinoY = PISO_Y;
				saltando = false;
				tiempoSalto = 0;
			}
		}
		
		cactusX--;
		if (cactusX < 2){
			cactusX = ANCHO_PISTA - 3;
			puntaje += 10;
			if (velocidad > 15 && puntaje % 50 == 0){
				velocidad -= 3;
			}
		}
		
		gotoxy(5, PISO_Y); cout << " ";
		gotoxy(5, PISO_Y - 1); cout << " ";
		gotoxy(5, PISO_Y - 2);  cout << " ";
		gotoxy(cactusX + 1, PISO_Y); cout << " ";
		
		gotoxy(5, dinoY);
		cout << "D";
		
		gotoxy(cactusX, PISO_Y);
		cout << "Y";
		
		gotoxy(0,0);
		cout << "Puntaje: "<< puntaje << " -- Presiona X para Salir :v";
		
		Sleep(velocidad);
	}
	
	gotoxy(15, 6);
	cout << "f en el chat papulince de m... nah olvidalo, ya suficiente tienes con lo tuyo" << endl;
	gotoxy(15, 7);
	cout << "GAME OVER" << endl;
	gotoxy(15, 8);
	cout << "Puntaje Final: "<< puntaje << endl;
	gotoxy(15, 9);
	cout << "si hiciste más de 100 puntos, felicidades, sino, eres bien estúpido" << endl;
	gotoxy(10, 12);
	cout << "Presiona cualquier tecla para salir" << endl;
	getch();
	
	return 0;
}
