#pragma once
struct Tile {
	bool explored; // has the player already seen this tile ?
	Tile() : explored(false) {}
};

//This class handles Map generation. And also, rendering and updating for each frame
class Map {
public:
	int width, height;				// Width and Height of the entire map

	//Constructors
	Map();
	Map(int width, int height);
	
	//Destructors
	~Map();

	//Member Functions
	bool canWalk(int x, int y) const;			//Check if the Actor can walk on (x,y) coordinates
	bool isWall(int x, int y) const;			//Check if there is a Wall on (x,y)
	bool isInFov(int x, int y) const;			//Check if (x,y) is in Field of View
	bool isExplored(int x, int y) const;		//Check if (x,y) has been explored
	void computeFov();							//Computes the Field of view of the player
	void render() const;						//Set all the tiles and enemies on map in TCODConsole
protected:
	Tile *tiles;								//An array of tiles which store the bool variable of 'explored' for each (x,y)
	TCODMap *map;								//TCODMap pointer
	//friend class BspListener;

	//dig() digs a corridor connecting (x1,y1) and (x2,y2)
	void dig(int x1, int y1, int x2, int y2);

	//createRoom() creates a rectangular room with top left corrdinates (x1, y1) and bottom right cooridnates (x2, y2)
	void createRoom(int x1, int y1, int x2, int y2, bool first = false);
};