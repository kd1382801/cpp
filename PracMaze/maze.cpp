#include "maze.h"

MapData::MapData() = default;

int MapData::getMapValue(int x, int y) {
	return MapData[y][x];
}

int MapData::getMapSize(int i) {
	return mapData[i].size();
}

int MapData::getMapSize() {
	return mapData.size();
}

int MapData::addMap(int j, int value) {
	mapData[j].push_back(value);
}

int MapData::resizeMap() {
	mapData.resize(mapData.size() + 1);
}

int MapData::setMapValue(int x, int y, int value) {
	mapData[y][x] = value;
}