#include "ofApp.h"
#include "square.h"

//--------------------------------------------------------------
void ofApp::setup() {
	ofSetBackgroundColor(255, 255, 255);

	correctClick.load("correctSquare.wav");
	gameLost.load("gameLost.wav");

	titleFont.load("C:\\Users\\asfah\\Downloads\\open-sans\\OpenSans-Regular.ttf", 36);
	rulesFont.load("C:\\Users\\asfah\\Downloads\\open-sans\\OpenSans-Regular.ttf", 20);

	startButton.set(500 - 150, 500 - 75, 300, 150);
	rulesButton.set(500 - 150, 700 - 75, 300, 150);
	rulesBackButton.set(500 - 150, 800 - 75, 300, 150);
	newGameButton.set(500 - 150, 500 - 75, 300, 150);
	mainMenuButton.set(500 - 150, 700 - 75, 300, 150);

	rootSquares = 3;
	gameStatus = 0;
	level = 1;
	currentActive = 3;

	setupNewRound();

}

//--------------------------------------------------------------
void ofApp::update() {







}

//--------------------------------------------------------------
void ofApp::draw() {
	if (gameStatus == 0)
	{
		displayStartScreen();
	}

	if (gameStatus == 1)
	{
		displayRulesScreen();
	}

	if (gameStatus == 2)
	{
		displayGame();
	}

	if (gameStatus == 3)
	{
		displayLoseScreen();
	}


}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {

	if (gameStatus == 0) //if in start screen
	{
		if (rulesButton.inside(x, y) == true)
		{
			gameStatus = 1; //show the rules screen
		}

		if (startButton.inside(x, y) == true)
		{
			gameStatus = 2; //start the game
		}
	}

	if (gameStatus == 1) //if in rules screen
	{
		if (rulesBackButton.inside(x, y) == true)
		{
			gameStatus = 0;
		}
	}

	if (gameStatus == 2) //if in game
	{
		for (int i = 0; i < currentActive; i++)
		{
			
			if (squares[activeSquares[i]].inside(x, y) == true) //did user click inside an active square
			{
				if (squares[activeSquares[i]].number == orderCheck) //is the clicked active square the correct order
				{
					correctClick.play();
					colors[activeSquares[i]].set(0, 255, 0);
					orderCheck = orderCheck + 1;

					if (orderCheck == 2)
					{
						showNumbers = false; //hide the numbers after the first square is clicked
					}
				}

				else
				{
					gameStatus = 3;
					gameLost.play();
				}
			}


		}

		// Check if all active squares are clicked in the correct order
		if (orderCheck > currentActive)
		{
			level = level + 1;     //if yes, go to next level and set up the round
			currentActive = currentActive + 1;
			setupNewRound();

		}
	}

	if (gameStatus == 3) //if game lost
	{
		resetGameSettings(); //reset game settings

		if (newGameButton.inside(x, y) == true)
		{
			gameStatus = 2;
			setupNewRound();
			return;
		}

		if (mainMenuButton.inside(x, y) == true)
		{
			gameStatus = 0;
			setupNewRound();
			return;
		}

	}


}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {

}