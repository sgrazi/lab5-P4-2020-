#include <iostream>
#include <set>

int main () {
   std::set<int> myset;
   std::set<int>::iterator it;

   for (int i = 1; i <= 10; i++) myset.insert(i*10);
   it = myset.find(40);
   myset.erase (it);
   myset.erase (myset.find(60));

   std::cout << "myset contains:";
   for (it = myset.begin(); it!=myset.end(); ++it)
      std::cout << ' ' << *it;
   std::cout << '\n';

   return 0;
}
//https://www.tutorialspoint.com/cpp_standard_library/cpp_set_find.htm
//https://www.tutorialspoint.com/cpp_standard_library/cpp_set_insert.htm
//https://www.tutorialspoint.com/cpp_standard_library/cpp_set_def_constructor.htm
//https://www.tutorialspoint.com/cpp_standard_library/set.htm
