#include "Files.h"
#include "MainMenu.h"

int main()
{
	make_file();
	vector<Team> teams;
	vector<Player> players;
	read_file(teams, players);
	main_menu(teams, players);
	return 0;
}

// Borrar equipo blanquea jugador
// Compra y Venta con FA (vacio solo cobra no paga)
// Añadir jugador libre (preguntar si tiene equipo)
// Buscar por nombre muestra lista de jugadores
