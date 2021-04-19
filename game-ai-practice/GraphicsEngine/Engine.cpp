#include <stdexcept>
#include <SDL2/SDL.h>
#include <gl/glew.h>
#include <sstream>
#include <imgui.h>
#include <imgui_impl_opengl3.h>
#include <imgui_impl_sdl.h>

#include "Engine.h"

void Engine::Init()
{
    SDL_Init(SDL_INIT_VIDEO);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 6);
    SDL_GL_SetAttribute(SDL_GL_MULTISAMPLEBUFFERS, 1);
    SDL_GL_SetAttribute(SDL_GL_MULTISAMPLESAMPLES, 4);

    this->window = SDL_CreateWindow("Game AI Demo", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600,
        SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE);
    if (window == nullptr)
    {
        throw std::runtime_error{ "Failed to create SDL2 Window" };
    }

    this->glContext = SDL_GL_CreateContext(window);
    if (glContext == nullptr)
    {
        throw std::runtime_error{ "Failed to create OpenGL Context" };
    }


    if (GLenum value = glewInit(); value != GLEW_OK)
    {
        std::ostringstream msg;
        msg << "Failed to init glew : " << glewGetErrorString(value);
        throw std::runtime_error{ msg.str() };
    }

    //IMGUI_CHECKVERSION();
    //ImGui::CreateContext();
    //ImGui_ImplSDL2_InitForOpenGL(window, glContext);
    //ImGui_ImplOpenGL3_Init("#version 330");

    SDL_GL_SetSwapInterval(1);

    SDL_GetWindowSize(window, &windowWidth, &windowHeight);
    SDL_GetMouseState(&mouseX, &mouseY);

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

    shader.Init();
}

void Engine::Update()
{
    SDL_Event event{ 0 };
    while (SDL_PollEvent(&event) != 0)
    {
        switch (event.type)
        {
        case SDL_QUIT: isDone = true; break;
        case SDL_KEYDOWN:
            if (event.key.keysym.sym == SDLK_ESCAPE)
            {
                isDone = true;
            }
            else
            {
            }
            break;
        case SDL_MOUSEMOTION:
        {
            mouseX = event.motion.x;
            mouseY = event.motion.y;
            std::string title = std::to_string(mouseX) + ", " + std::to_string(mouseY);
            SDL_SetWindowTitle(window, title.c_str());
            break;
        }
        case SDL_WINDOWEVENT:
            if (event.window.event == SDL_WINDOWEVENT_RESIZED)
            {
                const auto WIDTH = event.window.data1;
                const auto HEIGHT = event.window.data2;
                windowWidth = WIDTH;
                windowHeight = HEIGHT;
                glViewport(0, 0, WIDTH, HEIGHT);
            }
            break;
        }
    }

    if (nextScene != nullptr)
    {
        currentScene = nextScene;
        nextScene = nullptr;
        currentScene->Init();
    }

    glClearColor(0.5F, 0.99F, 1.0F, 1.0F);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    shader.Bind();
    currentScene->Update(0.0);
    currentScene->DrawObjects();
    currentScene->DrawGUI();
    shader.Unbind();
    
    SDL_GL_SwapWindow(window);
}