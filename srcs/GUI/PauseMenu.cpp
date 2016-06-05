//
// PauseMenu.cpp for Menus in /home/rigola_s/test_repo/test_irrlicht/test_indie/srcs/Menus
// 
// Made by Rigolat Sébastien
// Login   <rigola_s@epitech.net>
// 
// Started on  Mon May  2 17:40:09 2016 Rigolat Sébastien
// Last update Mon May  2 17:40:09 2016 Rigolat Sébastien
//

#include "MenuManager.hpp"
#include "GameManager.hpp"

PauseMenu::PauseMenu(SAppContext const &context)
	: AGUIMenu(context)
{
	AGUIMenu::initGUIelements();
	initGUIelements();
	initKeyMap();
}

PauseMenu::~PauseMenu() {}

void				PauseMenu::initGUIelements()
{
	s32 X = 1920/ 2 - 100;
	s32 Y = 1080 / 2 - 32;
	_selectableButtons.push_back(Environment->addButton(core::rect<s32>(X, 360, X + 100, 360 + 32),
						   this,
						   CONTINUE,
						   L"Continue"));
	//	->setImage(_driver->getTexture("Media/irrlichtlogo2.png"));
	_selectableButtons.push_back(Environment->addButton(core::rect<s32>(X, Y - 60, X + 100, (Y - 60) + 32),
						   this,
						   EXIT,
						   L"Quit"));
//	 ->setImage(_driver->getTexture("Media/irrlichtlogo2.png"));
	_currentButton = getElementFromId(CONTINUE);
	moveSelector();
}

void				PauseMenu::initKeyMap()
{
	_mMap[KEY_UP] = &PauseMenu::upKeyPressed;
	_mMap[KEY_DOWN] = &PauseMenu::downKeyPressed;
	_mMap[KEY_RETURN] = &PauseMenu::enterKeyPressed;
	_mMap[KEY_ESCAPE] = static_cast<mPtr>(&PauseMenu::onContinue);

	_mMap[CONTINUE] = static_cast<mPtr>(&PauseMenu::onContinue);
	_mMap[EXIT] = static_cast<mPtr>(&PauseMenu::onExit);
}

void				PauseMenu::onContinue()
{
	Manager::MenuManager::getInstance()->unPause();
}

void PauseMenu::onExit()
{
	_context.device->closeDevice();
}
