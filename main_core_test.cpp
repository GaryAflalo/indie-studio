 //
// main.cpp for main in /home/drozdz_b/Documents/TestIrrlitch
//
// Made by drozdz_b
// Login   <drozdz_b@epitech.net>
//
// Started on  Wed May  4 14:00:27 2016 drozdz_b
// Last update Wed May  4 14:01:00 2016 drozdz_b
//

#include <iostream>
#include <irr/irrlicht.h>

#include "../irrlicht-1.8.3/include/IGeometryCreator.h"

#include "Character.hpp"
#include "KeyReceiver.hpp"
#include "PlayerController.hpp"
#include "Plan.hpp"
#include "Object.hh"
#include "Box.hh"

using namespace irr;
using namespace core;
using namespace scene;
using namespace video;
using namespace io;
using namespace gui;

int			main()
{
  SIrrlichtCreationParameters		params;

  E_DRIVER_TYPE				driverType = EDT_OPENGL;
  params.DriverType = driverType;
  params.WindowSize = dimension2d<u32>(640, 480);

  KeyReceiver receiver;

  //            core::dimension2d<u32>(640, 480), 16, false, false, false, &receiver);
  IrrlichtDevice	*device = createDevice(driverType,
            core::dimension2d<u32>(1024, 980), 16, false, false, false, &receiver);

  if (!device)
    return 1;

  device->setWindowCaption(L"Sisi la famille!!!");

  IVideoDriver		*driver = device->getVideoDriver();
  ISceneManager		*smgr = device->getSceneManager();
  IGUIEnvironment	*guienv = device->getGUIEnvironment();
  core::dimension2d<f32> tileSize(1, 1);
  core::dimension2d<u32>   tileCount(50, 50);

  IMesh			*plane = smgr->getGeometryCreator()->createPlaneMesh(tileSize, tileCount);
  IMeshSceneNode	*node = smgr->addMeshSceneNode(plane);

  Plan plan(node, smgr);

    //IMesh *cube = smgr->getGeometryCreator()->createCubeMesh();
    Box box(smgr, driver);
    Box box2(smgr, driver);
    box2.setPosition(0,0,-20);
  Character obj(smgr, driver);
  obj.setCollision(box.getNode(),
  smgr->getGeometryCreator()->createCubeMesh(), smgr);
  obj.setCollision(box2.getNode(),
  smgr->getGeometryCreator()->createCubeMesh(), smgr);

//  obj.setCollision(node, plane, smgr);
  PlayerController player(&obj, &receiver, device);

  plan.addObject(&obj);
//  plan.addObject(&box);
  plan.checkChild();

  if (node)
    {
      node->setMaterialFlag(EMF_LIGHTING, false);
      // node->setMD2Animation(EMAT_STAND);
      node->setMaterialTexture(0, driver->getTexture("WoodChips01_D.tga"));
    }

  driver->setTextureCreationFlag(ETCF_CREATE_MIP_MAPS, false);

  scene::ISceneNode* skybox=smgr->addSkyBoxSceneNode(
						     driver->getTexture("../irrlicht-1.8.3/media/irrlicht2_up.jpg"),
						     driver->getTexture("../irrlicht-1.8.3/media/irrlicht2_dn.jpg"),
						     driver->getTexture("../irrlicht-1.8.3/media/irrlicht2_lf.jpg"),
						     driver->getTexture("../irrlicht-1.8.3/media/irrlicht2_rt.jpg"),
						     driver->getTexture("../irrlicht-1.8.3/media/irrlicht2_ft.jpg"),
						     driver->getTexture("../irrlicht-1.8.3/media/irrlicht2_bk.jpg"));

  scene::ISceneNode* skydome=smgr->addSkyDomeSceneNode(driver->getTexture("../irrlicht-1.8.3/media/skydome.jpg"),16,8,0.95f,2.0f);

  driver->setTextureCreationFlag(ETCF_CREATE_MIP_MAPS, true);

//  smgr->addCameraSceneNode(0, vector3df(0, 30, -40), vector3df(0, 5, 0));
  smgr->addCameraSceneNode(0, vector3df(10, 30, -40), vector3df(0, 10, 0));
  while (device->run())
    {
      driver->beginScene(true, true, 0);
      player.doAction();
      smgr->drawAll();
      guienv->drawAll();
      driver->endScene();
    }

  device->drop();

  return (0);
}