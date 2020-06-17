//
// Created by יאנה on 08/06/2020.
//

#ifndef ITERTOOLS_CFAR_A_MASTER_RANGE_H
#define ITERTOOLS_CFAR_A_MASTER_RANGE_H
#include <iterator>

namespace itertools{
    class range{
         int begin_;
         int end_;

    public:
        range(int begin, int end):begin_(begin),end_(end){} // constrector range
        class iterator{
            int value; // pointer for begining iterator
        public:
             iterator(int v): value(v) {} // constractor iterator except only int (explicit)
            int operator*(){ return this->value;}
            bool operator==(const iterator& other){
                return (value==other.value);
            }
            bool operator!=(const iterator& other){
                return (value!=other.value);
            }
            iterator operator++(){
                this->value++;
                return this->value;
            }
            iterator operator=(iterator& other){
                 this->value=other.value;
                return this->value;
             }


        };

        int size() {return this->end_-this->begin_;}
        iterator begin() {return iterator(begin_); }
        iterator end()   { return iterator(end_); }
        typedef int	value_type;
    };
}

#endif //ITERTOOLS_CFAR_A_MASTER_RANGE_H
