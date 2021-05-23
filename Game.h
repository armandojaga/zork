#ifndef ZORK_GAME_H
#define ZORK_GAME_H

#include "parsers//CommandParser.h"
#include "characters/Hero.h"
#include "parsers/SceneParser.h"
#include "commands/AbstractCommand.h"

class Game
{
private:
	SceneParser* sceneParser;
	CommandParser* commandParser;
	Hero* hero;
	void Loop() const;
	static void ExecuteCommand(AbstractCommand* command);

public:
	Game();
	Game(const Game&) = delete;
	Game& operator =(const Game&) = delete;
	Game(Game&&) = delete;
	Game& operator=(Game&&) = delete;

	~Game() = default;

	void Start() const;
};

#endif  //ZORK_GAME_H
