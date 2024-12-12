// Mallbaserad Prioritetskö 

// Skapa en mallbaserad datastruktur som implementerar en enkel Prioritetskö med följande krav: 
// Använd en mallklass för att göra den generisk för olika datatyper och prioritetsnivåer
// Begränsa prioritetsnivåer till 2 (dvs 0 och 1) 1 har högre prioritetsnivå än 0.
// Implementera följande metoder: 
// enqueueWithPriority (lägg till element med prioritet)
// dequeue (ta bort högst prioriterat element)
// peek (visa högst prioriterat element)
// isEmpty (returnera true om kö är tom)
// size (returnera antal element i kö)
// Inkludera lämplig felhantering för tomma kö-operationer
// Skapa ett omfattande testprogram som: 
// Testar prioritetskön med minst två olika datatyper
// Demonstrerar prioritetshantering
// Inkluderar extrem fall, tex ogiltig priorititetsnivå
// Hanterar och visar fel på rätt sätt tex genom kastar exception 
// throw std::exception
// Skriv kommentarer som förklarar dina implementeringsval och prioritetsalgoritm
// Om vi planerar att utöka prioritetsnivåerna till tre (dvs. nivåerna 0, 1 och 2), behöver du inte implementera detta. 
// Din uppgift är istället att undersöka hur många kodrader i din implementationen som behöver uppdateras och identifiera i vilka metoder dessa ändringar krävs.

#include <utility>
#include <iostream>
#include <string>

template <class T> class PriorityQueue{

    private:
        unsigned int queue_size = 1;                            // storlek på arrayen/queue
        unsigned int elements_in_queue = 0;                     // räknar element
        std::pair<int, T> *queue_arr;

    public:
        
        PriorityQueue(){                                        // tom konstruktor om man inte vill ge en storlek från början
            queue_arr = new std::pair<int, T>[queue_size];
        }

        PriorityQueue(unsigned int in_size){                   //constructor if user want to set size from start
            queue_size = in_size;                              // sätter den "interna" storleken till värdet av den inmatade storleken
            queue_arr = new std::pair<int, T>[queue_size];
        }

        ~PriorityQueue(){                                     // deconstructor som tar bort objektet korrekt eftersom skapat objekt lagras på heapen i konstruktorn
            delete [] queue_arr;
            queue_arr = nullptr;
        }

        void make_queue_grow(std::pair<int, T>* &queue){

            std::pair<int, T> *temp_arr = new std::pair<int,T>[queue_size * 2];

            for(int i = 0; i < elements_in_queue; i++){
                temp_arr[i] = queue[i];
            }        
            queue_size *= 2;

            delete [] queue;
            queue = temp_arr;
            temp_arr = nullptr;
        }

        void enqueueWithPriority(int priority, T element){

            int index = 0;  // räknare för att hålla koll på index
            
            if(elements_in_queue == queue_size){                              // ökar storleken på arrayen om den är full . new size = current size * 2
                make_queue_grow(queue_arr);
            }
            

            if(priority == 1){                                                       // om det pair man vill lägga in är av prioritet 1 (högre prioritet)
                
                std::pair<int, T> *temp_arr = new std::pair<int, T>[queue_size];   // skapar ny temporär array för att kopiera över till

                while(queue_arr[index].first == 1 && index < elements_in_queue){     //här läggs först alla pairs med prioritet 1 in i temp_arr i den ordningen de lades in. while loopen bryts när nuvarande element har lägre prioritet

                    temp_arr[index] = queue_arr[index];
                    index++;
                }
                
                temp_arr[index] = std::make_pair(priority,element);    // här läggs nytt pair in på index efter sista 1 prioritet
                elements_in_queue++;
                index++;
                
                while(index < elements_in_queue){
                    temp_arr[index] = queue_arr[index - 1];
                    index++;
                }    
            
                delete [] queue_arr;                // frigör minnet
                queue_arr = temp_arr;               // main pekaren pekar nu på temp arrayens värde
                temp_arr = nullptr;                 // sätter temp_arr pekaren till nullptr för att undvika floating pointer
            }
            
            else if(priority == 0){                                                                   // om lägre prioritet
                queue_arr[elements_in_queue] = std::make_pair(priority,element);     // eftersom prioriteten är lägsta så behöver vi här bara lägga till pairvärdet längst bak i kön eftersom tidigare inlagda pairvärden som har prioritet 0 ska ligga före i kön eftersom de las in tidigare.
                elements_in_queue++;
            }
            else                 // om priority som blivit inmatad inte är 0 eller 1
                std::cerr << "Invalid priority. Entered priority: " << priority << ". Acceptable priorities are 0 and 1. Element was not added to the queue.\n";
        
        }           
        
        void dequeue(){

            if (isEmpty()) {
                throw std::runtime_error("Cannot dequeue from an empty queue.");
            }
            
            std::pair<int, T> *temp_arr = new std::pair<int, T>[queue_size];
            
            elements_in_queue--;  // tar bort ett element först så att for loopen inte går utanför index

            for(int i = 0; i < elements_in_queue; i++){
                temp_arr[i] = queue_arr[i + 1];
            }
            delete [] queue_arr;
            queue_arr = temp_arr;
            temp_arr = nullptr;  
        }
        

        void print(){   // simple print function
            
            if(elements_in_queue == 0)
                std::cout << "Queue is empty!\n";
            else{
                for(int i = 0; i < elements_in_queue; i++){
                    
                    std::cout << queue_arr[i].second << "\n"; 
                }
                std::cout << std::endl;
            }
        }
 
        void peek(){           // self explanitory
            
            if (isEmpty()) {
                throw std::runtime_error("Cannot peek at an empty queue.");
            }
            else{
                T most_prioritized = queue_arr[0].second;
                std::cout << "Most prioritized: " << most_prioritized << "\n";
            }


        }
    
        unsigned int get_size(){
            return elements_in_queue;
        }
        
        bool isEmpty(){
            if(elements_in_queue == 0)                     // if no elements have been added to the queue == the queue is empty
                return true;
            else
                return false;
        }
};

int main(int argc, char const *argv[])
{
    std::cout << "=================\n";
    std::cout << "==TYPE INT TEST==\n";
    std::cout << "=================\n";
    
    PriorityQueue<int> numbers(5);      // skapar en priorityqueue av typen int med storleken 5
    if(numbers.isEmpty())               // kollar om queuen är tom
        std::cout << "Queue is empty.\n";
    else
        std::cout << "Queue is not empty.\n";
    std::cout << "Size of queue before entering pairs: " << numbers.get_size() << "\n";          // skriver ut storleken innan något lagts till i queuen
    std::cout << std::endl;
    
    numbers.enqueueWithPriority(0, 15);         // lägger till ett pair med lägre prioritet 0 och värdet 15
    numbers.enqueueWithPriority(1, 30);         // lägger till ett pair med högre prioritet för att visa att den högre hamnar före i kön även fast den lades till senare
    std::cout << "Numbers in queue: \n"; numbers.print();        // skriver ut för att visa att 30 hamnat först
    std::cout << std::endl;
    
    numbers.enqueueWithPriority(0, 50);                        // lägger till en till låg prioritet för att visa att den hamnar sist i kön
    numbers.enqueueWithPriority(1, 666);                       // lägger till en till hög prioritet för att visa att den hamnar före de lägre men efter tidigare inmatade hög prioriterade
    std::cout << "Numbers in queue: \n"; numbers.print();        // print
    std::cout << std::endl;

    numbers.enqueueWithPriority(3, 444);         // försöker lägga till ett pair som inte har prioritet 1 eller 0
    numbers.enqueueWithPriority(-5, 444);         // försöker lägga till ett pair som inte har prioritet 1 eller 0

    std::cout << std::endl;

    std::cout << "Size of queue after entering four pairs: " << numbers.get_size() << "\n";         // skriver ut nuvarande storlek
    numbers.peek(); // skriver ut elementet som ligger allra först i kön dvs HÖGST PRIORITERAT
    numbers.dequeue();       // tar bort adet högst prioriterade dvs 30 i det här fallet
    std::cout << "After one dequeue operation: "; numbers.peek(); // nu är 666 först i kön
    std::cout << std::endl;

    std::cout << "Numbers in queue \n"; numbers.print();
    std::cout << "Size of queue now: " << numbers.get_size() << "\n";
    

    std::cout << "=================\n";
    std::cout << std::endl;
    
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    std::cout << std::endl;
    std::cout << "====================\n";
    std::cout << "==TYPE STRING TEST==\n";
    std::cout << "====================\n";
    PriorityQueue<std::string> assignments(4);        // skapar en priorityqueue av typen std::string med storlek 4

    assignments.print(); // försöker printa när queuen är tom

    //lägger till fyra element som bör hamna i följande ordning:  "Hämta barnen", "Laga mat", "Spela sällskapsspel", "Kolla på tv";
    assignments.enqueueWithPriority(1, "Hämta barnen");
    assignments.enqueueWithPriority(0, "Spela sällskapsspel");
    assignments.enqueueWithPriority(3, "Hejsanhoppsan"); // försöker lägga in med ogiltig prioritetsnivå. Felmeddelande skrivs ut i terminalen
    assignments.enqueueWithPriority(1, "Laga mat");
    assignments.enqueueWithPriority(0, "Kolla på tv");

    std::cout << "\nAssignments: \n"; assignments.print();      //skriver ut efter fyra adderingar

    if(assignments.isEmpty())               // kollar om queuen är tom
        std::cout << "Queue is empty.\n";
    else
        std::cout << "Queue is not empty.\n";
    std::cout << "Size of queue: " << assignments.get_size() << "\n";  // skriva ut size

    // Om man skulle vilja implementera fler prioritetsnivåer så sker de allra största ändringarna i koden i enqueueWithPriority()-funktionen. 
    // Skulle man tex ha 5 olika prioritetsnivåer (0-4) och man vill lägga in ett pair med prioritetsnivå 3 så
    // hade man kunnat göra precis som jag gjort dvs kopiera över alla högre prioriteter först tills man stöter på första pair med 
    // prioritet 4 och då lägga in det aktuella elementet där. precis som jag gjort i min funktion. Då skulle man istället för
    // att skriva if(priority == 1) så hade man kunna gjort 1an till en variabel som får värdet av den inmatade variabeln. 
    // Där med kan man kopiera över allt som finns i den nuvarande queuen tills man stöter på den första prioritetsnivån som är STÖRRE än 
    // den prioritetsnivå på pairet man försöker sätta in dvs 4 ifall man försöker mata in ett pair med prioritetsnivå 3. 
    // Jag skulle tro att jag inte behöver skriva så många fler rader kod utan bara omstrukturera funktionen lite och lägga till en variabel. 
    // Jag skulle även behöva ändra några meddelanden som tex att allat annat än 0 och 1 är ogiltiga prioriteringsnivåer. 
    // Om jag skulle estimera mängder kodrader så kanske 10 st kodrader till i enqueueWithPriority()-funktionen + lite omskrivning.

    return 0;
}
