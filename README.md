# Banking System Simulation

This C++ project simulates a banking system that uses a **binary heap** data structure to handle customer service operations. The system manages clients based on their arrival time and priority, ensuring that high-priority clients are serviced first.

## Features

- **Binary Heap for Priority Queue**: The project implements a binary heap to manage the order of clients waiting for service, ensuring efficient priority-based handling.
- **Priority-Based Service**: Clients with higher priority are served before those with lower priority, regardless of arrival time.
- **Client Arrival Time**: The system tracks when each client arrives to ensure fairness in service based on their arrival and priority.
- **Simulation of Banking Operations**: The simulation models the flow of clients in a banking system, handling multiple clients based on the provided rules.

## Project Structure

- `BankSimApp.cpp`: Contains the main logic for the banking simulation.
- `Client.h` & `Client.cpp`: Represents a client with arrival time and priority.
- `BinaryHeap.h` & `BinaryHeap.cpp`: Implements a binary heap for managing the priority queue of clients.
- `BankSimulation.h` & `BankSimulation.cpp`: Manages the entire simulation process, including client arrival and service handling.

## Usage

1. Clone this repository.
2. Compile the project using the provided `Makefile`:
   ```bash
   make
