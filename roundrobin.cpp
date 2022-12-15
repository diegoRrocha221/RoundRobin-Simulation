#include <iostream>
#include <queue>
#include <unistd.h>
#include <stdlib.h>

using namespace std;

struct Process {
  int id;
  int ioRun;
  int burst;
};

Process processes[10];

queue<Process> fila;

void RoundRobin() {
  int quantum = 2;
  for (int i = 0; i < 10; i++) {
  processes[i].id = i + 1;
  processes[i].ioRun = rand() % 10 + 1;
  processes[i].burst = rand() % 10 + 1;
 }
  cout << "Executando Round Robin..." << endl;
  for (int i = 0; i < 10; i++) {
    fila.push(processes[i]);
  }

  while (!fila.empty()) {
    Process process = fila.front();
    fila.pop();

    cout << "Executando processo" << process.id << " com IO run " << process.ioRun << " e burst " << process.burst << endl;
    sleep(process.ioRun + process.burst);
    
    if (process.burst > quantum) {
      fila.push(process);
    }
  }
}