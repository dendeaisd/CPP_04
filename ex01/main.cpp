/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvoicu <fvoicu@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 20:20:04 by fvoicu            #+#    #+#             */
/*   Updated: 2024/04/29 02:55:35 by fvoicu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"

int main() {
  Animal* animals[10];

  /*Create Dogs and Cats*/
  for (int i = 0; i < 5; i++) {
      animals[i] = new Dog();
  }
  for (int i = 5; i < 10; i++) {
      animals[i] = new Cat();
  }

  /*Invoke behavior*/
  for (int i = 0; i < 10; i++) {
      animals[i]->makeSound();
  }

  /*Clean up*/
  for (int i = 0; i < 10; i++) {
      delete animals[i];  // This should trigger Brain destructor via Dog/Cat destructors
  }

  return 0;
}
