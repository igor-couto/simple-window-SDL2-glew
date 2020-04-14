# simple-window-SDL2-glew
A simple exemple of how to open a window with SDL2 (2.0.5 stable) and initialize OpenGl stuff with Glew.
  
I compile it with g++ (Mingw32) using this:
  
`g++ main.cpp --std=c++14 -Wall -I../include -L../lib -lmingw32 -lSDL2main -lSDL2 -lglew32s -lopengl32 -o main`	
  
It won't work on Visual Studio compiler though. The glew library I'm using is not the defaulf one downloaded in the site, witch uses VS compiler. In order to make it work with mingw32 I had to compile it and using it as a static library and add the preprocessor directive "#define GLEW_STATIC" in the first line.
