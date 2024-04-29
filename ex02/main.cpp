/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvoicu <fvoicu@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 20:20:04 by fvoicu            #+#    #+#             */
/*   Updated: 2024/04/29 03:20:58 by fvoicu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"

int main() {
  /*Uncommenting this should cause a compile-time error*/
  // Animal testAnimal;

    /*Array of pointers to Animal*/
    Animal* animals[2];

    /*Create instances of derived classes*/
    animals[0] = new Dog();
    animals[1] = new Cat();

    // Invoke behavior
    for (int i = 0; i < 2; i++) {
        animals[i]->makeSound();
    }

    /*Invoke behavior*/
    for (int i = 0; i < 2; i++) {
        delete animals[i];
    }

    return 0;
}
