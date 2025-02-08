// Construction with no parameter: Creates an empty array
template <typename T>
Array<T>::Array() : data(NULL), _size(0) {}


//  Construction with an unsigned int n as a parameter: Creates an array of n elements 
template <typename T>
Array<T>::Array(unsigned int n) : data(new T[n]), _size(n) {}


// Construction by copy
template <typename T>
Array<T>::Array(const Array<T>& other) {
    _size = other._size;
    data = new T[_size];
    for (unsigned int i = 0; i < _size; ++i) {
        data[i] = other.data[i];
    }
}


// Construction by assignment
template <typename T>
Array<T>& Array<T>::operator=(const Array<T>& other) {
    if (this != &other) {
        delete[] data;  // Free any existing memory
        _size = other._size;
        data = new T[_size];
        for (unsigned int i = 0; i < _size; ++i) {
            data[i] = other.data[i];  // Deep copy
        }
    }
    return *this;
}


// Elements can be accessed through the subscript operator: [ ]
template <typename T>
T& Array<T>::operator[](unsigned int index) {
    if (index >= _size) {
        throw std::out_of_range("Index out of bounds");
    }
    return data[index];
}


// Returns the number of elements in the array
template <typename T>
unsigned int Array<T>::size() const {
    return _size;
}


// Destructor
template <typename T>
Array<T>::~Array() {
    delete[] data;
}

/* Shallow copy: just copy the pointer

template <typename T>
Array<T>::Array(const Array<T>& other) {
    _size = other._size;
    data = other.data;

* it doesn't allocate new memory or copy the elements one by one
* both arrays point to the same memory location which leads to shared data
* double-free error: if both arrays deallocate the same memory
*/