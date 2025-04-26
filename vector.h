#include <iostream>
using namespace std;

template <typename T>
class Vector
{
    T *data_array;
    int maxSize, currentSize;

    void resize()
    {
        int new_max = currentSize;
        if (new_max == 0)
        {
            maxSize = 1;
        }
        else if (new_max == maxSize)
        {
            maxSize *= 2;
        }
        else if (new_max <= maxSize / 4)
        {
            maxSize /= 2;
        }

        else
        {
            new_max = maxSize;
        }
        T *new_array = new T[new_max];
        for (int i = 0; i < new_max; i++)
        {
            new_array[i] = data_array[i];
        }
        delete[] data_array;
        data_array = new_array;
    }

public:
    Vector()
    {
        maxSize = 0, currentSize = 0;
        data_array = nullptr;
    }

    Vector(int size)
    {
        if (size < 0)
        {
            throw invalid_argument("Size should be the greater than one");
        }
        maxSize = size;
        currentSize = size;
        data_array = new T[maxSize];
    }
    
    int getSize()
    {
        return currentSize;
    }

    Vector(const Vector &other)
    {
        currentSize = 0;
        this->maxSize = other.maxSize;
        data_array = new T[maxSize];
        for (int i = 0; i < maxSize; i++)
        {
            data_array[i] = other.data_array[i];
            currentSize++;
        }
    }

    ~Vector()
    {
        delete[] data_array;
    }

    void setMaxSize(int size)
    {
        maxSize = size;
    }

    int Size() const
    {
        return currentSize;
    }

    int getMaxSize() const
    {
        return maxSize;
    }

    void Pop_back()
    {

        if (currentSize == 0)
        {
            throw invalid_argument("Vector is empty.");
        }
        data_array[currentSize - 1] = T{};
        currentSize--;
        resize();
    }

    void Push_back(T value)
    {

        if (currentSize == maxSize)
        {
            resize();
        }
        data_array[currentSize] = value;
        currentSize++;
    }

    bool is_empty()
    {
        if (Size() == 0)
        {
            return true;
        }
        return false;
    }

    bool is_full()
    {
        if (Size() == maxSize)
        {
            return true;
        }
        return false;
    }

    T at(int index)
    {
        if (index < 0 || index >= Size())
        {
            throw invalid_argument("Out of Range.");
        }
        return data_array[index];
    }

    T Erase(int index)
    {
        if (index < 0 && index >= Size())
        {
            throw invalid_argument("Out of Range.");
        }
        T value = data_array[index];
        T *new_array = new T[maxSize];
        for (int i = 0; i < index; i++)
        {

            new_array[i] = data_array[i];
        }
        for (int i = index; i < Size(); i++)
        {
            if (i + 1 < Size())
                new_array[i] = data_array[i + 1];
        }
        delete[] data_array;
        data_array = new_array;
        currentSize--;
        resize();
        return value;
    }

    void swapElements(Vector &other)
    {
        Vector<T> temp(maxSize);
        temp.currentSize = this->currentSize;
        for (int i = 0; i < currentSize; i++)
        {
            temp.data_array[i] = data_array[i];
        }

        this->maxSize = other.maxSize;
        this->currentSize = other.currentSize;
        for (int i = 0; i < other.Size(); i++)
        {
            data_array[i] = other.data_array[i];
        }

        other.maxSize = temp.maxSize;
        other.currentSize = temp.currentSize;
        for (int i = 0; i < temp.Size(); i++)
        {
            other.data_array[i] = temp.data_array[i];
        }
    }

    void insert(int index, const T &value)
    {
        if (index < 0 || index > Size())
        {
            throw out_of_range("Index out of range");
        }

        if (is_full())
        {
            resize();
        }

        for (int i = Size(); i > index; --i)
        {
            data_array[i] = data_array[i - 1];
        }

        data_array[index] = value;
        currentSize++;
    }

    void Sort()
    {
        for (int i = 0; i < Size() - 1; ++i)
        {
            for (int j = 0; j < Size() - i - 1; ++j)
            {
                if (data_array[j] > data_array[j + 1])
                {
                    T temp = data_array[j];
                    data_array[j] = data_array[j + 1];
                    data_array[j + 1] = temp;
                }
            }
        }
    }

    Vector<T> Union(const Vector<T> &other)
    {
        Vector<T> result(Size() + other.Size());
        int k = 0;
        result.currentSize = 0;

        for (int i = 0; i < Size(); ++i)
        {
            result.data_array[k++] = data_array[i];
            result.currentSize++;
        }

        for (int i = 0; i < other.Size(); ++i)
        {
            bool found = false;
            for (int j = 0; j < Size(); ++j)
            {
                if (other.data_array[i] == result.data_array[j])
                {
                    found = true;
                    break;
                }
            }
            if (!found)
            {
                result.data_array[k++] = other.data_array[i];
                result.currentSize++;
            }
        }

        return result;
    }

    Vector<T> Intersection(const Vector<T> &other)
    {
        int size;
        if (Size() <= other.Size())
        {
            size = Size();
        }
        else
        {
            size = other.Size();
        }
        Vector<T> result(size);
        int k = 0;
        result.currentSize = 0;

        for (int i = 0; i < Size(); ++i)
        {
            for (int j = 0; j < other.Size(); ++j)
            {
                if (data_array[i] == other.data_array[j])
                {
                    result.data_array[k++] = data_array[i];
                    result.currentSize++;
                    break;
                }
            }
        }

        return result;
    }

    Vector<T> Unique()
    {
        Vector<T> result(Size());
        result.data_array[0] = this->data_array[0];
        int k = 1;
        result.currentSize = 1;

        for (int i = 1; i < Size(); ++i)
        {
            bool isUnique = true;
            for (int j = 0; j < k; ++j)
            {
                if (data_array[i] == result.data_array[j])
                {
                    isUnique = false;
                    break;
                }
            }
            if (isUnique)
            {
                result.data_array[k++] = data_array[i];
                result.currentSize++;
            }
        }

        return result;
    }

    int count(T element)
    {
        int n = 1;
        for (int i = 0; i < Size(); i++)
        {
            if (data_array[i] == element)
            {
                n++;
            }
        }
        return n;
    }

    void move(int n)
    {
        if (n < -(Size()) || n > Size())
        {
            throw invalid_argument("Invalid movement Expected.");
        }
        if (n == 0 || Size() <= 1)
        {
            return;
        }
        Vector<T> temp(Size());

        if (n > 0)
        {
            for (int i = 0; i < Size(); i++)
            {
                int index = (i + n) % Size();
                temp.data_array[index] = data_array[i];
            }
        }
        else
        {
            n = -n;
            for (int i = 0; i < Size(); i++)
            {
                int index = (i - n + Size()) % Size();
                temp.data_array[index] = data_array[i];
            }
        }

        for (int i = 0; i < Size(); i++)
        {
            data_array[i] = temp.data_array[i];
        }
    }

    bool Subset(const Vector<T> &other)
    {
        if (Size() < other.Size())
        {
            return false;
        }

        for (int i = 0; i < other.Size(); i++)
        {
            for (int j = 0; j < Size(); j++)
            {
                if (other.data_array[i] == data_array[j])
                {
                    return true;
                }
            }
        }
    }

    bool Search(T key)
    {
        for (int i = 0; i < Size(); i++)
        {
            if (data_array[i] == key)
            {
                return true;
            }
        }
        return false;
    }

    Vector<T> operator+(const Vector<T> &other)
    {
        Vector<T> result(Size() + other.Size());
        result.currentSize = 0;

        for (int i = 0; i < Size(); i++)
        {
            result.data_array[i] = this->data_array[i];
            result.currentSize++;
        }

        int j = 0;
        for (int i = Size(); i < Size() + other.Size(); i++)
        {
            result.data_array[i] = other.data_array[j++];
            result.currentSize++;
        }
        cout << j;
        return result;
    }

    Vector<T> operator-(Vector<T> &other)
    {
        Vector<T> result(Size()+other.Size());
        int k = 0;
        result.currentSize = 0;
        bool found = false;
        for (int i = 0; i < Size(); i++)
        {
            for (int j = 0; j < other.Size(); j++)
            {
                if (data_array[i] == other.data_array[j])
                {
                    found = true;
                    break;
                }
            }
            if (!found)
            {
                result.data_array[k++] = data_array[i];
                result.currentSize++;
            }
        }
        return result;
    }

    T operator[](int index)
    {
        if (index < 0 || index >= Size())
        {
            throw out_of_range("Index is out of Range.");
        }
        return data_array[index];
    }

    bool operator==(Vector<T> &other)
    {
        if (Size() > other.Size() || other.Size() > Size())
        {
            return false;
        }

        bool check = true;
        for (int i = 0; i < Size(); i++)
        {
            if (data_array[i] != other.data_array[i])
            {
                check = false;
            }
        }
        return check;
    }

    bool operator>(Vector<T> &other)
    {
        return Size() > other.Size();
    }

    bool operator<(Vector<T> other)
    {
        cout<<currentSize;
        return Size() < other.Size();
    }

    Vector<T> &operator=(Vector<T> &other)
    {
        if (this != &other)
        {
            delete[] data_array;
            maxSize = other.maxSize;
            data_array = new T[maxSize];
            for (int i = 0; i < other.Size(); i++)
            {
                data_array[i] = other.data_array[i];
            }
        }
        return *this;
    }

    friend istream &operator>>(istream &in, Vector<T> &other)
    {
        for (int i = 0; i < other.getMaxSize(); i++)
        {
            in >> other.data_array[i];
        }
        return in;
    }

    friend ostream &operator<<(ostream &o, const Vector<T> &other)
    {
        o << "Elements are: ";
        for (int i = 0; i < other.Size(); i++)
        {
            o << other.data_array[i] << " ";
        }
        return o;
    }
};
