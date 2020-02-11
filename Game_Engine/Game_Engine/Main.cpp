#include "System.h"
#include "GameSystem.h"
int main()
{
	DummySystem dummySystem;
	GameLoop gameSystem;
	MsgBus messageBus;
	messageBus.addReceiver(&dummySystem);
	messageBus.addReceiver(&gameSystem);
	gameSystem.handleMessage(&Msg(three));
	dummySystem.handleMessage(&Msg(one));

	System *systemPointer = &dummySystem;
	(*systemPointer).handleMessage(&Msg(one));

	while (gameSystem.isPlaying)
	{
		messageBus.notify();
	}
	return 0;
}