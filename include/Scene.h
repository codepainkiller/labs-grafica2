#ifndef SCENE_H
#define SCENE_H

#include <windows.h>
#include <GL/glut.h>

class Scene
{
    static const unsigned RENDER_2D = 1;
    static const unsigned RENDER_3D = 2;
    static const unsigned VIEW_ORTHOGONAL = 1;
    static const unsigned VIEW_ISOMETRIC = 2;

    public:
        Scene();
        ~Scene();
        virtual void inputVariables() = 0;
        virtual void drawScene() = 0;
        unsigned getRenderMode();
        unsigned getViewMode();

    protected:
        unsigned mRenderMode;   // 2D or 3D
        unsigned mViewMode;     // Ortogonal or Isometric
};

#endif // SCENE_H
