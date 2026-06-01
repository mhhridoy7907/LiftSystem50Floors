import java.util.*;

public class LiftSystem50Floors {

    static int currentFloor = 0;        
    static boolean goingUp = true;        
    static TreeSet<Integer> requests = new TreeSet<>();  

  
    public static void addRequest(int floor){
        if(floor >= 0 && floor <= 50){
            requests.add(floor);
        } else {
            System.out.println("Invalid floor: " + floor);
        }
    }

    public static void runLift(){
        while(!requests.isEmpty()){
            if(goingUp){
                Integer next = requests.ceiling(currentFloor);  
                if(next != null){
                    moveToFloor(next);
                } else {
                    goingUp = false;  
                }
            } else {
                Integer next = requests.floor(currentFloor);  
                if(next != null){
                    moveToFloor(next);
                } else {
                    goingUp = true;  
                }
            }
        }
        System.out.println("All requests completed. Lift is idle at floor " + currentFloor);
    }

    
    public static void moveToFloor(int floor){
        System.out.println("Moving from " + currentFloor + " to " + floor);
        currentFloor = floor;
        requests.remove(floor);
        System.out.println("Stopped at floor " + floor);
    }

    public static void main(String[] args){

       
        Random rand = new Random();
        for(int i = 0; i < 20; i++){
            int floor = rand.nextInt(51);  
            addRequest(floor);
        }

        System.out.println("Lift requests: " + requests);
        runLift();
    }
}
