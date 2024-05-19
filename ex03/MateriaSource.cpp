/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvoicu <fvoicu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 19:19:44 by fvoicu            #+#    #+#             */
/*   Updated: 2024/05/19 19:43:39 by fvoicu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
  for(int i = 0; i < 4; i++) {
    _materias[i] = nullptr; 
  }
}

MateriaSource::MateriaSource(const MateriaSource& other) {
  copyMaterias(other);
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other) {
  if(this != &other) {
    deleteMaterias();
    copyMaterias(other);
  }
  return *this;
}

MateriaSource::~MateriaSource() {
  deleteMaterias();
}

void MateriaSource::learnMateria(AMateria* m) {
  if (!m) return;
  for(int i = 0; i < 4; i++) {
    if (_materias[i] == nullptr) {
      _materias[i] = m->clone();
      return;
    }
  }
}

AMateria*  MateriaSource::createMateria(std::string const& type) {
  for(int i = 0; i < 4; i++) {
    if (_materias[i] && _materias[i]->getType() == type) {
      return _materias[i]->clone();
    }
  }
  return nullptr;
}

void MateriaSource::deleteMaterias() {
  for(int i = 0; i < 4; i++) {
    delete _materias[i];
    _materias[i] = nullptr;
  }
}

void MateriaSource::copyMaterias(const MateriaSource& other) {
  for(int i = 0; i < 4; i++) {
    if (other._materias[i] !=  nullptr) {
      _materias[i] = other._materias[i]->clone();
    } else {
      _materias[i] = nullptr;
    }
  }
}
