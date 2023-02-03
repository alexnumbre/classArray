#ifndef INTARRAY_H
#define INTARRAY_H

#include <exception>


using namespace std;


class bad_range : public exception
{
public:
    virtual const char* what() const noexcept override   { return "ERROR: Wrong Index!"; }
};

class bad_length : public exception
{
public:
    virtual const char* what() const noexcept override   { return "ERROR: Wrong Length"; }
};
class bad_value : public exception
{
public:
    virtual const char* what() const noexcept override { return "ERROR: No Such Index Was Found"; }
};

class IntArray
{
private:
    int m_length{};
    int* m_data{};

public:
    IntArray() = default;
    IntArray(int length);
    IntArray(const IntArray& a);
    ~IntArray();

    void erase();
    void remove(int index);
    int& operator[](int index);
    IntArray& operator=(const IntArray& a);


    // reallocate resizes the array.  Any existing elements will be destroyed.  This function operates quickly.
    void reallocate(int newLength);
   

    // resize resizes the array.  Any existing elements will be kept.  This function operates slowly.
    void resize(int newLength);
   




    void insertBefore(int value, int index);




    // A couple of additional functions just for convenience
    void insertAtBeginning(int value) { insertBefore(value, 0); }
    void insertAtEnd(int value) { insertBefore(value, m_length); }
    int findIndexByValue(int value);

    int getLength() const { return m_length; }
};

#endif