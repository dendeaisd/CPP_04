/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvoicu <fvoicu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 18:15:36 by fvoicu            #+#    #+#             */
/*   Updated: 2024/05/19 21:14:50 by fvoicu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "MateriaSource.hpp"
#include "Character.hpp"

void testMateriaUsage(ICharacter* user, ICharacter* target, int idx) {
    user->use(idx, *target);
}

void testMateriaInventory(ICharacter* character) {
    for (int i = 0; i < 4; ++i) {
        testMateriaUsage(character, character, i);
    }
}

void testMateriaSource(IMateriaSource* src) {
  AMateria* tmp;
    
  tmp = src->createMateria("ice");
  if (tmp) {
    std::cout << "Created Materia of type: " << tmp->getType() << std::endl;
  } else {
    std::cout << "Failed to create Materia of type: ice" << std::endl;
  }
  delete tmp;
    
  tmp = src->createMateria("cure");
  if (tmp) {
    std::cout << "Created Materia of type: " << tmp->getType() << std::endl;
  } else {
    std::cout << "Failed to create Materia of type: cure" << std::endl;
  }
  delete tmp;
    
  // tmp = src->createMateria("unknown");
  // if (tmp) {
  //   std::cout << "Created Materia of type: " << tmp->getType() << std::endl;
  // } else {
  //   std::cout << "Failed to create Materia of type: unknown" << std::endl;
  // }
  // delete tmp;
}

int main()
{
  /*Subject test*/
  IMateriaSource* src = new MateriaSource();
  src->learnMateria(new Ice());
  src->learnMateria(new Cure());
  ICharacter* me = new Character("me");
  AMateria* tmp;
  tmp = src->createMateria("ice");
  me->equip(tmp);
  tmp = src->createMateria("cure");
  me->equip(tmp);
  ICharacter* bob = new Character("bob");
  me->use(0, *bob);
  me->use(1, *bob);
  
  /*Additional tests*/
  std::cout << "Additional tests:" << std::endl;

  // Test with another character
  ICharacter* alice = new Character("alice");
  me->use(0, *alice);
  me->use(1, *alice);
  testMateriaInventory(me);

  // Equip more Materia
  tmp = src->createMateria("ice");
  me->equip(tmp);
  tmp = src->createMateria("cure");
  me->equip(tmp);
  testMateriaInventory(me);

  AMateria* uneqMateria[2] = {NULL, NULL};
  // Unequip Materia
  me->unequip(2);
  // uneqMateria[0] = me->_inventory[2];
  me->unequip(3);
  // uneqMateria[1] = me->_inventory[3];
  
  
  testMateriaInventory(me);

  // Test MateriaSource
  testMateriaSource(src);
  
  delete bob;
  delete alice;
  delete me;
  delete src;

  delete uneqMateria[0];
  delete uneqMateria[1];
  return 0;
}