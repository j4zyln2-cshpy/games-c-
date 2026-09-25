#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cctype>
using namespace std;

struct Pregunta {
    string enunciado;
    string opcionA;
    string opcionB;
    string opcionC;
    char respuestaCorrecta; // 'A', 'B' o 'C'
    string explicacion;
};

class KirbyTrivia {
private:
    std::vector<Pregunta> bancoPreguntas;
    int puntaje;

    char aMayuscula(char c) {
        return static_cast<char>(std::toupper(static_cast<unsigned char>(c)));
    }

public:
    KirbyTrivia() : puntaje(0) {
        cargarPreguntas();
    }

    void cargarPreguntas() {
        bancoPreguntas = {
            {
                "¿En qué año debutó Kirby en su primer juego (Kirby's Dream Land)?",
                "1990", "1992", "1995",
                'B', "Correcto. Kirby debutó en 1992 para la Game Boy."
            },
            {
                "¿Cuál es el nombre del planeta natal de Kirby?",
                "Popstar", "Dream Land", "Floralia",
                'A', "Correcto. Su planeta tiene forma de estrella y se llama Popstar."
            },
            {
                "¿De qué color iba a ser Kirby originalmente según Shigeru Miyamoto?",
                "Rosa", "Azul", "Amarillo",
                'C', "Correcto. Shigeru Miyamoto lo quería amarillo, pero Masahiro Sakurai insistió en el rosa." //le pegó btw. gracias Samurai, digo, Sakurai
            },
            {
                "¿Cómo se llama el rival icónico de Kirby que lleva máscara y espada?",
                "King Dedede", "Meta Knight", "Bandana Waddle Dee",
                'B', "YEAAAAH. Mi main en S... DIGO, Meta Knight es el caballero enmascarado." //casi la cago
            },
            {
                "¿Qué habilidad obtiene Kirby al absorber a un enemigo tipo fuego?",
                "Fire (Fuego)", "Spark (Chispa)", "Burn (Quemadura)",
                'A', "Correcto Le otorga la habilidad Fire."
            }
        };
    }

    void iniciarJuego() {
        puntaje = 0;
        cout << "¿ERES REALMENTE UN FAN DE KIRBY?" << endl; //no pensé en otro título

        for (size_t i = 0; i < bancoPreguntas.size(); ++i) {
            cout << "Pregunta " << (i + 1) << " de " << bancoPreguntas.size() << endl;
            cout << bancoPreguntas[i].enunciado << endl;
            cout << "A) " << bancoPreguntas[i].opcionA << endl;
            cout << "B) " << bancoPreguntas[i].opcionB << endl;
            cout << "C) " << bancoPreguntas[i].opcionC << endl;
            
            char res;
            cout << "Tu respuesta (A/B/C): " << endl;
            cin >> res;
            res = aMayuscula(res);

            while (res != 'A' && res != 'B' && res != 'C') {
                cout << "Opción inválida. Ingrese A, B o C: " << endl;
                cin >> res;
                res = aMayuscula(res);
            }

            if (res == bancoPreguntas[i].respuestaCorrecta) {
                cout << bancoPreguntas[i].explicacion << " (+10 pts)" << endl;
                puntaje += 10;
            } else {
                cout << "Incorrecto. La respuesta era " << bancoPreguntas[i].respuestaCorrecta << endl;
            }
        }

        mostrarResultado();
    }

    void mostrarResultado() const {
        int maxPuntaje = bancoPreguntas.size() * 10;
        cout << "PUNTAJE FINAL: " << puntaje << " / " << maxPuntaje << " pts\n";

        if (puntaje == maxPuntaje) {
            cout << "Rango: Enfermo Mental. Me preocupas XDDDDD" << endl;
        } else if (puntaje >= (maxPuntaje * 0.6)) {
            cout << "Rango: Meh. Vas bien, te falta poco" << endl;
        } else {
            cout << "Rango: ¿Tan siquiera has jugado un Kirby? XD" << endl;
        }
        cout << "pene" << endl;
    }
};

int main() {
    KirbyTrivia juego;
    char jugarDeNuevo;

    do {
        juego.iniciarJuego();
        cout << "Quieres intentar de nuevo? (S/N): " << endl; 
        cin >> jugarDeNuevo;
    } while (jugarDeNuevo == 's' || jugarDeNuevo == 'S');

    cout << "Gracias por jugar. Poyo!" << endl;
    return 0;
}
