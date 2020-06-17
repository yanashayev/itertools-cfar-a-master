//
// Created by יאנה on 08/06/2020.
//

#ifndef ITERTOOLS_CFAR_A_MASTER_COMPRESS_H
#define ITERTOOLS_CFAR_A_MASTER_COMPRESS_H

namespace itertools{
    template <typename T,typename B>
    class compress{
    public:
        T list;
        B bool_list;
        typedef typename T::value_type value_type;

        compress(T l,B b):list(l),bool_list(b){}
        class iterator{
        public:
            typename T::iterator it_;
            typename T::iterator end_;
            typename B::iterator bool_it;
            iterator(typename T::iterator it, typename T::iterator end, typename B::iterator itb):
            it_(it),end_(end),bool_it(itb){}
            iterator operator=(const iterator& other){
                if(this!=&other){
                    this->it_=other.it_;

                }
                return *this;
            }
            bool operator==(const iterator& other){
                return (it_==other.it_);
            }
            bool operator!=(const iterator& other){
                return (it_!=other.it_);
            }
            auto operator*(){
                return *it_;
            }

            iterator& operator++(){//i++
                do{
                    ++it_;
                    ++bool_it;
                }while(it_!=end_&&!(*bool_it));
                return *this;
            }
            iterator& operator++(int){ //++i
                iterator temp=*this;
                ++(*this);
                return temp;

            }


        };
        iterator begin(){ return iterator(list.begin(),list.end(),bool_list.begin());}
        iterator end(){ return iterator(list.end(), list.end(),  bool_list.end());}


    };
}

#endif //ITERTOOLS_CFAR_A_MASTER_COMPRESS_H
