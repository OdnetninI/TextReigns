#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Reign.hpp"
#include "Card.hpp"

std::ostream& operator<<(std::ostream& cout, struct ReignPowers powers) {
  cout << "Iglesia: " << powers.church;
  cout << " Gente: " << powers.people;
  cout << " Ejercito: " << powers.army;
  cout << " Dinero: " << powers.money;
  return cout;
}

std::ostream& operator<<(std::ostream& cout, Card& card) {
  cout << "Text: " << card.getText();
  cout << "\nOption1: " << card.getOption(0)->getText() << " " << card.getOption(0)->getChange();
  cout << "\nOption2: " << card.getOption(1)->getText() << " " << card.getOption(1)->getChange();
  cout << "\nOption3: " << card.getOption(2)->getText() << " " << card.getOption(2)->getChange();
  return cout;
}

std::ostream& operator<<(std::ostream& cout, Card* card) {
  cout << *card;
  return cout;
}

struct ReignPowers operator+ (struct ReignPowers a, struct ReignPowers b) {
  int32_t church = a.church + b.church;
  int32_t people = a.people + b.people;
  int32_t army = a.army + b.army;
  int32_t money = a.money + b.money;
  return {church, people, army, money};
}

#define MAX_CARDS 2
Card* cards[MAX_CARDS];

void initializeCards() {
  for (uint32_t card = 0; card < MAX_CARDS; card++)
    cards[card] = nullptr;
}

void addCard (uint32_t card, const char* text, const char* op1, struct ReignPowers op1Powers, const char* op2, struct ReignPowers op2Powers, const char* op3, struct ReignPowers op3Powers) {
  if (card >= MAX_CARDS) return;
  if (cards[card] != nullptr) delete cards[card];
  cards[card] = new Card();
  Option* opt1 = new Option();
  Option* opt2 = new Option();
  Option* opt3 = new Option();
  cards[card]->setText(text);
  opt1->setText(op1);
  opt2->setText(op2);
  opt3->setText(op3);
  opt1->setChange(op1Powers);
  opt2->setChange(op2Powers);
  opt3->setChange(op3Powers);
  cards[card]->setOption(opt1, 0);
  cards[card]->setOption(opt2, 1);
  cards[card]->setOption(opt3, 2);
}

bool isLose (Reign* reign) {
  struct ReignPowers powers = reign->getReignPowers();
  if (powers.church <= 0 || powers.people <= 0 || powers.army <= 0 || powers.money <= 0) return true;
  return false;
}

int main (int argc, char* argv[]) {

  std::srand(std::time(nullptr));

  Reign reino;

  reino.setKingName("OdnetninI");
  //std::cout << "Rey: " << reino.getKingName() << "\n";

  //std::cout << "Años: " << reino.getKingYears() << "\n";
  //reino.newYear();
  //std::cout << "Ha pasado 1 año." << "\n";
  //std::cout << "Años: " << reino.getKingYears() << "\n";

  //std::cout << reino.getReignPowers() << "\n";
  reino.setReignPowers({10,5,20,35});
  //std::cout << reino.getReignPowers() << "\n";

  initializeCards();
  addCard(0, "Hay que construir un establo", "Hagamoslo", {0,15,0,-20}, "NO!", {0,-10,0,0}, "Haced algo más pequeño", {0,5,0,-10});
  addCard(1, "Atacad el reino vecino", "A LA CARGA", {0,-5,-10,-15}, "NO!", {5,0,0,0}, "Hagamos un Pacto", {0,5,-5,-10});

  while (!isLose(&reino)) {
    std::cout << "Rey: " << reino.getKingName() << " Años al Poder: " << reino.getKingYears() << "\n";
    std::cout << reino.getReignPowers() << "\n";
    uint32_t card = std::rand()%MAX_CARDS;
    std::cout << cards[card] << "\n";
    uint32_t opcion = 0;
    do {
      std::cin >> opcion;
      opcion--;
    } while (opcion >= MAX_OPTIONS);
    reino.setReignPowers(reino.getReignPowers()+cards[card]->getOption(opcion)->getChange());
    reino.newYear();
  }

  std::cout << "HAS PERDIDO" << "\n";
  std::cout << "EL REY HA MUERTO" << "\n";
  std::cout << reino.getReignPowers() << "\n";
  return 0;
}
