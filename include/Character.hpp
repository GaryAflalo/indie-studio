/*
** Character.hpp for Character in /home/drozdz_b/Documents/TestIrrlitch3
**
** Made by drozdz_b
** Login   <drozdz_b@epitech.net>
**
** Started on  Thu May 26 15:18:39 2016 drozdz_b
** Last update Sun May 29 03:02:52 2016 drozdz_b
*/

#ifndef CHARACTER_HPP_
#define CHARACTER_HPP_

#include <irr/irrlicht.h>
#include <map>

#include "CharacterInfo.hh"

using namespace irr;

class Character
{

private:
  scene::ISceneNode*	_node;
  core::vector3df			_pos;
  CharacterInfo				_info;

public:
  Character(scene::ISceneNode* node);
  ~Character();

  const core::vector3df&	getPosition() const;
  CharacterInfo&					getInfo();
  void 	setPosition(f32 x, f32 y);
  void 	setPosition(f32 x, f32 y, f32 z);

  void	move(f32 x, f32 y);
  void	move(f32 x, f32 y, f32 z);
};

#endif
