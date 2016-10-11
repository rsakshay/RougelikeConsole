#include "libtcod.hpp"
#include "Map.h"
#include "Actor.h"
#include "Enemy.h"
#include "Engine.h"
#include "MyList.h"

static const int ROOM_MAX_SIZE = 12;
static const int ROOM_MIN_SIZE = 6;

class BspListener : public ITCODBspCallback {
private:
	Map &map; // a map to dig
	int roomNum; // room number
	int lastx, lasty; // center of the last room
public:
	BspListener(Map &map) : map(map), roomNum(0) {}
	bool visitNode(TCODBsp *node, void *userData) {
		if (node->isLeaf()) {
			int x, y, w, h;
			// dig a room
			TCODRandom *rng = TCODRandom::getInstance();
			w = rng->getInt(ROOM_MIN_SIZE, node->w - 2);
			h = rng->getInt(ROOM_MIN_SIZE, node->h - 2);
			x = rng->getInt(node->x + 1, node->x + node->w - w - 1);
			y = rng->getInt(node->y + 1, node->y + node->h - h - 1);
			map.createRoom(x, y, x + w - 1, y + h - 1, roomNum == 0);
			if (roomNum != 0) {
				// dig a corridor from last room
				map.dig(lastx, lasty, x + w / 2, lasty);
				map.dig(x + w / 2, lasty, x + w / 2, y + h / 2);
			}
			lastx = x + w / 2;
			lasty = y + h / 2;
			roomNum++;
		}
		return true;
	}
};

Map::Map() {

}

Map::Map(int width, int height) : width(width), height(height) {
	tiles = new Tile[width*height];
	map = new TCODMap(width, height);
	/*TCODBsp bsp(0, 0, width, height);
	bsp.splitRecursive(NULL, 8, ROOM_MAX_SIZE, ROOM_MAX_SIZE, 1.5f, 1.5f);
	BspListener listener(*this);
	bsp.traverseInvertedLevelOrder(&listener, NULL);*/
	/*createRoom(3, 3, 10, 10);
	createRoom(3, 15, 10, 35);
	dig(7, 10, 7, 15);
	createRoom(15, 3, 22, 15);*/
	createRoom(3, 3, 10, 10);
	createRoom(3, 15, 10, 30);
	dig(7, 10, 7, 15);
	createRoom(15, 3, 22, 15);
	dig(10, 7, 15, 7);
	createRoom(17, 20, 21, 23);
	dig(19, 15, 19, 20);
	createRoom(27, 3, 32, 8);
	dig(22, 5, 27, 5);
	createRoom(27, 12, 47, 19);
	dig(22, 13, 26, 13);
	dig(29, 8, 29, 11);
	dig(30, 19, 30, 30);
	dig(44, 19, 44, 23);
	//createRoom(29,24,49,31);
	createRoom(43, 24, 46, 27);
	createRoom(29, 31, 49, 38);
	createRoom(15, 31, 22, 38);
	dig(23, 34, 29, 34);
	dig(49, 34, 59, 34);
	createRoom(60, 31, 67, 38);
	dig(64, 26, 64, 30);
	createRoom(50, 19, 70, 26, true);
	createRoom(63, 3, 70, 10);
	dig(66, 10, 66, 18);
	dig(57, 15, 57, 18);
	createRoom(55, 10, 59, 14);
	createRoom(40, 3, 44, 7);
	dig(45, 5, 62, 5);
	dig(7, 30, 7, 33);
	createRoom(5, 34, 9, 38);
}


Map::~Map() {
	delete[] tiles;
	delete map;
}

bool Map::canWalk(int x, int y) const
{
	if (isWall(x, y))
		return false;
	//for (Enemy *iterator = &(engine.myList.begin());
	//	iterator != &(engine.myList.end()); iterator++) {
	//	Enemy* enemy = iterator;
	//	if (enemy->getPos().first == x && enemy->getPos().second == y) {
	//		return false;
	//	}
	//}
	for (int i = 0; i <= engine.myList.top; i++)
	{
		if (engine.myList.objects[i].getPos().first == x && engine.myList.objects[i].getPos().second == y)
		{
			return false;
		}
	}
	return true;
}

bool Map::isWall(int x, int y) const {
	return !map->isWalkable(x, y);
}

bool Map::isExplored(int x, int y) const {
	return tiles[x + y*width].explored;
}

bool Map::isInFov(int x, int y) const {
	if (map->isInFov(x, y)) {
		tiles[x + y*width].explored = true;
		return true;
	}
	return false;
}

void Map::computeFov() {
	map->computeFov(engine.player->getPos().first, engine.player->getPos().second,
		engine.fovRadius);
}

void Map::render() const {
	static const TCODColor darkWall(0, 0, 100);
	static const TCODColor darkGround(50, 50, 150);
	static const TCODColor lightWall(130, 110, 50);
	static const TCODColor lightGround(200, 180, 50);
	for (int x = 0; x < width; x++) {
		for (int y = 0; y < height; y++) {
			if (isExplored(x, y)) {
				TCODConsole::root->setCharBackground(x, y,
					isWall(x, y) ? darkWall : darkGround);
			}
			if (isInFov(x, y)) {
				TCODConsole::root->setCharBackground(x, y,
					isWall(x, y) ? lightWall : lightGround);
			}
		}
	}
}

void Map::dig(int x1, int y1, int x2, int y2) {
	if (x2 < x1) {
		int tmp = x2;
		x2 = x1;
		x1 = tmp;
	}
	if (y2 < y1) {
		int tmp = y2;
		y2 = y1;
		y1 = tmp;
	}
	for (int tilex = x1; tilex <= x2; tilex++) {
		for (int tiley = y1; tiley <= y2; tiley++) {
			map->setProperties(tilex, tiley, true, true);
		}
	}
}

void Map::createRoom(int x1, int y1, int x2, int y2, bool first) {
	dig(x1, y1, x2, y2);
	if (first) {
		// put the player in the first room
		engine.player->setActorPos((x1 + x2) / 2, (y1 + y2) / 2);
	}
	else {
		TCODRandom *rng = TCODRandom::getInstance();
		if (rng->getInt(0, 3) == 0) {
			engine.myList.push(*(new Enemy((x1 + x2) / 2, (y1 + y2) / 2, '@',
				TCODColor::yellow, 'o')));
		}
	}
}

