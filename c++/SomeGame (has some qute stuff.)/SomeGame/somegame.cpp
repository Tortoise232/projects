#include "somegame.h"

void SomeGame::initGUI()
{
	QFormLayout* mainLay = new QFormLayout{ this };
	this->guess = new QPushButton{ "GUESS!" };
	this->scrambled = new QLineEdit;
	this->word = new QLineEdit;
	this->scoreKeeper = new QSpinBox{};
	this->scoreKeeper->setValue(score);
	QLabel* wordLabel = new QLabel{ "Your guess:" };
	QLabel* scrambledLabel = new QLabel{ "Scrambled: " };
	mainLay->addRow(scrambledLabel, this->scrambled);
	mainLay->addRow(wordLabel, this->word);
	mainLay->addWidget(this->guess);
}

void SomeGame::connectSignalSlots()
{
	QObject::connect(this->guess, SIGNAL(clicked()), this, SLOT(checkGuess()));
	QObject::connect(this, SIGNAL(guessSignal()), this, SLOT(fill()));
}

void SomeGame::fill()
{
	int rand = 
}

SomeGame::~SomeGame()
{

}
