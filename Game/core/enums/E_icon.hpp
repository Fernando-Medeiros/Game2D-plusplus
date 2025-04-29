#ifndef ENUM_ICON_HPP
#define ENUM_ICON_HPP

#include <cstdint>

enum class EIcon : uint8_t
{
  Increment,
  Decrement,
  Locked,
  Unlocked,
  /// region Representação do menu de navegação
  Stats,
  Skill,
  Proficiency,
  Codex,
  Setting,
  Bank,
  Inventory,
  Equipment,
  Forge,
  Ornament,
  World,
  Quest,
  Dungeon,
  Tower,
  Training,
  /// region
  Rune,
  Stack,
  Hand,
  Coin,
  /// region
  Consumable,
  Weapon,
  Material,
  Token,
  /// region Representação dos equipamentos
  Necklace,
  Cloak,
  Helmet,
  Armor,
  Boots,
  Ring,
  LeftHand,
  RightHand,
  /// region Representação da construção do personagem
  Alignment,
  Profession,
  Race,
};
#endif
