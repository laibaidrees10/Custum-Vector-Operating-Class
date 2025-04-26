#include <iostream>
#include "vector.h"
using namespace std;

void displayMenu()
{
    cout << "\nMenu:" << endl;
    cout << " 0. Input elements into vectors" << endl;
    cout << " 1. Display elements\t\t\t 2. Add an element\n 3. Remove an element \t\t\t 4. Access at index\n 5. Remove Element at index\t\t 6. Swap two Vectors\n 7. Sort the array\t\t\t 8. Add a element at a specific index\n 9. Move elements in the array\t\t 10. Union of Vectors\n 11. Intersection of Vectors\t\t 12. Only store the Unique elements\n 13. Count the frequency of element\t 14. Check whether the Vector 2 is a Subset of Vector 1\n 15. Search the desired key\t\t 16. Add two vectors\n 17. Check if two vectors are equal\t 18. Check vector 1 is greater than vector 2\n 19. Subtract vector2 from vector1\t 20. Check vector 1 is less than vector 2\n 21. Exit." << endl;
    cout << "Enter your choice: ";
}

int main()
{
    Vector<int> v1(4), v2(5);  // Sizes can be changed if needed
    int choice = 0;

    cout << "Size of Vector 1: " << v1.getSize() << endl;
    cout << "Enter elements for Vector 1:" << endl;
    cin >> v1;

    while (choice != 21)
    {
        displayMenu();
        cin >> choice;
        switch (choice)
        {
        case 0:
            cout << "Input elements into Vectors selected" << endl;
            cout << "Enter elements for Vector 1:" << endl;
            cin >> v1;
            cout << "Enter elements for Vector 2:" << endl;
            cin >> v2;
            break;

        case 1:
            cout << "Display elements selected" << endl;
            cout << v1;
            break;

        case 2:
            cout << "Add an element selected" << endl;
            int element;
            cout << "Enter the element: ";
            cin >> element;
            v1.Push_back(element);
            break;

        case 3:
            cout << "Remove an element selected" << endl;
            v1.Pop_back();
            break;

        case 4:
            cout << "Access at index selected" << endl;
            try
            {
                int index;
                cout << "Enter index: ";
                cin >> index;
                int result = v1.at(index);
                cout << "Element at index: " << result;
            }
            catch (const exception &e)
            {
                cerr << "Error. " << e.what() << '\n';
            }
            break;

        case 5:
            cout << "Remove Element at index selected" << endl;
            try
            {
                int index;
                cout << "Enter index: ";
                cin >> index;
                int result = v1.Erase(index);
                cout << "Element: " << result << " at index: " << index << " is erased. " << endl;
            }
            catch (const exception &e)
            {
                cerr << e.what() << '\n';
            }
            break;

        case 6:
            cout << "Swap two Vectors selected" << endl;
            v1.swapElements(v2);
            cout << "After Swapping ";
            cout << v1;
            cout << "\nAfter Swapping ";
            cout << v2;
            break;

        case 7:
            cout << "Sort the array selected" << endl;
            v1.Sort();
            cout << v1;
            break;

        case 8:
            cout << "Add an element at a specific index selected" << endl;
            try
            {
                int index, element;
                cout << "Enter index: ";
                cin >> index;
                cout << "Enter element: ";
                cin >> element;
                v1.insert(index, element);
            }
            catch (const exception &e)
            {
                cerr << "Error. " << e.what() << '\n';
            }
            break;

        case 9:
            cout << "Move elements in the array selected" << endl;
            try
            {
                int num;
                cout << "Enter Number to move the elements: ";
                cin >> num;
                v1.move(num);
            }
            catch (const exception &e)
            {
                cerr << "Error. " << e.what() << '\n';
            }
            break;

        case 10:
            cout << "Union of Vectors selected" << endl;
            cout << v1.Union(v2);
            break;

        case 11:
            cout << "Intersection of Vectors selected" << endl;
            cout << v1.Intersection(v2);
            break;

        case 12:
            cout << "Only store the Unique elements selected" << endl;
            cout << v1.Unique();
            break;

        case 13:
            cout << "Count the frequency of element selected" << endl;
            cout << "Enter element: ";
            cin >> element;
            cout << "No. of elements are: " << v1.count(element);
            break;

        case 14:
            cout << "Check whether the Vector 2 is a Subset of Vector 1 selected" << endl;
            if (!v1.Subset(v2))
            {
                cout << "Vector 2 not a subset of Vector 1" << endl;
            }
            else
            {
                cout << "Vector 2 is a subset of Vector 1" << endl;
            }
            break;

        case 15:
            cout << "Search the desired key selected" << endl;
            int k;
            cout << "Enter key: ";
            cin >> k;
            if (!v1.Search(k))
            {
                cout << "Key not found" << endl;
            }
            else
            {
                cout << "Key found" << endl;
            }
            break;

        case 16:
            cout << "Add two vectors selected" << endl;
            cout << v1 + v2;
            break;

        case 17:
            cout << "Check if two vectors are equal selected" << endl;
            if (v1 == v2)
            {
                cout << "Vector 1 is equal to Vector 2";
            }
            else
            {
                cout << "Vector 1 is not equal to Vector 2";
            }
            break;

        case 18:
            cout << "Check if vector 1 is greater than vector 2 selected" << endl;
            if (v1 > v2)
            {
                cout << "Vector 1 is greater than Vector 2." << endl;
            }
            else
            {
                cout << "Vector 1 is not greater than Vector 2." << endl;
            }
            break;

        case 19:
            cout << "Subtract vector 2 from vector 1 selected" << endl;
            cout << v1 - v2;
            break;

        case 20:
            cout << "Check if vector 1 is less than vector 2 selected" << endl;
            if (v1 < v2)
            {
                cout << "Vector 1 is less than Vector 2." << endl;
            }
            else
            {
                cout << "Vector 1 is not less than Vector 2." << endl;
            }
            break;

        case 21:
            cout << "Exiting.";
            break;

        default:
            cout << "Invalid choice. Please enter a valid option." << endl;
        }
    }

    return 0;
}
