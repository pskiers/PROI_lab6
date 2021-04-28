#ifndef SET_H
#define SET_H
#include <iostream>

template <class Type>// Szablon klasy
class Set
{
    int lenght, current;
    Type *table;
public:
    Set(int n=1): lenght(n), current(0), table(new Type[n]) {}
    ~Set() { delete [] table; }

    Type & operator[](int i)
    {
        if(i>=0 && i<lenght) return table[i];
        return NULL;
    }
    const Type & operator[](int i) const
    {
        if(i>=0 && i<lenght) return table[i];
        return NULL;
    }
    void operator+(Type element)
    {
        if(is_in_set(element)) return;
        if(current == lenght)
        {
            Type *new_table = new Type[lenght+1];
            for(int i=0; i<current; ++i)
            {
                new_table[i] = table[i];
            }
            delete [] table;
            table = new_table;
            ++lenght;
        }
        table[current] = element;
        ++current;
    }
    void operator-(Type element)
    {
        for(int i=0; i<current; ++i)
        {
            if(element == table[i])
            {
                for(int j=i+1; j<current; ++j)
                {
                    table[j-1] = table[j];
                }
                --current;
                break;
            }
        }
    }
    void operator+(Set other_set)
    {
        for(int i=0; i<other_set.sets_size(); ++i)
        {
            operator+(other_set[i]);
        }
    }
    void operator-(Set other_set)
    {
        for(int i=0; i<other_set.sets_size(); ++i)
        {
            operator-(other_set[i]);
        }
    }
    bool is_in_set(Type element)
    {
    for(int i=0; i<current; ++i)
        {
            if(element == table[i])
            return true;
        }
    return false;
    }
    int sets_size(){return current;}
    int size(){return lenght;}
    void intersection(Set other_set)
    {
        for(int i=0; i<current; ++i)
        {
            if(other_set.is_in_set(table[i])==false) operator-(table[i]);
        }
    }
    bool operator==(Set other_set)
    {
        if(current != other_set.sets_size()) return false;
        for(int i=0; i<other_set.sets_size(); ++i)
        {
            if(is_in_set(other_set[i]) == false) return false;
        }
        return true;
    }

    //friend
    //std::ostream& operator<< (std::ostream &os,Set &set);
};
#endif