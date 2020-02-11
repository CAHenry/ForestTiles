#pragma once
#include "System.h"

class GameLoop : public System
{
public:
	bool isPlaying = true;

	void handleMessage(Msg *msg) override;
};

class DummySystem : public System
{
public:
	void handleMessage(Msg *msg) override;
};
