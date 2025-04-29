#ifndef ENUM_RACE_HPP
#define ENUM_RACE_HPP

#include <cstdint>

enum class ERace : uint8_t
{
  /// region Player 0 ~ 14
  Dwarf = 0,
  Dragonborn = 1,
  Elf = 2,
  Gnome = 3,
  Goblin = 4,
  Human = 5,
  Lizardfolk = 6,
  Orc = 7,
  Kobold = 8,
  Khajiit = 9,
  Lich = 10,
  Pixie = 11,

  Scarecrow,

  /// region Goblin
  GoblinPyromancer,
  GoblinShaman,
  GoblinCleric,
  GoblinBattleMage,
  /// region Bat
  Bat,
  VampireBat,
  /// region Slime
  Slime,
  RedSlime,
  BlueSlime,
  DarkSlime,
  BrownSlime,
  /// region Spider
  Spider,
  Tarantula,
  FireSpider,
  DarkSpider,
  EnchantSpider,
};
#endif
