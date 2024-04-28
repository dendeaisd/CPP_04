/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvoicu <fvoicu@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 20:20:04 by fvoicu            #+#    #+#             */
/*   Updated: 2024/04/28 20:57:16 by fvoicu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

// int main() {
//   std::cout << "\n----------------------------------------\n";
//   std::cout << "Testing the Animal class\n\n";
//   Animal a;
//   std::cout << "Type of a: " << a.getType() << std::endl;
//   a.makeSound();
//   std::cout << "\n----------------------------------------\n";
//   std::cout << "Testing the Cat class\n\n";
//   Cat b;
//   std::cout << "Type of c: " << b.getType() << std::endl;
//   b.makeSound();
//   std::cout << "\n----------------------------------------\n";
//   std::cout << "Testing the Dog class\n\n";
//   Dog c;
//   std::cout << "Type of c: " << c.getType() << std::endl;
//   c.makeSound();
//   std::cout << std::endl;
// }

int main()
{
const Animal* meta = new Animal();
const Animal* j = new Dog();
const Animal* i = new Cat();
std::cout << j->getType() << " " << std::endl;
std::cout << i->getType() << " " << std::endl;
i->makeSound(); //will output the cat sound!
j->makeSound();
meta->makeSound();
delete meta;
delete j;
delete i;
return 0;
}