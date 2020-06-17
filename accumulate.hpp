//
// Created by יאנה on 08/06/2020.
//

#ifndef ITERTOOLS_CFAR_A_MASTER_ACCUMULATE_H
#define ITERTOOLS_CFAR_A_MASTER_ACCUMULATE_H

#include <string>
#include "range.hpp"
#include <vector>
#include <iostream>

namespace itertools {
    typedef struct  {
        template <typename T>
        T operator()(T a, T b){return a+b;}
    }myFun;
    template<typename T,typename FUN = myFun>
    class accumulate {
    public:

        T ans; // arr[int]
        FUN f_; // +
        typedef typename T::value_type value_type; // int
        explicit accumulate(T list,FUN f =myFun()):ans(list),f_(f){}

        class iterator {
        public:
            typename T::value_type data_;
            typename T::iterator it_;
            typename T::iterator end_;
            FUN f_;
            iterator(typename T::iterator it, typename T::iterator end, FUN f):it_(it),end_(end),f_(f){
                if(it_!=end_){
                    data_=*it;
                }
            }

            iterator& operator=(const iterator& other ) {
                if (this != &other) {
                    this->data_ = other.data_;
                    this->it_ = other.it_;
                    this->end_ = other.end_;
                    this->f_=other.f_;
                }
                return *this;
            }
            bool operator==(const iterator& other){
                return (it_==other.it_);
            }
            bool operator!=(const iterator& other){
                return !(it_==other.it_);
            }

            decltype(data_) operator*(){
                return data_;
            }
            iterator operator++(int){ //i++
                iterator temp=*this;
                ++(*this);
                return temp;
            }
            iterator operator++(){//++i
                ++it_;
                if(it_!=end_){
                    data_=f_(data_, *it_);
                }
                return *this;

            }

        };


        iterator begin(){ return iterator(ans.begin(), ans.end(),f_);}
        iterator end(){ return iterator(ans.end(), ans.end(), f_); }

    };
}

#endif //ITERTOOLS_CFAR_A_MASTER_ACCUMULATE_H
