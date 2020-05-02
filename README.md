# Simple window setup with SDL2 and glew

A basic and straightforward exemple of how to open a window with SDL2 (2.0.5 stable) and initialize OpenGl stuff with Glew.
  
I compile it with GCC g++ (Mingw32) using this:
  
`g++ main.cpp --std=c++14 -Wall -I../include -L../lib -lmingw32 -lSDL2main -lSDL2 -lglew32s -lopengl32 -o main`	
  
It won't work with Visual Studio compiler though. The glew library I'm using is not the defaulf one downloaded in the site, witch uses VS compiler. In order to make it work with mingw32 I had to compile it and using it as a static library and add the preprocessor directive "#define GLEW_STATIC".

### Author

* **Igor Couto** - [igor.fcouto@gmail.com](mailto:igor.fcouto@gmail.com)
