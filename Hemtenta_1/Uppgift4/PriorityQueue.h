/*
Upggift 4 (VG - 30 poäng)

Mallbaserad Prioritetskö 

Skapa en mallbaserad datastruktur som implementerar en enkel Prioritetskö med följande krav: 

	Använd en mallklass för att göra den generisk för olika datatyper och prioritetsnivåer
	Begränsa prioritetsnivåer till 2 (dvs 0 och 1) 1 har högre prioritetsnivå än 0.
	Implementera följande metoder: 
		enqueueWithPriority (lägg till element med prioritet)
		dequeue (ta bort högst prioriterat element)
		peek (visa högst prioriterat element)
		isEmpty (returnera true om kö är tom)
		size (returnera antal element i kö)
	Inkludera lämplig felhantering för tomma kö-operationer
	Skapa ett omfattande testprogram som: 
		Testar prioritetskön med minst två olika datatyper
		Demonstrerar prioritetshantering
		Inkluderar extrem fall, tex ogiltig priorititetsnivå
		Hanterar och visar fel på rätt sätt tex genom kastar exception 
		throw std::exception
	Skriv kommentarer som förklarar dina implementeringsval och prioritetsalgoritm
	Om vi planerar att utöka prioritetsnivåerna till tre (dvs. nivåerna 0, 1 och 2), behöver du inte implementera detta. Din uppgift är istället att undersöka hur många kodrader i din implementationen som behöver uppdateras och identifiera i vilka metoder dessa ändringar krävs.
*/

// Carl Blumenthal

#include <iostream>
#include <deque>

template <typename T, unsigned int MAX_PRIORITY=2>
class PriorityQueue {
public:	
	
	// push T at given priority
	// automatically drops all things with a bad priority level
	void queueWithPriority(const T value, unsigned int priority) {
		#if 0
		// clamp the priority
		priority = (priority < 0) ? 0 : (priority > MAX_PRIORITY - 1) ? MAX_PRIORITY - 1 : priority;
		#else
		if(priority < 0 || priority > MAX_PRIORITY - 1) 
            throw std::invalid_argument("queue"); // drop the invalid enqueue priority
		#endif
		priqueueue[priority].push_back(value);
	}
	
	// walk from MAX_PRIORITY-1 down to 0 (high to low order)
	// read left-to-right from the queue (ring buffer)
	// if something exists, pop-left from queue and write-left on stack call
	T removeFromqueue() {
		if (isEmpty()) {
			throw std::out_of_range("Error: Priority queue is empty");
		}
		
		for(int i = MAX_PRIORITY - 1; i >= 0; i--) {
			if (!priqueueue[i].empty()) {
				T value = priqueueue[i].front();
				priqueueue[i].pop_front();
				return value;
			}
		}
		
		T value = priqueueue[0].front();
		priqueueue[0].pop_front();
		return value;
	}
	
	// do the exact same as dequeue excepts it doesnt pop from the queue
	// should probably give back a pointer instead...
	T peek() const {
		if (isEmpty()) {
			throw std::out_of_range("Error: Priority queue is empty");
		}
		
		for(int i = MAX_PRIORITY - 1; i >= 0; i--) {
			if (!priqueueue[i].empty()) {
				return priqueueue[i].front();
			}
		}
		
		return priqueueue[0].front();
	}
	
	// same kind of loop like dequeue and peek - nothing interesting.
	bool isEmpty() const {
		int n = 0;
		for(int i = MAX_PRIORITY - 1; i >= 0; i--) {
			if (!priqueueue[i].empty()) {
				n++;
			}
		}
		return !(n > 0);
	}
	
	// gets the total set of elements in all queues
	size_t size() const {
		size_t s = 0;
		for(int i = MAX_PRIORITY - 1; i >= 0; i--) {
			s += priqueueue[i].size();
		}
		return s;
	}
	
	// just in case - pops all queueus in order of hi-low
	void clear() {
		while (!isEmpty()) {
			removeFromqueue(); // just drop it on the stack - who cares
		}
	}
	
	// MAX_PRIORITY is not allowed to be 0 by the compiler :)
	// MAX_PRIORITY := 0 < x < 2^32-1
	// note: using too many priority levels would break the stack... maybe we should malloc it instead?
	std::deque<T> priqueueue[MAX_PRIORITY];
};
