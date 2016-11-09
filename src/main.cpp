#include <iostream>
#include "Reign.hpp"
#include "Card.hpp"

std::ostream& operator<<(std::ostream& cout, struct ReignPowers powers) {
  cout << "Iglesia: " << powers.church;
  cout << " Gente: " << powers.people;
  cout << " Ejercito: " << powers.army;
  cout << " Dinero: " << powers.money;
  return cout;
}

int main (int argc, char* argv[]) {
  Reign reino;

  reino.setKingName("OdnetninI");
  std::cout << "Rey: " << reino.getKingName() << "\n";

  std::cout << "Años: " << reino.getKingYears() << "\n";
  reino.newYear();
  std::cout << "Ha pasado 1 año." << "\n";
  std::cout << "Años: " << reino.getKingYears() << "\n";

  std::cout << reino.getReignPowers() << "\n";
  reino.setReignPowers({10,5,20,35});
  std::cout << reino.getReignPowers() << "\n";

  Card card;
  card.setText("Hay que construir un establo.");
  std::cout << "Tarjeta 1: " << card.getText() << "\n";

  Option option1("Construyamoslo", {0,15,0,-20});
  card.setOption(&option1,0);
  std::cout << "Opcion 1: " << card.getOption(0)->getText() << "\n";
  std::cout << "Option 1 Change: " << card.getOption(0)->getChange() << "\n";

  return 0;
}
