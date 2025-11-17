/*
 * All game items are objects of this class. The constructor initializes each 
 * object’s description, and an accessor method returns that description.
 * Author: Aahana Sapra
 * Date: 10/30/23
 */

public class Item {

	String description;
	
	/* Constructor 
	 */
	public Item(String newDescription) {
		description = newDescription;
	}
	
	/*
	 * Accessor method that returns the description of an item
	 */
	public String getDescription() {
		return description;
	}
}
