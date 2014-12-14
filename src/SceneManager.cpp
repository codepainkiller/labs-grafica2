#include "SceneManager.h"

SceneManager::SceneManager()
{
    cout << " Inicializando Scene Manager..." << endl;
    cout << " Cargando escenas..." << endl;
    this->showMenu();
    /*
    this->addScene(new Lab1());
    this->addScene(new Lab2());
    this->addScene(new Lab2());
    this->addScene(new Lab2());
    this->addScene(new Lab2());
    this->addScene(new Lab2());
    this->addScene(new Lab7());
    this->setCurrentScene(0);


    cout << " Escenas cargadas...[OK]" << endl;

    // Capturando opcion
    this->showMenu();
    int select = this->menuOption();

    if ( select != -1)
        this->setCurrentScene(select-1);
    else
        cout << " Ocion incorrecta!" << endl;
    */
}

SceneManager::~SceneManager()
{
    cout << "Destruyendo scene manager..." << endl;
}

void SceneManager::addScene(Scene* scene)
{
    m_listScenes.push_back(scene);
}

Scene* SceneManager::getScene(unsigned index)
{
    return m_listScenes.at(index);
}

void SceneManager::setCurrentScene(unsigned index)
{
    if ( index <= m_listScenes.size() )
        m_currentScene = m_listScenes.at(index);
    else
        cout << "No se puede asignar la escena " << index << endl;
}

Scene* SceneManager::getCurrenScene()
{
    return m_currentScene;
}

int SceneManager::menuOption()
{
    int option;

    cout << endl << endl;
    cout << " Ingrese opcion: "; cin >> option;

    switch (option) {

        case 1:
            m_currentScene = new Lab1();
            break;
        case 2:
            m_currentScene = new Lab2();
            break;
        case 3:
            m_currentScene = new Lab3();
            break;
        case 7:
            m_currentScene = new Lab7();
            break;
        default:
            cout << " Opcion incorrecta!" << endl;
    }


    cout << " Opcion " << option << " elegida!" << endl;

    return option;
}

void SceneManager::showMenu()
{
    cout << "\n\t Computacion Grafica II - Laboratorios          ";
    cout << "\n\t -------------------------------------       \n ";

    cout << "\n\t 1.  Escena 2D de la realidad                   ";
    cout << "\n\t 2.  Escena 3D de la realidad                   ";
    cout << "\n\t 3.  Bresenham en 3D para rectas                ";
    cout << "\n\t 4.  Superficies de revolucion                  ";
    cout << "\n\t 5.  Cuadricas                                  ";
    cout << "\n\t 6.  Curva de Bezier en 2D                      ";
    cout << "\n\t 7.  L-Systems en 2D y 3D                       ";
    cout << "\n\t 8.  Escena en 3D de la realidad + iluminacion  ";
    cout << "\n\t 9.  Escena en 3D + iluminacion (imagen)        ";
    cout << "\n\t 10. Raytracing rayo-esfera                     ";
    cout << "\n\t 11. Mapeo inverso esfera                       ";
    cout << "\n\t 12. Raytracing rayo-plano                      ";
    cout << "\n\t 13. Raytracing rayo-triangulo                  ";
    cout << "\n\t 14. Escena 3D con funciones Z-Buffer de OpenGL ";
    cout << "\n\t 15. Escena 3D con algoritmo de Z-Buffer        ";
    cout << "\n\t 15. Mapeo de texturas en OpenGL                ";

    int op = this->menuOption();
}


