//
// Created by dro on 20.08.18.
//
#pragma once

#include <iostream>
#include <map>
#include <memory>

typedef typename std::pair<std::size_t,std::size_t>   _key;


template <class T, T Def>
class Matrix {
public:
    Matrix() {};
    class Row {
        friend class Matrix;
    public:
        T& operator[](std::size_t col){
            parent.last_value=std::make_pair(row,col);
            parent.last_value_flushed=false;
            if (parent.data.count(parent.last_value)<1){
                parent.data[parent.last_value]=Def;
            }
            return parent.data[parent.last_value];
        }
    private:
        Row(Matrix &parent_, std::size_t row_) :
                parent(parent_), row(row_) {}
        Matrix& parent;
        std::size_t row;
    };

    Row operator[](std::size_t row)
    {
        flush();
        return Row(*this, row);
    }

    void flush(){
        if (! last_value_flushed){
            if (data[last_value] == Def){
                data.erase(last_value);
            }
            last_value_flushed=true;
        }
    }

    std::size_t size(){
        flush();
        return data.size();
    }

    typedef typename std::map<_key,T>::iterator		 iterator;
    iterator begin () { return data.begin(); }
    iterator end () { return data.end(); }

private:
    _key last_value;
    bool last_value_flushed=true;
    std::map<_key,T> data;
};
