#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H

#include "Scene.h"
#include "Lab1.h"
#include "Lab2.h"
#include "Lab3.h"
#include "Lab4.h"
#include "Lab5.h"
#include "Lab6.h"
#include "Lab7.h"
#include "Lab8.h"
#include "Lab9.h"
#include "Lab10.h"
#include "Lab15.h"
#include <iostream>
#include <vector>

using namespace std;

class SceneManager
{
    public:
        SceneManager();
        ~SceneManager();

        void     addScene(Scene* scene);

        Scene*   getScene(unsigned index);

        void     setCurrentScene(unsigned index);

        Scene*   getCurrentScene();


    private:
        int menuOption();
        void showMenu();

        vector<Scene*> m_listScenes;
        Scene*         m_currentScene;

};

#endif // SCENEMANAGER_H
