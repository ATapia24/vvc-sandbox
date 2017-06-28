//VVC VIRTUAL SANDBOX
//6-20-2017
//ADRIAN TAPIA

#include <iostream>
#include <thread>
#include "KinectManager.h"
#include "Window.h"

int main() {
	//Window window(1600, 900, "sandbox", true);
	//window.draw();

	Window window(1600, 900, "sandbox", false);
	std::thread t1(&Window::draw, window);

	while(true){}

	//pthread_create(&windowThread, NULL, drawLoop, NULL);
	//window.loop();

    //KinectManager kinectMgr;
    //kinectMgr.connect();
    //kinectMgr.captureLoop();
    return 0;
}