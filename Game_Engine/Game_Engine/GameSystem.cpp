#include "GameSystem.h"


void GameLoop::handleMessage(Msg *msg)
{
	switch (msg->type)
	{
	case three:
		std::cout << "almost exiting\r\n";
		break;
	case game_exit:
		std::cout << "exiting\r\n";
		isPlaying = false;
		break;
	}
};

void DummySystem::handleMessage(Msg *msg)
{
	switch (msg->type)
	{
	case one:
		std::cout << "one\r\n";
		break;
	case two:
		std::cout << "two\r\n";
		break;
	}
};

