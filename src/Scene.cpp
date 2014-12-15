#include "Scene.h"

Scene::Scene()
{
    this->m_renderMode = RENDER_3D;
    this->m_viewMode   = VIEW_ISOMETRIC;
}

Scene::~Scene()
{
    //dtor
}

unsigned Scene::getRenderMode()
{
    return m_renderMode;
}

unsigned Scene::getViewMode()
{
    return m_viewMode;
}

void Scene::setRenderMode(const unsigned mode)
{
    m_renderMode = mode;
}

void Scene::setViewMode(const unsigned mode)
{
    m_viewMode = mode;
}
void Scene::setOrthoSize(unsigned size)
{
    m_orthoSize = size;
}

unsigned Scene::getOrthoSize()
{
    return m_orthoSize;
}

