#include <SFML/Graphics.hpp>
#include <Windows.h>
#include<iostream>
#include<fstream>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

using namespace sf;


int game = 1, speed = 500, size = 2;
int dir;
int score = 0;
int* difficulty = new int (1);
int highscore = 0;
int randomx = 0;
int randomy = 0;
bool good = true;

class Snake
{
public:
	int x = 0;
	int y = 0;
};
Snake s[100];



class Menu
{
protected:
	int select = 0;
	sf::Font font;
	sf::Text text[3];

public:
	Menu()
	{
		font.loadFromFile("Fonts/Calibri.ttf");

		// Play
		text[0].setFont(font);
		text[0].setFillColor(Color::White);
		text[0].setString("Play");
		text[0].setCharacterSize(70);
		text[0].setPosition(150, 150);

		// Options
		text[1].setFont(font);
		text[1].setFillColor(Color::White);
		text[1].setString("Options");
		text[1].setCharacterSize(70);
		text[1].setPosition(150, 250);

		// Exit
		text[2].setFont(font);
		text[2].setFillColor(Color::White);
		text[2].setString("Exit");
		text[2].setCharacterSize(70);
		text[2].setPosition(150, 350);

		select = -1;
	}

	void draw(sf::RenderWindow& window)
	{
		for (int i = 0; i < 3; i++)
		{
			window.draw(text[i]);
		}
	}

	void up()
	{
		text[select].setFillColor(sf::Color::White);

		select--;
		if (select < 0)
		{
			select = 2;
		}
		text[select].setFillColor(Color::Blue);
	}

	void down()
	{
		text[select].setFillColor(sf::Color::White);

		select++;
		if (select >= 3)
		{
			select = 0;
		}
		text[select].setFillColor(Color::Blue);
	}

	int press()
	{
		return select;
	}
};

class OptionsMenu : public Menu
{
public:
	OptionsMenu() : Menu()
	{
		// Snake Color
		text[0].setString("Snake Color");
		text[0].setPosition(150, 150);

		// Fruit
		text[1].setString("Fruit");
		text[1].setPosition(150, 250);

		// Back
		text[2].setString("Back");
		text[2].setPosition(150, 350);

	}
};


class scmenu   //snake color menu
{
protected:
	int select = 0;
	sf::Font font;


private:

	sf::Text sctext[6];

public:
	scmenu()
	{
		font.loadFromFile("Fonts/Calibri.ttf");
		//play
		sctext[0].setFont(font);
		sctext[0].setFillColor(Color::White);
		sctext[0].setString("Blue");
		sctext[0].setCharacterSize(70);
		sctext[0].setPosition(200, 100);

		//options
		sctext[1].setFont(font);
		sctext[1].setFillColor(Color::White);
		sctext[1].setString("Yellow");
		sctext[1].setCharacterSize(70);
		sctext[1].setPosition(200, 200);

		//exit
		sctext[2].setFont(font);
		sctext[2].setFillColor(Color::White);
		sctext[2].setString("Red");
		sctext[2].setCharacterSize(70);
		sctext[2].setPosition(200, 300);

		//play
		sctext[3].setFont(font);
		sctext[3].setFillColor(Color::White);
		sctext[3].setString("Pink");
		sctext[3].setCharacterSize(70);
		sctext[3].setPosition(200, 400);

		//play
		sctext[4].setFont(font);
		sctext[4].setFillColor(Color::White);
		sctext[4].setString("White");
		sctext[4].setCharacterSize(70);
		sctext[4].setPosition(200, 500);

		//play
		sctext[5].setFont(font);
		sctext[5].setFillColor(Color::White);
		sctext[5].setString("Back");
		sctext[5].setCharacterSize(70);
		sctext[5].setPosition(200, 600);

		select = -1;
	}

	void draw(sf::RenderWindow& scwindow)
	{
		for (int i = 0; i < 6; i++)
		{
			scwindow.draw(sctext[i]);
		}
	}
	void up()
	{
		sctext[select].setFillColor(sf::Color::White);

		select--;
		if (select < 0)
		{
			select = 5;
		}
		sctext[select].setFillColor(Color::Blue);

	}
	void down()
	{
		sctext[select].setFillColor(sf::Color::White);

		select++;
		if (select >= 6)
		{
			select = 0;
		}
		sctext[select].setFillColor(Color::Blue);
	}

	int press()
	{
		return select;
	}

};

class fruitmenu
{
protected:
	int select = 0;
	sf::Font font;


private:

	sf::Text fruit[6];

public:
	fruitmenu()
	{
		font.loadFromFile("Fonts/Calibri.ttf");
		//play
		fruit[0].setFont(font);
		fruit[0].setFillColor(Color::White);
		fruit[0].setString("Berry");
		fruit[0].setCharacterSize(70);
		fruit[0].setPosition(200, 100);

		//options
		fruit[1].setFont(font);
		fruit[1].setFillColor(Color::White);
		fruit[1].setString("Orange");
		fruit[1].setCharacterSize(70);
		fruit[1].setPosition(200, 200);

		//exit
		fruit[2].setFont(font);
		fruit[2].setFillColor(Color::White);
		fruit[2].setString("Apple");
		fruit[2].setCharacterSize(70);
		fruit[2].setPosition(200, 300);

		//play
		fruit[3].setFont(font);
		fruit[3].setFillColor(Color::White);
		fruit[3].setString("Lemon");
		fruit[3].setCharacterSize(70);
		fruit[3].setPosition(200, 400);

		//play
		fruit[4].setFont(font);
		fruit[4].setFillColor(Color::White);
		fruit[4].setString("Grape");
		fruit[4].setCharacterSize(70);
		fruit[4].setPosition(200, 500);

		//play
		fruit[5].setFont(font);
		fruit[5].setFillColor(Color::White);
		fruit[5].setString("Back");
		fruit[5].setCharacterSize(70);
		fruit[5].setPosition(200, 600);

		select = -1;
	}

	void draw(sf::RenderWindow& scwindow)
	{
		for (int i = 0; i < 6; i++)
		{
			scwindow.draw(fruit[i]);
		}
	}
	void up()
	{
		fruit[select].setFillColor(sf::Color::White);

		select--;
		if (select < 0)
		{
			select = 5;
		}
		fruit[select].setFillColor(Color::Blue);

	}
	void down()
	{
		fruit[select].setFillColor(sf::Color::White);

		select++;
		if (select >= 6)
		{
			select = 0;
		}
		fruit[select].setFillColor(Color::Blue);
	}

	int press()
	{
		return select;
	}

};

int main()
{
	{
		std::ifstream file;
		file.open("highscore.txt");
		if (file.is_open())
		{
			file >> highscore;
			file.close();
		}

	}

	Texture square, refresh, bg, food;
	square.loadFromFile("assets/body1.png");
	refresh.loadFromFile("assets/retry.png");
	bg.loadFromFile("assets/Untitled-1.png");
	food.loadFromFile("assets/fruit.png");

	Sprite snake(square), red(food), Refresh(refresh), fondo(bg);
	snake.setPosition(0, 0);
	snake.setColor(sf::Color(32,0,64));
	snake.setScale(0.819, 0.819);
	red.setPosition(1000, 0);
	red.setColor(sf::Color::Red);
	fondo.setPosition(400, 50);
	fondo.setScale(0.685, 0.55);
	red.setScale(0.08, 0.08);

	int e = 0;
	// Create a window
	sf::RenderWindow window(sf::VideoMode(960, 720), "Snake Game", sf::Style::Fullscreen);

	// Background
	RectangleShape bgm;
	bgm.setSize(Vector2f(1366, 768));

	Texture bgt;
	bgt.loadFromFile("assets/mainbgr.png");
	bgm.setTexture(&bgt);

	//game textures 

	Menu mainMenu;
	OptionsMenu optionsMenu;

	bool showOptionsMenu = false;

	// Game loop
	while (window.isOpen())
	{
		e = 0;

		// Handle events
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			if (!showOptionsMenu && event.type == Event::KeyReleased)
			{
				if (event.key.code == Keyboard::Up)
				{
					mainMenu.up();
					break;
				}
				else if (event.key.code == Keyboard::Down)
				{
					mainMenu.down();
					break;
				}
				else if (event.key.code == Keyboard::Return)
				{
					int x = mainMenu.press();
					if (x == 0)
					{
						RenderWindow Play(VideoMode(1366, 768), "Snake Game", sf::Style::Fullscreen);
						while (Play.isOpen())
						{
							game = 1;
							Play.requestFocus();
							Event aevent;

							sf::RectangleShape playzone;
							playzone.setPosition(400, 50);
							playzone.setOutlineThickness(10);
							playzone.setFillColor(sf::Color::Transparent);
							playzone.setOutlineColor(sf::Color::Black);
							playzone.setSize(sf::Vector2f(750, 595));

							//to set snake start in the playzone
							s[0].x = 450;
							s[0].y = 100;

						

							Font font;
							font.loadFromFile("Fonts/Calibri.ttf");

							Text Score;
							Score.setFont(font);
							Score.setCharacterSize(100);
							Score.setStyle(Text::Bold);
							Score.setString("SCORE : " + std::to_string(score));
							Score.setPosition(60, 200);
							Score.setScale(0.5, 0.5);

							Text Highscore;
							Highscore.setFont(font);
							Highscore.setCharacterSize(100);
							Highscore.setStyle(Text::Bold);
							Highscore.setString("HIGH SCORE: " + std::to_string(highscore));
							Highscore.setPosition(60, 300);
							Highscore.setScale(0.5, 0.5);

							Text NewHighscore;  //New High score
							NewHighscore.setFont(font);
							NewHighscore.setCharacterSize(100);
							NewHighscore.setStyle(Text::Bold);
							NewHighscore.setString(" ");
							NewHighscore.setFillColor(sf::Color::Black);
							NewHighscore.setPosition(50, 700);
							NewHighscore.setScale(0.5, 0.5);


							Text Difficulty;  // Difficulty
							Difficulty.setFont(font);
							Difficulty.setCharacterSize(100);
							Difficulty.setStyle(Text::Bold);
							Difficulty.setString("DIFFICULTY : " + std::to_string(*difficulty));
							Difficulty.setPosition(60, 400);
							Difficulty.setScale(0.5, 0.5);


							// generation random values of randomx and randomy
							srand(time(NULL));
							randomx = 450 + rand() % 551;
							randomy = 100 + rand() % 406;

							for (int i = 0; i < 12; i++)  //crreating a grid here to place fruit inside
							{
								if (randomx <= (i + 1) * 50 + 400 && randomx > i * 50 + 400)
								{
									randomx = (i + 1) * 50 + 400;
								}
								if (randomy <= (i + 1) * 50 && randomy > i * 50)
								{
									randomy = (i + 1) * 50;
								}
							}




							while (Play.isOpen())
							{

								Vector2i pos = Mouse::getPosition(Play);

								while (Play.pollEvent(aevent))
								{
									if (aevent.type == Event::Closed)
									{
										Play.close();
									}

									if (aevent.type == Event::MouseButtonReleased || aevent.type == Event::KeyReleased)
									{
										if (aevent.key.code == Mouse::Left || aevent.key.code == Keyboard::Return)
										{
											if (Refresh.getGlobalBounds().contains(pos.x, pos.y))
											{
												if (game == 2)
												{

													score = 0;
													Highscore.setString("High Score: " + std::to_string(highscore));


													Score.setString("SCORE : " + std::to_string(score));

													NewHighscore.setString(" ");

													(*difficulty) = 1;
													Difficulty.setString("DIFFICULTY : " + std::to_string(*difficulty));
													
													Play.draw(NewHighscore);
													Play.draw(Difficulty);
													game = 1;
													Refresh.setPosition(1000, 0);
													size = 2;
													s[0].x = 450;
													s[0].y = 100;
													dir = 0;
													speed = 700;
													good = true;
													while (good)  // this while loop checks that if fruit is spawned on the snake position then try again
													{
														randomx = 450 + rand() % 551;
														randomy = 100 + rand() % 406;

														for (int i = 0; i < 12; i++)
														{
															if (randomx <= (i + 1) * 50 + 400 && randomx > i * 50 + 400)
															{
																randomx = (i + 1) * 50 + 400;
															}
															if (randomy <= (i + 1) * 50 && randomy > i * 50)
															{
																randomy = (i + 1) * 50;
															}
														}

														for (int i = 0; i < size; i++)
														{
															if (randomx != s[i].x || randomy != s[i].y)
															{
																good = false;
															}
														}
													}
												}
											}
										}
									}

									if (aevent.type == Event::KeyPressed)
									{
										if (game == 1)
										{
											/*if (aevent.key.code == Keyboard::V && dir != 1)
											{
												snake.setColor(sf::Color::Green);
											}
											if (aevent.key.code == Keyboard::C && dir != 1)
											{
												snake.setColor(sf::Color::Magenta);
											}*/
											if (aevent.key.code == Keyboard::Right && dir != 1)
											{
												dir = 0;
											}
											else if (aevent.key.code == Keyboard::Left && dir != 0)
											{
												dir = 1;
											}
											else if (aevent.key.code == Keyboard::Down && dir != 3)
											{
												dir = 2;
											}
											else if (aevent.key.code == Keyboard::Up && dir != 2)
											{
												dir = 3;
											}
											else if (aevent.key.code == Keyboard::Escape)
											{
												game = 2;
												score = 0;
												Highscore.setString("High Score: " + std::to_string(highscore));

												Score.setString("SCORE : " + std::to_string(score));

												(*difficulty) = 1;
												Difficulty.setString("DIFFICULTY : " + std::to_string(*difficulty));

												game = 1;
												Refresh.setPosition(1000, 0);
												size = 2;
												s[0].x = 450;
												s[0].y = 100;
												dir = 0;
												speed = 700;
												Play.close();
											}
										}
									}
								}
								Play.clear(Color(64, 64, 64));  //change background colour of the game

								if (game == 1)
								{
									Refresh.setPosition(1000, 0);
									Play.draw(fondo);
									if (s[0].x >= 1200 || s[0].x < 450 || s[0].y >= 650 || s[0].y < 100 || s[0].x >= playzone.getPosition().x + playzone.getSize().x || s[0].x < playzone.getPosition().x || s[0].y >= playzone.getPosition().y + playzone.getSize().y || s[0].y < playzone.getPosition().y)
									{
										score = 0;
										game = 2;
									}

									for (int i = size; i > 0; i--)
									{
										s[i].x = s[i - 1].x;
										s[i].y = s[i - 1].y;
									}

									if (dir == 0)
									{
										s[0].x += 50;
									}
									if (dir == 1)
									{
										s[0].x -= 50;
									}
									if (dir == 2)
									{
										s[0].y += 50;
									}
									if (dir == 3)
									{
										s[0].y -= 50;
									}

									if (s[0].x >= 1100 || s[0].x < 450 || s[0].y >= 600 || s[0].y < 100) // if the snake touches the boundary then game over
									{
										score = 0;
										Score.setString("SCORE : " + std::to_string(score));
										game = 2;
									}

									for (int i = 1; i < size; i++) // this loop checks if the snake touches itself then game over
									{
										if (s[0].x == s[i].x && s[0].y == s[i].y)
										{
											score = 0;
											Score.setString("SCORE : " + std::to_string(score));
											game = 2;
										}
									}

									if (s[0].x == red.getPosition().x && s[0].y == red.getPosition().y) 
									{ 
										// sets the score and maintains the high score the file
										score++;
										Score.setString("SCORE : " + std::to_string(score));
										if (score > highscore) {
											highscore = score;
											std::ofstream highscoreFile("highscore.txt");
											if (highscoreFile.is_open()) {
												highscoreFile << highscore;
												highscoreFile.close();
											}
											
												NewHighscore.setString("New High Score");
												
										}
										
										if (size % 5 == 0) // increases the dificulty
										{
											(*difficulty)++;
											Difficulty.setString("DIFFICULTY : " + std::to_string(*difficulty));
											Play.draw(Difficulty);
										}

										size += 1;
										if (speed > 100) // this decreases the delay and increases the speed
										{
											speed -= 20;
										}
										good = true;
										while (good)
										{
											randomx = 450 + rand() % 551;
											randomy = 100 + rand() % 406;

											for (int i = 0; i < 12; i++)
											{
												if (randomx <= (i + 1) * 50 + 400 && randomx > i * 50 + 400)
												{
													randomx = (i + 1) * 50 + 400;
												}
												if (randomy <= (i + 1) * 50 && randomy > i * 50)
												{
													randomy = (i + 1) * 50;
												}
											}

											for (int i = 0; i < size; i++)
											{
												if (randomx == s[i].x && randomy == s[i].y)
												{
													break;
												}
												else if ((randomx != s[i].x || randomx != s[i].x) && i == size - 1)
												{
													good = false;
												}
											}
										}
									}
									
									red.setPosition(randomx, randomy);
									Play.draw(red);

									for (int i = 0; i < size; i++) //drawing snake
									{
										snake.setPosition(s[i].x, s[i].y);
										Play.draw(snake);

									}

									Play.draw(Score);
									Highscore.setPosition(60, 300);
									Play.draw(Highscore);									
									Play.draw(NewHighscore);
									Play.draw(Difficulty);
									Play.draw(playzone);
									Play.display();
									Sleep(speed);
								}
								else if (game == 2)
								{
									Play.clear(Color(0, 128, 128));
									//Play.draw(fondo);
									Refresh.setPosition(450, 300);
									Play.draw(Refresh);
									Play.display();
									if (aevent.type == Event::KeyReleased)
									{
										if (aevent.key.code == Keyboard::Escape)
										{
											Play.close();

											score = 0;
											Highscore.setString("High Score: " + std::to_string(highscore));


											Score.setString("SCORE : " + std::to_string(score));

											NewHighscore.setString(" ");

											(*difficulty) = 1;
											Difficulty.setString("DIFFICULTY : " + std::to_string(*difficulty));

											Play.draw(NewHighscore);
											Play.draw(Difficulty);
											game = 1;
											Refresh.setPosition(1000, 0);
											size = 2;
											s[0].x = 450;
											s[0].y = 100;
											dir = 0;
											speed = 700;

											break;
										}
									}
								}

							}
						
							Play.clear();
							Play.display();
						}
					}
					else if (x == 1)
					{
						showOptionsMenu = true;
					}
					else if (x == 2)
					{
						window.close();
					}
				}
			}
			else if (showOptionsMenu && event.type == Event::KeyReleased)
			{
				if (event.key.code == Keyboard::Up)
				{
					optionsMenu.up();
					break;
				}
				else if (event.key.code == Keyboard::Down)
				{
					optionsMenu.down();
					break;
				}
				else if (event.key.code == Keyboard::Return)
				{
					int x = optionsMenu.press();
					if (x == 0)
					{
						
						sf::RenderWindow scwindow(sf::VideoMode(1366, 768), "Color Menu", sf::Style::Fullscreen);

						//back ground
						RectangleShape bgsc;
						bgsc.setSize(Vector2f(1366, 768));

						Texture bgs;
						bgs.loadFromFile("assets/snakecolor.png");
						bgsc.setTexture(&bgs);

						scmenu sctext;

						while (scwindow.isOpen())
						{

							// Handle events
							sf::Event scevent;
							while (scwindow.pollEvent(scevent))
							{

								if (scevent.type == sf::Event::Closed)
									scwindow.close();

								if (scevent.type == Event::KeyReleased)
								{
									if (scevent.key.code == Keyboard::Escape)
									{
										scwindow.close();
										break;
									}
								}

								if (scevent.type == Event::KeyReleased)
								{
									if (scevent.key.code == Keyboard::Up)
									{
										sctext.up();
										break;
									}
								}
								if (scevent.type == Event::KeyReleased)
								{
									if (scevent.key.code == Keyboard::Down)
									{
										sctext.down();
										break;
									}
								}
								if (scevent.key.code == Keyboard::Return)
								{

									int x = sctext.press();
									if (x == 0)
									{
										snake.setColor(sf::Color::Cyan);

										
									}

									if (x == 1)
									{
										snake.setColor(sf::Color::Yellow);
										e = 1;
										
									}

									if (x == 2)
									{
										snake.setColor(sf::Color::Red);
										e = 1;
										
									}

									if (x == 3)
									{
										snake.setColor(sf::Color::Magenta);
										e = 1;
										
									}

									if (x == 4)
									{
										snake.setColor(sf::Color::White);
										e = 1;
										
									}

									if (x == 5)
									{
										e = 1;
										
										break;
									}

								}


							}
							// Clear the window
							scwindow.clear();
							// Draw the window							
							scwindow.draw(bgsc);
							sctext.draw(scwindow);

							if (e < 2 && e>0)
							{
								scwindow.close();
							}
							// Display the contents of the window
							scwindow.display();

						}

					}

					else if (x == 1)
					{

						sf::RenderWindow fruitwindow(sf::VideoMode(1366, 768), "Fruit Menu", sf::Style::Fullscreen);

						//back ground
						RectangleShape bgsc;
						bgsc.setSize(Vector2f(1366, 768));

						Texture bgs;
						bgs.loadFromFile("assets/selectfruit.png");
						bgsc.setTexture(&bgs);

						fruitmenu fruit;

						while (fruitwindow.isOpen())
						{

							// Handle events
							sf::Event fevent;
							while (fruitwindow.pollEvent(fevent))
							{

								if (fevent.type == sf::Event::Closed)
									fruitwindow.close();

								if (fevent.type == Event::KeyReleased)
								{
									if (fevent.key.code == Keyboard::Escape)
									{
										fruitwindow.close();
										break;
									}
								}
								
								if (fevent.type == Event::KeyReleased)
								{
									if (fevent.key.code == Keyboard::Up)
									{
										fruit.up();
										break;
									}
								}
								if (fevent.type == Event::KeyReleased)
								{
									if (fevent.key.code == Keyboard::Down)
									{
										fruit.down();
										break;
									}
								}
								if (fevent.key.code == Keyboard::Return)
								{

									int x = fruit.press();
									if (x == 0)
									{
										red.setColor(sf::Color::Blue);
										e = 1;
										
									}

									if (x == 1)
									{
										red.setColor(sf::Color(255, 128, 0));
										e = 1;
										

									}

									if (x == 2)
									{
										red.setColor(sf::Color::Red);
										e = 1;
										
									}

									if (x == 3)
									{
										red.setColor(sf::Color::Yellow);
										e = 1;
										
									}

									if (x == 4)
									{
										red.setColor(sf::Color::Green);
										e = 1;
										
									}

									if (x == 5)
									{
										e = 1;
										
										break;
									}

								}


							}
							// Clear the window
							fruitwindow.clear();
							// Draw the window							
							fruitwindow.draw(bgsc);
							fruit.draw(fruitwindow);

							if (e < 2 && e>0)
							{
								fruitwindow.close();
							}
							// Display the contents of the window
							fruitwindow.display();

						}
					}
					else if (x == 2)
					{
						showOptionsMenu = false;
					}
				}
			}
		}

		// Clear the window
		window.clear();

		// Draw the menu
		window.draw(bgm);
		if (showOptionsMenu)
		{
			optionsMenu.draw(window);
		}
		else
		{
			mainMenu.draw(window);
		}

		// Display the contents of the window
		window.display();
	}
	delete difficulty;
	return 0;
}
