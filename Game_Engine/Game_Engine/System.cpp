#include "System.h"

Msg::Msg(message_types msg_type) : type(msg_type) {};

Msg::Msg(const std::string& str)
{
	if (str == "one") this->type = one;
	else if (str == "two") this->type = two;
	else if (str == "three") this->type = three;
	else if (str == "game_exit") this->type = game_exit;
}

MsgBus::MsgBus()
{
	consoleInput = std::thread(&MsgBus::input, this);
}

MsgBus::~MsgBus()
{
	consoleInput.join();
}


void MsgBus::input()
{
	while (true)
	{
		std::string inputString;
		std::cin >> inputString;
		consoleMutex.lock();
		messages.push(Msg(inputString));
		consoleMutex.unlock();
		if (inputString == "game_exit")
		{
			break;
		}
	}
	OutputDebugString("Console thread closing\r\n");
};

void MsgBus::addReceiver(System *messageReceiver)
{
	receivers.push_back(messageReceiver);
}

void MsgBus::sendMessage(Msg message)
{
	messages.push(message);
}

void MsgBus::notify()
{
	consoleMutex.lock();
	while (!messages.empty()) {
		for (std::vector<System*>::iterator iter = receivers.begin(); iter != receivers.end(); iter++) {
			(**iter).handleMessage(&messages.front());
		}

		messages.pop();
	}
	consoleMutex.unlock();
}


void System::handleMessage(Msg *msg)
{
	switch (msg->type)
	{
	case one:
		std::cout << "la\r\n";
	}
};


