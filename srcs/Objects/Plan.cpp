/*
** Plan.cpp for Plan in /home/drozdz_b/Documents/TestIrrlitch7
**
** Made by drozdz_b
** Login   <drozdz_b@epitech.net>
**
** Started on  Wed Jun 01 16:08:39 2016 drozdz_b
// Last update Sun Jun  5 00:47:18 2016 Sacha Sacha Monderer
*/

#include "Plan.hpp"

Plan::Plan(scene::ISceneNode *node, scene::ISceneManager *smgr)
: Object(node)
{
  this->_smgr = smgr;
}

Plan::Plan(scene::ISceneManager* smgr, video::IVideoDriver * driver)
: Object(NULL)
{
  core::dimension2d<f32> tileSize(1, 1);
  core::dimension2d<u32>   tileCount(10, 10);
  scene::IMesh			*plane =
    smgr->getGeometryCreator()->createPlaneMesh(tileSize, tileCount);
  
  _node = smgr->addMeshSceneNode(plane);

  if(_node)
  {
    _node->setMaterialFlag(video::EMF_LIGHTING, false);
    _node->setMaterialTexture(0, driver->getTexture("imgs/WoodChips01_D.tga"));
    _node->setPosition(core::vector3df(4.5f, 0, 4.5f));
    // _node->setRotation(core::vector3df(90, 0, 0));
  }
}

Plan::~Plan()
{
}
