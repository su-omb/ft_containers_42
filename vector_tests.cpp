/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_tests.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouykou <obouykou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 23:15:44 by obouykou          #+#    #+#             */
/*   Updated: 2021/05/18 19:11:52 by obouykou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"
#include <vector>
#include <cmath>
#include <iostream>

#ifndef NS
# define NS ft
#endif

template <typename T>
void print_namespace(ft::vector<T> const &vec)
{
	if (vec.size())
		vec.empty();
	std::cout << "\nNAMESPACE : ft" << std::endl;
}

template <typename T>
void print_namespace(std::vector<T> const &vect)
{
	if (vect.size())
		vect.empty();
	std::cout << "\nNAMESPACE : std" << std::endl;
}

template < typename T >
void print_vector(NS::vector<T> &vect, char const *label)
{
	std::cout << "\nvector Size: " << vect.size();
	std::cout << "\nvector [" << label <<"] contains:";
	if (!vect.size())
		std::cout << "\tnothing";
	for (typename NS::vector<T>::iterator it = vect.begin(); it != vect.end(); ++it)
	{
		std::cout << "  [ " << *it << " ]";
	}
	std::cout << std::endl;
}


// a predicate implemented as a function:
bool single_digit (const int& value) { return (value<10); }

// a predicate implemented as a class:
struct is_odd {
  bool operator() (const int& value) { return (value%2)==1; }
};

// a binary predicate implemented as a function:
bool same_integral_part (double first, double second)
{ return ( int(first)==int(second) ); }

// a binary predicate implemented as a class:
struct is_near {
  bool operator() (double first, double second)
  { return (fabs(first-second)<5.0); }
};


// compare only integral part:
bool mycomparison (double first, double second)
{ return ( int(first)<int(second) ); }


int main(void)
{
	NS::vector<int> vectGolbal;
	print_namespace(vectGolbal);
	// front() and back()
	{	
		std::cout << "\nfront() & back()" << std::endl;
		std::cout << "=======================================" << std::endl;
		NS::vector<int> myvect;

		myvect.push_back(77);
		myvect.push_back(22);

		print_vector(myvect, "myvect");
		
		// now front equals 77, and back 22
		
		myvect.front() -= myvect.back();
		
		std::cout << "myvect.front() is now " << myvect.front() << '\n';
		std::cout << "=======================================" << std::endl;
	}
	
	// max_size()
	{	
		std::cout << "\nmax_size()" << std::endl;
		std::cout << "=======================================" << std::endl;
		NS::vector<size_t> myvect;

		myvect.push_back(77);
		myvect.push_back(22);
		
		std::cout << "myvect.max_size() is: " << myvect.max_size() << '\n';
		std::cout << "=======================================" << std::endl;
	}
	
	// assign()
	{
		std::cout << "\nassign()" << std::endl;
		std::cout << "=======================================" << std::endl;
		NS::vector<int> first;
		NS::vector<int> second;

		first.assign (7,100);                      // 7 ints with value 100

		second.assign (first.begin(),first.end()); // a copy of first
		print_vector(first, "first");
		print_vector(second, "second");

		NS::vector<int> vect(3);
		first.assign (vect.begin(),vect.end());
		print_vector(first, "first");

		std::cout << "Size of first: " << int (first.size()) << '\n';
		std::cout << "Size of second: " << int (second.size()) << '\n';
		
		std::cout << "=======================================" << std::endl;
	}


	// insert()
	{
		std::cout << "\ninsert()" << std::endl;
		std::cout << "=======================================" << std::endl;
		NS::vector<int> myvect;
		NS::vector<int>::iterator ite;

		// set some initial values:
		for (int i=1; i<=5; ++i) 
		{
			myvect.push_back(i);
		}
		ite = myvect.begin();				  
		++ite;

		myvect.insert(ite++,10);

		ite = myvect.begin();			  
		ite += 2; 
		myvect.insert(ite,2,20);                
		print_vector(myvect, "myvect");


		NS::vector<int> mytmp (2,30);
		print_vector(mytmp, "mytmp");
		
		ite = myvect.begin();	  
		myvect.insert(ite,mytmp.begin(),mytmp.end());
		
		print_vector(myvect, "myvect");
		std::cout << "=======================================" << std::endl;
	}	


	// erase()
	{
		std::cout << "\nerase()" << std::endl;
		std::cout << "=======================================" << std::endl;

		NS::vector<int> myvect;
		NS::vector<int>::iterator it1,it2;

		// set some values:
		for (int i=1; i<10; ++i)
			myvect.push_back(i*10);

		print_vector(myvect, "myvect");

														// 10 20 30 40 50 60 70 80 90
		it1 = it2 = myvect.begin(); 					// ^^
		for (size_t i = 0; i < 6; i++, it2++);          // ^                 ^
		++it1;                      					//    ^              ^
		--it2;
		it1 = myvect.erase (it1);   // 10 30 40 50 60 70 80 90
									//    ^              ^

		print_vector(myvect, "myvect");
		std::cout << "*it1 = " << *it1 << std::endl;
		std::cout << "*it1 = " << *it2 << std::endl;

		it2 = myvect.erase (it2);   // 10 30 40 50 60 80 90
									//    ^           ^
		print_vector(myvect, "myvect");
		std::cout << "*it1 = " << *it1 << std::endl;
		std::cout << "*it1 = " << *it2 << std::endl;
									// 10 30 40 50 60 80 90
		++it1;                      //    ^           ^
		--it2;                      //       ^     ^
		std::cout << "*it1 = " << *it1 << std::endl;
		std::cout << "*it1 = " << *it2 << std::endl;
		// it1 = myvect.begin();
		it2 = myvect.end();
		myvect.erase (it1,it2);     // 10 30 60 80 90
									//        ^

		print_vector(myvect, "myvect");

		std::cout << "=======================================" << std::endl;
	}
	
	// swap()
	{
		std::cout << "\nswap()" << std::endl;
		std::cout << "=======================================" << std::endl;
		// ft::vector
		NS::vector<int> first (3, 100) ;   // three ints with a value of 100
		NS::vector<int> second (5,200);  // five ints with a value of 200


		print_vector(first, "first");
		print_vector(second, "second");

		first.swap(second);

		print_vector(first, "first");
		print_vector(second, "second");

		std::cout << "=======================================" << std::endl;
	}

	// resize()
	{
		std::cout << "\nresize()" << std::endl;
		std::cout << "=======================================" << std::endl;

		NS::vector<int> myvect;

		// set some initial content:
		for (int i = 1; i < 10; ++i)
			myvect.push_back(i);

		print_vector(myvect, "myvect");
		myvect.resize(5);
		print_vector(myvect, "myvect");
		myvect.resize(8, 100);
		print_vector(myvect, "myvect");
		myvect.resize(12);
		print_vector(myvect, "myvect");

		
		std::cout << "=======================================" << std::endl;
	}	


	// relational operators()
	{
		std::cout << "\nrelational operators" << std::endl;
		std::cout << "=======================================" << std::endl;

		NS::vector<int> a;
		a.push_back(10);
		a.push_back(20);
		a.push_back(30);
		print_vector(a, "a");
		std::cout << "/* message */" << std::endl;
		NS::vector<int> b = a;
		// b = a;
		std::cout << "/* message */" << std::endl;
		print_vector(b, "b");
		
		NS::vector<int> c;
		c.push_back(30);
		c.push_back(20);
		c.push_back(10);
		print_vector(c, "c");
		

		if (a==b) std::cout << "\na and b are equal\n";
		if (b!=c) std::cout << "b and c are not equal\n";
		if (b<c) std::cout << "b is less than c\n";
		if (c>b) std::cout << "c is greater than b\n";
		if (a<=b) std::cout << "a is less than or equal to b\n";
		if (a>=b) std::cout << "a is greater than or equal to b\n";
		std::cout << "=======================================" << std::endl;
	}
	
	// non-member swap()
	{
		std::cout << "\nnon-member swap()" << std::endl;
		std::cout << "=======================================" << std::endl;
		
		NS::vector<int> foo (3,100);   // three ints with a value of 100
		NS::vector<int> bar (5,200);   // five ints with a value of 200

		print_vector(foo, "foo");
		print_vector(bar, "bar");
		NS::swap(foo,bar);
		print_vector(foo, "foo");
		print_vector(bar, "bar");
		
		std::cout << "=======================================" << std::endl;
	}

	// reverse iterators
	{
		std::cout << "\nreverse iterators" << std::endl;
		std::cout << "=======================================" << std::endl;
		NS::vector<int> l;
		l.push_back(1);
		l.insert(l.end(),4, 100);
		l.push_back(2);
		NS::vector<int>::reverse_iterator ite = l.rbegin();
		NS::vector<int>::reverse_iterator it = l.rend();
		for (int i = 0; it != ite; ite++, i++)
		{
			std::cout << "[" << *ite << "]  ";
		}
		std::cout << "\n=======================================" << std::endl;
	}

	return 0;
}

// // function()
// {
// 	std::cout << "\nfunction()" << std::endl;
// 	std::cout << "=======================================" << std::endl;
	

// 	std::cout << "=======================================" << std::endl;
// }