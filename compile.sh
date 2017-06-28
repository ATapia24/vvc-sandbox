#!/bin/sh
g++ -o sandbox *.cpp -std=c++11 -Ifreenect2/include -Iglad/include -Iglew2/include -Lglew2/lib -I/usr/local/lib -L/usr/local/include -Lfreenect2/lib -lfreenect2 -lglfw3 -lpthread -lXrandr -lXi -lXrender -ldrm -lXdamage -lXxf86vm -lXext -lX11 -lm -ldl -lXinerama -lXcursor -lGLEW -lGLU -lGL

