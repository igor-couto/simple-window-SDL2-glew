#include <iostream>
#include <SDL.h>

int main(int argc, char *argv[]){
	
	int width(1600);
	int height(900);

	SDL_GLContext m_glContext;
	SDL_Window * m_window;
	
	SDL_Init(SDL_INIT_EVERYTHING);

	SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8); // Number of bits used to display shades of red
	SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_BUFFER_SIZE, 32); // Sum of bits above. Space of a pixel
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1); // Enable double buffer
	
	m_window = SDL_CreateWindow(  "Title",
								SDL_WINDOWPOS_UNDEFINED,
								SDL_WINDOWPOS_UNDEFINED,
								width,
								height,
								SDL_WINDOW_OPENGL );
	
    if (m_window == NULL) {
		std::cerr << "Could not create window: " << SDL_GetError();
        return 1;
    }
	
	m_glContext = SDL_GL_CreateContext(m_window);
	
	
	GLenum status = glewInit();
	if(status != GLEW_OK){
		std::cerr << "Glew failed to initialize.";
	}
	
	while(!m_isClosed){
			glClearColor(0.0, 0.0, 1.0, 0.0); // Set the clear color. Just Set.
			glClear(GL_COLOR_BUFFER_BIT);
			Update(m_window);
	}

	SDL_GL_DeleteContext(m_glContext);
	SDL_DestroyWindow(m_window);
	SDL_Quit();
	
	return 0;
}

void Update(SDL_Window * m_window){
	SDL_GL_SwapWindow(m_window);
	
	SDL_Event e;
	
	while(SDL_PollEvent(&e)){
		if(e.type == SDL_QUIT){
			m_isClosed = true;
		}
	}
}
