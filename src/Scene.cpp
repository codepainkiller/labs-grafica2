#include "Scene.h"

Scene::Scene()
{
    this->mRenderMode = RENDER_3D;
    this->mViewMode   = VIEW_ISOMETRIC;
}

Scene::~Scene()
{
    //dtor
}

unsigned Scene::getRenderMode()
{
    return this->mRenderMode;
}

unsigned Scene::getViewMode()
{
    return this->mViewMode;
}

