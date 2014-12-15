#ifndef SCENE_H
#define SCENE_H

#include <windows.h>
#include <GL/glut.h>

class Scene
{
    public:

        static const unsigned RENDER_2D = 1;
        static const unsigned RENDER_3D = 2;
        static const unsigned VIEW_ORTHOGONAL = 1;
        static const unsigned VIEW_ISOMETRIC = 2;

        Scene();
        ~Scene();
        virtual void inputVariables() = 0;
        virtual void drawScene() = 0;

        unsigned getRenderMode();
        void setRenderMode(const unsigned mode);

        unsigned getViewMode();
        void setViewMode(const unsigned mode);

        void setOrthoSize(unsigned size);
        unsigned getOrthoSize();

        void setWindowWidth(unsigned width);
        void setWindowHeight(unsigned height);

        unsigned getWindowWidth();
        unsigned getWindowHeight();


    protected:

        unsigned m_renderMode;   // 2D or 3D
        unsigned m_viewMode;     // Ortogonal or Isometric
        unsigned m_orthoSize;
        unsigned m_windowWidth;
        unsigned m_windowHeight;
};

#endif // SCENE_H
