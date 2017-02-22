#ifndef SOMEGAME_H
#define SOMEGAME_H

#include <QtWidgets/QMainWindow>
#include "ui_somegame.h"
#include <QPushButton>
#include <QLineEdit>
#include <QFormLayout>
#include <QListWidget>
#include <QLabel>
#include <QSpinBox>
#include "controller.h"
class SomeGame : public QWidget
{
	Q_OBJECT

public:
	SomeGame(Controller ctrl, QWidget *parent = 0) : ctrl(ctrl) 
	{
		this->initGUI();
	};
	~SomeGame();
	void initGUI();
	void connectSignalSlots();
private:
	Controller& ctrl;
	QPushButton* guess;
	QLineEdit* scrambled;
	QLineEdit* word;
	QSpinBox* scoreKeeper;
	int score;
	//Ui::SomeGameClass ui;
signals:
	void guessSignal();
public slots:
	void checkGuess();
	void fill();
};

#endif // SOMEGAME_H
