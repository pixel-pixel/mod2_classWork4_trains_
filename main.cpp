#include <iostream>

using namespace std;

enum {BLUE, RED};

struct Steck{
private:
    int maxSize = 10;
    int top = -1;
    int *arr = new int[maxSize];
    int *arr2 = nullptr;

    void newArr(){
        maxSize *= 2;
        arr2 = new int[maxSize];
        for(int i = 0; i < maxSize/2; i++){
            arr2[i] = arr[i];
        }
        delete(arr);
        *arr = *arr2;
    }
public:
    void push(int element){
        if(top == maxSize){
            newArr();
        }
        arr[++top] = element;
    }
    int peek(){
        return arr[top];
    }
    int pop(){
        return arr[top--];
    }
    bool isEmpty(){
        return top == -1;
    }
    void print(){
        for(int i = 0; i <= top; i++){
            cout << arr[i] << ' ';
        }
        cout << endl;
    };
};

int main() {
    Steck main, blue, red;

    main.push(BLUE);
    main.push(RED);
    main.push(RED);
    main.push(RED);
    main.push(BLUE);
    main.push(RED);
    main.push(BLUE);
    main.push(BLUE);
    main.push(BLUE);
    main.push(BLUE);
    main.push(RED);
    main.push(RED);
    main.push(BLUE);
    main.push(RED);

    while(!main.isEmpty()){
        main.print();
        switch (main.peek()){
            case BLUE:
                blue.push(main.pop());
                break;
            case RED:
                red.push(main.pop());
        }
    }

    blue.print();
    red.print();

    return 0;
}
