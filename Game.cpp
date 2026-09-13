#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void jugarMath() {
	int opcion, num1, num2, resultadoCorrecto, respuestaJugador;
	int vidas = 3, puntos = 0, maxNum = 20;
	char operacion;
	
	cout << "   DESAFÍO MATEMÁTICO.   " << endl;
	cout << "Selecciona una dificultad" << endl;
	cout << "1. Facil (Sumas y Restas)" << endl;
	cout << "2. Medio (Multiplicaciones)" << endl;
	cout << "3. Dificil (Incluye Divisiones y numeros altos)" << endl;
	cout << "Opcion" << endl;
	cin >> opcion;
	
	while (vidas > 0) {
		if (opcion == 1){
			maxNum = 20;
			num1 = rand() % maxNum + 1;
			num2 = rand() % maxNum + 1;
			operacion = (rand() % 2 == 0) ? '+' : '-';
		} else if (opcion == 2) {
			maxNum = 50;
			num1 = rand() % maxNum + 1;
			num2 = rand() % maxNum + 1;
			int op = rand() % 3;
			operacion = (op == 0) ? '+' : (op == 1 ? '-' : '*');
		} else {
			maxNum = 100;
			num1 = rand() % maxNum + 1;
			num2 = rand() % maxNum + 1;
			int op = rand() % 4;
			if (op == 0) operacion = '+';
			else if (op == 1) operacion = '-';
			else if (op == 2) operacion = '*';
			else {
				operacion = '/';
				num1 = num2 * (rand() % 10 + 1);
			}
		}
		switch (operacion) {
			case '+': resultadoCorrecto = num1 + num2; break;
			case '-': resultadoCorrecto = num1 - num2; break;
			case '*': resultadoCorrecto = num1 * num2; break;
			case '/': resultadoCorrecto = num1 / num2; break;
		}
		
		cout << "Puntos:" << puntos << " | Vidas restantes: " << vidas << endl;
		cout << "Cuanto es" << num1 << " " << operacion << " " << num2 << "?: " << endl;
		cin >> respuestaJugador;
		
		if(respuestaJugador == resultadoCorrecto) {
			cout << "Correcto. Sumas 10 puntos :D";
			puntos += 10;
		} else {
			vidas--;
			cout << "JAJA INCORRECTO LOL";
		}
	}
	
	cout << "Game Over: Puntuacion final" << puntos << endl;
}

int main() {
	srand(time(0));
	jugarMath();
	return 0;
}

