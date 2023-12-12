#include <iostream>
#include <vector>

// Iterator
template <typename T>
class Iterator {
private:
    const std::vector<T>& collection;
    size_t position;

public:
    Iterator(const std::vector<T>& collection) : collection(collection), position(0) {}

    bool hasNext() const {
        return position < collection.size();
    }

    T next() {
        return collection[position++];
    }
};

// Aggregate
template <typename T>
class Aggregate {
private:
    std::vector<T> elements;

public:
    void add(const T& element) {
        elements.push_back(element);
    }

    Iterator<T> createIterator() const {
        return Iterator<T>(elements);
    }
};

int main() {
    Aggregate<int> aggregate;
    aggregate.add(1);
    aggregate.add(2);
    aggregate.add(3);

    Iterator<int> iterator = aggregate.createIterator();

    while (iterator.hasNext()) {
        std::cout << "Element: " << iterator.next() << std::endl;
    }

    return 0;
}
