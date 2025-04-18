#ifndef ENUM_SKILL_HPP
#define ENUM_SKILL_HPP

#include <cstdint>

namespace core::enums {

enum class Skill : uint8_t {
    /// region Habilidades de Coleta e Produção(1 - 10)

    // Corte de Madeira
    Woodcutting = 1,
    // Mineração
    Mining = 2,
    // Pesca
    Fishing = 3,
    // Coleta de recursos
    Foraging = 4,
    // Agricultura
    Farming = 5,

    /// region Habilidades de Contrução e Artesanato(11 - 20)

    // Alquimia (trabalho com poçães)
    Alchemy = 11,
    // Ferraria (trabalho com metais para criação de armas e armaduras)
    Blacksmithing = 12,
    // Escultura em Ossos (criação de joias e outros itens)
    BoneCarving = 13,
    // Culinaria (trabalho com alimentos)
    Cooking = 14,
    // Carpintaria (trabalho com madeira)
    Carpentry = 15,
    // Joalheria (trabalho com joias e pedras preciosas)
    Jewelcrafting = 16,
    // Curtimento (trabalho com couro)
    Leatherworking = 17,
    // Ourivesaria (trabalho com metais)
    Metalsmithing = 18,
    // Alfaiataria (trabalho com tecidos)
    Tailoring = 19,
};
}
#endif
