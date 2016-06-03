//
// PlaySubMenu.cpp for Menus in /home/rigola_s/test_repo/test_irrlicht/test_indie/srcs/Menus
// 
// Made by Rigolat Sébastien
// Login   <rigola_s@epitech.net>
// 
// Started on  Mon May  2 17:40:34 2016 Rigolat Sébastien
// Last update Mon May  2 17:40:34 2016 Rigolat Sébastien
//

#include "MenuManager.hpp"

PlaySubMenu::PlaySubMenu(SAppContext const &context)
	: AGUIMenu(context)
{
	_nbPlayer = 1;
	AGUIMenu::initGUIelements();
	initGUIelements();
	initKeyMap();
}

PlaySubMenu::~PlaySubMenu() {}

void				PlaySubMenu::initGUIelements()
{
	s32 X = 1920/ 2 - 100;
	s32 Y = 1080 / 2 - 32;
	_selectableButtons.push_back(Environment->addButton(core::rect<s32>(X, 360, X + 100, 360 + 32),
						   this,
						   PLAY,
						   L"Start"));
	//	->setImage(_driver->getTexture("Media/irrlichtlogo2.png"));
	_selectableButtons.push_back(Environment->addButton(core::rect<s32>(X, Y - 60, X + 100, (Y - 60) + 32),
						   this,
						   BACK,
						   L"Return"));
//	 ->setImage(_driver->getTexture("Media/irrlichtlogo2.png"));
	Environment->addStaticText(L"Nombre de joueur",
								   core::rect<s32>(100, 200, 200, 400),
								   false,
								   true,
								   this);
//	test->setText(core::stringw(15).c_str()); => used to set a new text;
	_names.push_back(Environment->addEditBox(L"Player 1", core::rect<s32>(500, 500, 550, 520), true, this));
	_names.push_back(Environment->addEditBox(L"Player 2", core::rect<s32>(500, 540, 550, 560), true, this));
	_names.at(1)->setVisible(false);
	Environment->addButton(core::rect<s32>(500, 600, 600, 600 + 32),
						   this,
						   INC,
							L"INC");
	Environment->addButton(core::rect<s32>(500, 700, 600, 700 + 32),
						   this,
						   DEC,
						   L"DEC");
	_nbTxt = Environment->addStaticText(core::stringw(_nbPlayer).c_str(),
								   core::rect<s32>(500, 650, 600, 700),
								   false,
								   true,
								   this);
	_currentButton = getElementFromId(PLAY);
	moveSelector();
}

void				PlaySubMenu::initKeyMap()
{
	_mMap[KEY_UP] = &PlaySubMenu::upKeyPressed;
	_mMap[KEY_DOWN] = &PlaySubMenu::downKeyPressed;
	_mMap[KEY_RETURN] = &PlaySubMenu::enterKeyPressed;
	_mMap[KEY_ESCAPE] = static_cast<mPtr>(&PlaySubMenu::onReturn);

	_mMap[BACK] = static_cast<mPtr>(&PlaySubMenu::onReturn);
	_mMap[INC] = static_cast<mPtr>(&PlaySubMenu::incPlayerNb);
	_mMap[DEC] = static_cast<mPtr>(&PlaySubMenu::decPlayerNb);
}

void				PlaySubMenu::incPlayerNb()
{
	_nbPlayer + 1 > 2 ? (_nbPlayer = 1) : ++_nbPlayer;
	if (_nbPlayer == 2)
		_names.at(1)->setVisible(true);
	else
		_names.at(1)->setVisible(false);
	_nbTxt->setText(core::stringw(_nbPlayer).c_str());
}

void				PlaySubMenu::decPlayerNb()
{
	_nbPlayer - 1 < 1 ? _nbPlayer : --_nbPlayer;
	if (_nbPlayer == 2)
		_names.at(1)->setVisible(true);
	else
		_names.at(1)->setVisible(false);
	_nbTxt->setText(core::stringw(_nbPlayer).c_str());
}

void				PlaySubMenu::onReturn()
{
	Manager::MenuManager::getInstance()->switchMenu(PLAY_MENU);
}