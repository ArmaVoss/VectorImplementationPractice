#include <iostream>

class VectorImplementation {
    private:
        unsigned int length;
        unsigned int capacity;
        int *arr;

        void reallocate(){
            //allocate a new part of memory twice the capacity
            //copy over all data
            //free original array and point it at the new address
            int* a = new int[capacity*2];
            for(int i = 0; i<length; i++){
                a[i] = arr[i];
            }
            delete[] arr;
            arr = a;
            capacity*=2;
        }

    public:
        //defualt constructor creates vector with capacity 10
        VectorImplementation(){
            arr = new int[10];
            length = 0;
            capacity = 10;
        }

        //constructor creates a vector of specified length
        VectorImplementation(int len){
            length = len;
            capacity = len * 2;
            arr = new int[capacity];
            //defaults values of arr to 0
            for(int i = 0; i<len; i++){
                arr[i] = 0;
            }
        }

        //returns the number of elements currently in the array
        int getLength(){
            return length;
        }

        //returns the total capacity allocated to the vector
        int getCapacity(){
            return capacity;
        }

        //appending an element to the end of a vector
        void append(int x){
            //guard to dynamically increase size of array
            if (length == capacity){
               reallocate();
            } 

            //add the element and print success
            arr[length] = x;
            std::cout << "number added succesfully \n";
            length++;
        }

        //remove an element at a specific index
        bool remove(int x){
            //guard to ensure we don't remove elements not in the vector
            if(x < 0 || x >= length){
                throw::std::invalid_argument("Trying to remove element out of range \n");
                return false;
            }
            
            for(int i = x; i < length-1; i++){
                arr[i] = arr[i+1];
            }
            length--;
            return true;
        }

        //inserts an element into the vector
        bool insert(int x, int y){
            //gaurd to ensure index in range
            if(x < 0 || x > length){
                std::cout << "Can't insert here in the array\n";
                return false;
            }
            
            //reallocates the array if the length is equal to arrays capacity
            if(length == capacity){
                reallocate();
            }

            //shifts elements over to the right to new length and 
            //inserts x in place
            length++;
            for(int i = length - 1; i > x; i--){
                arr[i] = arr[i-1];
            }
            arr[x] = y;
            return true;
        }

        //prints the vector
        void print(){
            //guard to print empty array
            if (length == 0){
                std::cout << "[] \n";
                return;
            }

            std::cout << "[";
            for(int i = 0; i < length-1; i++){
                std::cout << arr[i] << ", ";
            }
            std::cout << arr[length-1] << "]" << std::endl;
        }
};

int main() {
    VectorImplementation test;
    test.append(1);
    test.append(2);
    test.append(3);
    test.append(4);
    test.append(5);
    test.append(6);
    test.append(7);
    test.append(8);
    test.append(9);
    test.append(10);
    test.insert(2, 10);
    test.insert(0,5);
    test.print();
    std::cout << test.getLength() << std::endl;
    std::cout << test.getCapacity() << std::endl;

    return 0;
}