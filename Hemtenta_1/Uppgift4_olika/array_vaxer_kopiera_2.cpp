/*
- template baserad priority-queue
- 2 prioteringsnivåer
- moduläritet

- multidimensionell array
*/

#include <iostream>
#include <vector>

template <class T> class PrioQueue {
private:
    unsigned int que0Size = 1, que1Size = 1;
    unsigned int que0Elements = 0, que1Elements = 0;
    const int maxPrio = 1;

    T* queue0 = nullptr; //2st heap array
    T* queue1 = nullptr; //en per prioritering

public:
    
    PrioQueue () { //skapar plats på heap för båda prioriteringar
        queue0 = new T[que0Size];
        queue1 = new T[que1Size];
    }

    ~PrioQueue () { //destructor som frigör minne
        delete [] queue0;
        delete [] queue1;
        queue0 = nullptr; //återställer pekare
        queue1 = nullptr;
    }

    bool isEmpty(int prio) { //returnar om specifik lista är tom
        if (prio == 0 && que0Elements > 0) {
                return false;
        }
        else if (prio == 1 && que1Elements > 0) {
            return false;
        }
        return true;
    }

    bool isEmpty() { //returnerar om hela queue är tom
        if ((que0Elements + que1Elements) > 0) {
            return false;
        }
        return true;
    }

    void enqueueWithPriority(T element, int prio) { //lägg till nytt element med prioritering
        if (prio == 0) {
            if (que0Size == que0Elements) { //allokera mer minne för array[0]
                que0Size *= 2; //dubblar storlek på size
                T* temp = new T[que0Size]; //använder ny size

                for (int i = 0; i < que0Elements; i++) { //kopiera till ny array
                    temp[i] = queue0[i];
                }
                delete [] queue0; //tar bort gamla minnet
                queue0 = temp; //pekar på nya arrayen

                temp = nullptr; //ställer temp pointer till nullpointer 
            }
            //sätter nytt värde på första lediga plats i array
            queue0[que0Elements] = element;
            que0Elements++;
        }

        else if (prio == 1) {
            if (que1Size == que1Elements) { //allokera mer minne för array[0]
                que1Size *= 2; //dubblar storlek på size
                T* temp = new T[que1Size]; //använder ny size

                for (int i = 0; i < que1Elements; i++) { //kopiera till ny array
                    temp[i] = queue1[i];
                }
                delete [] queue1; //tar bort gamla minnet
                queue1 = temp; //pekar på nya arrayen

                temp = nullptr; //ställer temp pointer till nullpointer 
            }
            queue1[que1Elements] = element;
            que1Elements++;
        }
        else if (prio > maxPrio){
            std::cout << "Priority level " << prio << " does not exist\n";
        }
    }

    void dequeue() { //pekar om pekaren och returnerar elementet som togs bort
        if (que1Elements == que1Size) { //om elementet är på sista index i array
            que1Size++;
            T* temp = new T[que1Size];
            for (int i = 0; i < que1Elements; i++) {
                temp[i] = queue1[i];
            }

            queue1 = temp;
            temp = nullptr;
        }
        
        if (que0Elements == que0Size) { //om elementet är på sista index i array
            que0Size++;
            T* temp = new T[que0Size];
            for (int i = 0; i < que0Elements; i++) {
                temp[i] = queue0[i];
            }

            queue0 = temp;
            temp = nullptr;
        }

        if (!isEmpty(1)) { //om högsta prio har element
            for (int i = 0; i < que1Elements; i++) {
                queue1[i] = queue1[i + 1];
            }
            que1Elements--; //-1 på antal element
            return; 
        }
        else if (!isEmpty(0)) { //om låg prio har element
            for (int i = 0; i < que0Elements; i++) {
                queue0[i] = queue0[i + 1];
            }
            que0Elements--; //-1 på antal element
            return;
        }
        else { //om båda är tomma
            std::cout << "\nEmpty queue\nNothing to dequeue\n";
        }
    }

    void peek() {
        if (!isEmpty(1)) { //om hög prio har element
            std::cout << queue1[0] << "\n";
            return;
        }
        else if (!isEmpty(0)) {
            std::cout << queue0[0] << "\n";
            return;
        }
        std::cout << "List empty\n";
        return; 
    }

    int size() {
        return que0Elements + que1Elements;
    }

    void printQueue() {
        std::cout << "  Top priority\n";
        std::cout << "----------------\n";
        for (int i = 0; i < que1Elements; i++) {
            std::cout << queue1[i] << " ";
        }
        std::cout << "\n  Low priority\n";
        std::cout << "----------------\n";
        for (int i = 0; i < que0Elements; i++) {
            std::cout << queue0[i] << " ";
        }
        std::cout << "\n----------------\n";
    }    
};


int main() {
    PrioQueue<int> queue; //int test

    //test 1 int
    std::cout << "\n============\nINT TEST\n============\n";
    std::cout << "queue size: " << queue.size() << "\n";
    queue.dequeue();
    queue.enqueueWithPriority(3, 0);
    queue.enqueueWithPriority(12, 0);
    queue.printQueue();
    std::cout << "queue size: " << queue.size() << "\n";

    //test 2 int 
    queue.enqueueWithPriority(7, 0);
    queue.enqueueWithPriority(4, 1);
    std::cout << "peek: ";
    queue.peek(); //skriver 4
    queue.dequeue(); //tar bort 4 trots att den lades in sist
    queue.printQueue();
    std::cout << "peek: ";
    queue.peek(); //skriver 3

    std::cout << "\n============\nSTRING TEST\n============\n";

    PrioQueue<std::string> q; //string test
    std::cout << "is empty: " << q.isEmpty() << "\n";
    q.enqueueWithPriority("test", 0);
    q.enqueueWithPriority("teststring", 1);
    
    q.printQueue();
    std::cout << "queue size: " << q.size() << "\n";
    q.dequeue();
    q.dequeue();
    q.printQueue();

    //ogiltig prioriteringsnivå
    q.enqueueWithPriority("test", 2);

    return 0;
}

/*
Jag har hårdkodat ganska mycket i denna uppgift till de 2 prioriterings-nivåerna som finns.
För att lägga till en till prio-nivå behöver jag lägga till en ny nivå i konstruktorn, och
sen har jag försökt göra det ganska lätt att kunna göra en copy paste i alla funktioner och
bara byta ut variabelnamnen till namnet på den nya prio-nivån.

De enda funktionerna jag egentligen behöver ändra är return i peek() och isEmpty()
Resten är bara copy paste och ändra variabelnamn som jag skrev ovan.

Jag skulle säga att ca 3-5 rader behöver ändras, men säkert 50+ rader som behöver läggas till
vid utökning av prioriteringar.
Det hade varit mer modulärt med tex. std::pair eller multidimensionell array och 
for-loopar som itererar varje prioriterings-nivå istället för hårdkodade funktioner.
*/