/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvoicu <fvoicu@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 20:39:22 by fvoicu            #+#    #+#             */
/*   Updated: 2024/04/28 20:58:12 by fvoicu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal() {
  _type = "Cat";
  std::cout << PINK << "Cat constructor called" 
            << RESET << std::endl;
}

Cat::Cat(const Cat &other) : Animal(other) {
  std::cout << PINK << "Cat copy constructor called" 
            << RESET << std::endl;
}

Cat Cat::operator=(const Cat &other) {
  if (this != &other)
    _type = other._type;
  std::cout << PINK << "Cat assignation operator called" 
            << RESET << std::endl;
  return *this;
}

Cat::~Cat() {
  std::cout << PINK << "Cat destructor called" 
            << RESET << std::endl;
}

void Cat::makeSound() const {
  std::cout << PINK << "* meow meow🐱 *" 
            << RESET << std::endl;
}