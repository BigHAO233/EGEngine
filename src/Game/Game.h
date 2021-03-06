#ifndef GAME_H_
#define GAME_H_

#include "../GameObject/GameObject.h"
#include "../GameObject/Vector2.h"
#include "../GameObject/Text.h"
#include "../Texture/Texture.h"
#include "../Tool/Tool.h"
#include "../Window/Window.h"

#include "conio.h"

#include <cstdio>
#include <string>
#include <queue>
#include <vector>

namespace EGEngine {
    class Game {
        private:
            std::string name;
            std::priority_queue<GameObject*> screen;
            Vector2 size;
            std::vector<std::string> screenWin;
            Window gameWin;

            void Render();
            void Draw();
        public:
            Game(const std::string name = "Game", const Vector2 Size = Vector2(120, 30));
            GameObject* new_GameObject(GameObject* Object);
            bool Get_KeyDown(const char Key) { return ((GetAsyncKeyState(Key) & 0x8000) ? 1:0); }
            
            typedef void (*runFun)();
            void Run(runFun Start, runFun Update);
    };
}

#endif 