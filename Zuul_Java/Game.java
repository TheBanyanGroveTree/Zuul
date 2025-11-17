/**
 *  This class is the main class of the "World of Zuul" application. 
 *  "World of Zuul" is a very simple, text based adventure game.  Users 
 *  can walk around some scenery. That's all. It should really be extended 
 *  to make it more interesting!
 * 
 *  To play this game, create an instance of this class and call the "play"
 *  method.
 * 
 *  This main class creates and initialises all the others: it creates all
 *  rooms, creates the parser and starts the game.  It also evaluates and
 *  executes the commands that the parser returns.
 * 
 * @author  Michael Kolling and David J. Barnes
 * @version 1.0 (February 2002)
 */

// import classes
import java.util.ArrayList;

class Game 
{
	// declare global objects
    private Parser parser;
    private Room currentRoom;
    Room outside, mainOffice, counselorOffice, oneTwenty, courtyard, mainHall, restroom;
    Room mathClass, oneHall, scienceClass, cafeteria, library, upperGym, gym, auditorium, aHall;
    ArrayList<Item> inventory = new ArrayList<Item>(); // general types, create class Item
        
    /**
     * Create the game and initialise its internal map.
     */
    public Game() 
    {
        createRooms();
        parser = new Parser();
    }
    
    
    public static void main(String[] args) {
    	Game myGame = new Game();
    	myGame.play();
    }
    

    /**
     * Create all the rooms and link their exits together.
     */
    private void createRooms()
    {
        // create the rooms
        outside = new Room("outside the main entrance of the campus");
        mainOffice = new Room("in the main office getting your late slip");
        counselorOffice = new Room("in the counselor's office to talk");
        oneTwenty = new Room("in the coolest place in the world");
        courtyard = new Room("outside surrounded by benches");
        mainHall = new Room("in main hall");
        restroom = new Room("taking a ten minute break from class to use the \"restroom\"");
        mathClass = new Room("in the boringest room in the entire school");
        oneHall = new Room("getting trampled by the masses in one hall");
        scienceClass = new Room("surrounded by hazardous substances. Be careful");
        cafeteria = new Room("eating a nutritious and delicious school lunch");
        library = new Room("in the quietest room");
        upperGym = new Room("on the second floor");
        gym = new Room("in the middle of flying balls");
        auditorium = new Room("interupting rehearsals for the school play");
        aHall = new Room("where the English classes are");
        
        // initialize room exits
        outside.setExit("north", mainOffice);
        
        mainOffice.setExit("north", mainHall);
        mainOffice.setExit("east", counselorOffice);
        mainOffice.setExit("south", outside);
        
        counselorOffice.setExit("north", restroom);
        counselorOffice.setExit("west", mainOffice);
        
        oneTwenty.setExit("east", courtyard);
        
        courtyard.setExit("north", mathClass);
        courtyard.setExit("east", mainHall);
        courtyard.setExit("west", oneTwenty);
        
        mainHall.setExit("north", oneHall);
        mainHall.setExit("east", restroom);
        mainHall.setExit("south", mainOffice);
        mainHall.setExit("west", courtyard);
        
        restroom.setExit("south", counselorOffice);
        restroom.setExit("west", mainHall);
        
        mathClass.setExit("north", scienceClass);
        mathClass.setExit("east", oneHall);
        mathClass.setExit("south", courtyard);
        
        oneHall.setExit("north", cafeteria);
        oneHall.setExit("south", mainHall);
        oneHall.setExit("west", mathClass);
        
        scienceClass.setExit("east", cafeteria);
        scienceClass.setExit("south", mathClass);
        
        cafeteria.setExit("north", gym);
        cafeteria.setExit("east", library);
        cafeteria.setExit("south", oneHall);
        cafeteria.setExit("west", scienceClass);
        
        library.setExit("north", auditorium);
        library.setExit("west", cafeteria);
        
        upperGym.setExit("east", gym);
        
        gym.setExit("east", auditorium);
        gym.setExit("south", cafeteria);
        gym.setExit("west", upperGym);
        
        auditorium.setExit("east", aHall);
        auditorium.setExit("south", library);
        auditorium.setExit("west", gym);
        
        aHall.setExit("west", auditorium);
        
        currentRoom = outside;  // start game outside
        
        // create items
        mainOffice.setItem(new Item("Slip"));
        oneTwenty.setItem(new Item("Robot"));
        mathClass.setItem(new Item("Protractor"));
        scienceClass.setItem(new Item("Acid"));
        cafeteria.setItem(new Item("Banana"));
        library.setItem(new Item("Book"));
        auditorium.setItem(new Item("Speakers"));
        gym.setItem(new Item("Basketball"));
    }

    /**
     *  Main play routine.  Loops until end of play.
     */
    public void play() 
    {            
        printWelcome();

        // Enter the main command loop.  Here we repeatedly read commands and
        // execute them until the game is over.
                
        boolean finished = false;
        while (! finished) {
            Command command = parser.getCommand();
            finished = processCommand(command);
        }
        System.out.println("Thank you for playing.  Good bye.");
    }

    /**
     * Print out the opening message for the player.
     */
    private void printWelcome()
    {
        System.out.println();
        System.out.println("Welcome to Adventure!");
        System.out.println("Adventure is a new, incredibly boring adventure game.");
        System.out.println("Type 'help' if you need help.");
        System.out.println();
        System.out.println(currentRoom.getLongDescription());
    }

    /**
     * Given a command, process (that is: execute) the command.
     * If this command ends the game, true is returned, otherwise false is
     * returned.
     */
    private boolean processCommand(Command command) 
    {
        boolean wantToQuit = false;

        if(command.isUnknown()) { // invalid command
            System.out.println("I don't know what you mean...");
            return false;
        }

        String commandWord = command.getCommandWord();
        if (commandWord.equals("help")) {
            printHelp();
        }
        else if (commandWord.equals("go")) {
            wantToQuit = goRoom(command);
        }
        else if (commandWord.equals("quit")) {
            wantToQuit = quit(command);
        }
        else if (commandWord.equals("inventory")) {
        	printInventory();
        }
        else if (commandWord.equals("get")) {
        	getItem(command);
        }
        else if (commandWord.equals("drop")) {
        	dropItem(command);
        }
        
        return wantToQuit;
    }

    /*
     * Drop specified item in current room and remove it from the inventory
     */
    private void dropItem(Command command) {
        if(!command.hasSecondWord()) {
            // if there is no second word, we don't know what to drop...
            System.out.println("Drop what?");
            return;
        }

        String item = command.getSecondWord();
        
        // check if item is in the inventory
        Item newItem = null;
        int index = 0;
        for (int i = 0; i < inventory.size(); i++) {
			if (inventory.get(i).getDescription().equals(item)) {
				newItem = inventory.get(i);
				index = i;
			}
		}

        if (newItem == null) { // item isn't in inventory
            System.out.println("That item is not in your inventory!");
        }
        else { // item is in inventory
           inventory.remove(index);
           currentRoom.setItem(new Item(item));
           System.out.println("Dropped: " + item);
        }
    }
    
    /*
     * Pick up item from current room and add it to the inventory
     */
    private void getItem(Command command) {
        if(!command.hasSecondWord()) {
            // if there is no second word, we don't know what item to look for/pick up...
            System.out.println("Get what?");
            return;
        }

        String item = command.getSecondWord();

        Item newItem = currentRoom.getItem(item);

        if (newItem == null)
            System.out.println("That item is not here!");
        else {
           inventory.add(newItem);
           currentRoom.removeItem(item);
           System.out.println("Picked up: " + item);
        }
    }
    
    /*
     * Display all items in the inventory when player enters "inventory" command
     */
    private void printInventory() {
		String output = "";
		for (int i = 0; i < inventory.size(); i++) { // must use .size() method to return length of ArrayList
			output += inventory.get(i).getDescription() + " ";
		}
		System.out.println("You are carrying: ");
		System.out.println(output);
		
	}

	// implementations of user commands:

    /**
     * Print out some help information.
     * Here we print some stupid, cryptic message and a list of the 
     * command words.
     */
    private void printHelp() 
    {
        System.out.println("You are lost. You are alone. You wander");
        System.out.println("around at the university.");
        System.out.println();
        System.out.println("Your command words are:");
        parser.showCommands();
    }

    /** 
     * Try to go to one direction. If there is an exit, enter the new
     * room, otherwise print an error message. Player wins the game if they are
     * in the upper gym and have the item "Robot" in their inventory.
     */
    private boolean goRoom(Command command) 
    {
        if(!command.hasSecondWord()) {
            // if there is no second word, we don't know where to go...
            System.out.println("Go where?");
            // returning no value stops the execution of a function
            return false;
        }

        String direction = command.getSecondWord();

        // Try to leave current room.
        Room nextRoom = currentRoom.getExit(direction);

        if (nextRoom == null)
            System.out.println("There is no door!");
        else {
            currentRoom = nextRoom;
            System.out.println(currentRoom.getLongDescription());
            if ((currentRoom == upperGym) && (checkInventory("Robot"))) {
            	System.out.println("You win!");
            	return true;
            }
        }
        return false;
    }

    /*
     * Check if an item is in the player's inventory
     */
    private boolean checkInventory(String description) {
    	for(int i = 0; i < inventory.size(); i++) {
    		if (inventory.get(i).getDescription().equals(description)) {
    			return true;
    		}
    	}
    	return false; // item not found
    }
    
    /** 
     * "Quit" was entered. Check the rest of the command to see
     * whether we really quit the game. Return true, if this command
     * quits the game, false otherwise.
     */
    private boolean quit(Command command) 
    {
        if(command.hasSecondWord()) {
            System.out.println("Quit what?");
            return false;
        }
        else
            return true;  // signal that we want to quit
    }
}
