#pragma once

#include "ofMain.h"
#include "square.h"

class ofApp : public ofBaseApp {
public:
	void setup();
	void update();
	void draw();

	ofSoundPlayer correctClick;
	ofSoundPlayer gameLost;

	ofTrueTypeFont titleFont;
	ofTrueTypeFont rulesFont;

	ofRectangle startButton;
	ofRectangle rulesButton;
	ofRectangle rulesBackButton;
	ofRectangle newGameButton;
	ofRectangle mainMenuButton;

	Square squares[100];
	ofColor colors[100];
	int rootSquares;
	int numSquares;
	int squareSize;
	int rowsNcols;
	int level;
	int activeSquares[100];
	int spacing;
	int order[100];
	int orderCheck;
	int gameStatus;
	bool showNumbers;
	int currentActive;


	void displayStartScreen()
	{
		ofImage background;
		background.load("backgroundStart.jpg");
		background.draw(0, 0);

		ofImage lightning;
		lightning.load("lightning.png");
		lightning.draw(350, 125);

		ofPushStyle();

		ofSetColor(0, 255, 0);
		ofDrawRectangle(startButton);
		ofDrawRectangle(rulesButton);

		ofSetColor(0, 0, 0);
		titleFont.drawString("Human Benchmark", 300, 120);
		titleFont.drawString("START", 425, 525);
		titleFont.drawString("RULES", 425, 725);

		ofPopStyle();
	}

	void displayRulesScreen()
	{
		ofImage background;
		background.load("backgroundStart.jpg");
		background.draw(0, 0);

		ofPushStyle();

		ofSetColor(0, 0, 0);
		titleFont.drawString("RULES", 425, 100);
		rulesFont.drawString("When the game begins, you will be shown 3 squares that are\n numbered. Once you click the first square (numbered 1),\n the rest of the numbers will disappear, and you \nwill need to click the squares in the correct order\n to move on to the next round. After each round,\n the number of squares will increase.", 100, 300);

		ofSetColor(0, 255, 0);
		ofDrawRectangle(rulesBackButton);
		ofSetColor(0, 0, 0);
		titleFont.drawString("BACK", 425, 825);

		ofPopStyle();

	}

	void displayGame()
	{

		ofSetColor(0, 0, 0);
		titleFont.drawString("LEVEL: ", 400, 100);
		titleFont.drawString(ofToString(level), 550, 100);

		int o = 0;

		for (int i = 0; i < numSquares; i++)
		{
			ofSetColor(colors[i]);
			squares[i].draw();


			if (isSquareActive(i) == true)
			{

				squares[i].setNumber(order[o]);

				if (showNumbers == true)
				{
					squares[i].drawNumber();
				}

				o = o + 1;

			}
		}


	}

	void setupNewRound()
	{
		if (currentActive > ((rootSquares * rootSquares) / 2)) //makes grid of squares bigger
		{
			rootSquares = rootSquares + 1;
		}

		numSquares = rootSquares * rootSquares;
		rowsNcols = sqrt(numSquares);
		spacing = 100 / rowsNcols;
		squareSize = (700 - (spacing * (rowsNcols - 1))) / rowsNcols;
		orderCheck = 1;
		showNumbers = true;

		for (int i = 0; i < numSquares; i++)
		{
			colors[i].set(255, 255, 255);  //set all squares to white
		}


		for (int i = 0; i < currentActive; i++) //choose (currentActive) indexes to be the active squares
		{
			activeSquares[i] = rand() % numSquares; //generating a random index

		
			for (int j = 0; j < currentActive; j++)
			{
			
				while (activeSquares[i] == activeSquares[j] && i != j)
				{
					activeSquares[i] = rand() % numSquares;
					j = 0; //restart the check
				}

			}

			colors[activeSquares[i]].set(0, 0, 255);  //set all active squares to blue
		}

		for (int i = 0; i < currentActive; i++) //generating a random sequence order for the active squares
		{
			order[i] = 1 + rand() % (currentActive);

			for (int j = 0; j < currentActive; j++)
			{
				while (order[i] == order[j] && i != j) //if the index generated already exists, generate new index
				{
					order[i] = 1 + rand() % (currentActive);
					j = 0; //restart the check
				}
			}
		}



		for (int i = 0; i < numSquares; i++) //setting the squares positions
		{
			int row = i / rowsNcols;
			int col = i % rowsNcols;

			squares[i].set(150 + col * (squareSize + spacing), 150 + row * (squareSize + spacing), squareSize);
		}
	}


	bool isSquareActive(int index)
	{
		for (int i = 0; i < currentActive; i++)
		{
			if (activeSquares[i] == index)
			{
				return(true);
			}
		}
		return(false);
	}


	void displayLoseScreen()
	{
		ofSetBackgroundColor(255, 255, 255);
		ofSetColor(255, 255, 255);

		ofImage background;
		background.load("backgroundStart.jpg");
		background.draw(0, 0);
		
		ofPushStyle();

		ofSetColor(0, 255, 0);
		ofDrawRectangle(newGameButton);
		ofDrawRectangle(mainMenuButton);

		

		ofSetColor(0, 0, 0);
		titleFont.drawString("YOU LOST!", 375, 300);
		titleFont.drawString("NEW GAME", 365, 525);
		titleFont.drawString("MAIN MENU", 355, 725);

		ofPopStyle();


	}

	void resetGameSettings()
	{
		level = 1;
		rootSquares = 3;
		currentActive = 3;
	}



	void keyPressed(int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y);
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void mouseEntered(int x, int y);
	void mouseExited(int x, int y);
	void windowResized(int w, int h);
	void dragEvent(ofDragInfo dragInfo);
	void gotMessage(ofMessage msg);
};
