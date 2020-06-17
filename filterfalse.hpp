//
// Created by יאנה on 08/06/2020.
//

#ifndef ITERTOOLS_CFAR_A_MASTER_FILTERFALSE_H
#define ITERTOOLS_CFAR_A_MASTER_FILTERFALSE_H

namespace itertools{
    template <typename T, typename FUN>
    class filterfalse{
    public:
        FUN f_;
        T ans_;
        typename T::value_type value_type;
         filterfalse(FUN f, T list):f_(f),ans_(list){}
         class iterator{
         public:
             typename T::iterator it_;
             typename T::iterator end_;
             FUN f_;
             explicit iterator(typename T::iterator it,typename T::iterator end, FUN f)
             :it_(it),end_(end),f_(f){
                 while (it_ != end_ && f_(*it_))
                     ++it_;
             }
             iterator(const iterator& other) = default;

             auto operator*(){
                 return *it_;
             }
             bool operator==(const iterator& other){
                 return (it_==other.it_);
             }

             bool operator!=(const iterator& other){
                 return (it_!=other.it_);
             }
             iterator& operator=(const iterator& other){
                 if(this!=&other){

                     this->it_=other.it_;
                     this->end_=other.end_;
                     this->f_=other.f_;
                 }
                 return *this;
             }
             iterator& operator++(int){ //++i
                 iterator temp=*this;
                 ++(*this);
                 return temp;
             }
             iterator&operator++(){
                 do{
                     ++it_;
                 }while(it_!=end_&&f_(*it_));
                 return *this;
             }
         };
        iterator begin(){ return iterator(ans_.begin(), ans_.end(),f_);}
        iterator end(){ return iterator(ans_.end(), ans_.end(), f_); }

    };
}

#endif //ITERTOOLS_CFAR_A_MASTER_FILTERFALSE_H
