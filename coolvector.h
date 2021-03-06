#ifndef coolvector_h
#define coolvector_h

#include <algorithm>

using namespace std;

template<class T>
class coolvector {
 public:
  typedef T* iterator;
  
  coolvector() { T items[] = new T[10]; }

  iterator begin() { return &items[0]; }

  iterator end() { return &items[used-1]; }

  int size() { return used; }

  iterator insert(iterator position, const T& item) {
    used++;


    /*RESIZE ARRAY IF THERE IS TOO MUCH DATA FOR IT*/
    if (used > items.size()) {
      T newitems[] = new T[used*2];
      copy(begin(), end(), &newitems[0]);
      delete [] items;
      items = newitems;
    }


    /*MAKE ROOM FOR NEW ELEMENT IN THE ARRAY*/
    iterator i = end();
    while (i != position) {
      *i+1 = i;
      i--;
    }

    /*ADD NEW ELEMENT INTO ARRAY*/
    *position = item;
  }

 private:
  T items[10];
  int used;

};

#endif
