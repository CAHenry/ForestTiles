#pragma once
#include <vector>
#include <iostream>
#include <queue>
#include <thread>
#include <string>
#include <mutex>
#include <iterator>
#include <Windows.h>

enum message_types { one, two, three, game_exit};

class Msg
{
public:
	Msg(message_types);
	Msg(const std::string& str);
	message_types type;
};

class System
{
public:
	virtual void handleMessage(Msg *msg);
};


class MsgBus
{
public:
	MsgBus();
	~MsgBus();
	void addReceiver(System *messageReceiver);

	void sendMessage(Msg message);

	void notify();

private:
	void input();
	std::thread consoleInput;
	std::mutex consoleMutex;
	std::queue<Msg> messages;
	std::vector<System*> receivers;
};

class Console
{
public:
private:
	MsgBus _msgBus;
};

