#ifndef CS433_ASSIGNMENT1_PCB_H
#define CS433_ASSIGNMENT1_PCB_H


// Remember to add comments to your code
// ...

// enum class of process state
// A process (PCB) in ready queue should be in READY state
enum class ProcState {NEW=0, READY, RUNNING, WAITING, TERMINATED};

/*
Process control block(PCB) is a data structure representing a process in the system.
A process should have at least an ID and a state(i.e.NEW, READY, RUNNING, WAITING or TERMINATED).
It may also have other attributes, such as scheduling information (e.g. priority)
*/
class PCB {
public:
    // The unique process ID
    unsigned int id;
    // The priority of a process valued between 1-50. Larger number represents higher priority
    unsigned int priority;
    // The current state of the process.
    // A process in the ReadyQueue should be in READY state
    ProcState state;

    // TODO: Add constructor and other necessary functions for the PCB class
    //Constructor Deconstructor
    PCB(unsigned int id, unsigned int priority, ProcState state);
    ~PCB();

    //Getters and Setters
    unsigned int getId() const;
    void         setId(unsigned int id);
    unsigned int getPriority() const;
    void         setPriority(unsigned int priority);
    ProcState    getState() const;
    std::string  getStateAsString();
    void         setState(ProcState state);
};
//=============================================================================================
//=============================================================================================
//=============================================================================================
//                      An array(list) of all PCB elements in the system.

class PCBTable {
// TODO: Add your implementation of the PCBTable
private:
    const static int TABLE_SIZE = 30;
    PCB *table[TABLE_SIZE];

public:
    PCBTable();

    void initializeRand();
    void initializeSeq();

    PCB* getPCB_Element(int index);
};
//=============================================================================================
//=============================================================================================
//=============================================================================================


#endif //CS433_ASSIGNMENT1_PCB_H
