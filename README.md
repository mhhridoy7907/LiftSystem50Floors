# LiftSystem 50 Floors 🏢🛗

A **human-readable Java simulation** of a 50-floor elevator using the **SCAN (Elevator) algorithm** to efficiently serve floor requests in both directions.  

---

## Problem 🛑

In high-rise buildings:  
- Multiple people press lift buttons at different floors.  
- Lifts often change direction unnecessarily, causing long **waiting times** and inefficient travel.  

---

## Solution ✅

- **Store all lift requests** in a sorted data structure (`TreeSet`) to quickly find next stops.  
- **Track direction** of the lift (`goingUp`) to avoid frequent direction changes.  
- **Serve requests on the way** using SCAN algorithm:  
  - Move in one direction (up or down).  
  - Stop at every requested floor along the path.  
- **Change direction** only when no more requests exist in current path.  

This minimizes **waiting time** and **total travel distance**, simulating how real elevators work in big buildings.  

---

## Features 

- Supports **50 floors** (0–50).  
- Handles **random or user-defined floor requests**.  
- Displays **step-by-step movement** in the console.  
- Uses **SCAN (Elevator) Algorithm** for efficiency.  
- Includes **visual cues** using emojis:  
  - 🛗 = Lift moving  
  - ✅ = Stopped at floor  
  - 🏁 = Idle after finishing all requests  
