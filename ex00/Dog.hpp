/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvoicu <fvoicu@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 20:43:42 by fvoicu            #+#    #+#             */
/*   Updated: 2024/04/28 20:44:18 by fvoicu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP
# include "Animal.hpp"

class Dog : public Animal {
 public:
  Dog();
  Dog(const Dog &other);
  Dog operator=(const Dog &other);
  virtual ~Dog();

  void makeSound() const;
};

#endif
